/*

There are two kinds of threads: oxygen and hydrogen. Your goal is to group these threads to form water molecules.

There is a barrier where each thread has to wait until a complete molecule can be formed. Hydrogen and oxygen threads will be given releaseHydrogen and releaseOxygen methods respectively, which will allow them to pass the barrier. These threads should pass the barrier in groups of three, and they must immediately bond with each other to form a water molecule. You must guarantee that all the threads from one molecule bond before any other threads from the next molecule do.

In other words:

If an oxygen thread arrives at the barrier when no hydrogen threads are present, it must wait for two hydrogen threads.
If a hydrogen thread arrives at the barrier when no other threads are present, it must wait for an oxygen thread and another hydrogen thread.
We do not have to worry about matching the threads up explicitly; the threads do not necessarily know which other threads they are paired up with. The key is that threads pass the barriers in complete sets; thus, if we examine the sequence of threads that bind and divide them into groups of three, each group should contain one oxygen and two hydrogen threads.

Write synchronization code for oxygen and hydrogen molecules that enforces these constraints.



Example 1:

Input: water = "HOH"
Output: "HHO"
Explanation: "HOH" and "OHH" are also valid answers.
Example 2:

Input: water = "OOHHHH"
Output: "HHOHHO"
Explanation: "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" and "OHHOHH" are also valid answers.


Constraints:

3 * n == water.length
1 <= n <= 20
water[i] is either 'H' or 'O'.
There will be exactly 2 * n 'H' in water.
There will be exactly n 'O' in water.

*/

#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct {
	sem_t semh;
	sem_t semo;
	int h;
} Context;

typedef struct {
	Context *ctx;
	void (*handler)(Context *);
	int len;
} Runner;

void
initctx(Context *c)
{
	sem_init(&c->semh, 0, 1);
	sem_init(&c->semo, 0, 0);
	c->h = 0;
}

void
freectx(Context *c)
{
	sem_destroy(&c->semh);
	sem_destroy(&c->semo);
}

void
hydrogen(Context *c)
{
	sem_wait(&c->semh);
	c->h++;
	printf("H");
	if ((c->h & 1) == 0)
		sem_post(&c->semo);
	else
		sem_post(&c->semh);
}

void
oxygen(Context *c)
{
	sem_wait(&c->semo);
	printf("O");
	sem_post(&c->semh);
}

void *
runner(void *ud)
{
	Runner *r;
	int i;

	r = ud;
	for (i = 0; i < r->len; i++)
		r->handler(r->ctx);
	return NULL;
}

int
chars(const char *s, int c)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; s[i]; i++) {
		if (s[i] == c)
			r++;
	}
	return r;
}

int
build(const char *s)
{
	Context c;
	Runner h, o;
	pthread_t th[2];

	h.ctx = &c;
	h.handler = hydrogen;
	h.len = chars(s, 'H');

	o.ctx = &c;
	o.handler = oxygen;
	o.len = chars(s, 'O');

	if (h.len != o.len * 2)
		return -EINVAL;

	initctx(&c);
	pthread_create(th + 0, NULL, runner, &h);
	pthread_create(th + 1, NULL, runner, &o);
	pthread_join(th[0], NULL);
	pthread_join(th[1], NULL);
	freectx(&c);

	printf("\n");
	fflush(stdout);

	return 0;
}

int
main(void)
{
	build("HOH");
	build("OOHHHH");
	build("HHHHHHOOO");

	return 0;
}
