/*

One integer number is given. Check whether it is divisible by 3, by 6, and by 9.

Input
One integer that contains no more than 1000 digits.

Output
Print in the first line Yes if the number is divisible by 3, otherwise print No.

Print in the second line Yes if the number is divisible by 6, otherwise print No.

Print in the third line Yes if the number is divisible by 9, otherwise print No.

Examples

Input #1
3

Answer #1
Yes
No
No

Input #2
15

Answer #2
Yes
No
No

*/

#include <stdio.h>

typedef unsigned long long uvlong;

void
check(uvlong n, uvlong m)
{
	if (!(n % m))
		puts("Yes");
	else
		puts("No");
}

void
solve(uvlong n)
{
	check(n, 3);
	check(n, 6);
	check(n, 9);
	puts("");
}

int
main()
{
	solve(3);
	solve(15);

	return 0;
}
