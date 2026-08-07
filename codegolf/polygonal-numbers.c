/*

A polygonal number is the number of dots in a k-gon of size n.

You will be given n and k, and your task is to write a program/function that outputs/prints the corresponding number.

Scoring
This is code-golf. Shortest solution in bytes wins.

Example

https://i.stack.imgur.com/5z3yt.png

The 3rd hexagon number (k=6, n=3) is 28 because there are 28 dots above.

Testcases
Can be generated from this Pyth test suite.

Usage: two lines per testcase, n above, k below.

n    k  output
10   3  55
10   5  145
100  3  5050
1000 24 10990000

Further information
In Wikipedia: https://en.wikipedia.org/wiki/Polygonal_number
In Wolfram Mathworld: http://mathworld.wolfram.com/PolygonalNumber.html
In OEIS Wiki: http://oeis.org/wiki/Polygonal_numbers
OEIS sequences for n-gonal numbers for various n: 3 (A000217), 4 (A000290), 5 (A000326), 6 (A000384), 7 (A000566), 8 (A000567), 9 (A001106), 10 (A001107), 11 (A051682), 12 (A051624), 13 (A051865), 14 (A051866), 15 (A051867), 16 (A051868), 17 (A051869), 18 (A051870), 19 (A051871), 20 (A051872), 21 (A051873), 22 (A051874), 23 (A051875), 24 (A051876)

*/

#include <assert.h>

typedef long long vlong;

vlong
polygonal(vlong n, vlong k)
{
	return (k - 2) * ((n * (n - 1)) / 2) + n;
}

int
main(void)
{
	assert(polygonal(7, 3) == 28);
	assert(polygonal(10, 3) == 55);
	assert(polygonal(10, 5) == 145);
	assert(polygonal(100, 3) == 5050);
	assert(polygonal(1000, 24) == 10990000);

	return 0;
}
