/*
Name:      Andrew Van
Student#:  141267179
Section:   QQ
*/

#define _CRT_SECURE_NO_WARNINGS
#define NUMS 3
#include <stdio.h>

int main(void) {
	float mean;
	int high;
	int low;
	int i;
	int totalhigh = 0;
	int totallow = 0;

	printf("---===IPC Temperature Analyzer===---\n");
	for (i = 1; i <= NUMS; i++) {
		do {
			printf("Enter the high value for day %d: ", i);
			scanf("%d", &high);
			printf("\n");
			printf("Enter the low value for day %d: ", i);
			scanf("%d", &low);
			printf("\n");
			if (high > 40 || low < -40 || high < low) {
				printf("Incorrect values, temperatures must be in the range of -40 to 40, high must be greater than low.\n");
				printf("\n");
			}
			else {
				totalhigh += high;
				totallow += low;
				mean = (totalhigh + totallow) / (float)(NUMS*2);
				
			}
		} while (high > 40 || low < -40 || high < low);
	}
	printf("The average (mean) temperature was: %.2f\n", mean);
}