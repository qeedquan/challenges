/*

Story

So I have a book that I want to separate from my table with nothing but other books. I want to know how many books do I need to achieve this with n book lengths.

Here's a visualization that my friend at Wolfram drew for me:

a visualization from Wolfram

More information about the topic in Wolfram and Wikipedia.

Challenge

Given an integer input n, output how many books needed for the top book to be n book length away from the table horizontally. or
Find the smallest integer value of m for input n in the following inequality.
Sum[i=1, m] 1/(2^i) >= n
Edit: for fractions use at least a IEEE single-precision floating point. sorry for editing challenge after posting

(OEIS A014537)

Test cases

 1          4
 2         31
 3        227
 5      12367
10  272400600

*/

#include <assert.h>

typedef unsigned long long uvlong;

// https://oeis.org/A014537
uvlong
bookstack(double n)
{
	uvlong i;
	double s;

	i = 0;
	s = 0;
	while (s < n) {
		i += 1;
		s += 0.5 / i;
	}
	return i;
}

int
main(void)
{
	assert(bookstack(1) == 4);
	assert(bookstack(2) == 31);
	assert(bookstack(3) == 227);
	assert(bookstack(5) == 12367);
	assert(bookstack(10) == 272400600ULL);

	return 0;
}
