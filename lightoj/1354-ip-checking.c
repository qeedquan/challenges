/*

An IP address is a 32 bit address formatted in the following way: a.b.c.d

where a, b, c, d are integers each ranging from 0 to 255. Now you are given two IP addresses, first one in decimal form and second one in binary form, your task is to find if they are the same or not.

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case starts with two lines. First line contains an IP address in decimal form, and second line contains an IP address in binary form. In binary form, each of the four parts contains 8 digits. Assume that the given addresses are valid.

Output
For each case, print the case number and Yes if they are same, otherwise print No.

Sample
Input	Output
2
192.168.0.100
11000000.10101000.00000000.11001000
65.254.63.122
01000001.11111110.00111111.01111010

Case 1: No
Case 2: Yes

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long long uvlong;
typedef long long vlong;

vlong
parseip(const char *s)
{
	uvlong p[4];
	int i;

	if (sscanf(s, "%llb.%llb.%llb.%llb", p, p + 1, p + 2, p + 3) != 4) {
		if (sscanf(s, "%llu.%llu.%llu.%llu", p, p + 1, p + 2, p + 3) != 4)
			return -1;
	}
	for (i = 0; i < 4; i++) {
		if (p[i] > 255)
			return -1;
	}
	return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
}

const char *
solve(const char *s1, const char *s2)
{
	vlong i1, i2;

	i1 = parseip(s1);
	i2 = parseip(s2);
	if (i1 < 0 || i2 < 0 || i1 != i2)
		return "No";
	return "Yes";
}

void
test(const char *s1, const char *s2, const char *r)
{
	const char *p;

	p = solve(s1, s2);
	puts(p);
	assert(!strcmp(p, r));
}

int
main()
{
	test("192.168.0.100", "11000000.10101000.00000000.11001000", "No");
	test("65.254.63.122", "01000001.11111110.00111111.01111010", "Yes");

	return 0;
}
