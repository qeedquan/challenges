/*

This program resembles more complex algorithms for calculation CRC and other checksums and also hash-functions on character strings. Besides it will provide you with one more exercise on splitting values to decimal digits. You may want to try Sum of Digits before this one.

Let us calculate sum of digits, as earlier, but multiplying each digit by its position (counting from the left, starting from 1). For example, given the value 1776 we calculate such weighted sum of digits (let us call it "wsd") as:

wsd(1776) = 1 * 1 + 7 * 2 + 7 * 3 + 6 * 4 = 60
Input data will give the number of test-cases in the first line.
Values themselves are in the second line. For each of these values you are to calculate weighted sum of digits.
Answer: as usually, put results in one line, separating them with spaces.

Example:

input data:
3
9 15 1776

answer:
9 11 60

*/

#include <cassert>

typedef unsigned int uint;

uint diglen(uint n)
{
	uint c = 0;
	do
	{
		c += 1;
		n /= 10;
	} while (n);
	return c;
}

uint wsd(uint n)
{
	uint w = diglen(n);
	uint r = 0;
	while (n > 0)
	{
		r += (n % 10) * w;
		w -= 1;
		n /= 10;
	}
	return r;
}

int main()
{
	assert(wsd(9) == 9);
	assert(wsd(15) == 11);
	assert(wsd(1776) == 60);

	return 0;
}
