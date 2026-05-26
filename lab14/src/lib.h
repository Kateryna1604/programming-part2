#ifndef LIB_H
#define LIB_H

#include <stdio.h>

/**
 * @brief Supported text encodings
 */
typedef enum {
    UTF8,
    UTF16,
    CP1251
} Encoding;

/**
 * @brief Represents person (name + email)
 */
typedef struct {
    char name[100];
    char email[100];
} Person;

/**
 * @brief Email message structure
 *
 * Contains sender, receiver, message body,
 * encoding, type and compression info.
 */
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

/* IO */
/**
 * @brief Reads mails from file
 */
Mail* readMails(const char* filename, int* size);
/**
 * @brief Writes mails to file
 */
void writeMails(const char* filename, Mail* arr, int size);
/**
 * @brief Prints mails to output stream
 */
void printMails(Mail* arr, int size, FILE* out);

/* base methods */

/**
 * @brief Builds formatted message from Mail
 */
char* buildMessage(Mail* m);
/**
 * @brief Calculates size of message
 */
int calculateSize(Mail* m);

/* collection methods (STRICT TASK) */
/**
 * @brief Finds messages by sender name
 */
Mail* findMessagesByUser(Mail* arr, int size, const char* userName, int* outSize);
/**
 * @brief Finds all secret messages
 */
Mail* findSecretMessages(Mail* arr, int size, int* outSize);
/**
 * @brief Calculates total size of all messages
 */
int totalMessagesSize(Mail* arr, int size);

/* sort */
/**
 * @brief Sorts mails by subject alphabetically
 */
void sortBySubject(Mail* arr, int size);

#endif
