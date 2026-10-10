#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	long x, y;

	x = *(long *)a;
	y = *(long *)b;
	if (x < y)
		return 1;
	if (x == y)
		return 0;
	return -1;
}

long
mintime(long nfiles, long *files, long numcores, long limit)
{
	long *index;
	long total;
	long count;
	long i;

	index = calloc(nfiles, sizeof(*index));
	if (!index)
		return -errno;

	total = 0;
	count = 0;
	for (i = 0; i < nfiles; i++) {
		if (!(files[i] % numcores))
			index[count++] = files[i];
		else
			total += files[i];
	}

	qsort(index, count, sizeof(*index), cmp);

	for (i = 0; i < count; i++) {
		if (i < limit)
			total += index[i] / numcores;
		else
			total += index[i];
	}

	free(index);
	return total;
}

int
main()
{
	long files1[] = { 5, 3, 1 };
	long files2[] = { 3, 1, 5 };

	assert(mintime(nelem(files1), files1, 5, 5) == 5);
	assert(mintime(nelem(files2), files2, 1, 5) == 9);

	return 0;
}
