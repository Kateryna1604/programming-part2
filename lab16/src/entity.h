#ifndef ENTITY_H
#define ENTITY_H

#include <stdio.h>

typedef enum {
    UTF8,
    UTF16,
    CP1251
} Encoding;

typedef struct {
    char name[100];
    char email[100];
} Person;

typedef struct {
    int isDraft;

    char subject[200];
    char body[1000];

    Person sender;
    Person receiver;

    Encoding encoding;

    char type[20];
    float compression;

} Mail;

/* base methods */
/**
 * Build mail message
 */
char* buildMessage(Mail* m);
/**
 * Calculate mail size
 */
int calculateSize(Mail* m);

#endif
