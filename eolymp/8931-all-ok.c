/*

A positive integer n is given.

Print the text "OK", each time prefixed by its corresponding number from 1 to n, as shown in the example. Each line should be of the form

k) OK

where k is the line number (1≤k≤n).

Input
The input contains a single positive integer n (n≤100).

Output
Print n lines, each containing the line number followed by "OK", as described above.

Examples

Input #1
3

Answer #1
1 OK
2 OK
3 OK

*/

#include <stdio.h>

void
solve(int n)
{
	int i;

	for (i = 1; i <= n; i++)
		printf("%d OK\n", i);
}

int
main()
{
	solve(3);

	return 0;
}
