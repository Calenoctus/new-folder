#include <stdio.h>
#include <stdlib.h>

// Intentionally demonstrates a memory leak: the allocated block is not
// freed and becomes unreachable when this function returns.
void createLeak(void)
{
	int *ptr = malloc(sizeof *ptr);
	if (ptr == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}

	*ptr = 42;
	printf("Inside function. The value is: %d\n", *ptr);
	printf("Memory allocated at address: %p\n", (void *)ptr);

	// Deliberately omit free(ptr) to demonstrate the leak.
}

// Corrected version: release the allocated block before returning.
void fixLeak(void)
{
	int *ptr = malloc(sizeof *ptr);
	if (ptr == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}

	*ptr = 42;
	printf("Inside fixed function. Value: %d\n", *ptr);

	free(ptr);
	ptr = NULL;
	printf("Memory has been successfully freed.\n");
}

int main(void)
{
	printf("Calling function that demonstrates a leak...\n");
	createLeak();
	printf("Calling the corrected function...\n");
	fixLeak();
	return 0;
}
