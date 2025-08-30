/*

ZigZag encoding is a method of encoding signed integers to unsigned integers.
Non-negative integers are multiplied by two.
Negative integers are equal to their absolute values multiplied by two, minus one. Decoding is the inverse process.

https://i.sstatic.net/Ol8Ye481.png

 (Viotti, Juan & Kinderkhedia, Mital. (2022). A Survey of JSON-compatible Binary Serialization Specifications. arXiv.2201.02089. CC BY 4.0)

Write two programs or functions: One which takes a signed integer and ZigZag encodes it, and another which decodes a ZigZag-encoded integer. Your program or function should be able to accommodate the largest number types your language or platform supports.

This is code-golf. Your score is the combined number of bytes of your two programs or functions. Lowest score wins.

Rules
Default I/O rules and standard rules apply. Standard loopholes are forbidden.
Test cases
Decoded Encoded
  -10      19
   -3       5
   -1       1
    0       0
    1       2
    3       6
   10      20

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
enc(int n)
{
	if (n < 0)
		return (-2 * n) - 1;
	return 2 * n;
}

int
dec(int n)
{
	if (!(n & 1))
		return n / 2;
	return -(n + 1) / 2;
}

int
main()
{
	static const int tab[][2] = {
		{ -10, 19 },
		{  -3,  5 },
		{  -1,  1 },
		{   0,  0 },
		{   1,  2 },
		{   3,  6 },
		{  10, 20 },
	};

	size_t i;
	int x, y;

	for (i = 0; i < nelem(tab); i++) {
		x = tab[i][0];
		y = tab[i][1];
		assert(enc(x) == y);
		assert(dec(y) == x);
	}

	for (x = -10000; x <= 10000; x++)
		assert(dec(enc(x)) == x);

	return 0;
}
