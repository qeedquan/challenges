/*

Every Turkish citizen has an identity number whose validity can be checked by these set of rules:

It is an 11 digit number
First digit can't be zero
Take the sum of 1st, 3rd, 5th, 7th and 9th digit and multiply it by 7. Then subtract the sum of 2nd, 4th, 6th and 8th digits from this value. Modulus 10 of the result should be equal to 10th digit.
Sum of first ten digits' modulus 10 should be equal to eleventh digit.
Example:

10167994524
//  1+1+7+9+5= 23   // "Take the sum of 1st, 3rd, 5th, 7th and 9th digit..."
//    23 * 7= 161   //  "...and multiply it by 7"
//   0+6+9+4 = 19   // "Take the sum of 2nd, 4th, 6th and 8th digits..."
// 161 - 19 = 142   // "...and subtract from first value"
// "Modulus 10 of the result should be equal to 10th digit"
10167994524
         ^ = 2 = 142 % 10
// 1+0+1+6+7+9+9+4+5+2 = 44
// "Sum of first ten digits' modulus 10 should be equal to eleventh digit"
10167994524
          ^ = 4 = 44 % 10
Your task is to write a function to check the validity of a given number. Return true or false accordingly.

Note: The input can be a string in some cases.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef long long vlong;

bool
valid(vlong n)
{
	char b[16];
	vlong s0, s1;
	vlong i;

	if (n < 0)
		return false;

	if (snprintf(b, sizeof(b), "%lld", n) != 11)
		return false;

	for (i = 0; i < 11; i++)
		b[i] -= '0';

	s0 = 0;
	for (i = 0; i <= 8; i += 2)
		s0 += b[i];
	s0 *= 7;
	for (i = 1; i <= 7; i += 2)
		s0 -= b[i];
	s0 %= 10;

	s1 = 0;
	for (i = 0; i < 10; i++)
		s1 += b[i];
	s1 %= 10;

	return s0 == b[9] && s1 == b[10];
}

int
main()
{
	assert(valid(10167994524) == true);
	assert(valid(6923522112) == false);
	assert(valid(692352217312) == false);
	assert(valid(36637640050) == true);
	assert(valid(12762438338) == false);

	return 0;
}
