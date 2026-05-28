#include "list.h"
#include <stdio.h>
#include <string.h>

int main() {

    MailList list;
    initList(&list);

    Mail m1 = {
        0,
        "Hello",
        "First message",
        {"Ivan Ivanov", "ivan@mail.com"},
        {"Petro Petrov", "petro@mail.com"},
        UTF8,
        "normal",
        0
    };

    Mail m2 = {
        0,
        "Secret",
        "Hidden 123 data",
        {"Anna Smith", "anna@mail.com"},
        {"John Doe", "john@mail.com"},
        UTF8,
        "secret",
        0
    };

    Mail m3 = {
        0,
        "Report",
        "Project completed",
        {"Ivan Ivanov", "ivan@mail.com"},
        {"Admin", "admin@mail.com"},
        UTF16,
        "compressed",
        0.5
    };

    addMail(&list, m1);
    addMail(&list, m2);
    addMail(&list, m3);

    printf("ALL MAILS:\n\n");
    printList(&list, stdout);

    printf("TOTAL SIZE: %d\n\n",
        totalMessagesSize(&list));

    MailList userList =
        findMessagesByUser(
            &list,
            "Ivan Ivanov"
        );

    printf("MAILS BY USER:\n\n");
    printList(&userList, stdout);

    MailList secretList =
        findSecretMessages(&list);

    printf("SECRET MAILS:\n\n");
    printList(&secretList, stdout);

    sortBySubject(&list);

    printf("SORTED MAILS:\n\n");
    printList(&list, stdout);

    removeMail(&list, 1);

    printf("AFTER REMOVE:\n\n");
    printList(&list, stdout);

    freeList(&list);
    freeList(&userList);
    freeList(&secretList);

    return 0;
}

