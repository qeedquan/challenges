/*

Task
"AL-AHLY" and "Zamalek" are the best teams in Egypt, but "AL-AHLY" always wins the matches between them. "Zamalek" managers want to know what is the best match they've played so far.

The best match is the match they lost with the minimum goal difference. If there is more than one match with the same difference, choose the one "Zamalek" scored more goals in.

Given the information about all matches they played, return the index of the best match (0-based). If more than one valid result, return the smallest index.

Example
For ALAHLYGoals = [6,4] and zamalekGoals = [1,2], the output should be 1 (2 in COBOL).

Because 4 - 2 is less than 6 - 1

For ALAHLYGoals = [1,2,3,4,5] and zamalekGoals = [0,1,2,3,4], the output should be 4.

The goal difference of all matches are 1, but at 4th match "Zamalek" scored more goals in. So the result is 4 (5 in COBOL).

Input/Output
[input] integer array ALAHLYGoals
The number of goals "AL-AHLY" scored in each match.

[input] integer array zamalekGoals
The number of goals "Zamalek" scored in each match. It is guaranteed that zamalekGoals[i] < ALAHLYGoals[i] for each element.

[output] an integer
Index of the best match.

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
bestmatch(int *alahly, int *zamalek, size_t len)
{
	size_t best;
	size_t i;
	int diff;
	int mindiff;
	int maxgoal;

	mindiff = INT_MAX;
	maxgoal = INT_MIN;
	best = 0;
	for (i = 0; i < len; i++) {
		diff = alahly[i] - zamalek[i];
		if (mindiff > diff || (mindiff == diff && maxgoal < zamalek[i])) {
			maxgoal = zamalek[i];
			mindiff = diff;
			best = i;
		}
	}
	return best;
}

int
main()
{
	int alahly1[] = { 1, 2, 3, 4, 5 };
	int zamalek1[] = { 0, 1, 2, 3, 4 };

	int alahly2[] = { 6, 4 };
	int zamalek2[] = { 1, 2 };

	int alahly3[] = { 1 };
	int zamalek3[] = { 0 };

	int alahly4[] = { 3, 4, 3 };
	int zamalek4[] = { 1, 1, 2 };

	int alahly5[] = { 4, 3, 4 };
	int zamalek5[] = { 1, 1, 1 };

	assert(bestmatch(alahly1, zamalek1, nelem(alahly1)) == 4);
	assert(bestmatch(alahly2, zamalek2, nelem(alahly2)) == 1);
	assert(bestmatch(alahly3, zamalek3, nelem(alahly3)) == 0);
	assert(bestmatch(alahly4, zamalek4, nelem(alahly4)) == 2);
	assert(bestmatch(alahly5, zamalek5, nelem(alahly5)) == 1);

	return 0;
}
