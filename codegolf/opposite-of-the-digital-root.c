/*

Also known as the [analog root]

(Opposite of the digital root!) ;)

The digital root of a number is the continuous summation of its digits until it is a single digit, for example, the digital root of 89456 is calculated like this:

8 + 9 + 4 + 5 + 6 = 32

3 + 2 = 5

The digital root of 89456 is 5.

Given a digit as input via STDIN, print/return all of the possible two digit numbers that have that digital root. If you need it to, it can include itself, e.g. 05

These are all of the possible inputs and outputs:

(You get to choose whether or not to include the leading zero for the digit itself)

I/O
0 => 0 or 00 or nothing

1 => 01 and/or 1, 10, 19, 28, 37, 46, 55, 64, 73, 82, 91 - Make sure that 1 does not return 100

2 => 02 and/or 2, 11, 20, 29, 38, 47, 56, 65, 74, 83, 92

3 => 03 and/or 3, 12, 21, 30, 39, 48, 57, 66, 75, 84, 93

4 => 04 and/or 4, 13, 22, 31, 40, 49, 58, 67, 76, 85, 94

5 => 05 and/or 5, 14, 23, 32, 41, 50 ,59, 68, 77, 86, 95

6 => 06 and/or 6, 15, 24, 33, 42, 51, 60, 69, 78, 87, 96

7 => 07 and/or 7, 16, 25, 34, 43, 52, 61, 70, 79, 88, 97

8 => 08 and/or 8, 17, 26, 35, 44, 53, 62, 71, 80, 89, 98

9 => 09 and/or 9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99

No standard loopholes, and it's code-golf, so the shortest answer in bytes wins.

*/

#include <stdio.h>

typedef unsigned long long uvlong;

// https://oeis.org/A010888
uvlong
digroot(uvlong x)
{
	if (x == 0)
		return 0;
	return 1 + ((x - 1) % 9);
}

void
solve(uvlong n)
{
	uvlong i;

	printf("%llu: ", n);
	for (i = 0; i <= 99; i++) {
		if (digroot(i) == n)
			printf("%llu ", i);
	}
	printf("\n");
}

int
main()
{
	uvlong i;

	for (i = 0; i <= 9; i++)
		solve(i);

	return 0;
}
