/*

Tired of always wondering how many more Pokémon you need to catch to get those high-tier evolutions? Wonder no more! Now you will write a complete program or function to calculate it for you!

The Challenge:
As input, your program will receive a list of the costs in candy to evolve a Pokémon to the next tier. (This list may be separated by any delimiter of your choosing, or as function arguments). Your program will then return or print the number of Pokémon that must be caught, including the one that will be evolved, to evolve through all the tiers given.

How do you calculate this? Like so:
1. Add up all the candy costs: 12 + 50 = 62
2. Subtract 3 candies from the total, this being from the one Pokémon you keep for evolving: 62 - 3 = 59
3. Divide this number by 4 (3 for catching, 1 for giving it to the Professor), always taking the ceil() of the result: ceil(59/4) = 15
4. Finally, add 1 to this total to get the total number of Pokémon you must catch, 16!

Example Input -> Output:

[4] -> 2
[50] -> 13
[12, 50] -> 16
[25, 100] -> 32
[19, 35, 5, 200] -> 65

Winning:
The app has already taken up most of the space on your phone, so your program needs to be as short as possible. The complete program or function with the smallest byte count will be accepted in two weeks! (with any ties being settled by the earliest submitted entry!)

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
evolution(int *a, size_t n)
{
	size_t i;
	double s;

	s = 0;
	for (i = 0; i < n; i++)
		s += a[i];
	return ceil((s - 3) / 4) + 1;
}

int
main(void)
{
	int a1[] = {4};
	int a2[] = {50};
	int a3[] = {12, 50};
	int a4[] = {25, 100};
	int a5[] = {19, 35, 5, 200};
	int a6[] = {12, 50};

	assert(evolution(a1, nelem(a1)) == 2);
	assert(evolution(a2, nelem(a2)) == 13);
	assert(evolution(a3, nelem(a3)) == 16);
	assert(evolution(a4, nelem(a4)) == 32);
	assert(evolution(a5, nelem(a5)) == 65);
	assert(evolution(a6, nelem(a6)) == 16);

	return 0;
}
