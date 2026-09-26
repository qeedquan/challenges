/*

Write a function that returns a normally distributed random number, with specified mean μ and standard deviation σ.

# Generate a random number, normally distributed
# with mean 1.23 and standard deviation 4.56
normal(1.23,4.56)
NOTE: The tests are statistical, and there is a small probability that they will fail even for a correct answer. If this happens, try re-running the test.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
	double x[2];
	int i;
} Normal;

void
newnormal(Normal *n)
{
	n->x[0] = 0;
	n->x[1] = 0;
	n->i = 0;
}

// https://kcru.lawsonresearch.ca/research/srk/normalDBN_random.html
double
normal(Normal *n, double mu, double sigma)
{
	double u1, u2;
	double w, mult;

	if (n->i == 1) {
		n->i ^= 1;
		return mu + (sigma * n->x[1]);
	}

	do {
		u1 = -1 + (rand() * 1.0 / RAND_MAX) * 2;
		u2 = -1 + (rand() * 1.0 / RAND_MAX) * 2;
		w = pow(u1, 2) + pow(u2, 2);
	} while (w >= 1 || w == 0);

	mult = sqrt((-2 * log(w)) / w);
	n->x[0] = u1 * mult;
	n->x[1] = u2 * mult;
	n->i ^= 1;

	return mu + (sigma * n->x[0]);
}

int
main()
{
	Normal dis;
	double mu;
	double sigma;
	int i;

	srand(time(NULL));
	newnormal(&dis);
	mu = 1.23;
	sigma = 4.56;
	for (i = 0; i < 10000; i++) {
		printf("%f\n", normal(&dis, mu, sigma));
	}

	return 0;
}
