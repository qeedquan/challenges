/*

For this kata you will have to forget how to add two numbers.

It can be best explained using the following meme:

https://knowyourmeme.com/memes/girl-at-whiteboard-adding

In simple terms, our method does not like the principle of carrying over numbers and just writes down every number it calculates :-)

You may assume both integers are positive integers.

Examples
  1 6
+ 1 8
------
  2 14

  2 6
+ 3 9
-----
  5 15

  1 2  2
+   8  1
--------
  1 10 3

  7 2
+   9
------
  7 11

You may assume both integers are positive integers and the result will not be bigger than Integer.MAX_VALUE

*/

#include <stdio.h>
#include <assert.h>

unsigned
add(unsigned a, unsigned b)
{
	unsigned p, r, v;

	r = 0;
	p = 1;
	while (a > 0 || b > 0) {
		v = (a % 10) + (b % 10);
		r += v * p;
		if (v >= 10)
			p *= 10;

		p *= 10;
		a /= 10;
		b /= 10;
	}
	return r;
}

int
main()
{
	assert(add(16, 18) == 214);
	assert(add(26, 39) == 515);
	assert(add(122, 81) == 1103);
	assert(add(72, 9) == 711);
	return 0;
}
