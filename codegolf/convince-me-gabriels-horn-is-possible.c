/*

From Wikipedia, Gabriel's Horn is a particular geometric figure that has infinite surface area but finite volume. I discovered this definition in this Vsauce's video (starting at 0:22) where I took the inspiration for this problem.

You begin with a cake (a cuboid) of dimension x×y×z. In your first slice of the cake, you will end up with two smaller cakes of dimension x2×y×z.
Next, you will slice only one of the two pieces of cake you sliced previously, and so on. The picture below illustrates this:

https://i.stack.imgur.com/5yl7W.png

Task
I cannot believe that the surface area can grow infinitely even if the volume of the cake stays the same and your task is to prove me that!
However, I trust you and if you show me that the first 10 slices of the cake that the surface area is really growing, I will believe you.

You will receive the initial x×y×z dimension of the cake as input and will output a list of 10 values referring to the total surface area of all cuboids after each consecutive slice.

Specs
The cake will always be sliced in half and it will always be sliced in the same dimension.
The surface area S of a cuboid of dimension x×y×z is: S=2xy+2xz+2yz
The outputted list should first start with the surface area after no slices (that is, the cuboid original surface area), then 1 slice and so on.
The slices are going to be done in the x dimension and the test cases below will assume this.
The surface area you have to calculate includes all pieces of cake sliced in previous iterations.
Input is flexible, read it however you see fit for you.
Standard loopholes are not allowed.
This is code-golf, so the shortest code in bytes wins
Test Cases

Format:
x, y, z --> output

1, 1, 1 --> [6, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0, 20.0, 22.0, 24.0]
1, 2, 3 --> [22, 34.0, 46.0, 58.0, 70.0, 82.0, 94.0, 106.0, 118.0, 130.0]
3, 2, 1 --> [22, 26.0, 30.0, 34.0, 38.0, 42.0, 46.0, 50.0, 54.0, 58.0]
7, 11, 17 --> [766, 1140.0, 1514.0, 1888.0, 2262.0, 2636.0, 3010.0, 3384.0, 3758.0, 4132.0]
111, 43, 20 --> [15706, 17426.0, 19146.0, 20866.0, 22586.0, 24306.0, 26026.0, 27746.0, 29466.0, 31186.0]
1.3, 5.7, 21.2 --> [311.62, 553.3, 794.98, 1036.6599999999999, 1278.3400000000001, 1520.02, 1761.6999999999998, 2003.38, 2245.06, 2486.74]

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dump(double *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%f ", a[i]);
	printf("\n");
}

void
gen(double x, double y, double z, double r[10])
{
	int i;

	for (i = 0; i < 10; i++)
		r[i] = 2 * ((x * y) + (x * z) + ((i + 1) * y * z));
}

void
test(double x, double y, double z, double r[10])
{
	static const double eps = 1e-8;
	double v[10];
	size_t i;

	gen(x, y, z, v);
	dump(v, nelem(v));
	for (i = 0; i < nelem(v); i++)
		assert(fabs(v[i] - r[i]) < eps);
}

int
main(void)
{
	double r1[] = {6, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0, 20.0, 22.0, 24.0};
	double r2[] = {22, 34.0, 46.0, 58.0, 70.0, 82.0, 94.0, 106.0, 118.0, 130.0};
	double r3[] = {22, 26.0, 30.0, 34.0, 38.0, 42.0, 46.0, 50.0, 54.0, 58.0};
	double r4[] = {766, 1140.0, 1514.0, 1888.0, 2262.0, 2636.0, 3010.0, 3384.0, 3758.0, 4132.0};
	double r5[] = {15706, 17426.0, 19146.0, 20866.0, 22586.0, 24306.0, 26026.0, 27746.0, 29466.0, 31186.0};
	double r6[] = {311.62, 553.3, 794.98, 1036.6599999999999, 1278.3400000000001, 1520.02, 1761.6999999999998, 2003.38, 2245.06, 2486.74};

	test(1, 1, 1, r1);
	test(1, 2, 3, r2);
	test(3, 2, 1, r3);
	test(7, 11, 17, r4);
	test(111, 43, 20, r5);
	test(1.3, 5.7, 21.2, r6);

	return 0;
}
