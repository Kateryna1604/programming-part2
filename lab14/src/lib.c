#include "lib.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static Encoding parseEncoding(char* s) {
    if (strcmp(s, "UTF8") == 0) return UTF8;
    if (strcmp(s, "UTF16") == 0) return UTF16;
    return CP1251;
}

/* ===================== IO ===================== */

Mail* readMails(const char* filename, int* size) {
    FILE* f = fopen(filename, "r");
    if (!f) return NULL;

    int cap = 10;
    Mail* arr = malloc(sizeof(Mail) * cap);
    *size = 0;

    char line[2000];

    while (fgets(line, sizeof(line), f)) {

        if (*size >= cap) {
            cap *= 2;
            arr = realloc(arr, sizeof(Mail) * cap);
        }

        Mail* m = &arr[*size];

        char enc[20];

        memset(m, 0, sizeof(Mail));

        int ok = sscanf(line,
            "%d|%199[^|]|%999[^|]|%99[^|]|%99[^|]|%99[^|]|%99[^|]|%19[^|]|%19[^|]|%f",
            &m->isDraft,
            m->subject,
            m->body,
            m->sender.name,
            m->sender.email,
            m->receiver.name,
            m->receiver.email,
            enc,
            m->type,
            &m->compression
        );

        if (ok < 9) {
            continue;
        }

        m->encoding = parseEncoding(enc);

        (*size)++;
    }

    fclose(f);
    return arr;
}

void writeMails(const char* filename, Mail* arr, int size) {
    FILE* f = fopen(filename, "w");
    if (!f) return;

    printMails(arr, size, f);
    fclose(f);
}

void printMails(Mail* arr, int size, FILE* out) {
    for (Mail* m = arr; m < arr + size; m++) {
        fprintf(out, "Subject: %s\n", m->subject);
        fprintf(out, "From: %s <%s>\n", m->sender.name, m->sender.email);
        fprintf(out, "To: %s <%s>\n", m->receiver.name, m->receiver.email);
        fprintf(out, "Body: %s\n", m->body);
        fprintf(out, "Type: %s\n\n", m->type);
    }
}

/* ===================== BASE ===================== */

char* buildMessage(Mail* m) {
    static char buf[2000];

    sprintf(buf,
        "%s -> %s | %s | %s",
        m->sender.name,
        m->receiver.name,
        m->subject,
        m->body
    );

    return buf;
}

int calculateSize(Mail* m) {
    return strlen(m->subject) + strlen(m->body);
}

/* ===================== COLLECTION METHODS ===================== */

Mail* findMessagesByUser(Mail* arr, int size, const char* userName, int* outSize) {
    Mail* res = malloc(sizeof(Mail) * size);
    *outSize = 0;

    for (Mail* m = arr; m < arr + size; m++) {
        if (strcmp(m->sender.name, userName) == 0) {
            res[*outSize] = *m;
            (*outSize)++;
        }
    }

    return res;
}

Mail* findSecretMessages(Mail* arr, int size, int* outSize) {
    Mail* res = malloc(sizeof(Mail) * size);
    *outSize = 0;

    for (Mail* m = arr; m < arr + size; m++) {
        if (strcmp(m->type, "secret") == 0) {
            res[*outSize] = *m;
            (*outSize)++;
        }
    }

    return res;
}

int totalMessagesSize(Mail* arr, int size) {
    int sum = 0;

    for (Mail* m = arr; m < arr + size; m++) {
        sum += calculateSize(m);
    }

    return sum;
}

/* ===================== SORT ===================== */

void sortBySubject(Mail* arr, int size) {
    for (Mail* i = arr; i < arr + size; i++) {
        for (Mail* j = i + 1; j < arr + size; j++) {
            if (strcmp(i->subject, j->subject) > 0) {
                Mail tmp = *i;
                *i = *j;
                *j = tmp;
            }
        }
    }
}
