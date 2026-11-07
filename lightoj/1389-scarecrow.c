/*

Taso owns a very long field. He plans to grow different types of crops in the upcoming growing season. The area, however, is full of crows and Taso fears that they might feed on most of the crops. For this reason, he has decided to place some scarecrows at different locations of the field.

The field can be modeled as a 1 x N grid. Some parts of the field are infertile and that means you cannot grow any crops on them. A scarecrow, when placed on a spot, covers the cell to its immediate left and right along with the cell it is on. Given the description of the field, what is the minimum number of scarecrows that needs to be placed so that all the useful section of the field is covered? Useful section refers to cells where crops can be grown.

Input
Input starts with an integer T (≤ 50), denoting the number of test cases.

Each case starts with a line containing an integer N (0 < N < 100). The next line contains N characters that describe the field. A dot . indicates a crop-growing spot and a hash # indicates an infertile region.

Output
For each case, print the case number and the number of scarecrows that need to be placed.

Sample
Input	Output
3
3
.#.
11
...##....##
2
##

Case 1: 1
Case 2: 3
Case 3: 0

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
solve(const char *s)
{
	size_t c, i, n;

	n = strlen(s);
	for (c = i = 0; i < n; i++) {
		if (s[i] == '.') {
			i += 2;
			c += 1;
		}
	}
	return c;
}

int
main()
{
	assert(solve(".#.") == 1);
	assert(solve("...##....##") == 3);
	assert(solve("##") == 0);

	return 0;
}
