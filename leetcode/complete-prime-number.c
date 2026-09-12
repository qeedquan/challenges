/*

You are given an integer num.

A number num is called a Complete Prime Number if every prefix and every suffix of num is prime.

Return true if num is a Complete Prime Number, otherwise return false.

Note:

A prefix of a number is formed by the first k digits of the number.
A suffix of a number is formed by the last k digits of the number.
Single-digit numbers are considered Complete Prime Numbers only if they are prime.


Example 1:

Input: num = 23

Output: true

Explanation:

Prefixes of num = 23 are 2 and 23, both are prime.
Suffixes of num = 23 are 3 and 23, both are prime.
All prefixes and suffixes are prime, so 23 is a Complete Prime Number and the answer is true.
Example 2:

Input: num = 39

Output: false

Explanation:

Prefixes of num = 39 are 3 and 39. 3 is prime, but 39 is not prime.
Suffixes of num = 39 are 9 and 39. Both 9 and 39 are not prime.
At least one prefix or suffix is not prime, so 39 is not a Complete Prime Number and the answer is false.
Example 3:

Input: num = 7

Output: true

Explanation:

7 is prime, so all its prefixes and suffixes are prime and the answer is true.

Constraints:

1 <= num <= 10^9

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A020994
bool
completeprime(long n)
{
	static const long tab[] = {
		2, 3, 5, 7, 23, 37, 53, 73, 313, 317, 373, 797, 3137, 3797, 739397
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (n < tab[i])
			break;
		if (n == tab[i])
			return true;
	}
	return false;
}

int
main()
{
	assert(completeprime(23) == true);
	assert(completeprime(39) == false);
	assert(completeprime(7) == true);
	assert(completeprime(739397) == true);

	return 0;
}
