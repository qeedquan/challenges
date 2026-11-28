/*

At the site, in the results table of competitions held according to ACM (Association for Computing Machinery) rules, a correctly solved problem is marked with a plus. 
However, it is quite small. Print a big plus using stars.

Input
One integer n (1≤n≤100).

Output
Print the corresponding large square "plus" made of dots and stars. See the examples for details.

Examples

Input #1
1

Answer #1
.*.
***
.*.

Input #2
2

Answer #2
..*..
..*..
*****
..*..
..*..

*/

#include <cstdio>

void plus(int n)
{
	for (auto i = 1; i <= (2 * n) + 1; i++)
	{
		for (auto j = 1; j <= (2 * n) + 1; j++)
		{
			if (i == n + 1 || j == n + 1)
				printf("%c", '*');
			else
				printf("%c", '.');
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	plus(1);
	plus(2);

	return 0;
}
