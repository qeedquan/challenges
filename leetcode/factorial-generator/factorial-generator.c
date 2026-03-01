/*

Description
Write a generator function that takes an integer n as an argument and returns a generator object which yields the factorial sequence.

The factorial sequence is defined by the relation n! = n * (n-1) * (n-2) * ... * 2 * 1​​​.

The factorial of 0 is defined as 1.

Example 1:

Input: n = 5
Output: [1,2,6,24,120]
Explanation:
const gen = factorial(5)
gen.next().value // 1
gen.next().value // 2
gen.next().value // 6
gen.next().value // 24
gen.next().value // 120

Example 2:

Input: n = 2
Output: [1,2]
Explanation:
const gen = factorial(2)
gen.next().value // 1
gen.next().value // 2

Example 3:

Input: n = 0
Output: [1]
Explanation:
const gen = factorial(0)
gen.next().value // 1


Constraints:

0 <= n <= 18

*/

#include <stdio.h>
#include <limits.h>
#include "coroutine.h"

typedef long long vlong;

vlong
factorial(ccrContParam)
{
	ccrBeginContext;
	vlong i, p;
	ccrEndContext(r);

	ccrBegin(r);
	for (r->i = r->p = 1; r->i < LLONG_MAX; r->i++) {
		r->p *= r->i;
		ccrReturn(r->p);
	}
	ccrFinish(-1);
}

int
main()
{
	ccrContext z = 0;
	vlong i;

	for (i = 0; i < 20; i++)
		printf("%lld\n", factorial(&z));
	ccrAbort(z);

	return 0;
}
