/*

http://24.media.tumblr.com/tumblr_m8nk1vGUMQ1r3ifxzo1_500.gif

In Pokemon Go, an easy way to increase your XP level is to evolve pokemon you've caught.

Every time you catch a pokemon, you also receive some Candy. The Candy is limited to the pokemon type (eg. a Pidgey will give you Pidgey Candy) and once you have enough, you can spend it to evolve a pokemon.

To evolve a Pidgey costs 12 Pidgey Candy, but you'll be rewarded with 500 XP and 1 extra Pidgey Candy.

Surplus Pidgeys can be transferred to Professor Willow in exchange for 1 Pidgey Candy - you won't get the Pidgey back.

#Example

If you have 2 Pidgeys and 23 Pidgey Candy, you can evolve 1 Pidgey for 12 Pidgey Candy. You have 11 Pidgey Candy left, but you received 1 Pidgey Candy for evolving the first Pidgey, making the 12 you need to evolve the 2nd. You will end up with 1000 XP.

#Your job

Create a function that will take 2 integers as arguments: a number of Pidgeys and an amount of Pidgey Candy. It should return the maximum XP gained from evolving the highest possible number of Pidgeys.

Remember, you'll need to take into account the extra Pidgey Candy gained from tranferring and evolving Pidgeys.

*/

#include <assert.h>

int
pidgey(int pidgeys, int candy)
{
	int experience;

	for (experience = 0; pidgeys > 0; pidgeys--) {
		if (candy < 12)
			candy += 1;
		else {
			candy -= 11;
			experience += 500;
		}
	}
	return experience;
}

int
main()
{
	assert(pidgey(1, 12) == 500);
	assert(pidgey(13, 144) == 6500);
	assert(pidgey(10, 63) == 3000);
	assert(pidgey(1, 63) == 500);
	assert(pidgey(63, 1) == 2500);
	assert(pidgey(0, 0) == 0);

	return 0;
}
