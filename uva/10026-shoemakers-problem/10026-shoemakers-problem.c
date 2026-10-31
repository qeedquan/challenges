#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int time;
	int fine;
	int id;
} Job;

int
jobcmp(const void *a, const void *b)
{
	const Job *j1, *j2;
	int r1, r2;

	j1 = a;
	j2 = b;
	r1 = j1->time * j2->fine;
	r2 = j2->time * j1->fine;
	if (r1 < r2)
		return -1;
	if (r1 > r2)
		return 1;
	if (j1->id < j2->id)
		return -1;
	if (j1->id > j2->id)
		return 1;
	return 0;
}

void
solve(Job *jobs, size_t njobs)
{
	size_t i;

	qsort(jobs, njobs, sizeof(*jobs), jobcmp);
	for (i = 0; i < njobs; i++)
		printf("%d ", jobs[i].id);
	printf("\n");
}

int
main()
{
	Job jobs[] = {
		{ 3, 4, 1 },
		{ 1, 1000, 2 },
		{ 2, 2, 3 },
		{ 5, 5, 4 },
	};

	solve(jobs, nelem(jobs));
	return 0;
}
