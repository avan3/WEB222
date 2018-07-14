#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
   int i, j = 11;
   char option;
   char q[14][22] = { "first name", "middle initial(s)", "last name", "street number", "street name", "apartment number", "postal code", "city", "cell phone number", "home phone number", "business phone number", "Name Details", "Address Details", "Phone Numbers:" };
   char det[11][22]; //Setting a 2D array for user input

   printf("Contact Management System\n-------------------------\n");
   for (i=0; i < 11; i++) { 
      printf("Please enter the contact's %s: ", q[i]); //Accept user input for all of the questions 
      scanf(" %40[^\n]s", &det[i]);
      if (i == 0 || i == 4 || i >= 7 && i < 10) { //Accept user input for option for middle initial(s), apartment number, cell/home/business phone number
         printf("Do you want to enter a %s? (y or n): ", q[i+1]);
         scanf(" %c", &option); //No validation, if user enters n or N, program breaks
      }
   }
   printf("\nContact Details\n---------------"); //Print out Contact Details
   for (i = 0; i < 11; i++) {
      if (i == 0 || i == 3 || i == 8) {
         printf("\n%s\n", q[j]);
         j++;
      }
      q[i][0] = toupper(q[i][0]); //Takes first character of each "string" and converts it to upper-case
      printf("%s: %s\n", q[i], det[i]); //Print all of the details
   }
   printf("\nStructure test for Name, Address, and Numbers Done!\n");
   return 0;
}