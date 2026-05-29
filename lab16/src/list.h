#ifndef LIST_H
#define LIST_H

#include "entity.h"

typedef struct Node {

    Mail data;
    struct Node* next;

} Node;

typedef struct {

    Node* head;
    int size;

} MailList;

/* init/free */
/**
 * Initialize linked list
 * @param list pointer to list
 */
void initList(MailList* list);
void freeList(MailList* list);

/* add/remove */
/**
 * Add mail to list
 */
void addMail(MailList* list, Mail mail);
/**
 * Remove mail by index
 */
void removeMail(MailList* list, int index);

/* file IO */
void readFromFile(
    MailList* list,
    const char* filename
);

void writeToFile(
    MailList* list,
    const char* filename
);

/* print */
void printList(MailList* list);

/* collection methods */
MailList findMessagesByUser(
    MailList* list,
    const char* userName
);

MailList findSecretMessages(
    MailList* list
);

int totalMessagesSize(
    MailList* list
);

/* sort */
void sortBySubject(MailList* list);

#endif
