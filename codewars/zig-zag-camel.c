/*

A camel at the base of a large sand dune wants to get to the top of it to see what is on the other side.

The dune distance d and height h are as shown below:

                              ....+
                          ........|
                      ............|
                  ................| h
              ....................|
          ........................|
Camel ----------------------------+
                    d
Steep dunes don't worry him because this is a smart camel!
When the slope is > 30 degrees, then instead of going straight up he will zig-zag back and forth so the climb is not so steep.

Kata Task
Given d and h then what is the shortest amount of walking for our smart camel to get to the top of the sand dune?

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
zzc(double d, double h)
{
	if ((d / h) > 1.7)
		return hypot(d, h);
	return h + h;
}

void
test(double d, double h, double r)
{
	double v;

	v = zzc(d, h);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-12);
}

int
main()
{
	test(9, 6, 12);
	test(10, 5, 11.18033988749895);
	return 0;
}
