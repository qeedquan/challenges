/*

Inspired by this question by @CᴏɴᴏʀO'Bʀɪᴇɴ.

Taken from the question:

Your task is simple: given two integers a and b, output ∏[a,b]; that is, the product of the range between a and b. You may take a and b in any reasonable format, whether that be arguments to a function, a list input, STDIN, et cetera. You may output in any reasonable format, such as a return value (for functions) or STDOUT. a will always be less than b.

Note that the end may be exclusive or inclusive of b. I'm not picky. ^_^

The difference for this challenge is we are going to be picky about the range type. Input is a string of the form [a,b], (a,b], [a,b), or (a,b) where a [] is an inclusive boundary and () is an exclusive boundary. Given the explicit boundaries, provide the product of the range. Also the input range will always include at least 1 number, meaning ranges like (3,4) are invalid and need not be tested.

Test cases
[a,b) => result
[2,5) => 24
[5,10) => 15120
[-4,3) => 0
[0,3) => 0
[-4,0) => 24

[a,b] => result
[2,5] => 120
[5,10] => 151200
[-4,3] => 0
[0,3] => 0
[-4,-1] => 24

(a,b] => result
(2,5] => 60
(5,10] => 30240
(-4,3] => 0
(0,3] => 6
(-4,-1] => -6

(a,b) => result
(2,5) => 12
(5,10) => 3024
(-4,3) => 0
(0,3) => 2
(-4,0) => -6

This is a code-golf, so the shortest program in bytes wins.

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

vlong
solve(const char *s)
{
	char c1, c2;
	vlong n1, n2;
	vlong n, r;

	if (sscanf(s, "%c%lld,%lld%c", &c1, &n1, &n2, &c2) != 4)
		return 0;

	switch (c1) {
	case '[':
		break;
	case '(':
		n1 += 1;
		break;
	default:
		return 0;
	}

	switch (c2) {
	case ']':
		break;
	case ')':
		n2 -= 1;
		break;
	default:
		return 0;
	}

	r = 1;
	for (n = n1; n <= n2; n++)
		r *= n;
	return r;
}

int
main()
{
	assert(solve("[2,5)") == 24);
	assert(solve("[5,10)") == 15120);
	assert(solve("[-4,3)") == 0);
	assert(solve("[0,3)") == 0);
	assert(solve("[-4,0)") == 24);

	assert(solve("[2,5]") == 120);
	assert(solve("[5,10]") == 151200);
	assert(solve("[-4,3]") == 0);
	assert(solve("[0,3]") == 0);
	assert(solve("[-4,-1]") == 24);

	assert(solve("(2,5]") == 60);
	assert(solve("(5,10]") == 30240);
	assert(solve("(-4,3]") == 0);
	assert(solve("(0,3]") == 6);
	assert(solve("(-4,-1]") == -6);

	assert(solve("(2,5)") == 12);
	assert(solve("(5,10)") == 3024);
	assert(solve("(-4,3)") == 0);
	assert(solve("(0,3)") == 2);
	assert(solve("(-4,0)") == -6);

	return 0;
}
