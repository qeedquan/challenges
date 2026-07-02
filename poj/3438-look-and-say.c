/*

Description

The look and say sequence is defined as follows. Start with any string of digits as the first element in the sequence. Each subsequent element is defined from the previous one by "verbally" describing the previous element. For example, the string 122344111 can be described as "one 1, two 2's, one 3, two 4's, three 1's". Therefore, the element that comes after 122344111 in the sequence is 1122132431. Similarly, the string 101 comes after 1111111111. Notice that it is generally not possible to uniquely identify the previous element of a particular element. For example, a string of 112213243 1's also yields 1122132431 as the next element.

Input

The input consists of a number of cases. The first line gives the number of cases to follow. Each case consists of a line of up to 1000 digits.

Output

For each test case, print the string that follows the given string.

Sample Input

3
122344111
1111111111
12345

Sample Output

1122132431
101
1112131415

Source

Rocky Mountain 2007

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
looksay(const char *s, char *b)
{
	size_t i, j, l;

	for (i = l = 0; s[i]; i = j) {
		j = i + 1;
		while (s[i] == s[j])
			j++;

		l += sprintf(b + l, "%zu%c", j - i, s[i]);
	}
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	looksay(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("122344111", "1122132431");
	test("1111111111", "101");
	test("12345", "1112131415");

	return 0;
}
