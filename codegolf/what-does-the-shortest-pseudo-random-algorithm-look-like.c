/*

After seeing some impossibly short solutions in this SE, I began to wonder what code someone could come up with to build a pseudo-random number generator. Now given that I am new to programming, I have absolutely no idea what such generator should look like, or what language to write them in. But that did not stop me from trying some goofy things like writing PRNG, listing primes or prime tests.

So here's the deal, the challenge is to write a pseudo-random number generator that does the following things:

1.Accept a seed in the form of string, number, bits, or whatever, and generate a pseudo-random sequence based on that string. The initial seed should default to 0 if nothing is provided.

2.Accept some input N and generate a pseudo random sequence of length N. Straight forward enough. You can choose to name this whatever you want, or not at all.

3.Be deterministic, the same seed should generate the same sequence each time.

4.I have absolutely no idea how this is tested but the results should be reasonably random. So the results from your generator should be close to uniform distribution within your arbitrary sample space.

5.You can choose any mathematical formula/operation for your pseudo random generation, but it should update its internal state in a deterministic way and use that new internal state for the generation of another number.

You may not outsource your random number generation to any source, be it built in or online. Every variable update/ operation should be explicitly ordered. (things like random.randint() is banned, sorry I only know python)

I can't come up with some inventive way of scoring, so shortest program wins.

*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	uint32_t state[16];
	unsigned index;
} wellrng512_t;

void
wellrng512_init(wellrng512_t *w, uint32_t init[16])
{
	memcpy(w->state, init, sizeof(w->state));
	w->index = 0;
}

/*

https://en.wikipedia.org/wiki/Well_equidistributed_long-period_linear
http://lomont.org/papers/2008/Lomont_PRNG_2008.pdf

*/

uint32_t
wellrng512_next(wellrng512_t *w)
{
	uint32_t a, b, c, d;

	a = w->state[w->index];
	c = w->state[(w->index + 13) & 15];
	b = a ^ c ^ (a << 16) ^ (c << 15);
	c = w->state[(w->index + 9) & 15];
	c ^= (c >> 11);
	a = w->state[w->index] = b ^ c;
	d = a ^ ((a << 5) & 0xDA442D24UL);
	w->index = (w->index + 15) & 15;
	a = w->state[w->index];
	w->state[w->index] = a ^ b ^ d ^ (a << 2) ^ (b << 18) ^ (c << 28);
	return w->state[w->index];
}

int
main(void)
{
	uint32_t init[16];
	wellrng512_t rng;
	size_t i;

	for (i = 0; i < nelem(init); i++)
		init[i] = i;
	wellrng512_init(&rng, init);

	for (i = 0; i < 8192; i++)
		printf("%" PRIu32 "\n", wellrng512_next(&rng));

	return 0;
}
