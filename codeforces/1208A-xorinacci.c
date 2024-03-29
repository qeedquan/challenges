/*

Cengiz recently learned Fibonacci numbers and now he is studying different algorithms to find them. After getting bored of reading them, he came with his own new type of numbers that he named XORinacci numbers. He defined them as follows:

f(0)=a;
f(1)=b;
f(n)=f(n−1)⊕f(n−2) when n>1, where ⊕ denotes the bitwise XOR operation.
You are given three integers a, b, and n, calculate f(n).

You have to answer for T independent test cases.

Input
The input contains one or more independent test cases.

The first line of input contains a single integer T (1≤T≤10^3), the number of test cases.

Each of the T following lines contains three space-separated integers a, b, and n (0≤a,b,n≤10^9) respectively.

Output
For each test case, output f(n).

Example

input
3
3 4 2
4 5 0
325 265 1231232

output
7
4
76

Note
In the first example, f(2)=f(0)⊕f(1)=3⊕4=7.

*/

#include <assert.h>

long
xorniacci(long a, long b, long n)
{
	switch (n % 3) {
	case 0:
		return a;
	case 1:
		return b;
	default:
		return a ^ b;
	}
}

int
main(void)
{
	assert(xorniacci(3, 4, 2) == 7);
	assert(xorniacci(4, 5, 0) == 4);
	assert(xorniacci(325, 265, 1231232L) == 76);
	assert(xorniacci(55, 66, 1) == 66);

	return 0;
}
