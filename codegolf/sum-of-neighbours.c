/*

This should be a fairly simple challenge.

For an array of numbers, generate an array where for every element all neighbouring elements are added to itself, and return the sum of that array.

Here is the transformation which occurs on the input array [1,2,3,4,5]

[1,2,3,4,5] => [1+2, 2+1+3, 3+2+4, 4+3+5, 5+4] => [3,6,9,12,9] => 39
 0          => neighbours of item 0, including item 0
[1,2]       => 1 + 2      => 3
   1
[1,2,3]     => 1 + 2 + 3  => 6
     2
  [2,3,4]   => 2 + 3 + 4  => 9
       3
    [3,4,5] => 3 + 4 + 5  => 12
         4
      [4,5] => 4 + 5      => 9

               3+6+9+12+9 => 39
Test cases
[]            => 0 (or falsy)
[1]           => 1
[1,4]         => 10 (1+4 + 4+1)
[1,4,7]       => 28
[1,4,7,10]    => 55
[-1,-2,-3]    => -14
[0.1,0.2,0.3] => 1.4
[1,-20,300,-4000,50000,-600000,7000000] => 12338842

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
neighborsum(double *a, size_t n)
{
	size_t i;
	double r;

	r = 0;
	for (i = 0; i < n; i++) {
		if (i > 0)
			r += a[i - 1];
		r += a[i];
		if (i + 1 < n)
			r += a[i + 1];
	}
	return r;
}

int
main()
{
	double a1[] = { 1, 2, 3, 4, 5 };
	double a2[] = { 1 };
	double a3[] = { 1, 4 };
	double a4[] = { 1, 4, 7 };
	double a5[] = { 1, 4, 7, 10 };
	double a6[] = { -1, -2, -3 };
	double a7[] = { 0.1, 0.2, 0.3 };
	double a8[] = { 1, -20, 300, -4000, 50000, -600000, 7000000 };

	printf("%.1f\n", neighborsum(a1, nelem(a1)));
	printf("%.1f\n", neighborsum(NULL, 0));
	printf("%.1f\n", neighborsum(a2, nelem(a2)));
	printf("%.1f\n", neighborsum(a3, nelem(a3)));
	printf("%.1f\n", neighborsum(a4, nelem(a4)));
	printf("%.1f\n", neighborsum(a5, nelem(a5)));
	printf("%.1f\n", neighborsum(a6, nelem(a6)));
	printf("%.1f\n", neighborsum(a7, nelem(a7)));
	printf("%.1f\n", neighborsum(a8, nelem(a8)));

	return 0;
}
