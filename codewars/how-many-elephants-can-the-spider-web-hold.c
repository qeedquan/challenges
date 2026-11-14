/*

How many elephants can the spider web hold?

Imagine a spider web that is defined by two variables:

strength, measured as the weight in kilograms that the web holds. Strength + 1 elephant will break the web
length, measured as the number of elephants that fit one after the other on the web :)
Paraphrasing the song "One elephant went out to play", how many elephants will the web hold if we put them one after the other, without breaking?

You must take into account two things:

elephants like to create super high pyramids, so, on each level of the structure fits one elephant less than in the previous one.
elephants sitting on the first row weight 1000 kg, the ones sitting on the second row weight 2000 kg, and so on. When rows are full of elephants, next elephants go up one level, and weight 1000 kg more than the previous ones.
Visualy represented:

Width: 3 Strength: 10000

3000Kg: E6
2000Kg: E4 E5
1000Kg: E1 E2 E3
The elephants weight 10000Kg. Since the web can hold 10000Kg (strength), the solution is 6 elephants.

Have fun!

Notes:

check all the possible values for the input parameters, even absurd ones :D

*/

#include <assert.h>

long
breakweb(long strength, long width)
{
	long count;
	long weight;
	long i;

	if (strength < 1 || width < 1)
		return 0;

	count = 0;
	for (weight = 1000; strength >= weight; weight += 1000) {
		for (i = 0; i < width && weight <= strength; i++) {
			strength -= weight;
			count += 1;
		}
		width -= 1;
	}
	return count;
}

int
main()
{
	assert(breakweb(10000, 3) == 6);
	assert(breakweb(9200, 12) == 9);
	assert(breakweb(9200, 3) == 5);
	assert(breakweb(532000, 532) == 532);
	assert(breakweb(532000, 5) == 15);
	assert(breakweb(532000, -1) == 0);
	assert(breakweb(0, 10) == 0);
	assert(breakweb(-1, 10) == 0);
	assert(breakweb(532000, 10) == 55);
	assert(breakweb(21000, 8) == 14);

	return 0;
}
