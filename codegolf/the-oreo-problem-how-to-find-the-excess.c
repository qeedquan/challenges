/*

This problem is inspired from this childhood advertisement I remembered of while making biscuits with my checkers. Assume you got a black checker, and white checker on top of it, and another black checker till point n. Note that it does not matter if the top checker is black or white, but the bottom checker is assumed to be black.

Let this line be black checker:
+++++++

And let this line be white checker:
------
A complete oreo biscuit is formed when the black checker sandwiches the white checker:

++++++
-----
++++++
This forms an oreo biscuit. But here is the twist, since you got n number of checkers, find how many checkers remain excess when a biscuit is not formed.

Note that for an oreo biscuit to form, it must be only enclosed by the two black checkers and each checker is unique and can not be reused.

Test Cases
Take n as 2, you get:

-----
++++++
That means 2 checkers are in excess and for 2, it is 2 because they failed to make the oreo biscuit. For n as 7:

++++++
-----
++++++
-----
++++++
-----
++++++
The excess here is the 4th checker, the white checker fails to get sandwiched to an oreo.

Challenge: Given an nth number, tell how many excess remains.

I checked to first 11 checkers to confirm the excess (starting from $n$ = 0) as: 0,1,2,0,1,2,3,1,2,3,4,2

https://i.sstatic.net/DiBHk54E.jpg

Eat some oreo (not creamy but ketchupy ones ToT)

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

@xnor

The formula is

n - 3*floor((n+1)/4)

This comes from starting with n checkers and removing sandwiches of 3.
How many sandwiches? The color alternation doesn't let sandwiches touch, so the densest they pack is: sandwich of 3, skip 1, sandwich of 3, skip 1, and so on.
This allows one sandwich per 4 checkers except the first one uses only 3, for floor((n+1)/4) sandwiches.

*/

int
excess(int n)
{
	if (n < 0)
		return 0;
	return n - (3 * ((n + 1) / 4));
}

int
main()
{
	static const int tab[] = { 0, 1, 2, 0, 1, 2, 3, 1, 2, 3, 4, 2 };

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(excess(i) == tab[i]);

	return 0;
}
