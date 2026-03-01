/*

The code provided has a method `plus100` which is supposed to return the number of the parameter incremented by 100.

But it's not working properly.

# Task
Fix the code so we can all go home early.

## Restrictions

* Do not modify the constructor
* Do not modify the `plus100` method
* Do not modify the `ONE_HUNDRED` declarationq

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	const int value;
} Hundred;

Hundred HUNDRED = { 100 };

int
plus100(Hundred *h, int n)
{
	return h->value + n;
}

int
main()
{
	Hundred h = HUNDRED;
	assert(plus100(&h, 2) == 102);
	assert(plus100(&h, 10) == 110);

	return 0;
}
