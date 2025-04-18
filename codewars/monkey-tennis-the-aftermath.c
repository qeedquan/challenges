/*

You are Chief Commissioning Editor at a broadcaster who recently approved the production of a televisual sports extravaganza, ‘Monkey Tennis’.

Broadcasting from Wimbledon has just finished and it did not go well. Adherence to the rules of the game was minimal and, in essence, you just spent 45 minutes watching a band of chimps running amuck on a tennis court in front of a live studio audience. Now you are left with a detritus; there are tennis balls and banana peels everywhere!

You will receive an array of tennis balls and banana peels, which will each be represented by their weight. Tennis balls weigh exactly 58 grams, and banana peels weigh 60 grams upwards.

Your job is to gather up just the tennis balls and return them in a sack. The sack will be represented by an object that has a 'weight' property, the value of which should be equal to the combined weight of all tennis balls in the array. If the array contains no tennis balls, then the weight value of the returned sack object should be 0.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
balls(int *w, size_t n)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; i < n; i++) {
		if (w[i] == 58)
			r += w[i];
	}
	return r;
}

int
main()
{
	int w1[] = { 58, 68, 62, 69, 58 };
	int w2[] = { 60, 66, 71, 68, 62 };
	int w3[] = { 58 };
	int w4[] = { 58, 58, 58 };

	assert(balls(w1, nelem(w1)) == 116);
	assert(balls(w2, nelem(w2)) == 0);
	assert(balls(w3, nelem(w3)) == 58);
	assert(balls(w4, nelem(w4)) == 174);

	return 0;
}
