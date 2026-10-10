/*

Write a program to compute the remainder when a given large number is divided by a specified digit.

Input
The first line contains the digit K (1≤K≤9). The second line contains a natural number N, which can have up to 255 digits.

Output
Print the remainder of the division of N by K.

Examples

Input #1
5
123456789

Answer #1
4

*/

#include <assert.h>
#include <stdio.h>

int
solve(const char *s, int k)
{
	int r;

	if (k == 0)
		return 0;

	for (r = 0; *s; s++)
		r = (r * 10 + (*s - '0')) % k;
	return r;
}

int
main()
{
	char s[80];
	int n, k;

	assert(solve("123456789", 5) == 4);

	for (n = 0; n <= 16000; n++) {
		for (k = 1; k <= 9; k++) {
			snprintf(s, sizeof(s), "%d", n);
			assert(solve(s, k) == n % k);
		}
	}

	return 0;
}
