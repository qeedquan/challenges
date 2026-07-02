/*

Suppose I have a big paper and i want to draw n number of grids just by folding it (see example ). How many times do i have to fold it to get n number of grids. eg.

n=1 , 0 operation, the original paper is one grid.

n=2, 1 operations, i have to fold it 1 time to get 2 grids (A,B).

 _______
|   |   |
| A | B |
|   |   |
|   |   |
|___|___|

No edge cases, all inputs are valid, But some built-in Math functions will have NO power here.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A029837
int
folds(int n)
{
	if (n < 2)
		return 0;
	return ceil(log2(n));
}

int
main()
{
	static const int tab[] = {
		0, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5,
		5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(folds(i + 1) == tab[i]);

	return 0;
}
