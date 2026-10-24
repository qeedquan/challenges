/*

Students get the chance to interact with different institutions while showcasing their problem-solving, programming, and teamwork abilities through the International Collegiate Programming Contest (ICPC).

The ranking of teams for this contest will be decided based on the following rules.

The team with the higher number of solved problems will get a higher rank. Rank 1 is considered the highest rank.
In case of a tie between two teams with the same number of problems solved, the higher rank is determined by penalty time. The team with a lower penalty time will get the higher rank.
The web page that shows all team's ranks in the contest from higher rank to lower rank, is known as the contest standings page. Usually, the contest standing page shows a live rank list consisting of the team name, number of problems solved, total penalty time, problem status (solved or unsolved), number of attempts on each problem, and so on. An example rank list page is shown in the following figure.

https://static.lightoj.com/images/problem-3044/icpc-img-1672231167179.png

This year the organizer will not provide any rank list in the contest standing page.

The contest is running. There are still 3 hours remaining in this contest. As a contestant, you are only informed that there are P problems in the problem set, your team has already solved S problems, and your current team rank is R. You have to determine whether there is a chance by any means for your team to become champion after the end of the contest.

Input
The first line will contain a single integer T (1 ≤ T ≤ 18150). Each test case will contain three integers P (1 ≤ P ≤ 10), S (0 ≤ S ≤ P) and R (1 ≤ R ≤ 165).

Output
For each test case, Print the case number in the format Case X: in a single line , where X is the case number, followed by Yes if there is a chance for your team, No otherwise.

Sample
Input	Output
2
10 0 165
10 10 1

Case 1: Yes
Case 2: Yes

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
solve(int p, int s, int r)
{
	if (p == s && r != 1)
		return "No";
	return "Yes";
}

void
test(int p, int s, int r, const char *t)
{
	const char *u;

	u = solve(p, s, r);
	puts(u);
	assert(!strcmp(u, t));
}

int
main()
{
	test(10, 0, 165, "Yes");
	test(10, 10, 1, "Yes");
	return 0;
}
