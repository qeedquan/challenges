/*

Two red beads are placed between every two blue beads. There are N blue beads. After looking at the arrangement below work out the number of red beads.

b rr b rr b rr b rr b rr b

Implement count_red_beads(n) (in PHP count_red_beads($n); in Java, Javascript, TypeScript, C, C++ countRedBeads(n)) so that it returns the number of red beads.
If there are less than 2 blue beads return 0.

*/

#include <stdio.h>

// https://oeis.org/A005843
int
beads(int n)
{
	if (n < 2)
		return 0;
	return (n - 1) * 2;
}

int
main()
{
	int i;
	for (i = 0; i <= 10; i++)
		printf("%d\n", beads(i));
	return 0;
}
