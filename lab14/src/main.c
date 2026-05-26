#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc < 3) return 1;

    int size = 0;
    Mail* mails = readMails(argv[1], &size);

    if (!mails) return 1;

    sortBySubject(mails, size);

    int out1 = 0;
    Mail* byUser = findMessagesByUser(mails, size, "Ivan Ivanov", &out1);

    int out2 = 0;
    Mail* secret = findSecretMessages(mails, size, &out2);

    int total = totalMessagesSize(mails, size);

    FILE* f = fopen(argv[2], "w");

    if (!f) {
    printf("Error: cannot open output file\n");
    return 1;
}

    fprintf(f, "TOTAL SIZE: %d\n\n", total);

    fprintf(f, "ALL MAILS:\n");
    printMails(mails, size, f);

    fprintf(f, "BY USER:\n");
    printMails(byUser, out1, f);

    fprintf(f, "SECRET MAILS:\n");
    printMails(secret, out2, f);

    fclose(f);

    free(mails);
    free(byUser);
    free(secret);

    return 0;
}