/*

I saw the following problem on MathsSE:

You try to do something and your probability of success is p.
If you fail, you try again, but the probability of success falls down to p^2.
If you fail again, you try again, but the probability of success is now down to p^3.
If you fail, you keep trying [and the success probability is multiplied by p each time].
What is your overall probability of success with unlimited tries?

I immediately gold-hammered it, because it is easy to see that the probability of never succeeding is given by the infinite Pochhammer symbol or Euler function:

phi(p) = Multiply[n=1, oo] (1 - p^n)

This function has a number of interesting alternative expressions, such as the pentagonal number theorem:

phi(p) = Sum[n=-oo, oo] (-1)^n * p^((n*(3*n-1))/2)

Task
Given 0≤p≤0.9, return ϕ(p) as defined above. The theoretical relative error may not exceed 0.1%, but you may ignore floating-point errors.

To keep the task interesting for mathematics-oriented languages and libraries it is forbidden to use any builtin directly computing ϕ(p).

Test cases
x phi(x)
0.0 1.0
0.1 0.890010099998999
0.2 0.760332795871232
0.3 0.612648154213257
0.4 0.451860550846419
0.5 0.288788095086602
0.6 0.143121482144708
0.7 0.0423158973846354
0.8 0.00336800585242312
0.9 1.28606743427662e-6

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
phi(double x)
{
	double r;
	int i;

	r = 1;
	for (i = 1; i <= 100; i++)
		r *= 1 - pow(x, i);
	return r;
}

void
test(double x, double r)
{
	double p;

	p = phi(x);
	assert(fabs(p - r) < 1e-9);
}

int
main()
{
	test(0.0, 1.0);
	test(0.1, 0.890010099998999);
	test(0.2, 0.760332795871232);
	test(0.3, 0.612648154213257);
	test(0.4, 0.451860550846419);
	test(0.5, 0.288788095086602);
	test(0.6, 0.143121482144708);
	test(0.7, 0.0423158973846354);
	test(0.8, 0.00336800585242312);
	test(0.9, 1.28606743427662e-6);

	return 0;
}
