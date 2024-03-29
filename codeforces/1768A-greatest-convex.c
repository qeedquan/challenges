/*

You are given an integer k. Find the largest integer x, where 1≤x<k, such that x!+(x−1)!† is a multiple of ‡ k, or determine that no such x exists.

†y! denotes the factorial of y, which is defined recursively as y!=y⋅(y−1)! for y≥1 with the base case of 0!=1. For example, 5!=5⋅4⋅3⋅2⋅1⋅0!=120.

‡ If a and b are integers, then a is a multiple of b if there exists an integer c such that a=b⋅c. For example, 10 is a multiple of 5 but 9 is not a multiple of 6.

Input
The first line contains a single integer t (1≤t≤10^4) — the number of test cases. The description of test cases follows.

The only line of each test case contains a single integer k (2≤k≤10^9).

Output
For each test case output a single integer — the largest possible integer x that satisfies the conditions above.

If no such x exists, output −1.

Example

input
4
3
6
8
10

output
2
5
7
9

Note
In the first test case, 2!+1!=2+1=3, which is a multiple of 3.

In the third test case, 7!+6!=5040+720=5760, which is a multiple of 8.

*/

#include <assert.h>

/*

Let x = k-1

x! + (x + 1)! = (x - 1)! * (x + 1) = ((k - 1) - 1)! * ((k - 1) + 1) = (k - 2)! * k which is always a multiple of k

*/

int
greatestconvex(int k)
{
	return (k >= 1) ? k - 1 : -1;
}

int
main(void)
{
	assert(greatestconvex(3) == 2);
	assert(greatestconvex(6) == 5);
	assert(greatestconvex(8) == 7);
	assert(greatestconvex(10) == 9);

	return 0;
}
