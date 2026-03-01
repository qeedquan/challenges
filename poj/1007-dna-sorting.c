/*

Description

One measure of ``unsortedness'' in a sequence is the number of pairs of entries that are out of order with respect to each other. For instance, in the letter sequence ``DAABEC'', this measure is 5, since D is greater than four letters to its right and E is greater than one letter to its right. This measure is called the number of inversions in the sequence. The sequence ``AACEDGG'' has only one inversion (E and D)---it is nearly sorted---while the sequence ``ZWQM'' has 6 inversions (it is as unsorted as can be---exactly the reverse of sorted).

You are responsible for cataloguing a sequence of DNA strings (sequences containing only the four letters A, C, G, and T). However, you want to catalog them, not in alphabetical order, but rather in order of ``sortedness'', from ``most sorted'' to ``least sorted''. All the strings are of the same length.
Input

The first line contains two integers: a positive integer n (0 < n <= 50) giving the length of the strings; and a positive integer m (0 < m <= 100) giving the number of strings. These are followed by m lines, each containing a string of length n.
Output

Output the list of input strings, arranged from ``most sorted'' to ``least sorted''. Since two strings can be equally sorted, then output them according to the orginal order.
Sample Input

10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT
Sample Output

CCCGGGGGGA
AACATGAAGG
GATCAGATTT
ATCGATGCAT
TTTTGGCCAA
TTTGGCCAAA

Source

East Central North America 1998

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dump(const char **s, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%s\n", s[i]);
	printf("\n");
}

size_t
inversions(const char *s)
{
	size_t c, i, j;

	for (c = i = 0; s[i]; i++) {
		for (j = i + 1; s[j]; j++) {
			if (s[i] > s[j])
				c++;
		}
	}
	return c;
}

int
cmp(const void *a, const void *b)
{
	const char *const *s;
	const char *const *t;
	size_t x, y;

	s = a;
	t = b;
	x = inversions(*s);
	y = inversions(*t);
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

void
test(const char **s, size_t n, const char **r)
{
	size_t i;

	qsort(s, n, sizeof(*s), cmp);
	dump(s, n);
	for (i = 0; i < n; i++)
		assert(!strcmp(s[i], r[i]));
}

int
main(void)
{
	const char *s1[] = {
	    "AACATGAAGG",
	    "TTTTGGCCAA",
	    "TTTGGCCAAA",
	    "GATCAGATTT",
	    "CCCGGGGGGA",
	    "ATCGATGCAT",
	};
	const char *r1[] = {
	    "CCCGGGGGGA",
	    "AACATGAAGG",
	    "GATCAGATTT",
	    "ATCGATGCAT",
	    "TTTTGGCCAA",
	    "TTTGGCCAAA",
	};

	test(s1, nelem(s1), r1);

	return 0;
}
