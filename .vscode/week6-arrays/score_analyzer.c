#include <stdio.h>

double calculateAverage(const int scores[], int size) {
	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += scores[i];
	}

	return (double)sum / size;
}

void displayAboveAverage(const int scores[], int size, double average) {
	int found = 0;

	printf("\nScores above average (%.2f):\n", average);
	for (int i = 0; i < size; i++) {
		if (scores[i] > average) {
			printf(" Score %d at position %d\n", scores[i], i + 1);
			found = 1;
		}
	}

	if (!found) {
		printf(" None\n");
	}
}

int main(void) {
	const int SIZE = 10;
	int scores[SIZE];

	printf("Enter %d student scores:\n", SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf("Score %d: ", i + 1);
		if (scanf("%d", &scores[i]) != 1) {
			fprintf(stderr, "Invalid score input.\n");
			return 1;
		}
	}

	double average = calculateAverage(scores, SIZE);

	printf("\n--- Results ---\n");
	printf("Average score: %.2f\n", average);
	displayAboveAverage(scores, SIZE, average);

	return 0;
}
