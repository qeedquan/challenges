/*

Although shapes can be very different by nature, they can be sorted by the size of their area.

Task:

Create different shapes that can be part of a sortable list. The sort order is based on the size of their respective areas:
The area of a Square is the square of its side
The area of a Rectangle is width multiplied by height
The area of a Triangle is base multiplied by height divided by 2
The area of a Circle is the square of its radius multiplied by π
The area of a CustomShape is given

The default sort order of a list of shapes is ascending on area size:
var side = 1.1234D;
var radius = 1.1234D;
var base = 5D;
var height = 2D;

var shapes = new List<Shape>{ new Square(side),
                            new Circle(radius),
                            new Triangle(base, height) };
shapes.Sort();
Use the correct π constant for your circle area calculations:
System.Math.PI

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int type;
	union {
		struct {
			double side;
		};
		struct {
			union {
				double width;
				double base;
			};
			double height;
		};
		struct {
			double radius;
		};
		struct {
			double area;
		};
	};
} Shape;

enum {
	SQUARE = 0,
	CIRCLE,
	TRIANGLE,
	CUSTOM_SHAPE,
};

double
getarea(const Shape *shape)
{
	double area;

	area = 0;
	switch (shape->type) {
	case SQUARE:
		area = shape->side * shape->side;
		break;
	case CIRCLE:
		area = shape->radius * shape->radius * M_PI;
		break;
	case TRIANGLE:
		area = shape->base * shape->height * 0.5;
		break;
	case CUSTOM_SHAPE:
		area = shape->area;
		break;
	}
	return area;
}

int
compare(const void *shape1, const void *shape2)
{
	double area1, area2;

	area1 = getarea(shape1);
	area2 = getarea(shape2);
	if (area1 < area2)
		return -1;
	if (area1 > area2)
		return 1;
	return 0;
}

int
main()
{
	double side = 1.1234;
	double radius = 1.1234;
	double base = 5;
	double height = 2;

	Shape shapes[] = {
		{ .type = SQUARE, .side = side },
		{ .type = CIRCLE, .radius = radius },
		{ .type = TRIANGLE, .base = base, .height = height },
	};

	Shape *shape;
	size_t index;

	qsort(shapes, nelem(shapes), sizeof(*shapes), compare);
	for (index = 0; index < nelem(shapes); index++) {
		shape = shapes + index;
		printf("Type: %d Area: %.3f\n", shape->type, getarea(shape));
	}

	return 0;
}
