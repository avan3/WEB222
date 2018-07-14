#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 11

struct info {
   char q[14][22]; //Allocating space for strings during initialization
   char det[MAX][22]; //Setting a two dimensional array for user input of 22 character string
};

void display(struct info newInfo); //Passing through structure with user input into display function
struct info question(struct info details); //Question function with return type struct info for user input

int main(void) {
   struct info newInfo; //Create new structure to save user input
   struct info details = { { "first name", "middle initial(s)", "last name", "street number", "street name", "apartment number", "postal code", "city", "cell phone number", "home phone number", "business phone number", "Name Details", "Address Details", "Phone Numbers:" }, "" };
   newInfo = question(details); //Save user input from question function 
   display(newInfo); //Use new structure for display function
   return 0;
}

void display(struct info newInfo) { //Passing through structure with user input into display function
   int i, j=11;
   //Print out Contact Details
   printf("\nContact Details\n");
   printf("---------------");
   for (i = 0; i < MAX; i++) {
      if (i == 0 || i == 3 || i == 8) {
         printf("\n%s\n", newInfo.q[j]);
         j++;
      }
      newInfo.q[i][0] = toupper(newInfo.q[i][0]); //Takes first character of each "string" and converts it to upper-case
      printf("%s: %s\n", newInfo.q[i], newInfo.det[i]); //Print all of the details
   }
   printf("\nTwo Dimensional Array, Structure, Function and Loop test for Name, Address, and Numbers Done!\n");
}

struct info question(struct info details) {
   int i = 0;
   char option;
   printf("Contact Management System\n");
   printf("-------------------------\n");
   //Accept user input for all of the questions 
   do {
      printf("Please enter the contact's %s: ", details.q[i]);
      scanf(" %40[^\n]s", &details.det[i]);
      i++;
      while (i == 1 || i == 5 || i >= 8 && i < MAX) {
         printf("Do you want to enter a %s? (y or n): ", details.q[i]);
         scanf(" %c", &option);
         if (option == 'y' || option == 'Y') {
            break;
         }
         else if (option == 'n' || option == 'N') {
            i++; //Skip the input for this question if option is n or N
         }
      }
   } while (i < MAX);
   return details; //Return entire structure to the function
}