/*

Given two integers, a and b, you should check whether a is divisible by b or not. We know that an integer a is divisible by an integer b if and only if there exists an integer c such that a = b * c.

Input
Input starts with an integer T (≤ 525), denoting the number of test cases.

Each case starts with a line containing two integers a (-10^200 ≤ a ≤ 10^200) and b (|b| > 0, b fits into a 32 bit signed integer). Numbers will not contain any leading zeroes.

Output
For each case, print the case number first. Then print divisible if a is divisible by b. Otherwise print not divisible.

Sample
Input	Output
6
101 101
0 67
-101 101
7678123668327637674887634 101
11010000000000000000 256
-202202202202000202202202 -101

Case 1: divisible
Case 2: divisible
Case 3: divisible
Case 4: not divisible
Case 5: divisible
Case 6: divisible

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *
solve(const char *a, int b)
{
	size_t i;
	int r;

	b = abs(b);
	if (b == 0)
		return "not divisible";

	i = 0;
	if (a[i] == '-')
		i++;

	for (r = 0; a[i]; i++) {
		r = (r * 10) + (a[i] - '0');
		r %= b;
	}

	if (r == 0)
		return "divisible";
	return "not divisible";
}

void
test(const char *a, int b, const char *r)
{
	const char *s;

	s = solve(a, b);
	puts(s);
	assert(!strcmp(s, r));
}

int
main()
{
	test("101", 101, "divisible");
	test("0", 67, "divisible");
	test("-101", 101, "divisible");
	test("7678123668327637674887634", 101, "not divisible");
	test("11010000000000000000", 256, "divisible");
	test("-202202202202000202202202", -101, "divisible");

	return 0;
}
