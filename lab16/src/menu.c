#include "menu.h"
#include <stdio.h>

void runMenu(MailList* list) {

    int choice;
    char user[100];

    do {
        printf("\n===== MENU =====\n");
        printf("1. Print list\n");
        printf("2. Add mail\n");
        printf("3. Remove mail\n");
        printf("4. Find by user\n");
        printf("5. Sort by subject\n");
        printf("0. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printList(list);
            break;

        case 2: {
            Mail m;

            printf("Subject: ");
            scanf(" %[^\n]", m.subject);

            printf("Body: ");
            scanf(" %[^\n]", m.body);

            printf("Sender name: ");
            scanf(" %[^\n]", m.sender.name);

            printf("Sender email: ");
            scanf(" %[^\n]", m.sender.email);

            printf("Receiver name: ");
            scanf(" %[^\n]", m.receiver.name);

            printf("Receiver email: ");
            scanf(" %[^\n]", m.receiver.email);

            addMail(list, m);
            break;
        }

        case 3: {
            int index;
            printf("Index: ");
            scanf("%d", &index);
            removeMail(list, index);
            break;
        }

        case 4:
            printf("User name: ");
            scanf(" %[^\n]", user);

            MailList res = findMessagesByUser(list, user);
            printList(&res);
            freeList(&res);
            break;

        case 5:
            sortBySubject(list);
            break;
        }

    } while (choice != 0);
}
