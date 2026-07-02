/*

Alex (Alex@codegolfcorp.example) So... uh, thanks for covering me last time. Look, we've had a pretty odd order from a client, but they're willing to pay a TON to have it on a microcontroller. Something about a square root or something. I'll send you the specs, buuuut they never specified how fast it had to run on the contract ;) You know what to do champ. Keep it small, and cheap, because I am not paying for bigger controllers for this... since we're probably going to end up spending half of what we make from this on the legal fees.

Julia (Julia@codegolfcorp.example) ??????? We make embedded systems, not GPUS!

You (You@codegolfcorp.example) I'll get looking for a new job after this then ;D

You've heard of the Fast Inverse Square Root... (One over the square root of x)

But how short can you make it... without resorting to math libraries or a builtin for it?

Your program must take any float input (any format), inverse square root it (with <1% error), and return it (any format).

Lowest byte count wins, performance is out of the question ;)!

Test Case! (From Wikipedia)

0.15625 -> (roughly) 2.52982 (NB: The Quake version gets 2.52549, 0.17% error)

*/

#include <stdio.h>
#include <xmmintrin.h>

__m128
invsqrt(const __m128 vec)
{
	return _mm_rsqrt_ps(vec);
}

void
print(__m128 vec)
{
	float out[4];

	_mm_storeu_ps(out, vec);
	printf("%f %f %f %f\n", out[0], out[1], out[2], out[3]);
}

int
main()
{
	__m128 vec = { 0.15625, 0.25, 0.50, 0.0625 };

	print(invsqrt(vec));

	return 0;
}
