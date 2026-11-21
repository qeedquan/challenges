/*

Imagine a company which award 0.1 holiday per each working day.
Working days are from Mon to Fri (each week has 5 working days) regardless of being off.
So If I'm off at Monday, I'll earn 0.1 holiday.
Write a program that given number of current available holidays, it gives the number of days I can continuously take as off.

Example
As an example, imagine I have 12 off days right now.
If I start continuously taking off days, I can take 13 days off (since I'll earn 1.2 holidays during the 12 days off).
You should floor the number of holidays, so 1.2 will be 1.

Test Cases
0 => 0
4 => 4
9 => 9
12 => 13
19 => 21
20 => 22
123 => 136

*/

#include <assert.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int
holidays(int n)
{
	return max(n + ((n - 1) / 9), n);
}

int
main()
{
	assert(holidays(0) == 0);
	assert(holidays(4) == 4);
	assert(holidays(9) == 9);
	assert(holidays(12) == 13);
	assert(holidays(19) == 21);
	assert(holidays(20) == 22);
	assert(holidays(123) == 136);

	return 0;
}
