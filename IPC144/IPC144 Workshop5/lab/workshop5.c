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
#define SIZE 2

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
      printf("ERROR!!! Please Enter an Integer: ");
      scanf("%d%c", &value, &newline);
   }
   return value;
}

/* main program */
int main(void) {

	int option = 0;
	int nEmp = 0;
	int i;
	printf("---=== EMPLOYEE DATA ===---\n");

	struct employee emp[SIZE] = { 0 };

	do {
      printf("\n");
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
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
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 

			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0

				for (i = 0; i < SIZE; i++) {
					if (emp[i].id > 0 && emp[i].age > 0) {
						printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
					}
			}
			break;

		case 2:	// Adding Employee
				// @IN-LAB
			printf("Adding Employee\n");
			printf("===============\n");
			// Check for limits on the array and add employee 
			// data accordingly. 

			if (nEmp >= SIZE) {
            printf("ERROR!!! Maximum Number of Employees Reached\n");
			}
			else {
            do {
               printf("Enter Employee ID: ");  
               emp[nEmp].id = getInt();
               if (emp[nEmp].id < 1) {
                  printf("ERROR!!! Employee ID cannot be lower than 1!\n");
               }
            } while (emp[nEmp].id < 1);
				
            do {
               printf("Enter Employee Age: ");
               emp[nEmp].age = getInt();
               if (emp[nEmp].age < 1) {
                  printf("ERROR!!! Employee Age cannot be lower than 1!\n");
               }
            } while (emp[nEmp].age < 1);
            printf("Enter Employee Salary: ");
            scanf("%lf", &emp[nEmp].salary);
            nEmp += 1;
			}
			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n");
		}

	} while (option != 0);

	return 0;
}