// ============================================================
// ACTIVITY 1: SIMULATING ENCAPSULATION IN C
// Learning Outcome: Apply encapsulation using structs and functions
// ============================================================

#include <stdio.h>  // For printf
#include <string.h> // For strcpy

// In C, structs hold data but cannot contain functions (methods).
struct Student {
	char name[50];
	int age; // Use the setter to validate changes to this field.
};

// Safely modify the age inside the struct.
void setAge(struct Student *s, int newAge) {
	if (newAge > 0 && newAge < 120) {
		s->age = newAge;
	} else {
		printf("Error: Invalid age! Age must be between 1 and 119.\n");
		s->age = 0; // Set to the default if invalid.
	}
}

// Safely read the age.
int getAge(const struct Student *s) {
	return s->age;
}

int main(void) {
	struct Student s1;

	strcpy(s1.name, "Alice");
	setAge(&s1, 20);

	printf("Student Name: %s\n", s1.name);
	printf("Student Age: %d\n", getAge(&s1));

	printf("\nAttempting to change age to -5...\n");
	setAge(&s1, -5);
	printf("Age after invalid attempt: %d\n", getAge(&s1));

	// C struct members are public, so encapsulation depends on following
	// the convention of accessing age through setAge and getAge.
	return 0;
}
