/*

The test fixture I use for this kata is pre-populated.

It will compare your guess to a random number generated using:

Math.floor(Math.random() * 100 + 1)
You can pass by relying on luck or skill but try not to rely on luck.

"The power to define the situation is the ultimate power." - Jerry Rubin

Good luck!

*/

#include <assert.h>

int
rand(void)
{
	return 1;
}

int
main(void)
{
	int i;

	for (i = 0; i <= 10000; i++)
		assert(rand() == 1);
	return 0;
}
