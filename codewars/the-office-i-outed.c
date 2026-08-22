/*

Your colleagues have been looking over you shoulder. When you should have been doing your boring real job, you've been using the work computers to smash in endless hours of codewars.

In a team meeting, a terrible, awful person declares to the group that you aren't working. You're in trouble. You quickly have to gauge the feeling in the room to decide whether or not you should gather your things and leave.

Given an object (meet) containing team member names as keys, and their happiness rating out of 10 as the value, you need to assess the overall happiness rating of the group. If <= 5, return 'Get Out Now!'. Else return 'Nice Work Champ!'.

Happiness rating will be total score / number of people in the room.

Note that your boss is in the room (boss), their score is worth double it's face value (but they are still just one person!).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[16];
	int score;
} Meet;

const char *
outed(Meet *meets, size_t meetlen, const char *boss)
{
	Meet *meet;
	double score;
	size_t i;

	if (meetlen == 0)
		return "Nice Work Champ!";

	score = 0;
	for (i = 0; i < meetlen; i++) {
		meet = meets + i;
		score += meet->score;
		if (!strcmp(meet->name, boss))
			score += meet->score;
	}
	if (score / meetlen <= 5)
		return "Get Out Now!";
	return "Nice Work Champ!";
}

int
main()
{
	Meet meets_1[] = { { "tim", 0 }, { "jim", 2 }, { "randy", 0 }, { "sandy", 7 }, { "andy", 0 }, { "katie", 5 }, { "laura", 1 }, { "saajid", 2 }, { "alex", 3 }, { "john", 2 }, { "mr", 0 } };
	Meet meets_2[] = { { "tim", 1 }, { "jim", 3 }, { "randy", 9 }, { "sandy", 6 }, { "andy", 7 }, { "katie", 6 }, { "laura", 9 }, { "saajid", 9 }, { "alex", 9 }, { "john", 9 }, { "mr", 8 } };
	Meet meets_3[] = { { "tim", 2 }, { "jim", 4 }, { "randy", 0 }, { "sandy", 5 }, { "andy", 8 }, { "katie", 6 }, { "laura", 2 }, { "saajid", 2 }, { "alex", 3 }, { "john", 2 }, { "mr", 8 } };

	assert(!strcmp(outed(meets_1, nelem(meets_1), "laura"), "Get Out Now!"));
	assert(!strcmp(outed(meets_2, nelem(meets_2), "katie"), "Nice Work Champ!"));
	assert(!strcmp(outed(meets_3, nelem(meets_3), "john"), "Get Out Now!"));

	return 0;
}
