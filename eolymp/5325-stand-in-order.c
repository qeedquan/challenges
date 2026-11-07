/*

At a session of the Summer Computer School, n schoolchildren are preparing for a parade. They need to stand in an orderly fashion. Upon a given command, they all line up and start counting. The first student in line says "first", the second says "second", and so on. Write the script for this process.

Input
One integer n (1≤n≤1000).

Output
Print all the numbers from 1 to n in a single line.

Examples

Input #1
1

Answer #1
1

Input #2
4

Answer #2
1 2 3 4

*/

#include <stdio.h>

void
solve(int n)
{
	int i;

	if (n < 1)
		return;

	for (i = 1; i < n; i++)
		printf("%d ", i);
	printf("%d\n", n);
}

int
main()
{
	solve(1);
	solve(4);

	return 0;
}
