/*

You are given a 0-indexed string word of length n consisting of digits, and a positive integer m.

The divisibility array div of word is an integer array of length n such that:

div[i] = 1 if the numeric value of word[0,...,i] is divisible by m, or
div[i] = 0 otherwise.
Return the divisibility array of word.

Example 1:

Input: word = "998244353", m = 3
Output: [1,1,0,0,0,1,1,0,0]
Explanation: There are only 4 prefixes that are divisible by 3: "9", "99", "998244", and "9982443".

Example 2:

Input: word = "1010", m = 10
Output: [0,1,0,1]
Explanation: There are only 2 prefixes that are divisible by 10: "10", and "1010".

Constraints:

1 <= n <= 10^5
word.length == n
word consists of digits from 0 to 9
1 <= m <= 10^9

Hint 1
We can check if the numeric value of the prefix of the given string is divisible by m by computing the remainder of the numeric value of the prefix when divided by m.

Hint 2
The remainder of the numeric value of a prefix ending at index i can be computed from the remainder of the prefix ending at index i-1.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
divarr(const char *s, int m, int *r)
{
	size_t n;
	int c;

	n = 0;
	for (c = 0; *s; s++) {
		c = ((c * 10) + (*s - '0')) % m;
		r[n++] = (c == 0);
	}
	return n;
}

void
test(const char *s, int m, int *r, size_t nr)
{
	int p[16];
	size_t np;

	np = divarr(s, m, p);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main()
{
	int r1[] = { 1, 1, 0, 0, 0, 1, 1, 0, 0 };
	int r2[] = { 0, 1, 0, 1 };

	test("998244353", 3, r1, nelem(r1));
	test("1010", 10, r2, nelem(r2));

	return 0;
}
