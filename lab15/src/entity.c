#include "entity.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* buildMessage(Mail* m) {
    char* result = malloc(2000);

    sprintf(result,
        "FROM: %s <%s>\nTO: %s <%s>\nSUBJECT: %s\n\n%s",
        m->sender.name,
        m->sender.email,
        m->receiver.name,
        m->receiver.email,
        m->subject,
        m->body
    );

    return result;
}

int calculateSize(Mail* m) {
    return strlen(m->subject) +
           strlen(m->body) +
           strlen(m->sender.name) +
           strlen(m->sender.email) +
           strlen(m->receiver.name) +
           strlen(m->receiver.email);
}
