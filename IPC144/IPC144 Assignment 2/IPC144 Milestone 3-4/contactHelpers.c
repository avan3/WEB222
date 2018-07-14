/* -------------------------------------------
Name: Andrew Van
Student number: 141267179
Email: avan3@myseneca.ca
Section: QQ
Date: April 6, 2018     
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contactHelpers.h"
#include "contacts.h"
#include <string.h>

// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void) {
    while (getchar() != '\n')   ; // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void) {
   printf("(Press Enter to Continue)");
   clearKeyboard();
}

// getInt function definition goes here:
int getInt(void) {
   int value;
   char newline = 'x';
   scanf("%d%c", &value, &newline);
   while (newline != '\n') {
      clearKeyboard();
      printf("*** INVALID INTEGER *** <Please Enter an Integer>: ");
      scanf("%d%c", &value, &newline);
   }
   return value;
}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max) {
   int value;
   value = getInt();
   while (value < min || value > max) {
      printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
      value = getInt();
   }
   return value;
}

// yes function definition goes here:
int yes(void) {
   char ch;
   char newline = 'x';
   scanf(" %c%c", &ch, &newline);
   while ((ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N') || newline != '\n') {
      if (newline != '\n') {
         clearKeyboard();
      }
      printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
      scanf(" %c%c", &ch, &newline);
   }
   return (ch == 'y' || ch == 'Y');
}

// menu function definition goes here:
int menu(void) {
   int value;

   printf("Contact Management System\n");
   printf("-------------------------\n");
   printf("1. Display contacts\n");
   printf("2. Add a contact\n");
   printf("3. Update a contact\n");
   printf("4. Delete a contact\n");
   printf("5. Search contacts by cell phone number\n");
   printf("6. Sort contacts by cell phone number\n");
   printf("0. Exit\n");
   printf("\n");
   printf("Select an option:> ");
   value = getIntInRange(0,6);
   return value;
}

// ContactManagerSystem function definition goes here:
void ContactManagerSystem(void) {
   int option;
   int done = 0;
   struct Contact contacts[MAXCONTACTS] = { { { "Rick", {"\0"}, "Grimes" }, 
                                              { 11, "Trailer Park", 0, "A7A 2J2", "King City" }, 
                                              { "4161112222", "4162223333", "4163334444" } }, 
                                            {
                                                { "Maggie", "R.", "Greene" },
                                                { 55, "Hightop House", 0, "A9A 3K3", "Bolton"},
                                                { "9051112222", "9052223333", "9053334444" } },
                                            {
                                                { "Morgan", "A.", "Jones" },
                                                { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
                                                { "7051112222", "7052223333", "7053334444" } },
                                            {
                                                { "Sasha", {"\0"}, "Williams" },
                                                { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
                                                { "9052223333", "9052223333", "9054445555" } },
                                          };
   while (!done) {
      option = menu();
      printf("\n");
      switch (option) {
      case 1:
         displayContacts(contacts, MAXCONTACTS);
         pause();
         printf("\n");
         break;
      case 2:
         addContact(contacts, MAXCONTACTS);
         pause();
         printf("\n");
         break;
      case 3:
         updateContact(contacts, MAXCONTACTS);
         pause();
         printf("\n");
         break;
      case 4:
         deleteContact(contacts, MAXCONTACTS);
         pause();
         printf("\n");
         break;
      case 5:
         searchContacts(contacts, MAXCONTACTS);
         pause();
         printf("\n");
         break;
      case 6:
         sortContacts(contacts, MAXCONTACTS);
         pause();
         printf("\n");
         break;
      default:
         printf("Exit the program? (Y)es/(N)o: ");
         if (yes() == 1) {
            printf("\nContact Management System: terminated");
            done = 1;
         }
         printf("\n");
      }
   }
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10 chars entered)
void getTenDigitPhone(char telNum[])
{
   int needInput = 1;

   while (needInput == 1) {
      scanf("%10s", telNum);
      clearKeyboard();

      // (String Length Function: validate entry of 10 characters)
      if (strlen(telNum) == 10)
         needInput = 0;
      else
         printf("Enter a 10-digit phone number: ");
   }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]) {
   int i;
   int found = -1;
   
   for (i = 0; found == -1 && i < size; i++) {
      if (strcmp(contacts->numbers.cell, cellNum) == 0) {
         found = i;
      }
      else {
         contacts++;
      }
   }
   return found;
}

// displayContactHeader
void displayContactHeader(void) {
   printf("+-----------------------------------------------------------------------------+\n");
   printf("|                              Contacts Listing                               |\n");
   printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int num) {
   printf("+-----------------------------------------------------------------------------+\n");
   printf("Total contacts: %d\n", num);
   printf("\n");
}

// displayContact:
void displayContact(const struct Contact* contact) {
   printf(" %s", contact->name.firstName);
   if (*contact->name.middleInitial == 0) {
      printf(" ");
   }
   else {
      printf(" %s ", contact->name.middleInitial);
   }
   printf("%s\n", contact->name.lastName);
   printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
   printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
   if (contact->address.apartmentNumber) {
      printf("Apt# %d, ", contact->address.apartmentNumber);
   }
   printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size) {
   int i;
   int count=0;

   displayContactHeader();
   for (i = 0; i < size; i++) {
      if (strlen(contacts[i].name.firstName) != 0) {
         displayContact(&contacts[i]);
         count++;
      }
   }
   displayContactFooter(count);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size) {
   int position;
   char number[11];

   printf("Enter the cell number for the contact: ");
   getTenDigitPhone(number);
   position = findContactIndex(contacts, size, number);
   if (position != -1) {
      printf("\n");
      displayContact(&contacts[position]);
      printf("\n");
   }
   else {
      printf("*** Contact NOT FOUND ***\n");
   }
}

// addContact:
void addContact(struct Contact contacts[], int size) {
   int i;

   for (i = 0; i < size; i++) {
      if (strlen(contacts[i].name.firstName) == 0) {
         getContact(&contacts[i]);
         printf("--- New contact added! ---\n");
         break;
      }
      else if (i == size - 1) {
         printf("*** ERROR: The contact list is full! ***\n");
         break;
      }
   }
}

// updateContact:
void updateContact(struct Contact contacts[], int size) {
   int position;
   char number[11];
   char option;

   printf("Enter the cell number for the contact: ");
   getTenDigitPhone(number);
   position = findContactIndex(contacts, size, number);
   if (position != -1) {
      printf("\nContact found:\n");
      displayContact(&contacts[position]);
      printf("\n");
      printf("Do you want to update the name? (y or n): ");
      option = yes();
      if (option == 1) {
         getName(&contacts[position].name);
      }
      printf("Do you want to update the address? (y or n): ");
      option = yes();
      if (option == 1) {
         getAddress(&contacts[position].address);
      }
      printf("Do you want to update the numbers? (y or n): ");
      option = yes();
      if (option == 1) {
         getNumbers(&contacts[position].numbers);
      }
      printf("--- Contact Updated! ---\n");
   }
   else {
      printf("*** Contact NOT FOUND ***\n");
   }
}

// deleteContact:
void deleteContact(struct Contact contacts[], int size) {
   struct Contact temp = {{ "\0" }};
   int position;
   char number[11];
   char option;

   printf("Enter the cell number for the contact: ");
   getTenDigitPhone(number);
   position = findContactIndex(contacts, size, number);
   if (position != -1) {
      printf("\nContact found:\n");
      displayContact(&contacts[position]);
      printf("\n");
      printf("CONFIRM: Delete this contact? (y or n): ");
      option = yes();
      if (option == 1) {
         contacts[position] = temp;
         printf("--- Contact deleted! ---\n");
      }
   }
   else {
      printf("*** Contact NOT FOUND ***\n");
   }
}

// sortContacts:
void sortContacts(struct Contact contacts[], int size) {
   struct Contact temp;
   int i;
   int j;

   //Bubble Sort:
   for (i = size - 1; i > 0; i--) { 
      for (j = 0; j < size; j++) {
         if (strcmp(contacts[j].numbers.cell, contacts[j+1].numbers.cell) > 0) {
            temp = contacts[j];
            contacts[j] = contacts[j+1];
            contacts[j+1] = temp;
         }  
      }
   }
   printf("--- Contacts sorted! ---\n");
}