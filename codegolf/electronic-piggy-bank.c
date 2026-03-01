/*

A piggy bank is a container used to collect coins in. For this challenge use the four US coins: quarter, dime, nickel, and penny.

Challenge
Your challenge is to create an electronic piggy bank. Write a program (or function) that when run (or called), outputs (or returns) the count of each coin you have, as well as the total amount the coins amount to.

Input
A string, array, etc...(your choice) of the coins into your piggy bank(case insensitive).

 Q - Quarter(Value of 25)
 D - Dime(Value of 10)
 N - Nickel(Value of 5)
 P - Penny(Value of 1)

Output
The count of coins from the input and the total amount, separated by the non-integer delimiter of your choice. (The order in which you output the coin totals does not matter, but the total coin value(sum) must be the last element)

Examples
 Input          ->       Output

 P              ->       1,0,0,0,1 or 0,0,0,1,1 or 0,0,1,0,1 or 1,1
 N              ->       0,1,0,0,5
 D              ->       0,0,1,0,10
 Q              ->       0,0,0,1,25
 QQQQ           ->       0,0,0,4,100
 QNDPQNDPQNDP   ->       3,3,3,3,123
 PPPPPPPPPP     ->       10,0,0,0,10
 PNNDNNQPDNPQND ->       3,6,3,2,113

Rules
Standard loopholes are not allowed.

This is code-golf, so the shortest code in bytes for each language wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
piggybank(const char *s, int b[5])
{
	size_t i;

	memset(b, 0, sizeof(*b) * 5);
	for (i = 0; s[i]; i++) {
		switch (s[i]) {
		case 'P':
			b[0]++;
			break;
		case 'N':
			b[1]++;
			break;
		case 'D':
			b[2]++;
			break;
		case 'Q':
			b[3]++;
			break;
		}
	}
	b[4] = b[0] + (5 * b[1]) + (10 * b[2]) + (25 * b[3]);
}

void
test(const char *s, int r[5])
{
	int b[5];

	piggybank(s, b);
	printf("%d %d %d %d %d\n", b[0], b[1], b[2], b[3], b[4]);
	assert(!memcmp(b, r, sizeof(b)));
}

int
main(void)
{
	int r1[] = {1, 0, 0, 0, 1};
	int r2[] = {0, 1, 0, 0, 5};
	int r3[] = {0, 0, 1, 0, 10};
	int r4[] = {0, 0, 0, 1, 25};
	int r5[] = {0, 0, 0, 4, 100};
	int r6[] = {3, 3, 3, 3, 123};
	int r7[] = {10, 0, 0, 0, 10};
	int r8[] = {3, 6, 3, 2, 113};

	test("P", r1);
	test("N", r2);
	test("D", r3);
	test("Q", r4);
	test("QQQQ", r5);
	test("QNDPQNDPQNDP", r6);
	test("PPPPPPPPPP", r7);
	test("PNNDNNQPDNPQND", r8);

	return 0;
}
