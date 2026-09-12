/*

The Riddle
The King of a small country invites 1000 senators to his annual party. As a tradition, each senator brings the King a bottle of wine. Soon after, the Queen discovers that one of the senators is trying to assassinate the King by giving him a bottle of poisoned wine. Unfortunately, they do not know which senator, nor which bottle of wine is poisoned, and the poison is completely indiscernible.

However, the King has 10 lab rats. He decides to use them as taste testers to determine which bottle of wine contains the poison. The poison when taken has no effect on the rats, until exactly 24 hours later when the infected rats suddenly die. The King needs to determine which bottle of wine is poisoned by tomorrow, so that the festivities can continue as planned.

Hence he only has time for one round of testing, he decides that each rat tastes multiple bottles, according to a certain scheme.

Your Task
You receive an array of integers (0 to 9), each of them is the number of a rat which died after tasting the wine bottles. Return the number of the bottle (1..1000) which is poisoned.

Good Luck!

Hint: think of rats as a certain representation of the number of the bottle...

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
bottles(int *a, size_t n)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; i < n; i++)
		r += (1 << a[i]);
	return r;
}

int
main()
{
	int a1[] = {8};
	int a2[] = {0, 1, 3, 4};
	int a3[] = {0, 1, 9, 3, 5};
	int a4[] = {0, 1, 2, 3, 4, 6};
	int a5[] = {0, 3, 5, 4, 9, 8};

	assert(bottles(a1, nelem(a1)) == 256);
	assert(bottles(a2, nelem(a2)) == 27);
	assert(bottles(a3, nelem(a3)) == 555);
	assert(bottles(a4, nelem(a4)) == 95);
	assert(bottles(a5, nelem(a5)) == 825);

	return 0;
}
