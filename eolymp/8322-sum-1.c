/*

Calculate the sum of a sequence of numbers based on the given variant number n.

For n=1: 5+10+15+20+25+30+35+40+45+50

For n=2: 1+4+7+10+13+16+19+22+25+28

For n=3: 4+8+12+16+20+24+28+32+36+40

For n=4: 1+3+5+7+9+11+13+15+17+19

For n=5: 2+4+6+8+10+12+14+16+18+20

For n=6: 1+2+3+4+5+6+7+8+9+10

Input
A single integer n, where 1≤n≤6.

Output
The sum of the numbers in the specified sequence.

Examples

Input #1
1

Answer #1
275

*/

#include <assert.h>

int
solve(int n)
{
	switch (n) {
	case 1:
		return 5 + 10 + 15 + 20 + 25 + 30 + 35 + 40 + 45 + 50;
	case 2:
		return 1 + 4 + 7 + 10 + 13 + 16 + 19 + 22 + 25 + 28;
	case 3:
		return 4 + 8 + 12 + 16 + 20 + 24 + 28 + 32 + 36 + 40;
	case 4:
		return 1 + 3 + 5 + 7 + 9 + 11 + 13 + 15 + 17 + 19;
	case 5:
		return 2 + 4 + 6 + 8 + 10 + 12 + 14 + 16 + 18 + 20;
	case 6:
		return 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10;
	}
	return 0;
}

int
main()
{
	assert(solve(1) == 275);
	return 0;
}
