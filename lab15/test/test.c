#include "../src/list.h"
#include <assert.h>
#include <stdio.h>

int main() {

    MailList list;
    initList(&list);

    Mail m = {
        0,
        "Test",
        "Body",
        {"Ivan", "ivan@mail.com"},
        {"Petro", "petro@mail.com"},
        UTF8,
        "normal",
        0
    };

    addMail(&list, m);

    assert(list.size == 1);

    removeMail(&list, 0);

    assert(list.size == 0);

    addMail(&list, m);

    int total = totalMessagesSize(&list);

    assert(total > 0);

    freeList(&list);

    printf("All tests passed!\n");

    return 0;
}

