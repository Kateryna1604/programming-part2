#include "../src/list.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>

int main() {

    MailList list;

    initList(&list);

    Mail m1;

    strcpy(m1.subject, "Hello");
    strcpy(m1.body, "Body");

    strcpy(m1.sender.name, "Ivan");
    strcpy(m1.receiver.name, "Petro");

    strcpy(m1.type, "normal");

    addMail(&list, m1);

    assert(list.size == 1);

    Mail m2;

    strcpy(m2.subject, "Secret");
    strcpy(m2.body, "Hidden");

    strcpy(m2.sender.name, "Anna");
    strcpy(m2.receiver.name, "John");

    strcpy(m2.type, "secret");

    addMail(&list, m2);

    assert(list.size == 2);

    MailList result =
        findMessagesByUser(&list, "Ivan");

    assert(result.size == 1);

    MailList secret =
        findSecretMessages(&list);

    assert(secret.size == 1);

    int total =
        totalMessagesSize(&list);

    assert(total > 0);

    removeMail(&list, 0);

    assert(list.size == 1);

    freeList(&list);
    freeList(&result);
    freeList(&secret);

    printf("ALL TESTS PASSED\n");

    return 0;
}
