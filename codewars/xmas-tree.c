/*

Complete the function that returns a christmas tree of the given height. The height is passed through to the function and the function should return a list containing each line of the tree.

XMasTree(5) should return : ['____#____', '___###___', '__#####__', '_#######_', '#########', '____#____', '____#____']
XMasTree(3) should return : ['__#__', '_###_', '#####', '__#__', '__#__']
Pad with underscores (_) so each line is the same length. Also remember the trunk/stem of the tree.

Examples
The final idea is for the tree to look like this if you decide to print each element of the list:

n = 5 will result in:

____#____              1
___###___              2
__#####__              3
_#######_              4
#########       -----> 5 - Height of Tree
____#____        1
____#____        2 - Trunk/Stem of Tree

n = 3 will result in:

__#__                  1
_###_                  2
#####          ----->  3 - Height of Tree
__#__           1
__#__           2 - Trunk/Stem of Tree

*/

#include <stdio.h>

void
repeat(const char *s, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%s", s);
}

void
xmastree(int n)
{
	int i;

	printf("n=%d\n", n);
	if (n < 1)
		return;

	for (i = 0; i < n; i++) {
		repeat("_", n - 1 - i);
		repeat("#", 1 + (2 * i));
		repeat("_", n - 1 - i);
		printf("\n");
	}
	for (i = 0; i < 2; i++) {
		repeat("_", n - 1);
		printf("#");
		repeat("_", n - 1);
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	int i;

	for (i = 0; i <= 5; i++)
		xmastree(i);
	return 0;
}
