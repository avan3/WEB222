//--------------------------------------------------
// Name: Andrew Van      
// Student Number: 141267179
// Email: avan3@myseneca.ca 
// Section: QQ       
// Workshop: 4     
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

// Place your code below
#include <stdio.h>

int main(void) {
   int day;
   int high[10];
   int low[10];
   int i;

   printf("---=== IPC Temperature Calculator V2.0 ===---\n");
   //Accept user input for #days
   printf("Please enter the number of days, between 3 and 10, inclusive: ");
   scanf("%d", &day);
   printf("\n");
   //Error message if user input is wrong
   while (day < 3 || day > 10) {
      printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
      scanf("%d", &day);
      printf("\n");
   }

   //Accept user input for high/low temperature for #days
   for (i = 0; i < day; i++) {
      printf("Day %d - High: ", i + 1);
      scanf("%d", &high[i]);
      printf("Day %d - Low: ", i + 1);
      scanf("%d", &low[i]);
   }
   printf("\n");
   //Print days and temperatures in chart format
   printf("Day  Hi  Low\n");
   for (i = 0; i < day; i++) {
      printf("%d    %d    %d\n", i + 1, high[i], low[i]);
   }

   return 0;
}
