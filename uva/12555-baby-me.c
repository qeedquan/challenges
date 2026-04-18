/*

When I was born, I was 5 斤 2 两。Sorry for non-Chinese people. Here’s what it means:
1 斤 =0.5kg
1 两 =0.05kg
So 5 斤 2 两 means 0.5*5+0.05*2=2.6kg.
Given similar information for other babies, your task is to find out their weights in kg.

Input
The first line contains the number of test cases T (T ≤ 100). Each test case contains a string in format
‘a 斤 b 两’ (1 ≤ a ≤ 10, 1 ≤ b ≤ 9) or ‘a 斤’ (1 ≤ a ≤ 10).
The input file will be encoded with UTF-8 without BOM (if you don’t know what it is, you can
safely ignore it).

Output
For each test case, print the ACCURATE weight in kg (without trailing zeros).

Sample Input
3
5 斤 2 两
7 斤 3 两
6 斤

Sample Output
Case 1: 2.6
Case 2: 3.65
Case 3: 3

*/

#include <assert.h>

double
solve(double a, double b)
{
	return (a * 0.5) + (b * 0.05);
}

int
main()
{
	assert(solve(5, 2) == 2.6);
	assert(solve(7, 3) == 3.65);
	assert(solve(6, 0) == 3);

	return 0;
}
