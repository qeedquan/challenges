/*

Background
Most of you know what a Fibonacci number is. Some of you may know that all positive integers can be represented as a sum of one or more distinct Fibonacci numbers, according to Zeckendorf's Theorem. If the number of terms in the optimal Zeckendorf Representation of an integer n is itself a Fibonacci number, we will call n "secretly" Fibonacci.

For example:

139 = 89 + 34 + 13 + 3
This is a total of 4 integers. Since 4 is not a Fibonacci number, 139 is not secretly Fibonacci

140 = 89 + 34 + 13 + 3 + 1
This is a total of 5 integers. Since 5 is a Fibonacci number, 140 is secretly Fibonacci
Notes
The optimal Zeckendorf Representation can be found using a greedy algorithm. Simply take the largest Fibonacci number <= n and subtract it from n until you reach 0
All Fibonacci numbers can be represented as a sum of 1 Fibonacci number (itself). Since 1 is a Fibonacci number, all Fibonacci numbers are also secretly Fibonacci.
Challenge
Your challenge is to write a program or function that takes an integer and returns whether that integer is secretly Fibonacci.

Input
You may take input in any reasonable format. You may assume the input will be a single positive integer.

Output
Output one of two distinct results for whether the input is secretly Fibonacci. Examples include True/False, 1/0, etc.

Scoring
This is code-golf, so shortest answer in bytes wins! Standard loopholes are forbidden.

Test Cases
Truthy (secretly Fibonacci)
1
2
4
50
140
300099

Falsey (NOT secretly Fibonacci)
33
53
54
139
118808

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

vlong
find(vlong n, vlong i, vlong j)
{
	if (j > n) {
		if (n == 0)
			return 0;
		return find(n - i, 1, 1) + 1;
	}
	return find(n, j, i + j);
}

/*

Ported from @l4m2 solution

@lynn

This makes use of the theorem that the two descriptions of OEIS A003714 are equivalent:

Fibbinary numbers: if n=F(i1)+F(i2)+⋯+F(ik) is the Zeckendorf representation of n
(i.e., write n in Fibonacci number system) then a(n)=2^i1 + 2^i2 + ⋯ + 2^ik.
Also numbers whose binary representation contains no two adjacent 1's.

We generate enough* such numbers, and then use z as a mapping from non-negative integers to
“how many terms are in the Zeckendorf representation of n?” by counting 1s in binary.

Then it remains to check if z[n] is a Fibonacci number, i.e. z[z[n]] == 1.

*At least, n^2+1 feels like enough, and experimentally it seems to be enough. I'll prove this some time later.

*/

vlong
secfib(vlong n)
{
	return find(find(n, 1, 1), 1, 1) < 2;
}

int
main()
{
	assert(secfib(1) == true);
	assert(secfib(2) == true);
	assert(secfib(4) == true);
	assert(secfib(50) == true);
	assert(secfib(140) == true);
	assert(secfib(300099) == true);

	assert(secfib(33) == false);
	assert(secfib(53) == false);
	assert(secfib(54) == false);
	assert(secfib(139) == false);
	assert(secfib(118808) == false);

	return 0;
}
