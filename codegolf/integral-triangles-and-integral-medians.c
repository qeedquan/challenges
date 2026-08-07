/*

Consider a triangle ABC where each side has integer length (an integral triangle). Define a median of ABC to be a line segment from a vertex to the midpoint of the opposing side. In the figure below, the red line segments represent the medians. Note that any given triangle has three medians.

https://i.stack.imgur.com/vqkWu.png

Let n be some positive integer. How many non-degenerate integral triangles with each side length less than or equal to n have at least one integral median?

Challenge
Write a program to compute the number of integral triangles with at least one integral median for a given maximum side length n. The order of the side lengths does not matter, i.e. <6,6,5> represents the same triangle as <5,6,6> and should be counted only once. Exclude degenerate triangles such as <1,2,3>.

Scoring
The largest n for which your program can generate the number of triangles in 60 seconds on my machine is your score. The program with the highest score wins. My machine is a Sony Vaio SVF14A16CLB, Intel Core i5, 8GB RAM.

Examples
Let T(N) be the program with input N.

T(1) = 0
T(6) = 1
T(20) = 27
T(22) = 34
Note that T(1) = T(2) = T(3) = T(4) = T(5) = 0 because no combination of integral sides will yield an integral median. However, once we get to 6, we can see that one of the medians of the triangle <5,5,6> is 4, so T(6) = 1.

Note also that T(22) is the first value at which double-counting becomes an issue: the triangle <16,18,22> has medians 13 and 17 (and 2sqrt(85)).

Computing the medians
The medians of a triangle can be calculated by the following formulas:

m_a = sqrt((2b^2 + 2c^2 - a^2) / 4)
m_b = sqrt((2a^2 + 2c^2 - b^2) / 4)
m_c = sqrt((2a^2 + 2b^2 - c^2) / 4)

Current top score: Sp3000 - 7000 points - C

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
issquare(int v)
{
	int s;

	s = sqrt(v);
	return s * s == v;
}

int
ismedian(int v)
{
	return (v % 4) == 0 && issquare(v / 4);
}

int
find(int n)
{
	int a, b, c, r;

	r = 0;
	for (c = 1; c <= n; c++) {
		for (b = (c + 1) / 2; b <= c; b++) {
			for (a = c - b + 1; a <= b; a++) {
				if (ismedian(2 * (b * b + c * c) - a * a) ||
				    ismedian(2 * (a * a + c * c) - b * b) ||
				    ismedian(2 * (a * a + b * b) - c * c))
					r++;
			}
		}
	}
	return r;
}

int
main(void)
{
	assert(find(1) == 0);
	assert(find(6) == 1);
	assert(find(20) == 27);
	assert(find(22) == 34);

	return 0;
}
