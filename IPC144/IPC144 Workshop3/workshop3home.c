// Name: Andrew Van
// Student Number: 141267179
// Email: avan3@myseneca.ca
// Section: QQ
// Workshop: 3

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#define NUMS 4
#include <stdio.h>

int main(void) {
	float mean;
	int high;
	int low;
	int i;
	int max = -41;
	int min = 41;
	int daymax = 0;
	int daymin = 0;
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
			if (max < high) {
				max = high;
				daymax = i;
			}
			if (min > low) {
				min = low;
				daymin = i;
			}
		} while (high > 40 || low < -40 || high < low);
	}
	printf("The average (mean) temperature was: %.2f\n", mean);
	printf("The highest temperature was %d, on day %d\n", max, daymax);
	printf("The lowest temperature was %d, on day %d\n", min, daymin);
   return 0;
}