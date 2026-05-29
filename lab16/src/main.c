#include "menu.h"
#include <stdio.h>

int main() {

    MailList list;
    initList(&list);

    runMenu(&list);

    freeList(&list);

    return 0;
}
