/*

I've invited some kids for my son's birthday, during which I will give to each kid some amount of candies.

Every kid hates receiving less amount of candies than any other kids, and I don't want to have any candies left - giving it to my kid would be bad for his teeth.

However, not every kid invited will come to my birthday party.

What is the minimum amount of candies I have to buy, so that no matter how many kids come to the party in the end, I can still ensure that each kid can receive the same amount of candies, while leaving no candies left?

It's ensured that at least one kid will participate in the party.

*/

#include <assert.h>

int
candies(int k)
{
	int c, i, j;

	c = k;
	for (i = k - 1; i > 0; i--) {
		if (!(c % i))
			continue;

		for (j = 2; j <= i; j++) {
			if (!((c * j) % i)) {
				c *= j;
				break;
			}
		}
	}
	return c;
}

int
main()
{
	assert(candies(1) == 1);
	assert(candies(2) == 2);
	assert(candies(5) == 60);
	assert(candies(6) == 60);
	assert(candies(9) == 2520);
	assert(candies(10) == 2520);
	return 0;
}
