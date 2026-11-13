#include <stdio.h>
#include <errno.h>
#include <string.h>

// Returns 0 on success and 1 if the file cannot be opened.
int readFileWithReturnCode(const char *filename) {
	FILE *file = fopen(filename, "r");

	if (file == NULL) {
		// Report the error on stderr, separate from normal output.
		fprintf(stderr, "Error opening file: %s\n", strerror(errno));
		return 1;
	}

	// ... read file ...

	fclose(file);
	return 0;
}

int main(void) {
	printf("--- Testing Return Code Strategy ---\n");

	// Check the return code (1 indicates failure).
	if (readFileWithReturnCode("data.txt") == 1) {
		printf("Main function: Handled error gracefully. Program continues.\n");
	}

	printf("\n--- Evaluation ---\n");
	printf("In C, we must manually check return codes.\n");
	printf("If the programmer forgets to check, the program might crash later.\n");

	return 0;
}
