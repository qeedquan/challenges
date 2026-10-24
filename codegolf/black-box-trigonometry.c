/*

Write a program or function that can distinguish the following 12 trigonometric functions: sin, cos, tan, asin, acos, atan, sinh, cosh, tanh, asinh, acosh, atanh.

Your program is given one of the above functions as black box and should output the function's name either as given above or the way it is named in your language.

This is code-golf, so the shortest answer in each language wins. You should show that your code works correctly by including test cases with all 12 possible inputs. If the language of your choice does not include build-ins for all of the above functions, you have to provide your own sensible implementations of the missing ones.

Further Clarifications
Using complex numbers to query the black box is allowed if the underlying build-ins can handle them.
As dom acosh ∩ dom atanh=∅
 when using only real numbers, queries to the black box function can give domain errors. In this case you should assume that the black box only communicates the existence of an error, but not from which function it originates.
If instead of an error some other value, e.g. NaN or null, is returned, then your submission should be able to handle them.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[32];
	double (*call)(double);
	double start;
	double end;
} Func;

const Func funcs[] = {
    {"sin", sin, 0, 2 * M_PI},
    {"cos", cos, 0, 2 * M_PI},
    {"tan", tan, 0, 2 * M_PI},
    {"asin", asin, -1, 1},
    {"acos", acos, -1, 1},
    {"atan", atan, -1, 1},
    {"sinh", sinh, -1, 1},
    {"cosh", cosh, -1, 1},
    {"tanh", tanh, -1, 1},
    {"asinh", asinh, -1, 1},
    {"acosh", acosh, 1, 2},
    {"atanh", atanh, -1, 1},
};

const char *
classify(double (*f)(double))
{
	static const double eps = 1e-8;
	static const double step = 1e-3;

	const Func *p;
	double n, d, t;
	size_t i;

	for (i = 0; i < nelem(funcs); i++) {
		p = funcs + i;
		n = 0;
		d = 0;
		for (t = p->start; t <= p->end; t += step) {
			if (fabs(f(t) - p->call(t)) < eps)
				n += 1;
			d += 1;
		}

		if (n / d >= 0.99)
			return p->name;
	}
	return "unknown";
}

int
main(void)
{
	const Func *p;
	size_t i;

	for (i = 0; i < nelem(funcs); i++) {
		p = funcs + i;
		assert(!strcmp(p->name, classify(p->call)));
	}

	return 0;
}
