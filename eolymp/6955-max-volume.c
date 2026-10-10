/*

Write a program to find the maximum volume of given geometric 3-dimensional figures. Here, there are 3 types of figures: cone, cylinder and sphere.

https://static.e-olymp.com/content/a5/a5d51a15d6044f985bbb860b50b1b0f27a4f2859.jpg

The volume (V) of each figure can be calculated by the following formulas.

Cone: V=1/3πr^2h

Cylinder: V=πr^2h

Sphere: V=4/3πr^3

Use the value π=3.14159 in your calculation.

Input
The first line of the input contains a positive integer n (1≤n≤100) which is the number of figures.
The n following lines contain the description of each figure.
In case of a cone, the line begins with letter C and is followed by 2 values: r and h respectively.
If it is a cylinder, the line begins with letter L and is followed by r and h.
If it is a sphere, the line begins with letter S and is followed by only one value: r.

Output
Print out the maximum volume among the input figures with 3 decimal places.

Examples

Input #1
5
S 3.0
C 2.5 3
S 1.79
L 2.78 1.4
C 1.15 2.36

Answer #1
113.097

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
sphere(double r)
{
	return 4 * M_PI * r * r * r / 3;
}

double
cone(double r, double h)
{
	return M_PI * r * r * h / 3;
}

double
cylinder(double r, double h)
{
	return M_PI * r * r * h;
}

double
solve(const char **s, size_t n)
{
	double h, v, r;
	size_t i;

	v = 0;
	for (i = 0; i < n; i++) {
		if (sscanf(s[i], "S %lf", &r) == 1)
			v = fmax(v, sphere(r));
		else if (sscanf(s[i], "C %lf %lf", &r, &h) == 2)
			v = fmax(v, cone(r, h));
		else if (sscanf(s[i], "L %lf %lf", &r, &h) == 2)
			v = fmax(v, cylinder(r, h));
	}
	return v;
}

int
main()
{
	const char *s1[] = {
		"S 3.0",
		"C 2.5 3",
		"S 1.79",
		"L 2.78 1.4",
		"C 1.15 2.36",
	};

	printf("%.3f\n", solve(s1, nelem(s1)));

	return 0;
}
