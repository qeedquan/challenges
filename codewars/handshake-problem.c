/*

Johnny is a farmer and he annually holds a beet farmers convention "Drop the beet".

Every year he takes photos of farmers handshaking. Johnny knows that no two farmers handshake more than once. He also knows that some of the possible handshake combinations may not happen.

However, Johnny would like to know the minimal amount of people that participated this year just by counting all the handshakes.

Help Johnny by writing a function, that takes the amount of handshakes and returns the minimal amount of people needed to perform these handshakes (a pair of farmers handshake only once).

*/

#include <assert.h>
#include <math.h>

int
participants(int handshakes)
{
	return ceil(sqrt(2 * handshakes + 0.25) + 0.5);
}

int
main()
{
	assert(participants(0) == 1);
	assert(participants(1) == 2);
	assert(participants(3) == 3);
	assert(participants(6) == 4);
	assert(participants(7) == 5);

	return 0;
}
