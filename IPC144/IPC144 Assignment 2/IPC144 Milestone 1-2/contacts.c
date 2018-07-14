/* -------------------------------------------
Name: Andrew Van
Student number: 141267179
Email: avan3@myseneca.ca
Section: QQ
Date: April 6, 2018
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function definitions below...            |
// +-------------------------------------------------+

// getName:
void getName(struct Name* name) {
   int option;
   char newline;
   printf("Please enter the contact's first name: ");
   scanf("%s", &name->firstName);
   printf("Do you want to enter a middle initial(s)? (y or n): ");
   option = yes();
   if (option == 1) {
      printf("Please enter the contact's middle initial(s): ");
      scanf("%s", &name->middleInitial);
   }
   printf("Please enter the contact's last name: ");
   scanf("%s", &name->lastName);
}

// getAddress:
void getAddress(struct Address* address) {
   char option;

   printf("Please enter the contact's street number: ");
   address->streetNumber = getInt();
   printf("Please enter the contact's street name: ");
   scanf("%[^\n]", &address->street);
   printf("Do you want to enter an apartment number? (y or n): ");
   option = yes();
   if (option == 1) {
      printf("Please enter the contact's apartment number: ");
      address->apartmentNumber = getInt();
   }
   printf("Please enter the contact's postal code: ");
   scanf(" %[^\n]", &address->postalCode);
   printf("Please enter the contact's city: ");
   scanf("%s", &address->city);
}

// getNumbers:
void getNumbers(struct Numbers* numbers) {
   char option;

   printf("Please enter the contact's cell phone number: ");
   scanf("%s", &numbers->cell);
   printf("Do you want to enter a home phone number? (y or n): ");
   option = yes();
   if (option == 1) {
      printf("Please enter the contact's home phone number: ");
      scanf("%s", &numbers->home);
   }
   printf("Do you want to enter a business phone number? (y or n): ");
   option = yes();
   if (option == 1) {
      printf("Please enter the contact's business phone number: ");
      scanf("%s", &numbers->business);
   }
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contact) {
   getName(&contact->name);
   getAddress(&contact->address);
   getNumbers(&contact->numbers);   
}