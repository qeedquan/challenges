/*

Given an integer n ≥ 1, output a 2D representation† of a percent sign of width n. The construction goes as follows:

Create an n by n matrix (or list of lists) filled with zeroes.
Insert ones in the top-left and bottom-right corners.
Place ones on the diagonal from the bottom-left to the top-right.
For input n = 4, this construction would look like:

1. 4x4 matrix of 0s
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
2. 1s in TL and BR corners
1 0 0 0
0 0 0 0
0 0 0 0
0 0 0 1
3. 1s across BL-TR diagonal
1 0 0 1
0 0 1 0
0 1 0 0
1 0 0 1
This is a code-golf, so the shortest program in bytes wins.

† I use a matrix of 1s and 0s, but it is also acceptable to use a string of any non-whitespace character and spaces. So, the example above could look like:

#  #
  #
 #
#  #
or

#     #
    #
  #
#     #
Test cases
n
output

1
1

2
1 1
1 1

3
1 0 1
0 1 0
1 0 1

4
1 0 0 1
0 0 1 0
0 1 0 0
1 0 0 1

10
1 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 0 1 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 1

Final note
Adding an explanation would be greatly appreciated.

*/

#include <stdio.h>

void
percentbox(int n)
{
	int x, y;

	printf("n=%d\n", n);
	for (y = 0; y < n; y++) {
		for (x = 0; x < n; x++) {
			if (((x == 0 && y == 0) || (x == n - 1 && y == n - 1)) || (x == n - y - 1))
				printf("1 ");
			else
				printf("0 ");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	percentbox(1);
	percentbox(2);
	percentbox(3);
	percentbox(4);
	percentbox(10);

	return 0;
}
