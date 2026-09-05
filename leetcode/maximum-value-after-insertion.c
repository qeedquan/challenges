/*

You are given a very large integer n, represented as a string, and an integer digit x. The digits in n and the digit x are in the inclusive range [1, 9], and n may represent a negative number.

You want to maximize n's numerical value by inserting x anywhere in the decimal representation of n. You cannot insert x to the left of the negative sign.

For example, if n = 73 and x = 6, it would be best to insert it between 7 and 3, making n = 763.
If n = -55 and x = 2, it would be best to insert it before the first 5, making n = -255.
Return a string representing the maximum value of n after the insertion.

Example 1:

Input: n = "99", x = 9
Output: "999"
Explanation: The result is the same regardless of where you insert 9.
Example 2:

Input: n = "-13", x = 2
Output: "-123"
Explanation: You can make n one of {-213, -123, -132}, and the largest of those three is -123.


Constraints:

1 <= n.length <= 10^5
1 <= x <= 9
The digits in n are in the range [1, 9].
n is a valid representation of an integer.
In the case of a negative n, it will begin with '-'.

Hint 1
Note that if the number is negative it's the same as positive but you look for the minimum instead.

Hint 2
In the case of maximum, if s[i] < x it's optimal that x is put before s[i].

Hint 3
In the case of minimum, if s[i] > x it's optimal that x is put before s[i].

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
maxvalue(const char *number, int digit, char *output)
{
	size_t index;
	bool negative;
	int current;

	negative = false;
	index = 0;
	if (number[0] == '-') {
		negative = true;
		index = 1;
	}

	for (; number[index]; index++) {
		current = number[index] - '0';
		if (negative) {
			if (current > digit)
				break;
		} else {
			if (current < digit)
				break;
		}
	}

	memcpy(output, number, index);
	sprintf(output + index, "%d%s", digit, number + index);
}

void
test(const char *number, int digit, const char *expected)
{
	char output[16];

	maxvalue(number, digit, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("73", 6, "763");
	test("-55", 2, "-255");
	test("99", 9, "999");
	test("-13", 2, "-123");

	return 0;
}
