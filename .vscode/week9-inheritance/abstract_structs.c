// ============================================================
// ACTIVITY 3: SIMULATING ABSTRACT CLASSES
// Learning Outcome: Evaluate pure virtual functions
// ============================================================

#include <stdio.h>

// Base struct: this function pointer represents an abstract method.
struct Shape {
	double (*calculateArea)(void *derivedShape);
};

// Derived structs
struct Square {
	struct Shape base;
	double side;
};

struct Circle {
	struct Shape base;
	double radius;
};

// Implementations of the area function
double squareArea(void *shapePtr) {
	struct Square *square = (struct Square *)shapePtr;
	return square->side * square->side;
}

double circleArea(void *shapePtr) {
	struct Circle *circle = (struct Circle *)shapePtr;
	return 3.14159 * circle->radius * circle->radius;
}

int main(void) {
	struct Square square;
	square.side = 5.0;
	square.base.calculateArea = squareArea;

	struct Circle circle;
	circle.radius = 3.0;
	circle.base.calculateArea = circleArea;

	printf("Area of Square: %.2f\n", square.base.calculateArea(&square));
	printf("Area of Circle: %.2f\n", circle.base.calculateArea(&circle));

	return 0;
}
