#include <stdio.h>

int main(void) {
	/* Attempt to open a file that does not exist. */
	FILE *myFile = fopen("missing_file.txt", "r");

	/* Intentionally ignore the possibility that fopen returned NULL. */
	char data[100];

	printf("Attempting to read from missing file...\n");
	fscanf(myFile, "%99s", data);
	printf("Data read: %s\n", data);

	fclose(myFile);
	return 0;
}
