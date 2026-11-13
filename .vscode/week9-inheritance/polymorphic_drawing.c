#include <stdio.h>

/* Base struct with a drawing operation. */
struct Shape {
	void (*draw)(void);
};

/* Derived structs embed Shape as their first member. */
struct Circle {
	struct Shape base;
};

struct Rectangle {
	struct Shape base;
};

struct Triangle {
	struct Shape base;
};

static void drawCircle(void)
{
	printf("Drawing a Circle ◯\n");
}

static void drawRectangle(void)
{
	printf("Drawing a Rectangle ▭\n");
}

static void drawTriangle(void)
{
	printf("Drawing a Triangle △\n");
}

static void renderCanvas(struct Shape *shapePtr)
{
	if (shapePtr != NULL && shapePtr->draw != NULL) {
		shapePtr->draw();
	}
}

int main(void)
{
	struct Circle c1 = {{drawCircle}};
	struct Rectangle r1 = {{drawRectangle}};
	struct Triangle t1 = {{drawTriangle}};
	struct Circle c2 = {{drawCircle}};

	struct Shape *canvas[] = {
		(struct Shape *)&c1,
		(struct Shape *)&r1,
		(struct Shape *)&t1,
		(struct Shape *)&c2
	};

	printf("--- Rendering Canvas ---\n");
	for (size_t i = 0; i < sizeof canvas / sizeof canvas[0]; ++i) {
		renderCanvas(canvas[i]);
	}

	return 0;
}
