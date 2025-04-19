/*

I think most people around here know what a 7-segment display for digits is:

 _         _   _         _    _    _    _    _
| |    |   _|  _|  |_|  |_   |_     |  |_|  |_|
|_|    |  |_   _|    |   _|  |_|    |  |_|   _|

We can define the 7-segment difference (7SD) between two digits to be the number of segments that need to be toggled to switch from one to the other. E.g. the 7SD between 1 and 2 is 5 (the three horizontal segments and the lower two vertical segments need to be toggled), and the 7SD between 6 and 8 is 1.

Furthermore, we can define the 7SD between two numbers to be the sum of 7SDs between their corresponding digits. If one number is longer than the other, we assume they are right-aligned and add the number of segments needed to display the additional most-significant digits of the larger number. As an example, consider the 7SD between 12345 and 549:

  x:  1 2 3 4 5
  y:      5 4 9
7SD:  2+5+2+0+1 = 10
Your task is to compute 7SD between n and n+1, given n.

For convenience, here is the full table of 7SDs between individual digits. The row _ represents an empty position.

   _ 0 1 2 3 4 5 6 7 8 9

_  0 6 2 5 5 4 5 6 3 7 6
0  6 0 4 3 3 4 3 2 3 1 2
1  2 4 0 5 3 2 5 6 1 5 4
2  5 3 5 0 2 5 4 3 4 2 3
3  5 3 3 2 0 3 2 3 2 2 1
4  4 4 2 5 3 0 3 4 3 3 2
5  5 3 5 4 2 3 0 1 4 2 1
6  6 2 6 3 3 4 1 0 5 1 2
7  3 3 1 4 2 3 4 5 0 4 3
8  7 1 5 2 2 3 2 1 4 0 1
9  6 2 4 3 1 2 1 2 3 1 0

Input
Input is a single positive integer n.
You may write a program or function, taking input via STDIN (or closest alternative), command-line argument or function argument.
You may assume that the input is at most one less than the largest number which can be represented by your language's standard integer type, as long as that type supports at least values up to and including 127.

Output
You should print a single integer, the 7SD between n and n+1.
You may output via STDOUT (or closest alternative), function return value or function (out) argument.

Scoring
Standard code-golf rules apply, shortest code (in bytes) wins.

Test Cases
For some obscure reason, this sequence isn't in OEIS yet, although there is the closely related sequence A123587. Here are the first 100 numbers (starting with n = 1, 2, 3, ...):

5, 2, 3, 3, 1, 5, 4, 1, 4, 4, 5, 2, 3, 3, 1, 5, 4, 1, 7, 4, 5, 2, 3, 3, 1,
5, 4, 1, 4, 4, 5, 2, 3, 3, 1, 5, 4, 1, 5, 4, 5, 2, 3, 3, 1, 5, 4, 1, 5, 4,
5, 2, 3, 3, 1, 5, 4, 1, 3, 4, 5, 2, 3, 3, 1, 5, 4, 1, 7, 4, 5, 2, 3, 3, 1,
5, 4, 1, 6, 4, 5, 2, 3, 3, 1, 5, 4, 1, 3, 4, 5, 2, 3, 3, 1, 5, 4, 1, 6, 4
The first input for which the 7SD is greater than 9 is 1999 which should yield 11. Here are some other larger examples:

n          7SD
1999        11
12345        1
999999      14
5699999     15
8765210248   1

*/

#include <assert.h>

typedef unsigned long long uvlong;

/*

@xsot

Explanation
This function operates on the least significant digit of the number n, summing the 7SD of the digits when incremented by one until after the first non-9 digit.

26523308 is a bitmask that encodes the mapping for the digits 0-8. When n=0, which only occurs when n comprises only 9s, the answer will be off by two.
This is compensated by the expression 0**n*2. As for the digit 9, the bitmask evaluates to zero which will trigger the recursive call while adding 2 to the 7SD.

*/

uvlong
sd7(uvlong n)
{
	uvlong r;

	if (n == 0)
		return 2;

	r = (26523308 >> ((n % 10) * 3)) & 7;
	if (r)
		return r;

	return sd7(n / 10) + 2;
}

int
main(void)
{
	assert(sd7(1999) == 11);
	assert(sd7(12345) == 1);
	assert(sd7(999999) == 14);
	assert(sd7(5699999) == 15);
	assert(sd7(8765210248) == 1);

	return 0;
}
