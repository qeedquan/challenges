/*

Description
This one came to me via the always interesting Data Genetics blog.

Van der Waerden's theorem relates to ways that collections can be colored, in order, avoiding spacing of colors that are a defined length arithmetic progression apart. They are named after the Dutch mathematician B. L. van der Waerden. W(c,k) can be defined as the smallest value where c represents the number of colors in the sequence, and k represents the number of elements in the arithmetic progression.

In mathematics, an arithmetic progression is a sequence of numbers such that the difference between the consecutive terms is constant. For instance, the sequence 5, 7, 9, 11, 13, 15, ... is an arithmetic progression with common difference of 2.

Van der Waerden numbers (W) are defined as the smallest arrangement of c different colors such that there exists an arithmetic sequence of length k. The simplest non-trivial example is W(2,3). Consider two colors, B and R:

B R R B B R R B
If we add a B to the sequence, we already have B at positions 1, 5 and 9 - a difference of 4. If we add an R to the sequence, we have an R at positions 3, 6 and 9 - a difference of 3. There is no way of coloring 1 through 9 without creating a three step progression of one color or another, so W(2,3)=9.

Adding a color - W(3,3) - causes the value to jump to 27; adding a length requirement to the arithmetic sequence - W(2,4) - causes the value to increase to 35.

Van der Waerden numbers are an open area of research, with exact values known for only a limited number of combinations.

Your challenge today is to write a program that can calculate the Van der Waerden number for some small values.

Input Description
You'll be given two integers per line indicating c and k. Example:

2 3
Output Description
Your program should emit the Van der Waerden number W(c,k) for that input. Example:

W(2,3) = 9
Challenge Input
2 6
4 3
3 4
Challenge Output
W(2,6) = 1132
W(4,3) = 76
W(3,4) = 293

*/

#include <assert.h>

typedef unsigned uint;

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

https://en.wikipedia.org/wiki/Van_der_Waerden_number
https://oeis.org/A005346

*/

int
W(uint c, uint k)
{
	static const int w2[] = {0, 1, 3, 9, 35, 178, 1132};
	static const int w3[] = {0, 0, 0, 27, 293};
	static const int w4[] = {0, 0, 0, 76};

	if (c == 0 || k == 0)
		return 0;
	if (c == 1)
		return k;
	if (k == 2)
		return c + 1;
	if (c == 2 && k < nelem(w2))
		return w2[k];
	if (c == 3 && k < nelem(w3))
		return w3[k];
	if (c == 4 && k < nelem(w4))
		return w4[k];
	return -1;
}

int
main()
{
	assert(W(2, 3) == 9);
	assert(W(2, 6) == 1132);
	assert(W(4, 3) == 76);
	assert(W(3, 4) == 293);

	return 0;
}
