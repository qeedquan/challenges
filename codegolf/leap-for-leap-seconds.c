/*

Since today marks the occasion of the 26th leap second ever to occur, your challenge will be to output the date and time of every leap second in GMT or UTC that has occurred so far, as well as the one to occur today.

Input
There is no input.

Output
1972-06-30 23:59:60
1972-12-31 23:59:60
1973-12-31 23:59:60
1974-12-31 23:59:60
1975-12-31 23:59:60
1976-12-31 23:59:60
1977-12-31 23:59:60
1978-12-31 23:59:60
1979-12-31 23:59:60
1981-06-30 23:59:60
1982-06-30 23:59:60
1983-06-30 23:59:60
1985-06-30 23:59:60
1987-12-31 23:59:60
1989-12-31 23:59:60
1990-12-31 23:59:60
1992-06-30 23:59:60
1993-06-30 23:59:60
1994-06-30 23:59:60
1995-12-31 23:59:60
1997-06-30 23:59:60
1998-12-31 23:59:60
2005-12-31 23:59:60
2008-12-31 23:59:60
2012-06-30 23:59:60
2015-06-30 23:59:60
Rules
Since I doubt there are many built-ins that allow leap-seconds, I'll allow them.

Standard loopholes are disallowed.

Shortest code wins.

Date format must have a zero-padded month and a 4-digit year, as well as military time and a space separating the time from the date. Putting UTC at the end is optional. Your choice of dashes or slashes.

EDIT: Yep as predicted, this became an encoding challenge. If only encoding could fix the leap second problem, ...then all our code would be much more practical. Maybe we need some ideas for more fun challenges with practical uses?

*/

#include <stdio.h>

typedef long long vlong;

// ported from @mlepage solution
void
output()
{
	vlong X, Y, Z;

	X = 0x2495288454AAAB;
	Y = 1972;
	Z = 1;
	while (Z) {
		while (X) {
			if (X & 1)
				printf("%lld-%02lld%lld 23:59:60\n", Y, 12 - (6 * Z), Z - 31);

			Z ^= 1;
			Y += Z;
			X >>= 1;
		}
		X = 4362608640;
	}
}

int
main()
{
	output();
	return 0;
}
