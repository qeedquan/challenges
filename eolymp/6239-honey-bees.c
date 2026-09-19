/*

The behavioral activity of worker honey bees can be divided into the following recognizable tasks:
resting (Re), patrolling (Pt), cell-cleaning (Cc), eating pollen (Ea), tending brood (Tb), comb-building and maintenance (Cm),
and external activities (Ex) such as guarding, foraging, and dance-following.

The tasks performed by a honey bee were recorded at hourly intervals for a day,
resulting in a data set consisting of whitespace-separated symbols from the set {Re, Pt, Cc, Ea, Tb, Cm, Ex}.

Input
The input consists of symbols from the set {Re, Pt, Cc, Ea, Tb, Cm, Ex}.
The symbols are separated by whitespace and may span several lines.
There are at most 24 symbols in total.

Output
Print a table consisting of 8 lines. Lines 1 to 7 should each have the following format:

Task Count Proportion
where Task is one of Re, Pt, Cc, Ea, Tb, Cm, or Ex, in that order.
Count is the total number of times the task appears, and Proportion is the frequency of the task divided by the total number of tasks,
rounded to the nearest hundredth and displayed with exactly two digits after the decimal point.

The 8th line should always be:

Total C 1.00
where C is the total number of recorded tasks.

Examples

Input #1
Cc Pt Pt Re Tb Re Cm Cm Re Pt Pt Re Ea Ea Pt Pt
Pt Re Re Cm Cm Pt Pt Cm

Answer #1
Re 6 0.25
Pt 9 0.38
Cc 1 0.04
Ea 2 0.08
Tb 1 0.04
Cm 5 0.21
Ex 0 0.00
Total 24 1.00

Input #2
Re Re
Pt Pt Cc Ea
Re Re
Ex
Re Re Re

Answer #2
Re 7 0.58
Pt 2 0.17
Cc 1 0.08
Ea 1 0.08
Tb 0 0.00
Cm 0 0.00
Ex 1 0.08
Total 12 1.00

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
solve(const char **task, size_t ntask)
{
	static const char *table[] = {
		"Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex"
	};

	size_t i, j;
	size_t total;
	size_t count[7];

	memset(count, 0, sizeof(count));
	total = 0;
	for (i = 0; i < ntask; i++) {
		for (j = 0; j < nelem(table); j++) {
			if (!strcmp(task[i], table[j])) {
				count[j] += 1;
				total += 1;
				break;
			}
		}
	}

	for (i = 0; i < nelem(table); i++)
		printf("%s %zu %.2f\n", table[i], count[i], count[i] * 1.0 / total);
	printf("Total %zu %.2f\n", total, 1.00);
}

int
main()
{
	const char *task1[] = {
		"Cc",
		"Pt",
		"Pt",
		"Re",
		"Tb",
		"Re",
		"Cm",
		"Cm",
		"Re",
		"Pt",
		"Pt",
		"Re",
		"Ea",
		"Ea",
		"Pt",
		"Pt",
		"Pt",
		"Re",
		"Re",
		"Cm",
		"Cm",
		"Pt",
		"Pt",
		"Cm",
	};

	const char *task2[] = {
		"Re",
		"Re",
		"Pt",
		"Pt",
		"Cc",
		"Ea",
		"Re",
		"Re",
		"Ex",
		"Re",
		"Re",
		"Re",
	};

	solve(task1, nelem(task1));
	solve(task2, nelem(task2));

	return 0;
}
