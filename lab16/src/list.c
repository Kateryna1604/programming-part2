#include "list.h"
#include <stdlib.h>
#include <string.h>

/* INIT */
void initList(MailList* list) {
    list->head = NULL;
    list->size = 0;
}

/* FREE */
void freeList(MailList* list) {
    Node* current = list->head;

    while (current) {
        Node* tmp = current;
        current = current->next;
        free(tmp);
    }

    list->head = NULL;
    list->size = 0;
}

/* ADD TO END */
void addMail(MailList* list, Mail mail) {

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = mail;
    newNode->next = NULL;

    if (!list->head) {
        list->head = newNode;
    } else {
        Node* cur = list->head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = newNode;
    }

    list->size++;
}

/* REMOVE BY INDEX */
void removeMail(MailList* list, int index) {

    if (!list->head || index < 0 || index >= list->size)
        return;

    Node* cur = list->head;

    if (index == 0) {
        list->head = cur->next;
        free(cur);
        list->size--;
        return;
    }

    Node* prev = NULL;

    for (int i = 0; i < index; i++) {
        prev = cur;
        cur = cur->next;
    }

    prev->next = cur->next;
    free(cur);

    list->size--;
}

/* PRINT */
void printList(MailList* list) {

    Node* cur = list->head;

    while (cur) {
        printf("Subject: %s\n", cur->data.subject);
        printf("Sender: %s\n", cur->data.sender.name);
        printf("Receiver: %s\n", cur->data.receiver.name);
        printf("Type: %s\n\n", cur->data.type);

        cur = cur->next;
    }
}

/* FIND BY USER */
MailList findMessagesByUser(MailList* list, const char* userName) {

    MailList result;
    initList(&result);

    Node* cur = list->head;

    while (cur) {

        if (strcmp(cur->data.sender.name, userName) == 0) {
            addMail(&result, cur->data);
        }

        cur = cur->next;
    }

    return result;
}

/* SECRET MESSAGES */
MailList findSecretMessages(MailList* list) {

    MailList result;
    initList(&result);

    Node* cur = list->head;

    while (cur) {

        if (strcmp(cur->data.type, "secret") == 0) {
            addMail(&result, cur->data);
        }

        cur = cur->next;
    }

    return result;
}

/* TOTAL SIZE */
int totalMessagesSize(MailList* list) {

    int total = 0;
    Node* cur = list->head;

    while (cur) {
        total += calculateSize(&cur->data);
        cur = cur->next;
    }

    return total;
}

/* SORT BY SUBJECT */
void sortBySubject(MailList* list) {

    if (!list->head) return;

    for (Node* i = list->head; i; i = i->next) {
        for (Node* j = i->next; j; j = j->next) {

            if (strcmp(i->data.subject, j->data.subject) > 0) {

                Mail tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}