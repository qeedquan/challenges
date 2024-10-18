/*

Introduction

A normal checkers board contains 8 x 8 = 64 squares:

enter image description here

You can see that in total, there are 12 white pieces. Black and white always have the same amount of pieces. If there are any more pieces on the board, the pieces would neighbouring, which is not allowed for this challenge. To clarify things, here are some examples:

The smallest board possible for this challenge is 3 x 3:

enter image description here

You can see that the maximum amount of pieces is equal to 2. So, when given N = 3, you need to output 2. If the input is N = 4, we get the following:

enter image description here

You can see that the maximum amount is also 2. So for N = 4, the output should be 2. For N = 5, the output should be equal to 5:

enter image description here

Examples
STDIN:  3
STDOUT: 2

STDIN:  4
STDOUT: 2

STDIN:  5
STDOUT: 5

STDIN:  6
STDOUT: 6

STDIN:  8
STDOUT: 12

Rules
Your submission must be a program, or function etc. that takes one integer and outputs or returns the number of pieces on the board
You can safely assume that the input is an non-negative integer > 2
This is code-golf, so the program with the least amount of bytes wins!
Note that the square in the lower left of the board is always dark. Pieces are only placed on dark squares
You have to occupy a full row with pieces

*/

#include <assert.h>

/*

@orlp

lambda n:~-n/2*n+1>>1
I first separate in two cases, odd N and even N.

With odd N we can fill (N - 1)/2 rows, containing on average N/2 pieces. Since the first row always has more pieces we should ceil this result. So when N is odd we have ceil((N-1)/2 * N/2) pieces.

With even N we can fill N/2 - 1, or floor((N - 1)/2) rows, each row containing N/2 pieces.

We can combine these two expressions by ceil(floor((N-1)/2) * N/2). Since ceil(x/2) = floor((x+1)/2) we can use flooring division: ((N - 1) // 2 * N + 1) // 2.

*/

int
pieces(int n)
{
	return (((n - 1) / 2 * n) + 1) / 2;
}

int
main(void)
{
	assert(pieces(3) == 2);
	assert(pieces(4) == 2);
	assert(pieces(5) == 5);
	assert(pieces(6) == 6);
	assert(pieces(8) == 12);

	return 0;
}
