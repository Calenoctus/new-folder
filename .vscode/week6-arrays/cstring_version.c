#include <stdio.h>
#include <string.h>

int main(void) {
	char name[50];

	printf("Enter your name: ");
	if (fgets(name, sizeof name, stdin) == NULL) {
		return 1;
	}

	name[strcspn(name, "\n")] = '\0';

	printf("Name: %s\n", name);
	printf("Length: %zu\n", strlen(name));
	printf("First character: %c\n", name[0]);

	char copy[50];
	strcpy(copy, name);
	printf("Copy: %s\n", copy);

	return 0;
}
