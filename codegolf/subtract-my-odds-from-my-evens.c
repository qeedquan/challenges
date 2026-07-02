/*

Given a non-negative integer, return the absolute difference between the sum of its even digits and the sum of its odd digits.

Default Rules
Standard Loopholes apply.

You can take input and provide output by any standard Input / Output method.

You may take input as a String, as an Integer or as a list of digits.

This is code-golf, so the shortest code in bytes in every language wins!

Test Cases
Input ~> Output

0 ~> 0 (|0-0| = 0)
1 ~> 1 (|1-0| = 1)
12 ~> 1 (|2-1| = 1)
333 ~> 9 (|0-(3+3+3)| = 9)
459 ~> 10 (|4-(5+9)| = 10)
2469 ~> 3 (|(2+4+6)-9| = 3)
1234 ~> 2 (|(2+4)-(1+3)| = 2)

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// https://oeis.org/A071650 (related)
int
subtractive(int number)
{
	int even, odd;

	if (number < 1)
		return 0;

	for (even = odd = 0; number > 0; number /= 10) {
		if (number & 1)
			odd += (number % 10);
		else
			even += (number % 10);
	}
	return abs(even - odd);
}

int
main()
{
	assert(subtractive(0) == 0);
	assert(subtractive(1) == 1);
	assert(subtractive(12) == 1);
	assert(subtractive(333) == 9);
	assert(subtractive(459) == 10);
	assert(subtractive(2469) == 3);
	assert(subtractive(1234) == 2);

	return 0;
}
