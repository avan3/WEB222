/*
Name: Andrew Van
Student number: 141267179
Email: avan3@myseneca.ca
Workshop: 5
Section: QQ
Date: 16/02/2018
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define SIZE 4

struct employee {
   int id;
   int age;
   double salary;
};

void flushKeyboard(void) {
   char newline = 'x';
   while (newline != '\n') {
      scanf("%c", &newline);
   }
}
int getInt(void) {
   int value;
   char newline = 'x';
   scanf("%d%c", &value, &newline);
   while (newline != '\n') {
      flushKeyboard();
      printf("\n");
      printf("ERROR!!! Please Enter an Integer: ");
      scanf("%d%c", &value, &newline);
   }
   return value;
}

/* main program */
int main(void) {

   int option;
   int nEmp = 0;
   int i;
   int position;
   int empId;
   int found;

   printf("---=== EMPLOYEE DATA ===---\n");

   struct employee emp[SIZE] = { 0 };

   do {
      printf("\n");
      // Print the option list
      printf("1. Display Employee Information\n");
      printf("2. Add Employee\n");
      printf("3. Update Employee Salary\n");
      printf("4. Remove Employee\n");
      printf("0. Exit\n\n");
      printf("Please select from the above options: ");

      // Capture input to option variable
      option = getInt();
      printf("\n");

      switch (option) {
      case 0:	// Exit the program
         printf("Exiting Employee Data Program. Good Bye!!!\n");
         break;
      case 1: // Display Employee Data

         printf("EMP ID  EMP AGE EMP SALARY\n");
         printf("======  ======= ==========\n");

         for (i = 0; i < nEmp; i++) {
            if (emp[i].id > 0 && emp[i].age > 0) {
               printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
            }
         }
         break;

      case 2:	// Adding Employee
         printf("Adding Employee\n");
         printf("===============\n");

         if (nEmp >= SIZE) {
            printf("ERROR!!! Maximum Number of Employees Reached\n");
         }
         //Allow user to input employee info if # max employees not reached
         else {
            do {
               found = 0;
               printf("Enter Employee ID: ");
               emp[nEmp].id = getInt();
               //Ensures employee ID is not 0 or negative number
               if (emp[nEmp].id < 1) {
                  printf("ERROR!!! Employee ID cannot be lower than 1!\n");
                  printf("\n");
               }
               //Ensures employee ID is unique
               for (i = 0; i < SIZE; i++) {
                  if (emp[nEmp].id == emp[i].id && nEmp != i && emp[nEmp].id != 0) { //User input = an ID in the array, but not at the same position and not 0, due to the initialization
                     found = 1;
                     printf("ERROR!!! Employee ID must be unique!\n");
                     printf("\n");
                  }
               }
            } while (emp[nEmp].id < 1 || found == 1); //Loop until conditions are met

            do {
               printf("Enter Employee Age: ");
               emp[nEmp].age = getInt();
               //Ensures employee age is not 0 or negative number
               if (emp[nEmp].age < 1) {
                  printf("ERROR!!! Employee Age cannot be lower than 1!\n");
                  printf("\n");
               }
            } while (emp[nEmp].age < 1);

            printf("Enter Employee Salary: ");
            scanf("%lf", &emp[nEmp].salary);

            nEmp += 1; //Counter for number of employees. Add one every time user wants to add employee info
         }
         break;

      case 3: // Update Salary
         printf("Update Employee Salary\n");
         printf("======================\n");

         do {
            found = 0;
            //Accept user input for employee ID
            printf("Enter Employee ID: ");
            empId = getInt();
            //Loop through array to find an employee ID that matches with user input 
            for (i = 0; i < SIZE; i++) {
               if (empId == emp[i].id && emp[i].id != 0) {
                  found = 1; //Change from false to true if employee ID matches
                  position = i; //Add flag to keep track of which employee ID matched
               }
            }
            //Accept user input for new salary if employee ID matches and change salary
            if (found == 1) {
               printf("The current salary is %.2lf\n", emp[position].salary);
               printf("Enter Employee New Salary: ");
               scanf("%lf", &emp[position].salary);
            }
            else {
               printf("\n");
               printf("ERROR!!! Employee ID not found!\n\n");
            }
         } while (found != 1); //Run until Employee ID matches 
         break;

      case 4: // Remove Employee
         printf("Remove Employee\n");
         printf("===============\n");

         do {
            found = 0;
            //Accept user input for employee ID
            printf("Enter Employee ID: ");
            empId = getInt();
            //Loop through array to find an employee ID that matches with user input 
            for (i = 0; i < SIZE; i++) {
               if (empId == emp[i].id && emp[i].id != 0) {
                  found = 1; //Change from false to true if employee ID matches
                  position = i; //Add flag to keep track of which employee ID matched
               }
            }
            //Removing employee by replacing the current position with next position
            if (found == 1) {
               printf("Employee %d will be removed\n", empId);
               for (i = position; i < nEmp; i++) { //Loop only as long as the current number of employees listed
                  emp[i] = emp[i + 1];
               }
               nEmp -= 1; //Decrease # of employee by 1 every time an employee is successfully removed
            }
            else {
               printf("\n");
               printf("ERROR!!! Employee ID not found!\n\n");
            }
         } while (found != 1); //Run until employee ID matches

         break;
      default:
         printf("ERROR: Incorrect Option: Try Again\n");
      }
   } while (option != 0);

   return 0;
}
