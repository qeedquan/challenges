/*

The crazy mathematician owns a wide collection of numbers, and therefore the space he has left is quite limited.
To save some, he must fold his integers, but unfortunately he is really lazy.
Your task, if you wish to help him, is to create a function / program that folds a given positive integer for our number maniac.

How to fold an integer?
If it is evenly divisible by the sum of its digits, divide it by the sum of its digits.
If it doesn't meet that requirement, take its remainder when divided by the sum of its digits.
Repeat the process until the result reaches 1.
The folded integer is the number of operations you had to perform. Let's take an example (say 1782):

Get the sum of its digits: 1 + 7 + 8 + 2 = 18. 1782 is evenly divisible by 18, so the next number is 1782 / 18 = 99.

99 is not evenly divisible by 9 + 9 = 18, hence we take the remainder: 99 % 18 = 9.

9 is obviously divisible by 9, so we divide it and obtain 1.

The result is 3, because 3 operations were required in order to reach 1.

Rules and Specs
Some integers might have the sum of digits equal to 1, such as 10 or 100.
Your program doesn't need to handle such cases.
That means, you will be guaranteed that the integer given as input doesn't have the sum of digits equal to 1, and no operation with the given integer will result in a number whose sum of digits is 1 (except for 1 itself, which is the "target").
For example, you will never receive 10 or 20 as input.

The input will be a positive integer higher than 1.

Default Loopholes apply.

You can take input and provide output by any standard mean.

Test Cases
Input     -> Output

2         -> 1
5         -> 1
9         -> 1
18        -> 2
72        -> 2
152790    -> 2
152       -> 3
666       -> 3
777       -> 3
2010      -> 3
898786854 -> 4

Here is a program that lets you visualize the process and try more test cases.

This is code-golf, so the shortest code in each language (scored in bytes) wins!

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

vlong
fold(vlong n)
{
	vlong i, k, l;

	for (i = 0; n > 1; i++) {
		l = n;
		for (k = 0; l > 0; l /= 10)
			k += l % 10;

		if (k == 1)
			return -1;

		if (n % k)
			n %= k;
		else
			n /= k;
	}
	return i;
}

int
main(void)
{
	assert(fold(2) == 1);
	assert(fold(5) == 1);
	assert(fold(9) == 1);
	assert(fold(18) == 2);
	assert(fold(72) == 2);
	assert(fold(152790LL) == 2);
	assert(fold(152) == 3);
	assert(fold(666) == 3);
	assert(fold(777) == 3);
	assert(fold(2010) == 3);
	assert(fold(898786854LL) == 4);

	return 0;
}
