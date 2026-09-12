/*

It's the most hotly anticipated game of the school year - Gryffindor vs Slytherin! Write a function which returns the winning team.

You will be given two arrays with two values.

The first given value is the number of points scored by the team's Chasers and the second a string with a 'yes' or 'no' value if the team caught the golden snitch!

The team who catches the snitch wins their team an extra 150 points - but doesn't always win them the game.

gameWinners([150, 'yes'],[200, 'no']) //'Gryffindor wins!'
gameWinners([400, 'no'],[350, 'yes']) //'Slytherin wins!'

If the score is a tie return "It's a draw!""

** The game only ends when someone catches the golden snitch, so one array will always include 'yes' or 'no.' Points scored by Chasers can be any positive integer.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	int value;
	char snitch[4];
} Score;

const char *
winner(Score *score0, Score *score1)
{
	int value0, value1;

	value0 = score0->value;
	value1 = score1->value;

	if (!strcmp(score0->snitch, "yes"))
		value0 += 150;
	else if (!strcmp(score1->snitch, "yes"))
		value1 += 150;

	if (value0 > value1)
		return "Gryffindor wins!";
	if (value0 < value1)
		return "Slytherin wins!";
	return "It's a draw!";
}

void
test(Score *score0, Score *score1, const char *expected)
{
	const char *result;

	result = winner(score0, score1);
	puts(result);
	assert(!strcmp(result, expected));
}

int
main()
{
	Score score1[] = {{150, "yes"}, {200, "no"}};
	Score score2[] = {{400, "no"}, {350, "yes"}};
	Score score3[] = {{150, "no"}, {0, "yes"}};

	test(score1 + 0, score1 + 1, "Gryffindor wins!");
	test(score2 + 0, score2 + 1, "Slytherin wins!");
	test(score3 + 0, score3 + 1, "It's a draw!");

	return 0;
}
