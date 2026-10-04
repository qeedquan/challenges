/*

It is known that Sergey writes A lines of code every working day. Every week he works B days and rests on the remaining days.
Sergey has decided to work continuously for C weeks.
It is necessary to determine how many lines of code Sergey will write during this period.

Input
Three lines, each containing one integer:

A — the number of lines of code Sergey writes in one working day (0≤A≤10000).

B — the number of working days in a week (0≤B≤7).

C — the number of weeks Sergey will work (0≤C≤500).

Output
Output a single number — the number of lines of code Sergey will write in C weeks.

Examples

Input #1
5
3
4

Answer #1
60

Note
Sergey works 3 days a week and writes 5 lines each day. In one week, he will write 3⋅5=15 lines of code.

In 4 weeks, he will write 4⋅15=60 lines of code.

*/

#include <assert.h>

int
solve(int a, int b, int c)
{
	return a * b * c;
}

int
main()
{
	assert(solve(5, 3, 4) == 60);

	return 0;
}
