/*

The new "Avengers" movie has just been released! There are a lot of people at the cinema box office standing in a huge line. Each of them has a single 100, 50 or 25 dollar bill. An "Avengers" ticket costs 25 dollars.

Vasya is currently working as a clerk. He wants to sell a ticket to every single person in this line.

Can Vasya sell a ticket to every person and give change if he initially has no money and sells the tickets strictly in the order people queue?

Return YES, if Vasya can sell a ticket to every person and give change with the bills he has at hand at that moment. Otherwise return NO.

Examples:
tickets([25, 25, 50]) // => YES
tickets([25, 100]) // => NO. Vasya will not have enough money to give change to 100 dollars
tickets([25, 25, 50, 50, 100]) // => NO. Vasya will not have the right bills to give 75 dollars of change (you can't make two bills of 25 from one of 50)q

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
tickets(int *prices, size_t nprice)
{
	int quarter;
	int fifty;
	size_t index;

	quarter = fifty = 0;
	for (index = 0; index < nprice; index++) {
		switch (prices[index]) {
		case 25:
			quarter += 1;
			break;

		case 50:
			quarter -= 1;
			fifty += 1;
			if (quarter < 0)
				return false;
			break;

		case 100:
			if (fifty == 0)
				quarter -= 3;
			else {
				quarter -= 1;
				fifty -= 1;
			}
			if (quarter < 0 || fifty < 0)
				return false;
			break;
		}
	}
	return true;
}

int
main()
{
	int prices_1[] = { 25, 25, 50 };
	int prices_2[] = { 25, 100 };
	int prices_3[] = { 25, 25, 50, 50, 100 };

	assert(tickets(prices_1, nelem(prices_1)) == true);
	assert(tickets(prices_2, nelem(prices_2)) == false);
	assert(tickets(prices_3, nelem(prices_3)) == false);

	return 0;
}
