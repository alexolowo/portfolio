//
// APS105 Lab 5
//
// Program for maintaining a personal phone book.
//
// Uses a linked list to hold the phone book entries.
//
// Author: <OLUWASINA OLOWOOKERE>
// Student Number: <1006648068>
//

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//**********************************************************************
// Linked List Definitions
//  Define your linked list node and pointer types
//  here for use throughout the file.
//
//   ADD STATEMENT(S) HERE
typedef struct node {
    char* familyName;
    char* firstName;
    char* address;
    char* phoneNumber;
    struct node* next;

} NODE;

//**********************************************************************
// Linked List Function Declarations
//
// Functions that modify the linked list.
//   Declare your linked list functions here.
//
//   ADD STATEMENT(S) HERE
NODE* createNode(char lName[], char fName[], char address[], char phoneNo[]);

NODE* sortListAlpha(NODE* head);

NODE* addToList(NODE* head, NODE* newEntry);

//**********************************************************************
// Support Function Declarations
//

void safegets(char s[], int arraySize);      // gets without buffer overflow
void familyNameDuplicate(char familyName[]); // marker/tester friendly
void familyNameFound(char familyName[]);     //   functions to print
void familyNameNotFound(char familyName[]);  //     messages to user
void familyNameDeleted(char familyName[]);
void phoneNumberFound(char phoneNumber[]);
void phoneNumberNotFound(char phoneNumber[]);
void printPhoneBookEmpty(void);
void printPhoneBookTitle(void);

//**********************************************************************
// Program-wide Constants
//

const int MAX_LENGTH = 1023;
const char NULL_CHAR = '\0';
const char NEWLINE = '\n';

//**********************************************************************
// Main Program
//

int main(void)
{
    const char bannerString[] = "Personal Phone Book Maintenance Program.\n\n";
    const char commandList[] = "Commands are I (insert), D (delete), S (search by name),\n"
                               "  R (reverse search by phone #), P (print), Q (quit).\n";

    // Declare linked list head.
    //   ADD STATEMENT(S) HERE TO DECLARE LINKED LIST HEAD.

    NODE* head = NULL;
    char lName[MAX_LENGTH], fName[MAX_LENGTH];
    char address[MAX_LENGTH];
    char phoneNo[MAX_LENGTH];
    // announce start of program
    printf("%s", bannerString);
    printf("%s", commandList);

    char response;
    char input[MAX_LENGTH + 1];
    do {
        printf("\nCommand?: ");
        safegets(input, MAX_LENGTH + 1);
        // Response is first char entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper(input[0]);

        if(response == 'I') {
            // Insert an phone book entry into the linked list.
            // Maintain the list in alphabetical order by family name.
            //   ADD STATEMENT(S) HERE
            // USE THE FOLLOWING PRINTF STATEMENTS WHEN PROMPTING FOR DATA:
            printf("  family name: ");
            safegets(lName, MAX_LENGTH);
            printf("  first name: ");
            safegets(fName, MAX_LENGTH);
            printf("  address: ");
            safegets(address, MAX_LENGTH);
            printf("  phone number: ");
            safegets(phoneNo, MAX_LENGTH);
            
            NODE* newEntry = createNode(lName, fName, address, phoneNo);
            head = addToList(head, newEntry);
            printf("%d %d\n", head, newEntry);

            printf("(%s) (%s) (%s) (%s)", head->familyName, head->firstName, head->address, head->phoneNumber);

        } else if(response == 'D') {
            // Delete an phone book entry from the list.

            printf("\nEnter family name for entry to delete: ");

            //   ADD STATEMENT(S) HERE

        } else if(response == 'S') {
            // Search for an phone book entry by family name.

            printf("\nEnter family name to search for: ");

            //   ADD STATEMENT(S) HERE

        } else if(response == 'R') {
            // Search for an phone book entry by phone number.

            printf("\nEnter phone number to search for: ");

            //   ADD STATEMENT(S) HERE

        } else if(response == 'P') {
            // Print the phone book.
            //   ADD STATEMENT(S) HERE
            //head = sortListAlpha(head);
            NODE* current = head;
            while(current != NULL) {
                printf("%s\n %s\n %s\n %s\n", current->familyName, current->firstName, current->address, current->phoneNumber);
                current = current->next;
            }

        } else if(response == 'Q') {
            ; // do nothing, we'll catch this below
        } else {
            // do this if no command matched ...
            printf("\nInvalid command.\n%s\n", commandList);
        }
    } while(response != 'Q');

    // Delete the whole phone book linked list.
    //   ADD STATEMENT(S) HERE

    // Print the linked list to confirm deletion.
    //   ADD STATEMENT(S) HERE

    return 0;
}

//**********************************************************************
// Support Function Definitions

// Function to get a line of input without overflowing target char array.
void safegets(char s[], int arraySize)
{
    int i = 0, maxIndex = arraySize - 1;
    char c;
    while(i < maxIndex && (c = getchar()) != NEWLINE) {
        s[i] = c;
        i = i + 1;
    }
    s[i] = NULL_CHAR;
}

// Function to call when user is trying to insert a family name
// that is already in the book.
void familyNameDuplicate(char familyName[])
{
    printf("\nAn entry for <%s> is already in the phone book!\n"
           "New entry not entered.\n",
        familyName);
}

// Function to call when a family name was found in the phone book.
void familyNameFound(char familyName[])
{
    printf("\nThe family name <%s> was found in the phone book.\n", familyName);
}

// Function to call when a family name was not found in the phone book.
void familyNameNotFound(char familyName[])
{
    printf("\nThe family name <%s> is not in the phone book.\n", familyName);
}

// Function to call when a family name that is to be deleted
// was found in the phone book.
void familyNameDeleted(char familyName[])
{
    printf("\nDeleting entry for family name <%s> from the phone book.\n", familyName);
}

// Function to call when a phone number was found in the phone book.
void phoneNumberFound(char phoneNumber[])
{
    printf("\nThe phone number <%s> was found in the phone book.\n", phoneNumber);
}

// Function to call when a phone number was not found in the phone book.
void phoneNumberNotFound(char phoneNumber[])
{
    printf("\nThe phone number <%s> is not in the phone book.\n", phoneNumber);
}

// Function to call when printing an empty phone book.
void printPhoneBookEmpty(void)
{
    printf("\nThe phone book is empty.\n");
}

// Function to call to print title when whole phone book being printed.
void printPhoneBookTitle(void)
{
    printf("\nMy Personal Phone Book: \n");
}

//**********************************************************************
// Add your functions below this line.
//   ADD STATEMENT(S) HERE

NODE* createNode(char lName[], char fName[], char addy[], char phoneNo[])
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));

    if(newNode != NULL) {
        newNode->familyName = strdup(lName);
        newNode->firstName = strdup(fName);
        newNode->address = strdup(addy);
        newNode->phoneNumber = strdup(phoneNo);
        newNode->next = NULL;
    }
    return newNode;
}

NODE* sortListAlpha(NODE* head)
{

    NODE* current = head;
    NODE* previous = NULL;
    while(current != NULL) {
        if(strcmp(current->familyName, current->next->familyName) > 0) {
            if(previous == NULL){
                head= head ->next;
                current->next = current->next->next;
                head->next = current;
            }else{
                previous->next = current->next;
                current->next = current->next->next;
                previous->next->next = current;
            }
            current = current->next;
        } else {
            previous = current;
            current = current->next;

        
        }
    }
                return head;
}

NODE* addToList(NODE* head, NODE* newEntry) {
    if (head != NULL)
        newEntry->next = head;
    return newEntry;
}