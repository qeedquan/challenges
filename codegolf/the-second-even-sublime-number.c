/*

A perfect number is a positive integer whose sum of divisors (except itself) is equal to itself. E.g. 6 (1 + 2 + 3 = 6) and 28 (1 + 2 + 4 + 7 + 14 = 28) are perfect.

A sublime number (OEIS A081357) is a positive integer whose count and sum of divisors (including itself) are both perfect. E.g. 12 is a sublime number because:

the divisors of 12 are 1, 2, 3, 4, 6, 12
the count of divisors is 6 (perfect)
the sum of divisors is 28 (perfect)
The next smallest known sublime number is

6086555670238378989670371734243169622657830773351885970528324860512791691264
which is a product of a power of 2 and six Mersenne primes

2^126 * (2^3 - 1) * (2^5 - 1) * (2^7 - 1) * (2^19 - 1) * (2^31 - 1) * (2^61 - 1)

These two numbers are the only known sublime numbers as of 2022. The necessary and sufficient conditions for even sublime numbers have been found in this paper (pdf), but it remains unknown whether odd sublime numbers exist.

It is known that there are no other even sublime numbers before the number, but it is not known whether there are any odd ones.

Task
Output the second even sublime number shown above. It is OK to only theoretically output this number in the following ways:

the program outputs the correct number with probability 1 in finite time
the program outputs the correct number given enough time and unlimited memory
the program would output the correct number if the native number type had infinite precision
Standard code-golf rules apply. The shortest code in bytes wins.

*/

#include <stdio.h>

// https://oeis.org/A081357
void
sublime(void)
{
	puts("6086555670238378989670371734243169622657830773351885970528324860512791691264");
}

int
main(void)
{
	sublime();
	return 0;
}
