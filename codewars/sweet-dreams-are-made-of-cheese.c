/*

Mr Leicester's cheese factory is the pride of the East Midlands, but he's feeling a little blue. It's the time of the year when the taxman is coming round to take a slice of his cheddar - and the final thing he has to work out is how much money he's spending on his staff. Poor Mr Leicester can barely sleep he's so stressed. Can you help?

Mr Leicester employs 4 staff, who together make 10 wheels of cheese every 6 minutes.
Worker pay is calculated on how many wheels of cheese they produce in a day.
Mr Leicester pays his staff according to the UK living wage, which is currently £8.75p an hour. There are 100 pence (p) to the UK pound (£).
The input for function payCheese will be provided as an array of five integers, one for each amount of cheese wheels produced each day.

When the workforce don't work a nice integer number of minutes - much to the chagrin of the company accountant - Mr Leicester very generously rounds up to the nearest hour at the end of the week (not the end of each day). Which means if the workers make 574 wheels on each day of the week, they're each paid 29 hours for the week (28.699 hours rounded up) and not 30 (6 hours a day rounded up * 5).

The return value should be a string (with the £ included) of the total £ of staff wages for that week.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
paycheese(int *a, size_t n)
{
	double s;
	size_t i;

	s = 0;
	for (i = 0; i < n; i++)
		s += a[i] / 100.0;
	return ceil(s) * 35;
}

int
main()
{
	int a1[] = { 750, 750, 750, 750, 600 };
	int a2[] = { 700, 750, 700, 750, 600 };
	int a3[] = { 574, 574, 574, 574, 574 };
	int a4[] = { 0, 0, 0, 0, 0 };
	int a5[] = { 1, 1, 1, 1, 1 };

	assert(paycheese(a1, nelem(a1)) == 1260);
	assert(paycheese(a2, nelem(a2)) == 1225);
	assert(paycheese(a3, nelem(a3)) == 1015);
	assert(paycheese(a4, nelem(a4)) == 0);
	assert(paycheese(a5, nelem(a5)) == 35);

	return 0;
}
