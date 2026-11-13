// ============================================================
// ACTIVITY 1: SIMULATING INHERITANCE IN C
// Learning Outcome: Apply inheritance using struct embedding
// ============================================================

#include <stdio.h>
#include <string.h>

// BASE STRUCT (Parent)
struct Shape {
	char color[20];
};

// DERIVED STRUCT (Child)
struct Circle {
	// Keep the base struct first to simulate inheritance.
	struct Shape base;
	double radius;
};

int main(void) {
	struct Circle myCircle;

	// Initialize inherited and Circle-specific data.
	strcpy(myCircle.base.color, "Red");
	myCircle.radius = 5.0;

	// Display the information.
	printf("Circle Color (Inherited): %s\n", myCircle.base.color);
	printf("Circle Radius (Specific): %.2f\n", myCircle.radius);

	return 0;
}
