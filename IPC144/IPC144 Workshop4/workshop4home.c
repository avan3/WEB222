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
   double mean;
   int day;
   int meanday;
   int high[10];
   int low[10];
   int max;
   int min;
   int daymax;
   int daymin;
   int totalhigh;
   int totallow;
   int i;

   printf("---=== IPC Temperature Calculator V2.0 ===---\n");
   //Accept user input for #days
   printf("Please enter the number of days, between 3 and 10, inclusive: ");
   scanf("%d", &day);
   //Error message if user input is wrong
   while (day < 3 || day > 10) {
      printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
      scanf("%d", &day);
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
   printf("Day Hi Low\n");
   for (i = 0; i < day; i++) {
      printf("%2d %3d %3d\n", i + 1, high[i], low[i]);
   }
   printf("\n");

   //Calculate the max and min temperature and day it occured
   max = high[0];
   min = low[0];
   for (i = 0; i < day; i++) {
      if (max <= high[i]) {
         max = high[i];
         daymax = i + 1; //i is one less than the day you want to display so i+1
      }
      if (min >= low[i]) {
         min = low[i];
         daymin = i + 1; //i is one less than the day you want to display so i+1
      }
   }
   printf("The highest temperature was %d, on day %d\n", max, daymax);
   printf("The lowest temperature was %d, on day %d\n", min, daymin);
   printf("\n");

   //Accept user input for calculating mean for days
   do {
      printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", day);
      scanf("%d", &meanday);
      printf("\n");
      //Repeat loop if meanday is greater than max #days or 0. 
      //Skip if meanday above 0 to equal to day. Skip if meanday is negative
      while (meanday > day || meanday == 0) {
         printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", day);
         scanf("%d", &meanday);
         printf("\n");
      }
      //Calculate the mean if user input is positive
      if (meanday > 0) {
         totalhigh = 0;
         totallow = 0;
         for (i = 0; i < meanday; i++) {
            totalhigh += high[i];
            totallow += low[i];
            mean = (double)(totalhigh + totallow) / (meanday * 2);
         }
         //Display average temperature over user input day period
         printf("The average temperature up to day %d is: %.2lf\n", meanday, mean);
         printf("\n");
      }
   } while (meanday <= day && meanday > 0); //Loop until negative is entered. Any value less than to equal to day will repeat the first printf

   //If user input is negative then display Goodbye
   printf("Goodbye!\n");

   return 0;
}