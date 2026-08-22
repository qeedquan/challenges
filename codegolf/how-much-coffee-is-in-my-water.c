/*

Sometimes I'll put coffee in my usual water bottle. Even after I drink it and put water in it, I can still slightly taste coffee, since there's a few drops left. After a few refills, it fades, but I still sometimes wonder what tiny proportion of my water is coffee. In this challenge, you'll take a sequence of operations (fill with water, fill with coffee, drink) and return the final proprtion of the bottle's contents which is coffee.

Spec
Your input will consist of a sequence of operations, which can be one of three types:

Add n milliliters of water to the bottle
Add n milliliters of coffee to the bottle
Drink n milliliters from the bottle (or as much as possible)
Assume the bottle is initially empty and can hold an arbitrary capacity of liquid, and that all liquids are perfectly mixed.
You may assume that n is a positive integer.

You may be given operations which attempt to drink more liquid than the bottle contains; in this case, the bottle is empty, as if the amount drank were equal to the amount of liquid in the bottle.

Your output should be the proportion, from 0 to 1, of the bottle's contents which is coffee. A fully empty bottle is undefined behavior; you don't have to handle that case. Your may choose to produce output in the form of two numbers representing a numerator and denominator.

This is code-golf, so shortest answer per language wins.

Test cases
These test cases use comma-separated operations, formatted as w(1) (fill with 1ml of water), c(1) (fill with 1ml of coffee), or d(1) (drink 1ml).

w(10) -- 0.0
w(10),c(15) -- 0.6
c(10) -- 1.0
w(10),c(10),d(10) -- 0.5
w(10),c(10),d(10),c(10) -- 0.75
w(5),w(5),w(5) -- 0
w(10),c(20),d(50),w(10) -- 0
c(10),d(5),w(5),d(5),w(5),d(5),w(5),d(5) -- 0.125
c(7),w(1),d(7),w(1) -- 0.4375

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

double
mixture(const char *s)
{
	double A[2], T;
	char t;
	int v;

	A[0] = A[1] = 0;
	for (;;) {
		if (sscanf(s, "%c(%d)", &t, &v) != 2)
			break;

		switch (t) {
		case 'w':
			A[0] += v;
			break;

		case 'c':
			A[1] += v;
			break;

		case 'd':
			T = A[0] + A[1];
			A[0] = fmax(A[0] - ((v * A[0]) / T), 0);
			A[1] = fmax(A[1] - ((v * A[1]) / T), 0);
			break;
		}

		s = strchr(s, ',');
		if (!s)
			break;
		s++;
	}
	return A[1] / (A[0] + A[1]);
}

void
test(const char *s, double r)
{
	double v;

	v = mixture(s);
	printf("%.6f\n", v);
	assert(fabs(v - r) < 1e-12);
}

int
main()
{
	test("w(10)", 0.0);
	test("w(10),c(15)", 0.6);
	test("c(10)", 1.0);
	test("w(10),c(10),d(10)", 0.5);
	test("w(10),c(10),d(10),c(10)", 0.75);
	test("w(5),w(5),w(5)", 0);
	test("w(10),c(20),d(50),w(10)", 0);
	test("c(10),d(5),w(5),d(5),w(5),d(5),w(5),d(5)", 0.125);
	test("c(7),w(1),d(7),w(1)", 0.4375);

	return 0;
}
