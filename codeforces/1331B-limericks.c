/*

There was once young lass called Mary,
Whose jokes were occasionally scary.
On this April's Fool
Fixed limerick rules
Allowed her to trip the unwary.

Can she fill all the lines
To work at all times?
On juggling the words
Right around two-thirds
She nearly ran out of rhymes.

Input
The input contains a single integer a (4≤a≤998). Not every integer in the range is a valid input for the problem; you are guaranteed that the input will be a valid integer.

Output
Output a single number.

Examples
input
35
output
57

input
57
output
319

input
391
output
1723

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
limericks(int n, char *b)
{
	size_t l;
	int i;

	*b = '\0';
	l = 0;
	for (i = 2; i <= n; i++) {
		while (n % i == 0) {
			l += sprintf(b + l, "%d", i);
			n /= i;
		}
	}
	return b;
}

void
test(int n, const char *r)
{
	char b[128];

	limericks(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(35, "57");
	test(57, "319");
	test(391, "1723");

	return 0;
}
