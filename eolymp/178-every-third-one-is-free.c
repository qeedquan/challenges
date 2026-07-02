/*

Barlimen Butterbur owns the renowned inn "The Prancing Pony" in the town of Bree.
This is a popular spot where weary orcs often gather after battles to enjoy a mug or two of their favorite drink, the dwarf-stomper.

Recently, however, new establishments have begun appearing, which has led to a decrease in the inn's number of customers.
To win back his clientele, Barlimen decided to introduce a promotion:
for every certain number of mugs of dwarf-stomper a patron buys, they receive an extra mug for free.
Naturally, the lower this number, the more attractive the offer is to customers.
On the other hand, if the number is too low, the owner will not make a profit—or might even incur losses.

Help the innkeeper determine the minimum number of mugs that must be purchased to offer one for free, so that the promotion is still profitable.

Input
Each test consists of a single line containing two integers: b, the cost price of one mug of dwarf-stomper, and c, the selling price of one mug (0≤b<c≤10^9).
The input ends with a line where b=c=0, which should not be processed.

Output
For each test case, print the minimum number of mugs that must be purchased to receive one free, in order to ensure the innkeeper makes a profit.
Print each answer on a separate line.

Examples

Input #1
5 8
100 1000
13 18
0 0

Answer #1
2
1
3

*/

#include <assert.h>

int
solve(int a, int b)
{
	int c;

	c = b - a;
	if (c == 0)
		return 0;
	return (a / c) + 1;
}

int
main()
{
	assert(solve(5, 8) == 2);
	assert(solve(100, 1000) == 1);
	assert(solve(13, 18) == 3);

	return 0;
}
