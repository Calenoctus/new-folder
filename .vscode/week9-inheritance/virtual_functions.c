// ============================================================
// ACTIVITY 2: SIMULATING VIRTUAL FUNCTIONS
// Learning Outcome: Analyse function pointers
// ============================================================

#include <stdio.h>

// Function pointer type: takes no arguments and returns void.
typedef void (*SpeakFunction)(void);

// Base struct
struct Animal {
	SpeakFunction speak;
};

// Derived struct embeds the base struct.
struct Dog {
	struct Animal base;
};

void genericSound(void) {
	printf("Animal makes a generic sound.\n");
}

void dogBark(void) {
	printf("Dog barks: Woof! Woof!\n");
}

int main(void) {
	printf("--- Simulating Non-Virtual (Base only) ---\n");
	struct Animal myAnimal;
	myAnimal.speak = genericSound;
	myAnimal.speak();

	printf("\n--- Simulating Virtual (Dynamic binding) ---\n");
	struct Dog myDog;
	myDog.base.speak = dogBark;

	// The embedded Animal is the first member, so its address matches
	// the address of myDog; speak dispatches to dogBark through the pointer.
	struct Animal *pet = (struct Animal *)&myDog;
	pet->speak();

	return 0;
}
