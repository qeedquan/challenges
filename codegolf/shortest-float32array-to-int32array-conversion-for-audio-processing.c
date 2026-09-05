/*

I'm currently converting a Float32Array to an Int32Array for input to a real-time audio raw PCM to MP3 recording application.

new Int32Array([...new Float32Array(b)].map(f=>f<0?f*32768:f*32767)
The examples in the wild I've seen convert each float individually to avoid static, gaps, glitches when the audio recording is played back. I have a sense there is a way to do this without comparing each float, though I've seen no such examples in the wild for audio processing.

Looking at the I wonder is there a way to do this without comparing each float, basically, what is the shortest code to convert a Float32Array to a Int32Array or Int16Array for audio processing?

*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
cfi32(int32_t *dst, float *src, size_t len)
{
	size_t i;

	for (i = 0; i < len; i++)
		dst[i] = src[i] * (32768 + fminf(copysignf(1, -src[i]), 0));
}

int
main(void)
{
	float floats[] = {-1, 0, 1};
	int32_t ints[3];
	size_t i;

	cfi32(ints, floats, nelem(floats));
	for (i = 0; i < nelem(ints); i++)
		printf("%" PRId32 "\n", ints[i]);

	return 0;
}
