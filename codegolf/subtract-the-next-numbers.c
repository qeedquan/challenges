/*

Description
Subtract the next P numbers from a N number. The next number of N is N + 1.

Look at the examples to get what I mean.

Examples:
Input: N=2,P=3
Calculate: n - (n+1) - (n+2) - (n+3)     //Ending with 3, because P=3
Calculate: 2 -  2+1  -  2+2  - 2+3       //Replacing N with 2 from Input
Calculate: 2 -  3    -  4    - 5
Output: -10


Input: N=100,P=5
Calculate: n - (n+1) - (n+2) - (n+3) - (n+4) - (n+5)
Calculate: 100-  101 -  102  -  103  -  104  - 105
Output: -415


Input: N=42,P=0
Calculate: n
Calculate: 42
Output: 42


Input: N=0,P=3
Calculate: n - (n+1) - (n+2) - (n+3)
Calculate: 0 -  1    -  2    -  3
Output: -6


Input: N=0,P=0
Calulate: n
Calculate: 0
Output: 0
Input:
N: Integer, positive, negative or 0

P: Integer, positive or 0, not negative

Output:
Integer or String, leading 0 allowed, trailing newline allowed

Rules:
No loopholes
This is code-golf, so shortest code in bytes wins
Input and Output must be as described

*/

#include <assert.h>
#include <stdio.h>

int
triangular(int n)
{
	return (n * (n + 1)) / 2;
}

int
subtract(int n, int p)
{
	return n - (n * p) - triangular(p);
}

int
main(void)
{
	assert(subtract(2, 3) == -10);
	assert(subtract(100, 5) == -415);
	assert(subtract(42, 0) == 42);
	assert(subtract(0, 3) == -6);
	assert(subtract(0, 0) == 0);

	return 0;
}
