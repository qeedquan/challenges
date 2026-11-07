/*

This is one of several challenges left for the community by Calvin's Hobbies.

The curve that an idealised hanging rope or chain makes is a catenary.

A chain forming a catenary
Image by Bin im Garten, via Wikimedia Commons. Used under the CC-By-SA 3.0 licence.

Write a program that will draw a catenary, as an image, in quadrant 1 of the plane given two points (x1,y1), (x2,y2), and the "rope length" L. L will be greater than the distance between the two points.

You must also draw axes on the left and bottom sides of the image (400x400 px min) for scale. Only draw the quadrant from x and y in range 0 to 100. (You may assume the points are in range.)

Dots, or something similiar, should be drawn at the (x1,y1), (x2,y2) endpoints to distinguish them. The curve should only be drawn in the space between these points.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <raylib.h>
#include <raymath.h>

/*

Ported from @Level River St solution

This has obviously been solved before, so the first thing I did was look what others have done.

The equation of a catenary centred at the origin is simply y=a*cosh(x/a).
It becomes slightly more complicated if it is not centred at the origin.

Various sources say that if the length and endpoints are known the value for a must be determined numerically.
There is an unspecified parameter h in the wikipedia article.
So I found another site and basically followed the method here: http://www.math.niu.edu/~rusin/known-math/99_incoming/catenary

*/

typedef struct {
	double r, s, u, v, l;
	double z;

	double R, S, U, V;
	double A, P, Q;
} Catenary;

double
sqr(double x)
{
	return x * x;
}

void
solve(Catenary *c)
{
	double r, s, u, v, l;
	double a, p, q, z;

	r = c->r * 8;
	s = c->s * 8;
	u = c->u * 8;
	v = c->v * 8;
	l = c->l * 8;

	z = 0;
	for (;;) {
		z += 1e-3;
		if (sinh(z) / z >= sqrt(sqr(l) - sqr(v - s)) / (u - r))
			break;
	}

	a = (u - r) / 2 / z;
	p = (r + u - a * log((l + v - s) / (l - v + s))) / 2;
	q = (v + s - l * cosh(z) / sinh(z)) / 2;

	c->R = r;
	c->S = s;
	c->U = u;
	c->V = v;

	c->A = a;
	c->P = p;
	c->Q = q;

	printf("SOLVER:\n");
	printf("U %f V %f\n", c->U, c->V);
	printf("R %f S %f\n", c->R, c->S);
	printf("A %f P %f Q %f\n", c->A, c->P, c->Q);
}

double
evaly(Catenary *c, double x)
{
	return (c->A * cosh((x - c->P) / c->A)) + c->Q;
}

void
plot(Catenary *c)
{
	double x, h;

	h = GetRenderHeight();
	DrawCircle(c->U, h - c->V, 8, WHITE);
	DrawCircle(c->R, h - c->S, 8, WHITE);
	for (x = c->R; x <= c->U; x += 1e-2) {
		DrawPixelV((Vector2){ x, h - evaly(c, x) }, WHITE);
	}
}

void
initrl()
{
	SetConfigFlags(FLAG_WINDOW_HIGHDPI);
	InitWindow(1200, 900, "Catenary");
	SetTargetFPS(60);
}

int
main(int argc, char *argv[])
{
	Catenary cat = {
		.r = 10,
		.s = 100,
		.u = 100,
		.v = 50,
		.l = 130,
	};

	if (argc >= 6) {
		cat.r = atof(argv[1]);
		cat.s = atof(argv[2]);
		cat.u = atof(argv[3]);
		cat.v = atof(argv[4]);
		cat.l = atof(argv[5]);
	}

	initrl();
	solve(&cat);
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		plot(&cat);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
