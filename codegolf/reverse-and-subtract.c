/*

Challenge description
Let's take a positive integer n, reverse its digits to get rev(n) and get the absolute value of the difference of these two numbers: |n - rev(n)| (or abs(n - rev(n))).

Example:

n = 5067
rev(n) = 7605
|n - rev(n)| = |5067 - 7605| = |-2538| = 2538
After repeating this operation sufficiently many times, most numbers will become 0 (thus terminating the loop)...

5067 -> 2538 -> 5814 -> 1629 -> 7632 -> 5265 -> 360 -> 297 -> 495 -> 99 -> 0
...though some numbers (like 1584) get stuck in an infinite loop:

1584 -> 3267 -> 4356 -> 2178 -> 6534 -> 2178 -> 6534 -> 2178 -> 6534 -> ...
                        ^ infinite loop starts here
Your job is to determine if a given integer gets stuck in an infinite loop.

Input description
A positive integer.

Output description
A truthy value (True, 1) if the number gets stuck in an infinite loop, a falsy value (False, 0) otherwise.

Notes
Trailing zeroes should be ommited. i.e. rev(5020) = 205.
Remember that this is code-golf, so make your code as short as possible!
Relevant sequence: A072140

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long vlong;

vlong
rev(vlong n)
{
	vlong r;

	for (r = 0; n > 0; n /= 10)
		r = (r * 10) + (n % 10);
	return r;
}

/*

https://oeis.org/A072140

@Dennis

Background
This uses @MartinEnder's upper bound of 10n iterations and the following observations.

There are 9 × 10k - 1 positive integers n with k digits.

The difference of a number and its reverse is always a multiple of 9, so only 10k - 1 of them can occur after the first iteration.

Of the multiples, more than 1 / 10 will lose a digit in the next iteration (for starters, all that start and end with the same digits, and roughly twice as many if the first digit is neither a 1 nor a 9), so it takes at most 9 × 10k - 2 to either enter a loop or lose a digit.

Applying the same reasoning to the eventual resulting integer of k - 1 digits and so on, it takes at most 9 × 10k - 2 + 9 × 10k - 2 + … ≤ 10k - 1 ≤ n iterations to enter a loop or reach 0.

@MartinEnder
Simply applies the reverse/subtract transformation n times to the input n and then checks whether the result is 0.
It can never take more than 10n steps to reach a loop, because the transformation cannot increase the number of digits,
and there are less than 10n numbers with no more digits than n.

*/

bool
loop(vlong n)
{
	vlong i, r;

	r = n;
	for (i = 0; r > 0 && i < n; i++)
		r = llabs(r - rev(r));
	return r == 0;
}

int
main()
{
	assert(loop(5067) == true);
	assert(loop(1584) == false);

	return 0;
}
