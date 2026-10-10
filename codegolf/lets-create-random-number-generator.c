/*

The task is to make a function which returns random number, no build in functions allowed, returned value should be random or pseudo-random and no sequence allowed, no matter what the formula is and how scattered values are.

To simplify task, returned value should be 32-bit integer or float from range [0; 1)

It is code golf, shortest code wins :)

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <inttypes.h>

enum {
	LEN = 607,
	TAP = 273,
	MASK = 0x7fffffffL,
	A = 48271,
	M = 2147483647,
	Q = 44488,
	R = 3399,
};

// ported from https://github.com/0intro/mitchell_reeds
typedef struct {
	uint32_t rng_vec[607];
	uint32_t *rng_tap;
	uint32_t *rng_feed;
} Mitchell_Reeds;

void
mitchell_reeds_init(Mitchell_Reeds *r)
{
	memset(r, 0, sizeof(*r));
	r->rng_tap = r->rng_vec;
}

void
mitchell_reeds_srand(Mitchell_Reeds *r, int32_t seed)
{
	int32_t lo, hi, x;
	int i;

	r->rng_tap = r->rng_vec;
	r->rng_feed = r->rng_vec + LEN - TAP;
	seed = seed % M;
	if (seed < 0)
		seed += M;
	if (seed == 0)
		seed = 89482311;
	x = seed;

	// Initialize by x[n+1] = 48271 * x[n] mod (2**31 - 1)
	for (i = -20; i < LEN; i++) {
		hi = x / Q;
		lo = x % Q;
		x = A * lo - R * hi;
		if (x < 0)
			x += M;
		if (i >= 0)
			r->rng_vec[i] = x;
	}
}

uint32_t
mitchell_reeds_lrand(Mitchell_Reeds *r)
{
	uint32_t x;

	r->rng_tap--;
	if (r->rng_tap < r->rng_vec) {
		if (r->rng_feed == 0) {
			mitchell_reeds_srand(r, 1);
			r->rng_tap--;
		}
		r->rng_tap += LEN;
	}
	r->rng_feed--;
	if (r->rng_feed < r->rng_vec)
		r->rng_feed += LEN;
	x = (*r->rng_feed + *r->rng_tap) & MASK;
	*r->rng_feed = x;

	return x;
}

int
main(void)
{
	Mitchell_Reeds r[1];
	int i;

	mitchell_reeds_init(r);
	mitchell_reeds_srand(r, time(NULL));
	for (i = 0; i <= 10; i++)
		printf("%" PRIu32 "\n", mitchell_reeds_lrand(r));

	return 0;
}
