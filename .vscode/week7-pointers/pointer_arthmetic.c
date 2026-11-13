// ============================================================
// ACTIVITY 1: POINTER ARITHMETIC (C VERSION)
// Learning Outcome: Apply pointer arithmetic to traverse an array
// ============================================================

// Include the standard input/output library for printf
#include <stdio.h>

// The main function - where the program starts
int main(void) {
	// Declare and initialise an array of 5 integers.
	// In C, arrays are contiguous blocks of memory.
	int numbers[5] = {10, 20, 30, 40, 50};

	// Declare a pointer named 'ptr' that points to the first element.
	int *ptr = numbers;

	// Display a header
	printf("Array elements accessed via pointer arithmetic:\n");

	// Loop 5 times to access each element
	for (int i = 0; i < 5; i++) {
		// Dereference ptr to get the value at its current address.
		printf("Value: %d\n", *ptr);

		// Move the pointer to the next integer in memory.
		ptr++;
	}

	// Reset the pointer back to the start of the array
	ptr = numbers;

	// Display a header
	printf("\nAccessing using offset arithmetic:\n");

	// Access each element using pointer offset arithmetic: (ptr + i).
	for (int i = 0; i < 5; i++) {
		printf("Index %d has value: %d\n", i, *(ptr + i));
	}

	// Return 0 to signal successful completion
	return 0;
}
