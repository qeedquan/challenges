/*

The Euclidean algorithm is a widely known algorithm for calculating the greatest common divisor (GCD) of two positive integers.

The algorithm
For the purpose of this challenge, the algorithm is described as below:

Display the two input as adjacent lines of a certain character
e.g. an input of 3,4 can be represented by the adjacent lines 000 and 0000

Turn the first length(short_line) characters in the longer line into another character, say -
now it looks like 000 and ---0

Eliminate the first length(short_line) characters in the longer line.
now 000, 0

Repeat step 2 and 3 until the two have equal length, using the shorter and longer lines after each iteration, e.g.
000,0
-00,0
00,0
-0,0
0,0

You can choose whether to stop here or continue the iteration and turn one of the lines into an empty line.
Each of these steps should be separated by an interval between 0.3s and 1.5s.

The challenge
Write a program that, given two natural numbers as input, creates an output that looks exactly the same as the output of the algorithm above. You can use other non-whitespace printable ASCII characters than 0 and -, but be consistent and use only two characters. You can also use alternative algorithms provided the output, including the timing, is exactly the same as would be produced by the algorithm above.

Examples
This is an example with input 24,35, which are coprimes so their GCD is 1.

enter image description here

This is an example with input 16,42, which have the GCD 2.

enter image description here

Rules
This is a code-golf, so shortest bytes wins
Standard loopholes apply
You can assume input to be positive decimal integers
Unless you are using sed, Retina, ///, etc, in which case you can use unary
Clarifications

The lines that represent the numbers need to stay in their original order, i.e. the first and second lines of the first displayed "frame" need to be the first and second lines respectively, in all subsequent frames.
After the algorithm ends, no additional visible entity should appear. However, this also means that it is okay to blank the lines, if you make sure that the last "frame" is displayed for at least the same amount of time as did all other frames before blanking out.

*/

#include <stdio.h>
#include <unistd.h>

typedef unsigned int uint;

void
clear(void)
{
	printf("\033c");
}

void
print1(uint n)
{
	uint i;

	for (i = 0; i < n; i++)
		printf("0");
	printf("\n");
}

void
print2(uint n, uint m)
{
	uint i;

	for (i = 0; i < n; i++)
		printf("-");
	for (i = 0; i < m; i++)
		printf("0");
	printf("\n");
}

void
visgcd(uint a, uint b)
{
	for (;;) {
		clear();
		print1(a);
		print1(b);
		if (a < 1 || b < 1)
			break;
		sleep(1);

		clear();
		if (a > b) {
			print2(b, a - b);
			print1(b);
			a -= b;
		} else {
			print1(a);
			print2(a, b - a);
			b -= a;
		}
		sleep(1);
	}
}

int
main(void)
{
	visgcd(24, 35);

	return 0;
}
