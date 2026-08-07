/*

Input

Integers a1, a2, a3, b1, b2, b3 each in the range 1 to 20.

Output

True if a1^(a2^a3) > b1^(b2^b3) and False otherwise.
^ is exponentiation in this question.

Rules

This is code-golf. Your code must terminate correctly within 10 seconds for any valid input on a standard desktop PC.

You can output anything Truthy for True and anything Falsey for False.

You can assume any input order you like as long as its specified in the answer and always the same.

For this question your code should always be correct. That is it should not fail because of floating point inaccuracies. Due to the limited range of the input this should not be too hard to achieve.

Test cases

3^(4^5) > 5^(4^3)
1^(2^3) < 3^(2^1)
3^(6^5) < 5^(20^3)
20^(20^20) > 20^(20^19)
20^(20^20) == 20^(20^20)
2^2^20 > 2^20^2
2^3^12 == 8^3^11
1^20^20 == 1^1^1
1^1^1 == 1^20^20

*/

#include <assert.h>
#include <stdbool.h>
#include <math.h>

// Based on @Artemis solution
int
cmp(unsigned a1, unsigned a2, unsigned a3, unsigned b1, unsigned b2, unsigned b3)
{
	double x, y;

	x = log2(a1) * pow(a2, a3);
	y = log2(b1) * pow(b2, b3);
	if (x > y)
		return '>';
	if (x < y)
		return '<';
	return '=';
}

int
main(void)
{
	assert(cmp(3, 4, 5, 5, 4, 3) == '>');
	assert(cmp(1, 2, 3, 3, 2, 1) == '<');
	assert(cmp(3, 6, 5, 5, 20, 3) == '<');
	assert(cmp(20, 20, 20, 20, 20, 19) == '>');
	assert(cmp(20, 20, 20, 20, 20, 20) == '=');
	assert(cmp(2, 2, 20, 2, 20, 2) == '>');
	assert(cmp(2, 3, 12, 8, 3, 11) == '=');
	assert(cmp(1, 20, 20, 1, 1, 1) == '=');
	assert(cmp(1, 1, 1, 1, 20, 20) == '=');
}
