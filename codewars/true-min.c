/*

The Math.min function has stopped working, so we have to use our own function. We are off to a good start, but this function doesn't seem to handle everything properly. Add in the proper checks to return NaN for anything that isn't an actual number, except treat null like 0.

Note: This min function need not handle more than two arguments.

function min(a, b){
  return (a<b)?a:b;
}

*/

#include <stdio.h>
#include <math.h>
#include <float.h>

#define min fmin

int
main()
{
	printf("%f\n", min(NAN, NAN));
	printf("%f\n", min(5, 4));
	printf("%f\n", min(INFINITY, NAN));
	printf("%f\n", min(5, NAN));
	printf("%f\n", min(NAN, 6));
	return 0;
}
