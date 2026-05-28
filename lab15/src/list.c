#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initList(MailList* list) {
    list->size = 0;
    list->capacity = 10;
    list->data = malloc(sizeof(Mail) * list->capacity);
}

void freeList(MailList* list) {
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}

void addMail(MailList* list, Mail mail) {

    if (list->size >= list->capacity) {
        list->capacity *= 2;

        list->data = realloc(
            list->data,
            sizeof(Mail) * list->capacity
        );
    }

    *(list->data + list->size) = mail;
    list->size++;
}

void removeMail(MailList* list, int index) {

    if (index < 0 || index >= list->size) {
        return;
    }

    for (int i = index; i < list->size - 1; i++) {
        *(list->data + i) = *(list->data + i + 1);
    }

    list->size--;
}

void printList(MailList* list, FILE* out) {

    for (Mail* m = list->data;
         m < list->data + list->size;
         m++) {

        fprintf(out,
            "Subject: %s\n"
            "Sender: %s\n"
            "Receiver: %s\n"
            "Type: %s\n\n",

            m->subject,
            m->sender.name,
            m->receiver.name,
            m->type
        );
    }
}

MailList findMessagesByUser(
    MailList* list,
    const char* userName
) {

    MailList result;
    initList(&result);

    for (Mail* m = list->data;
         m < list->data + list->size;
         m++) {

        if (strcmp(m->sender.name, userName) == 0) {
            addMail(&result, *m);
        }
    }

    return result;
}

MailList findSecretMessages(MailList* list) {

    MailList result;
    initList(&result);

    for (Mail* m = list->data;
         m < list->data + list->size;
         m++) {

        if (strcmp(m->type, "secret") == 0) {
            addMail(&result, *m);
        }
    }

    return result;
}

int totalMessagesSize(MailList* list) {

    int total = 0;

    for (Mail* m = list->data;
         m < list->data + list->size;
         m++) {

        total += calculateSize(m);
    }

    return total;
}

void sortBySubject(MailList* list) {

    for (int i = 0; i < list->size - 1; i++) {

        for (int j = 0; j < list->size - i - 1; j++) {

            Mail* a = list->data + j;
            Mail* b = list->data + j + 1;

            if (strcmp(a->subject, b->subject) > 0) {

                Mail temp = *a;
                *a = *b;
                *b = temp;
            }
        }
    }
}

