#ifndef LIST_H
#define LIST_H

#include "entity.h"

typedef struct {
    Mail* data;
    int size;
    int capacity;
} MailList;

/* init/free */
/** 
 * Initialize dynamic list. 
 * @param list pointer to MailList 
 */
void initList(MailList* list);
void freeList(MailList* list);

/* add/remove */
/** 
 * Add new mail to list. 
 * @param list pointer to MailList 
 * @param mail mail object 
 */
void addMail(MailList* list, Mail mail);
/** 
 * Remove mail by index. 
 * @param list pointer to MailList 
 * @param index element index 
 */
void removeMail(MailList* list, int index);

/* print */
void printList(MailList* list, FILE* out);

/* collection methods */
MailList findMessagesByUser(MailList* list, const char* userName);
MailList findSecretMessages(MailList* list);
int totalMessagesSize(MailList* list);

/* sort */
void sortBySubject(MailList* list);

#endif

