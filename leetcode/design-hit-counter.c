/*

Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

Example:

HitCounter counter = new HitCounter();
// hit at timestamp 1.
counter.hit(1);
// hit at timestamp 2.
counter.hit(2);
// hit at timestamp 3.
counter.hit(3);
// get hits at timestamp 4, should return 3.
counter.getHits(4);
// hit at timestamp 300.
counter.hit(300);
// get hits at timestamp 300, should return 4.
counter.getHits(300);
// get hits at timestamp 301, should return 3.
counter.getHits(301);
Follow up: What if the number of hits per second could be very large? Does your design scale?

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef unsigned int uint;

typedef struct {
	uint *buf;
	uint *time;
	uint *count;
	uint maxtime;
} Hits;

int
hitsinit(Hits *h, uint maxtime)
{
	h->buf = calloc(maxtime * 2, sizeof(*h->buf));
	if (!h->buf)
		return -errno;

	h->time = h->buf;
	h->count = h->buf + maxtime;
	h->maxtime = maxtime;
	return 0;
}

void
hitsfree(Hits *h)
{
	free(h->buf);
}

void
hitsadd(Hits *h, uint time)
{
	uint i;

	i = time % h->maxtime;
	if (h->time[i] != time) {
		h->time[i] = time;
		h->count[i] = 1;
	} else
		h->count[i]++;
}

uint
hitsget(Hits *h, uint time)
{
	uint i, r;

	r = 0;
	for (i = 0; i < h->maxtime; i++) {
		if (time >= h->time[i] && (time - h->time[i]) < h->maxtime)
			r += h->count[i];
	}
	return r;
}

int
main(void)
{
	Hits h[1];

	assert(hitsinit(h, 5 * 60) >= 0);
	hitsadd(h, 1);
	hitsadd(h, 2);
	hitsadd(h, 3);
	assert(hitsget(h, 4) == 3);
	hitsadd(h, 300);
	assert(hitsget(h, 300) == 4);
	assert(hitsget(h, 301) == 3);
	hitsfree(h);

	return 0;
}
