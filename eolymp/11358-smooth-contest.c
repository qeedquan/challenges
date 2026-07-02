/*

Andrey doesn't like sharp drops, especially in contests.
Two numbers a and b form a sharp drop if ∣a−b∣>1.
The contest is considered smooth if no difficulties of two neighboring problems form a sharp drop.

You are given 5 numbers — the complexity of the problems. Determine if these tasks form a smooth contest.

Input
The first line contains five integers a, b, c, d, e (1≤a,b,c,d,e≤10^6) — problem complexities.

Output
Print «YES» if the numbers form a smooth contest, and «NO» otherwise
(The checking system is case-insensitive, meaning responses like «Yes» and «yES» are also accepted).

Examples

Input #1
1 2 2 2 1

Answer #1
Yes

Input #2
1 2 2 1 3

Answer #2
No

Note
Explanation for the first example:

∣1−2∣=1, ∣2−2∣=0, ∣2−2∣=0, ∣2−1∣=1.

None of these pairs form a sharp drop, so the numbers {1,2,2,2,1} form a smooth contest.

Explanation for the second example: ∣1−2∣=1, ∣2−2∣=0, ∣2−1∣=1, ∣1−3∣=2.

As you can see, the last two numbers form a sharp drop, so the numbers {1,2,2,1,3} do not form a smooth contest.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *
solve(int x[5])
{
	int i;

	for (i = 1; i < 5; i++) {
		if (abs(x[i] - x[i - 1]) > 1)
			return "No";
	}
	return "Yes";
}

int
main()
{
	int x1[] = { 1, 2, 2, 2, 1 };
	int x2[] = { 1, 2, 2, 1, 3 };

	assert(!strcmp(solve(x1), "Yes"));
	assert(!strcmp(solve(x2), "No"));

	return 0;
}
