/* -------------------------------------------
Name: Andrew Van
Student number: 141267179
Email: avan3@myseneca.ca
Section: QQ
Date: March 9, 2018
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "contacts.h"

int main(void)
{
   // Declare variables here:
   struct Name fullName = { "" };
   struct Address addInfo = { 0, "", 0, "", "" };
   struct Numbers phInfo = { "", "", "" };
   char option;

   // Display the title

   printf("Contact Management System\n");
   printf("-------------------------\n");

   // Contact Name Input:
   printf("Please enter the contact's first name: ");
   scanf("%s", fullName.firstName);
   printf("Do you want to enter a middle initial(s)? (y or n): ");
   scanf(" %c", &option);
   if (option == 'y' || option == 'Y') {
      printf("Please enter the contact's middle initial(s): ");
      scanf("%s", fullName.middleInitial);
   }
   printf("Please enter the contact's last name: ");
   scanf("%s", fullName.lastName);

   // Contact Address Input:
   printf("Please enter the contact's street number: ");
   scanf("%d", &addInfo.streetNumber);
   printf("Please enter the contact's street name: ");
   scanf("%s", addInfo.street);
   printf("Do you want to enter a apartment number? (y or n): ");
   scanf(" %c", &option);
   if (option == 'y' || option == 'Y') {
      printf("Please enter the contact's apartment number: ");
      scanf("%d", &addInfo.apartmentNumber);
   }
   printf("Please enter the contact's postal code: ");
   scanf(" %[^\n]s", addInfo.postalCode);
   printf("Please enter the contact's city: ");
   scanf("%s", addInfo.city);
   
   // Contact Numbers Input:
   printf("Do you want to enter a cell number? (y or n): ");
   scanf(" %c", &option);
   if (option == 'y' || option == 'Y') {
      printf("Please enter the contact's cell phone number: ");
      scanf("%s", phInfo.cell);
   }
   printf("Do you want to enter a home phone number? (y or n): ");
   scanf(" %c", &option);
   if (option == 'y' || option == 'Y') {
      printf("Please enter the contact's home phone number: ");
      scanf("%s", phInfo.home);
   }
   printf("Do you want to enter a business phone number? (y or n): ");
   scanf(" %c", &option);
   if (option == 'y' || option == 'Y') {
      printf("Please enter the contact's business phone number: ");
      scanf("%s", phInfo.business);
   }
   printf("\n");

   // Display Contact Summary Details
   printf("Contact Details\n");
   printf("---------------\n");
   printf("Name Details\n");
   printf("First name: %s\n", fullName.firstName);
   printf("Middle initial(s): %s\n", fullName.middleInitial);
   printf("Last name: %s\n", fullName.lastName);
   printf("\n");

   printf("Address Details\n");
   printf("Street number: %d\n", addInfo.streetNumber);
   printf("Street name: %s\n", addInfo.street);
   printf("Apartment: %d\n", addInfo.apartmentNumber);
   printf("Postal code: %s\n", addInfo.postalCode);
   printf("City: %s\n", addInfo.city);
   printf("\n");

   printf("Phone numbers:\n");
   printf("Cell phone number: %s\n", phInfo.cell);
   printf("Home phone number: %s\n", phInfo.home);
   printf("Business phone number: %s\n", phInfo.business);
   printf("\n");

   // Display Completion Message

   printf("Structure test for Name, Address, and Numbers Done!\n");

   return 0;
}