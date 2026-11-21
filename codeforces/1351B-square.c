/*

Vasya claims that he had a paper square. He cut it into two rectangular parts using one vertical or horizontal cut. Then Vasya informed you the dimensions of these two rectangular parts. You need to check whether Vasya originally had a square. In other words, check if it is possible to make a square using two given rectangles.

Input
The first line contains an integer t (1≤t≤10^4) — the number of test cases in the input. Then t test cases follow.

Each test case is given in two lines.

The first line contains two integers a1 and b1 (1≤a1,b1≤100) — the dimensions of the first one obtained after cutting rectangle. The sizes are given in random order (that is, it is not known which of the numbers is the width, and which of the numbers is the length).

The second line contains two integers a2 and b2 (1≤a2,b2≤100) — the dimensions of the second obtained after cutting rectangle. The sizes are given in random order (that is, it is not known which of the numbers is the width, and which of the numbers is the length).

Output
Print t answers, each of which is a string "YES" (in the case of a positive answer) or "NO" (in the case of a negative answer). The letters in words can be printed in any case (upper or lower).

Example

input
3
2 3
3 1
3 2
1 3
3 3
1 3

output
Yes
Yes
No

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

const char *
sf2r(int a1, int b1, int a2, int b2)
{
	if (max(a1, b1) != max(a2, b2))
		return "NO";

	if (min(a1, b1) + min(a2, b2) != max(a1, b1))
		return "NO";

	return "YES";
}

void
test(int a1, int b1, int a2, int b2, const char *r)
{
	const char *p;

	p = sf2r(a1, b1, a2, b2);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test(2, 3, 3, 1, "YES");
	test(3, 2, 1, 3, "YES");
	test(3, 3, 1, 3, "NO");

	return 0;
}
