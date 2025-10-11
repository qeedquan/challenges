/*

The reverse-then-add (RTA) sequence is a sequence obtained by adding a number to its reverse, and repeating the process on the result. For eg.,

5+5=10 -> 10+01=11 -> 11+11=22 -> 22+22=44 -> ...

Thus, 5's RTA sequence contains 10, 11, 22, 44, 88, 176, etc.

The RTA root of a number n
 is the smallest number that is either equal to n
 or gives raise to n
 in its RTA sequence.

For eg., 44 is found in the RTA sequence of 5, 10, 11, 13, 22, 31, etc. Of these, 5 is the smallest, and hence RTAroot(44) = 5.

72 is not part of any number's RTA sequence, and so is considered its own RTA root.

Input is a positive integer in a range that your language can naturally handle.

Output is the RTA root of the given number, as defined above.

Test cases
Input
Output

44
5

72
72

132
3

143
49

1111
1

999
999

Related OEIS: A067031. The output will be a number from this sequence.

*/

#include <assert.h>

int
rta(int n)
{
	int a, b, c, d, r;

	r = n;
	for (a = n; a > 0; a--) {
		for (b = a; b < n; b += c) {
			c = 0;
			for (d = b; d > 0; d /= 10)
				c = (c * 10) + (d % 10);
		}
		r = (n / b) ? a : r;
	}
	return r;
}

int
main(void)
{
	assert(rta(44) == 5);
	assert(rta(72) == 72);
	assert(rta(132) == 3);
	assert(rta(143) == 49);
	assert(rta(1111) == 1);
	assert(rta(999) == 999);

	return 0;
}
