/*

Behold! The Crystal Maze™️ Time Matrix!

      0   1   2   3   4   5   6   7   8   9  10
  1   0   5  10  15  20  25  30  35  40  45  50
  2   0  10  20  30  40  50  60  70  80  90 100
  3   0  15  30  45  60  75  90 105 120 135 150
  4   0  20  40  60  80 100 120 140 160 180 200
  5   0  25  50  75 100 125 150 175 200 225 250
Obviously, this is self explanatory to anyone who knows The Crystal Maze™️, but here's a quick run-down for anyone else:

In The Crystal Maze™️ team members attempt a series of games where they can win Crystals.
Crystals represent time in the final game, 5 seconds for every crystal.
They can also fail these games in a way which gets a team member locked in, so they are not able to participate in the final game.
Before the final game, they have the option to buy the team members back with crystals. Giving them less time, but more people.
The Matrix shows you the number of crystals along the top, and the number of team members on the left. The body of the matrix is filled with "people seconds". Its purpose is to decide if selling a crystal will increase your "people seconds" or not.

The game
Generate the precise textual output of The Crystal Maze™️ Matrix.
The crystals, along the top, will range from 0 to 10
Team members will range from 1 to 5
All columns will be exactly 3 characters wide and right-justified.
Columns are separated with a space
A single value will show (crystals * team members * 5)
Use any language capable of producing this textual output.
It's code golf, so attempt to do so in the fewest bytes.
Please include a link to an online interpreter such as TIO.

*/

#include <stdio.h>

void
timematrix(void)
{
	int s, x, y, w, h;

	w = 11;
	h = 6;
	for (y = 0; y < h; y++) {
		if (!y)
			printf("%-4s", " ");
		else
			printf("%4d", y);

		for (x = 0; x < w; x++) {
			s = 5 * y;
			if (!s)
				s = 1;
			printf("%4d", s * x);
		}

		printf("\n");
	}
}

int
main(void)
{
	timematrix();
	return 0;
}
