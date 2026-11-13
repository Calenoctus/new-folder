#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================================================
// ACTIVITY 2: STACK VS HEAP STRUCTS IN C
// Learning Outcome: Analyse stack vs heap allocation
// ============================================================

struct Car {
	char model[20];
};

// Function to simulate a constructor.
void initCar(struct Car *car, const char *modelName) {
	snprintf(car->model, sizeof(car->model), "%s", modelName);
	printf("Car created: %s\n", car->model);
}

// Function to simulate a destructor (cleanup).
void destroyCar(const struct Car *car) {
	printf("Car destroyed: %s\n", car->model);
}

int main(void) {
	printf("--- Creating Stack Object ---\n");
	// Stack allocation: memory is managed automatically.
	struct Car stackCar;
	initCar(&stackCar, "Toyota");

	printf("\n--- Creating Heap Object ---\n");
	// Heap allocation: allocate memory dynamically.
	struct Car *heapCar = malloc(sizeof(*heapCar));

	if (heapCar == NULL) {
		fprintf(stderr, "Could not allocate memory for heapCar.\n");
		return EXIT_FAILURE;
	}

	initCar(heapCar, "Honda");
	printf("Heap car model: %s\n", heapCar->model);

	printf("\n--- End of main function ---\n");

	// Heap memory must be released manually.
	destroyCar(heapCar);
	free(heapCar);
	heapCar = NULL;

	// stackCar is released automatically when main returns.
	return EXIT_SUCCESS;
}
