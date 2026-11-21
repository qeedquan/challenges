/*

The graph of the modulo operation (y = x mod k) looks like this:

https://i.sstatic.net/FSjQG.png

This is a very useful function, as it allows us to create "wrapping" behavior.
However, it is very cumbersome when I want to use it to create an appearance of "bouncing" between two walls.
The graph of the "bounce" function (y=bounce(x,k)) looks like this:

https://i.sstatic.net/VHAf7.png

The period of the graph of y = x mod k is k.
The period of the graph of y = bounce(x, k) is 2k, because it moves upwards for k units, and then moves downwards for another k units, before returning to where it started.
For both functions, the minimum value for y is 0, and the maximum is k (Actually, for the modulus function with integral inputs, it's k−1).
In addition, for both functions, the value where x=0 is 0.

The challenge
Given an integer x and a positive integer k, return an integer or floating-point approximation of y = bounce(x, k).

This is code-golf, so the shortest valid submission (counted in bytes) wins.

Test Cases
  x,  k -> bounce(x, k)
  0, 14 ->            0
  3,  7 ->            3
 14, 14 ->           14
 15, 14 ->           13
-13, 14 ->           13 (12.999997 etc would be an acceptable answer)
-14, 14 ->           14
191,  8 ->            1
192,  8 ->            0
Bonus points for a Fourier-based approach in Fourier.

*/

#include <assert.h>
#include <stdlib.h>

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

// ported from @Leaky Nun solution
int
bounce(int x, int k)
{
	return k - abs(k - mod(x, k * 2));
}

int
main()
{
	assert(bounce(0, 14) == 0);
	assert(bounce(3, 7) == 3);
	assert(bounce(14, 14) == 14);
	assert(bounce(15, 14) == 13);
	assert(bounce(-13, 14) == 13);
	assert(bounce(-14, 14) == 14);
	assert(bounce(191, 8) == 1);
	assert(bounce(192, 8) == 0);

	return 0;
}
