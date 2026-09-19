#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
max(size_t a, size_t b)
{
	return (a > b) ? a : b;
}

int
cmp(const void *a, const void *b)
{
	const char *s, *t;

	s = *(const char **)a;
	t = *(const char **)b;
	return strcmp(s, t);
}

void
solve(const char **files, size_t nfiles)
{
	size_t L, C, R;
	size_t i, j;

	qsort(files, nfiles, sizeof(*files), cmp);

	L = 0;
	for (i = 0; i < nfiles; i++)
		L = max(L, strlen(files[i]));
	C = (60 - L) / (L + 2) + 1;
	R = (nfiles + C - 1) / C;

	printf("------------------------------------------------------------\n");
	for (i = 0; i < R; i++) {
		for (j = i; j < nfiles; j += R)
			printf("%-*s", (int)(L + 2), files[j]);
		printf("\n");
	}
}

int
main()
{
	const char *files1[] = {
		"tiny",
		"2short4me",
		"very_long_file_name",
		"shorter",
		"size-1",
		"size2",
		"size3",
		"much_longer_name",
		"12345678.123",
		"mid_size_name",
	};

	const char *files2[] = {
		"Weaser",
		"Alfalfa",
		"Stimey",
		"Buckwheat",
		"Porky",
		"Joe",
		"Darla",
		"Cotton",
		"Butch",
		"Froggy",
		"Mrs_Crabapple",
		"P.D.",
	};

	const char *files3[] = {
		"Mr._French",
		"Jody",
		"Buffy",
		"Sissy",
		"Keith",
		"Danny",
		"Lori",
		"Chris",
		"Shirley",
		"Marsha",
		"Jan",
		"Cindy",
		"Carol",
		"Mike",
		"Greg",
		"Peter",
		"Bobby",
		"Alice",
		"Ruben",
	};

	solve(files1, nelem(files1));
	solve(files2, nelem(files2));
	solve(files3, nelem(files3));

	return 0;
}
