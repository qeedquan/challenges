/*

Generate the shortest possible code in any programming language that can generate all
Pythagorean triples with all values not exceeding a given integer limit.
A Pythagorean triple is a set of three integers (a,b,c) that satisfy the equation a^2 + b^2 = c^2.
The program should output the triples in any format, such as a list of tuples or a newline-separated list of strings.

Input: An integer limit n (1 ≤ n ≤ 10^6)

Output: All Pythagorean triples (a,b,c) such that  1≤a,b,c≤n and a^2 + b^2 = c^2.

Test Cases
Input: 20
Output:
(3, 4, 5)
(5, 12, 13)
(6, 8, 10)
(8, 15, 17)
(9, 12, 15)
(12, 16, 20)

Input: 5
Output:
(3, 4, 5)

Note: The output order does not matter as long as all the correct Pythagorean triples are included. Duplicate triples should not be included. But, specifying the order might help.

*/

#include <cstdio>
#include <cmath>

using namespace std;

int sqr(int x)
{
	return x * x;
}

void gen(int n)
{
	for (int a = 1; a < n; a++)
	{
		for (int b = a; b < n; b++)
		{
			int c = hypot(a, b);
			if (sqr(a) + sqr(b) == sqr(c))
				printf("%d %d %d\n", a, b, c);
		}
	}
	printf("\n");
}

int main()
{
	gen(20);
	gen(5);
	return 0;
}
