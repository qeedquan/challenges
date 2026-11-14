/*

Definition (from Wikipedia)
A Pythagorean triple consists of three positive integers a, b, and c, such that a² + b² = c².

The typical example of a Pythagorean triple is (3,4,5): 3² + 4² = 9 + 16 = 25 which is 5²

Task:
Given an integer number c, write a program or function that returns the list of pythagorean triples where c is the hypotenuse.

The triples do not need to be primitive.

For example: if c=10, the answer will be [[6,8,10]]

Input:
An integer number, the hypotenuse of the possible triples

Output:
A list of triples, eventually empty. Order is not important, but the list must be duplicate-free ([3,4,5] and [4,3,5] are the same triple, only one must be listed)

Test cases:

5    -> [[3,4,5]]
7    -> []          # Empty
13   -> [[5,12,13]]
25   -> [[7,24,25],[15,20,25]]
65   -> [[16,63,65],[25,60,65],[33,56,65],[39,52,65]]
1105 -> [[47,1104,1105],[105,1100,1105],[169,1092,1105],[264,1073,1105],[272,1071,1105],[425,1020,1105],[468,1001,1105],[520,975,1105],[561,952,1105],[576,943,1105],[663,884,1105],[700,855,1105],[744,817,1105]]

This is code-golf, shortest entry for each language wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
solve(int n, int r[][3])
{
	int a, b, c, d;
	size_t l;

	l = 0;
	d = n * n;
	for (a = 1; a < n; a++) {
		for (b = a + 1; b < n; b++) {
			c = (a * a) + (b * b);
			if (c == d) {
				r[l][0] = a;
				r[l][1] = b;
				r[l][2] = n;
				l += 1;
			}
		}
	}
	return l;
}

void
test(int n, int r[][3], size_t nr)
{
	int p[128][3];
	size_t np;

	np = solve(n, p);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main()
{
	int r1[][3] = {{3, 4, 5}};
	int r2[][3] = {{5, 12, 13}};
	int r3[][3] = {{7, 24, 25}, {15, 20, 25}};
	int r4[][3] = {{16, 63, 65}, {25, 60, 65}, {33, 56, 65}, {39, 52, 65}};
	int r5[][3] = {{47, 1104, 1105}, {105, 1100, 1105}, {169, 1092, 1105}, {264, 1073, 1105}, {272, 1071, 1105}, {425, 1020, 1105}, {468, 1001, 1105}, {520, 975, 1105}, {561, 952, 1105}, {576, 943, 1105}, {663, 884, 1105}, {700, 855, 1105}, {744, 817, 1105}};

	test(5, r1, nelem(r1));
	test(7, NULL, 0);
	test(13, r2, nelem(r2));
	test(25, r3, nelem(r3));
	test(65, r4, nelem(r4));
	test(1105, r5, nelem(r5));

	return 0;
}
