/*

Mary add Sue are playing with dices. Rules are simple: at the begging each of them puts coin on the
table and roll a dice. Wins a player who rolled a larger number. If numbers are the same, coins stay
on the table for a next round. In order to make this game more interesting they decided to play now
with normal dices, but with dice that can have arbitrary number of bones, from 0 till 9. However each
round must be played with same dice by both players.
Girls have been playing this game for a day long, till Mary run out of coins (nevertheless she had
more coins at the beginning of the game). Now Mary is confused. How could she have lost all her
coins? She thinks that Sue had been cheating. Before each roll Mary wrote on a paper numbers of
bones on each side of the dice. Now she wonders if same dice was always used during one round. Help
her to find it out.

Input
On the first line there is the total number of test cases T (T ≤ 10^3), next T lines follows.
Each line contains two six digit numbers, each digit stands for number of bones on side of a dice in this order:
top, bottom, front, left, back, right.

Output
For each test case output line ‘Equal’ if two dices are equals, or ‘Not Equal’ otherwise.

Sample Input
3
345678 345678
123123 123456
123456 351624

Sample Output
Equal
Not Equal
Equal

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
shift(char a[6], int i, int j, int k, int l)
{
	char t;

	t = a[i];
	a[i] = a[j];
	a[j] = a[k];
	a[k] = a[l];
	a[l] = t;
}

bool
equal(const char *s, const char *t)
{
	char a[7], b[7];
	int i, j, k;

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));

	snprintf(a, sizeof(a), "%s", s);
	snprintf(b, sizeof(b), "%s", t);

	for (i = 0; i < 4; i++) {
		shift(a, 0, 4, 1, 2);
		for (j = 0; j < 4; j++) {
			shift(a, 2, 5, 4, 3);
			for (k = 0; k < 4; k++) {
				shift(a, 0, 5, 1, 3);
				if (!memcmp(a, b, 6))
					return true;
			}
		}
	}
	return false;
}

int
main()
{
	assert(equal("345678", "345678") == true);
	assert(equal("123123", "123456") == false);
	assert(equal("123456", "351624") == true);

	return 0;
}
