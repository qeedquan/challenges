/*

Inspired by Taken from a question at Stack Overflow.

https://stackoverflow.com/questions/47693536/how-to-generate-all-the-permutations-of-two-elements-in-an-array

The challenge
Given an integer n>1, output all arrays that can be obtained by swapping exactly two entries in the array [1, 2, ..., n].

The arrays can be produced in any order.

You can consistently use [0, 1, ..., n-1] (0-based) instead of [1, 2, ..., n] (1-based).

Additional rules
Input and output are flexible as usual.

Programs or functions are allowed, in any programming language. Standard loopholes are forbidden.

Shortest code in bytes wins.

Test cases
Input 2 gives output (assumed 1-based)

2 1
Input 3 gives output (note that the three arrays could be in any order)

1 3 2
2 1 3
3 2 1
Input 4 gives output

1 2 4 3
1 3 2 4
1 4 3 2
2 1 3 4
3 2 1 4
4 2 3 1
Input 7 gives output

1 2 3 4 5 7 6
1 2 3 4 6 5 7
1 2 3 4 7 6 5
1 2 3 5 4 6 7
1 2 3 6 5 4 7
1 2 3 7 5 6 4
1 2 4 3 5 6 7
1 2 5 4 3 6 7
1 2 6 4 5 3 7
1 2 7 4 5 6 3
1 3 2 4 5 6 7
1 4 3 2 5 6 7
1 5 3 4 2 6 7
1 6 3 4 5 2 7
1 7 3 4 5 6 2
2 1 3 4 5 6 7
3 2 1 4 5 6 7
4 2 3 1 5 6 7
5 2 3 4 1 6 7
6 2 3 4 5 1 7
7 2 3 4 5 6 1

*/

#include <stdio.h>

void
output(int n, int i0, int i1)
{
	int i;

	for (i = 0; i < n; i++) {
		if (i == i0)
			printf("%d ", i1 + 1);
		else if (i == i1)
			printf("%d ", i0 + 1);
		else
			printf("%d ", i + 1);
	}
	printf("\n");
}

/*

https://oeis.org/A211369 (related)

@Jonathan Allan
Entries at indexes given by oeis.org/A211369 plus one (or two if 0-indexing) in a lexicographically sorted list of all the permutations of length n.

*/

void
sswa(int n)
{
	int i, j;

	printf("n=%d\n", n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++)
			output(n, i, j);
	}
	printf("\n");
}

int
main()
{
	sswa(2);
	sswa(3);
	sswa(4);
	sswa(7);

	return 0;
}
