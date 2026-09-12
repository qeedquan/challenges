/*

Every positive integer can be expressed as the sum of at most three palindromic positive integers in any base b≥5.   Cilleruelo et al., 2017

A positive integer is palindromic in a given base if its representation in that base, without leading zeros, reads the same backwards. In the following, only base b=10 will be considered.

The decomposition as a sum of palindromic numbers is not unique. For example, 5 can be expressed directly as 5, or as the sum of 2, 3. Similarly, 132 can be decomposed as 44, 44, 44 or as 121, 11.

The challenge
Given a positive integer, produce its sum decomposition into three or fewer positive integers that are palindromic in base 10.

Additional rules
The algorithm used should work for arbitrarily large inputs. However, it is acceptable if the program is limited by memory, time or data type restrictions.

Input and output can be taken by any reasonable means. Input and output format is flexible as usual.

You can choose to produce one or more valid decompositions for each input, as long as the output format is unambiguous.

Programs or functions are allowed, in any programming language. Standard loopholes are forbidden.

Shortest code in bytes wins.

Examples
Since an input can have many decompositions, these are examples rather than test cases. Each decomposition is shown on a different line.

Input  ->  Output

5     ->   5
           2, 3

15    ->   1, 3, 11
           9, 6

21    ->   11, 9, 1
           7, 7, 7

42    ->   22, 11, 9
           2, 7, 33

132   ->   44, 44, 44
           121, 11

345   ->   202, 44, 99
           2, 343

1022  ->   989, 33
           999, 22, 1

9265  ->   9229, 33, 3
           8338, 828, 99

*/

#include <stdio.h>
#include <limits.h>

bool
ispal(int n)
{
	int d[sizeof(n) * CHAR_BIT];
	int i, l;

	if (n < 0)
		return false;

	l = 0;
	do {
		d[l++] = n % 10;
		n /= 10;
	} while (n > 0);

	for (i = 0; i < l / 2; i++) {
		if (d[i] != d[l - i - 1])
			return false;
	}
	return true;
}

void
yoboysum(int n)
{
	int x, y, z;

	for (x = 0; x <= n; x++) {
		if (!ispal(x))
			continue;

		for (y = 0; y < n; y++) {
			if (!ispal(y))
				continue;
			if (x + y > n)
				break;

			for (z = 0; z < n; z++) {
				if (!ispal(z))
					continue;
				if (x + y + z > n)
					break;

				if (x + y + z == n)
					printf("%d %d %d\n", x, y, z);
			}
		}
	}
	printf("\n");
}

int
main()
{
	yoboysum(0);
	yoboysum(5);
	yoboysum(15);
	yoboysum(21);
	yoboysum(42);
	yoboysum(132);
	yoboysum(345);
	yoboysum(1022);
	yoboysum(9265);
	return 0;
}
