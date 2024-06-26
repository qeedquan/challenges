/*

You are Dastan, the great Prince of Persia!

After searching long for the mysterious 'Sands of Time', you have finally arrived at the gates of the city that hosts the ancient temple of the gods.
However, the gate is locked and it can only be opened with a secret code, which you need to obtain by solving the following puzzle:

There is a table in front of you, with N coins placed in a row and numbered 1 through N from left to right.
For each coin, you know whether it is initially showing heads or tails. You have to perform exactly K operations.
In one operation, you should remove the rightmost coin present on the table, and if this coin was showing heads right before it was removed, then you should also flip all the remaining coins.
(If a coin was showing heads, then after it is flipped, it is showing tails, and vice versa.)

The code needed to enter the temple is the number of coins which, after these K operations are performed, have not been removed and are showing heads.
Can you find this number? The fate of Persia lies in your hands…

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-separated characters. For each valid i, the i-th of these characters is 'H' if the i-th coin is initially showing heads or 'T' if it is showing tails.

Output

For each test case, print a single line containing one integer ― the number of coins that are showing heads after K operations.

Constraints
1≤T≤200
1≤K<N≤100

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
inc(int c, size_t t, size_t *p)
{
	if (c == 'T' && (t & 1))
		(*p)++;
	else if (c == 'H' && !(t & 1))
		(*p)++;
}

size_t
heads(const char *s, size_t k)
{
	size_t i, n, p, r;

	n = strlen(s);
	if (n == 0 || k >= n)
		return 0;

	p = 0;
	for (i = n - 1; i >= n - k; i--)
		inc(s[i], p, &p);

	r = 0;
	for (i = 0; i < n - k; i++)
		inc(s[i], p, &r);

	return r;
}

int
main(void)
{
	assert(heads("HTTHT", 3) == 1);
	assert(heads("HHTTTHH", 4) == 2);
	assert(heads("THTHTT", 1) == 2);

	return 0;
}
