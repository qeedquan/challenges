/*

Andriy loves traveling by train. As he sits by the window, he keenly observes the passing landscape, paying special attention to the kilometer markers.
He considers a marker "lucky" if its kilometer number, when divided by 7, leaves a remainder of 3.
Your task is to write a program that calculates the number of "lucky" markers between two given markers, numbered from a to b.

Input
The program receives input in the form of two natural numbers (0≤a<b≤10^9), provided on a single line.

Output
The program should output the count of "lucky" markers.

Examples

Input #1
26 49

Answer #1
3

Input #2
73 80

Answer #2
2

*/

#include <assert.h>

int
solve(int a, int b)
{
	while (a % 7 != 3)
		a++;
	while (b % 7 != 3)
		b--;

	if (b < a)
		return 0;
	if (b == a)
		return 1;
	return (b - a) / 7 + 1;
}

int
main()
{
	assert(solve(26, 49) == 3);
	assert(solve(73, 80) == 2);

	return 0;
}
