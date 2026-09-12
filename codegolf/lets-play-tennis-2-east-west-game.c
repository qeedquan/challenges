/*

There is a challenge Let's play tennis by Daniel. He proposes to place a court in the North-South direction. My proposal is to create a court to play tennis in the East-West direction too.

You have to print a tennis court, but you have to do it in the fewest bytes possible because of confidential reasons.

Tennis court
------x------
|  |  x  |  |
|  |--x--|  |
|  |  x  |  |
------x------
Original rules are:

No extra spaces.
No tabs as they would be unfair.
One optional trailing newline is allowed.
This is code-golf, so shortest code in bytes wins!

*/

#include <stdio.h>

void
court(void)
{
	puts("------x------");
	puts("|  |  x  |  |");
	puts("|  |--x--|  |");
	puts("|  |  x  |  |");
	puts("------x------");
}

int
main(void)
{
	court();
	return 0;
}
