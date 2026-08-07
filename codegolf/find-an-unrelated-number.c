/*

Given 2 non-negative integers as input, output a non-negative integer that cannot be created through any mathematical operators on the 2 inputs.

For example, given inputs 2 and 3, 6, 0, 5, 1, 9, 8, 23, 2 are all invalid outputs.

Operations that must be taken into account are:

Addition        (a + b)
Subtraction     (a - b) and (b - a)
Multiplication  (a * b)
Division        (a / b) and (b / a)
Modulus         (a % b) and (b % a)
Exponentiation  (a ** b) and (b ** a)
Bitwise OR      (a | b)
Bitwise XOR     (a ^ b)
Bitwise AND     (a & b)
Concatenation   (a.toString() + b.toString()) and (b.toString() + a.toString())
In cases where an operation would lead to a non-integer (such as 2 / 3), always floor. So 2 / 3 = 0

Assume any invalid operations (such as dividing by 0) result in 0.

Input
2 non-negative integers.

Standard I/O methods are accepted

You can assume the input will always be within a handleable range for your given language, however remember standard loopholes still apply.

Output
Any non-negative integer that can not be created via any of the above operations on the 2 inputs.

Testcases
Input  -> Invalid outputs
2, 3   -> 0, 1, 2, 3, 5, 6, 8, 9, 23, 32
0, 0   -> 0
17, 46 -> 0, 2, 12, 17, 29, 63, 782, 1746, 4617, 18487710785295216663082172416, 398703807810572411498315063055075847178723756123452198369
6, 6   -> 0, 1, 6, 12, 36, 66, 46656
1, 1   -> 0, 1, 2, 11

Scoring
This is code-golf so fewest bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

/*

@Leo

Proof of correctness
Courtesy of Martin Ender

This operation computes a result with one more digit than the number of digits of the two numbers together; the only operation that could produce a result so big is exponentiation.

The result is a repunit (a number whose digits are all 1).

"It is know [sic] [...] that a repunit in base 10 cannot [...] be a perfect power." This means that this result can't be produced by exponentiation either.
https://mathoverflow.net/questions/132011/can-repunits-be-perfect-cubes/132025

*/

long
unrelate(long a, long b)
{
	char s[128];
	size_t i;

	snprintf(s, sizeof(s), "%ld%ld1", a, b);
	for (i = 0; s[i]; i++) {
		if (isdigit(s[i]))
			s[i] = '1';
	}
	return strtol(s, NULL, 10);
}

void
test(long a, long b)
{
	char s[128];
	long v;

	v = unrelate(a, b);
	printf("%ld\n", v);

	assert((a + b) != v);
	assert((a - b) != v);
	assert((b - a) != v);
	assert((a * b) != v);

	if (b) {
		assert((a / b) != v);
		assert((a % b) != v);
	}

	if (a) {
		assert((b / a) != v);
		assert((b % a) != v);
	}

	assert((a & b) != v);
	assert((a | b) != v);
	assert((a ^ b) != v);

	assert(pow(a, b) != v);
	assert(pow(b, a) != v);

	snprintf(s, sizeof(s), "%ld%ld", a, b);
	assert(strtol(s, NULL, 10) != v);

	snprintf(s, sizeof(s), "%ld%ld", b, a);
	assert(strtol(s, NULL, 10) != v);
}

int
main(void)
{
	test(2, 3);
	test(0, 0);
	test(17, 46);
	test(6, 6);
	test(1, 1);

	return 0;
}
