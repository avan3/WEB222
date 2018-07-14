/*
Name:      Andrew Van
Student#:  141267179
Section:   QQ
*/

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#include <stdio.h>
int main(void){ 
   double amtPaid;
   double gst;
   int intBalance; //Placeholder for converting amtPaid to integer for modulus usage
   int loonies;
   int quarters;
   int dimes;
   int nickels;
   int pennies;
   
   //Get user input 
   printf("Please enter the amount to be paid: $"); //user inputs 8.68
   scanf("%lf", &amtPaid);

   //Calculation of GST and display total amount + GST
   gst = amtPaid*.13+0.005;
   printf("GST: %.2lf\n", gst);
   amtPaid = amtPaid + gst; //amtPaid = 9.81
   printf("Balance owing: $%.2lf\n", amtPaid);

   //Calculating loonies required and subtract from amount to be paid
   loonies = amtPaid; //9 loonies
   amtPaid = amtPaid - loonies; //amtPaid = 0.81
   printf("Loonies required: %d, balance owing $%.2lf\n", loonies, amtPaid);

   //Converting amtPaid to an integer value by multiplying it by 100 (i.e. 0.81*100 = 81)
   intBalance = (int)(amtPaid * 100);

   //Calculating quarters required and take remainder --> Balance owing
   quarters = intBalance / 25; //Determining how many quarters is required in 81 --> 81/25 = 3.24 --> int quarters = 3
   intBalance =  intBalance % 25; //intBalance = 81. Take remainder of 81/25 = 6
   printf("Quarters required: %d, balance owing $%1.2f\n", quarters, (float)intBalance/100); //convert intBalance back into float = 6.00 and divide by 100 to get balance owing = $0.06

   //Calculating dimes required and take remainder --> Balance owing
   dimes = intBalance / 10; //intBalance = 6 --> 6/10 = int dimes = 0
   intBalance = intBalance % 10; //intBalance = 6. Take remainder of 6/10 = 6   
   printf("Dimes required: %d, balance owing $%1.2f\n", dimes, (float)intBalance / 100);

   //Calculating nickels required and take remainder --> Balance owing
   nickels = intBalance / 5; //intBalance = 6 --> 6/5 = int nickels = 1
   intBalance = intBalance % 5; //intBalance = 6. Take remainder of 6/5 = 1
   printf("Nickels required: %d, balance owing $%1.2f\n", nickels, (float)intBalance / 100); //intBalance = 1 --> float --> /100 = 0.01

   //Calculating pennies required and take remainder --> Balance owing
   pennies = intBalance / 1; //intBalance = 1
   intBalance = intBalance % 1; //intBalance = 1. Take remainder of 1/1 = 0
   printf("Pennies required: %d, balance owing $%1.2f\n", pennies, (float)intBalance / 100); //intBalance = 0 --> float --> /100 = 0.00
   
   return 0;
}
