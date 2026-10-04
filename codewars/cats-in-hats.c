/*

The Cat In The Hat has cat A under his hat, cat A has cat B under his hat and so on until Z

The Cat In The Hat is 2,000,000 cat units tall.

Each cat is 2.5 times bigger than the cat underneath their hat.

Find the total height of the cats if they are standing on top of one another.

Counting starts from the Cat In The Hat

n = the number of cats

fix to 3 decimal places.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
height(int n)
{
	double r, h;
	int i;

	r = 0;
	h = 2000000;
	for (i = 0; i <= n; i++) {
		r += h;
		h /= 2.5;
	}
	return r;
}

void
test(int n, double r)
{
	double h;

	h = height(n);
	printf("%.3f\n", h);
	assert(fabs(h - r) < 1e-3);
}

int
main()
{
	test(0, 2000000.000);
	test(7, 3331148.800);
	test(9, 3332983.808);

	return 0;
}
