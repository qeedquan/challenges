/*

Create a function that takes an array of football clubs with properties: name, wins, loss, draws, scored, conceded, and returns the team name with the highest number of points. If two teams have the same number of points, return the team with the largest goal difference.

How to Calculate Points and Goal Difference
team = { name: "Manchester United", wins: 30, loss: 3, draws: 5, scored: 88, conceded: 20 }

Total Points = 3 * wins + 0 * loss + 1 * draws = 3 * 30 + 0 * 3 + 5 * 1 = 95 points
Goal Difference = scored - conceded = 88 - 20 = 68
Examples
champions([
  {
    name: "Manchester United",
    wins: 30,
    loss: 3,
    draws: 5,
    scored: 88,
    conceded: 20,
  },
  {
    name: "Arsenal",
    wins: 24,
    loss: 6,
    draws: 8,
    scored: 98,
    conceded: 29,
  },
  {
    name: "Chelsea",
    wins: 22,
    loss: 8,
    draws: 8,
    scored: 98,
    conceded: 29,
  },
  ])
➞ "Manchester United"

Notes
Input is an array of teams.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[32];
	int wins;
	int loss;
	int draws;
	int scored;
	int conceded;
} Club;

const char *
champions(Club *clubs, size_t nclubs)
{
	Club *club;
	Club *winner;
	size_t i;
	int maxpoints;
	int maxgoaldiff;
	int points;
	int goaldiff;

	winner = NULL;
	maxpoints = 0;
	maxgoaldiff = 0;
	for (i = 0; i < nclubs; i++) {
		club = clubs + i;

		points = 3 * club->wins + club->draws;
		goaldiff = club->scored - club->conceded;
		if (!winner || points > maxpoints || (points == maxpoints && goaldiff > maxgoaldiff)) {
			winner = club;
			maxpoints = points;
			maxgoaldiff = goaldiff;
		}
	}
	return (winner) ? winner->name : NULL;
}

void
test(Club *clubs, size_t nclubs, const char *expected)
{
	const char *result;

	result = champions(clubs, nclubs);
	if (!result)
		assert(result == expected);
	else {
		printf("%s\n", result);
		assert(!strcmp(result, expected));
	}
}

int
main(void)
{
	Club clubs1[] = {
	    {
	        .name = "Manchester United",
	        .wins = 30,
	        .loss = 3,
	        .draws = 5,
	        .scored = 88,
	        .conceded = 20,
	    },
	    {
	        .name = "Arsenal",
	        .wins = 24,
	        .loss = 6,
	        .draws = 8,
	        .scored = 98,
	        .conceded = 29,
	    },
	    {
	        .name = "Chelsea",
	        .wins = 22,
	        .loss = 8,
	        .draws = 8,
	        .scored = 98,
	        .conceded = 29,
	    },
	};

	Club clubs2[] = {
	    {
	        .name = "Manchester City",
	        .wins = 30,
	        .loss = 8,
	        .draws = 0,
	        .scored = 67,
	        .conceded = 20,
	    },
	    {
	        .name = "Liverpool",
	        .wins = 34,
	        .loss = 2,
	        .draws = 2,
	        .scored = 118,
	        .conceded = 29,
	    },
	    {
	        .name = "Leicester City",
	        .wins = 22,
	        .loss = 8,
	        .draws = 8,
	        .scored = 98,
	        .conceded = 29,
	    },
	};

	Club clubs3[] = {
	    {
	        .name = "Manchester City",
	        .wins = 30,
	        .loss = 8,
	        .draws = 0,
	        .scored = 67,
	        .conceded = 20,
	    },
	    {
	        .name = "NewCastle United",
	        .wins = 34,
	        .loss = 2,
	        .draws = 2,
	        .scored = 118,
	        .conceded = 36,
	    },
	    {
	        .name = "Leicester City",
	        .wins = 34,
	        .loss = 2,
	        .draws = 2,
	        .scored = 108,
	        .conceded = 21,
	    },
	};

	Club clubs4[] = {
	    {
	        .name = "Manchester City",
	        .wins = 30,
	        .loss = 6,
	        .draws = 2,
	        .scored = 102,
	        .conceded = 20,
	    },
	    {
	        .name = "Liverpool",
	        .wins = 24,
	        .loss = 6,
	        .draws = 8,
	        .scored = 118,
	        .conceded = 29,
	    },
	    {
	        .name = "Arsenal",
	        .wins = 28,
	        .loss = 2,
	        .draws = 8,
	        .scored = 87,
	        .conceded = 39,
	    },
	};

	Club clubs5[] = {
	    {
	        .name = "Manchester City",
	        .wins = 30,
	        .loss = 6,
	        .draws = 2,
	        .scored = 102,
	        .conceded = 20,
	    },
	    {
	        .name = "Liverpool",
	        .wins = 24,
	        .loss = 6,
	        .draws = 8,
	        .scored = 118,
	        .conceded = 29,
	    },
	    {
	        .name = "Arsenal",
	        .wins = 30,
	        .loss = 0,
	        .draws = 8,
	        .scored = 87,
	        .conceded = 39,
	    },
	};

	Club clubs6[] = {
	    {
	        .name = "Chelsea",
	        .wins = 35,
	        .loss = 3,
	        .draws = 0,
	        .scored = 102,
	        .conceded = 20,
	    },
	    {
	        .name = "Liverpool",
	        .wins = 24,
	        .loss = 6,
	        .draws = 8,
	        .scored = 118,
	        .conceded = 29,
	    },
	    {
	        .name = "Arsenal",
	        .wins = 28,
	        .loss = 2,
	        .draws = 8,
	        .scored = 87,
	        .conceded = 39,
	    },
	};

	test(clubs1, nelem(clubs1), "Manchester United");
	test(clubs2, nelem(clubs2), "Liverpool");
	test(clubs3, nelem(clubs3), "Leicester City");
	test(clubs4, nelem(clubs4), "Manchester City");
	test(clubs5, nelem(clubs5), "Arsenal");
	test(clubs6, nelem(clubs6), "Chelsea");

	return 0;
}
