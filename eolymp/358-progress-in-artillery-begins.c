/*

Artillery has always been a branch of the military that uses various calculation devices intensively.
In the past, these devices were mechanical and displayed results using wheels painted with numbers.
However, progress did not stand still.
Designers eventually developed an electrical device that shows results using segmented LED indicators.

https://static.e-olymp.com/content/0a/0ab1a483b336da63114679009ef40c5f777e3d68.jpg

To mark this progress, you need to develop a program that, for a given number, determines the number of LEDs that must light up to properly display the number.

Input
A number N (0≤N≤10^9).

Output
The required number of LEDs.

Examples

Input #1
123

Answer #1
12

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
solve(uvlong n)
{
	static const uvlong lut[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
	uvlong r;

	r = 0;
	do {
		r += lut[n % 10];
		n /= 10;
	} while (n > 0);

	return r;
}

int
main()
{
	assert(solve(123) == 12);

	return 0;
}
