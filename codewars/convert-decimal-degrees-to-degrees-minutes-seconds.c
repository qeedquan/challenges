/*

Convert Decimal Degrees to Degrees, Minutes, Seconds.

Remember: 1 degree = 60 minutes; 1 minute = 60 seconds.

Input: Positive number.

Output: Array [degrees, minutes, seconds]. E.g [30, 25, 25]

Trailing zeroes should be omitted in the output. E.g

convert (50)
//correct output -> [50]
//wrong output -> [50, 0, 0]

convert(80.5)
//correct output -> [ 80, 30 ]
//wrong output -> [80, 30, 0]

convert(0.0001388888888888889)
//correct output -> [ 0, 0, 1 ]
//wrong output -> [1]

Round the seconds to the nearest integer.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void
convert(double d, int r[3])
{
	double t, m, s;

	t = floor(d);
	m = floor((d - t) * 60);
	s = round(((d - t) * 60 - m) * 60);
	if (s >= 60) {
		m += s / 60;
		s = 0;
	}
	if (m >= 60) {
		t += m / 60;
		m = 0;
	}

	r[0] = t;
	r[1] = m;
	r[2] = s;
}

void
test(double d, int r[3])
{
	int x[3];

	convert(d, x);
	printf("%d %d %d\n", x[0], x[1], x[2]);
	assert(!memcmp(x, r, sizeof(x)));
}

int
main()
{
	int r1[] = { 0, 0, 0 };
	int r2[] = { 40, 34, 1 };
	int r3[] = { 80, 30, 0 };
	int r4[] = { 20, 59, 56 };
	int r5[] = { 33, 19, 59 };
	int r6[] = { 50, 0, 0 };
	int r7[] = { 0, 0, 1 };
	int r8[] = { 0, 0, 0 };
	int r9[] = { 91, 20, 0 };
	int r10[] = { 69, 22, 0 };
	int r11[] = { 262, 13, 0 };

	test(0, r1);
	test(40.567, r2);
	test(80.5, r3);
	test(20.999, r4);
	test(33.333, r5);
	test(50, r6);
	test(0.0001398888888888889, r7);
	test(0.0001388888888888888, r8);
	test(91.33333333333333, r9);
	test(69.36666666666666, r10);
	test(262.21666666666664, r11);

	return 0;
}
