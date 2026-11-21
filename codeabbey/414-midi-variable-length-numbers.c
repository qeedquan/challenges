/*

https://imgur.com/cHR6k8x

Example of MIDI input controller - it doesn't produce sound on its own, but needs to be connected to some MIDI synthesizer unit (or computer).

This is very simple problem introducing curious feature found in MIDI data format (and some others). If you are unacquainted - MIDI stands for Musical Instruments Digital Interface and describes how various digital pianos, drum-pads and other similar music devices send their data to "synthesizer" core to produce music. Besides this, MIDI data could be stored into files (often with mid or rmi extension) which could be fed into software or hardware synthesizer to playback the recorded music - in contrast to mp3 or wav files they are much smaller (as they practically record events of producing musical notes over time, not the exact waveforms).

Such files have relatively simple format - there are bytes describing events (like "key N pressed on channel Y") and delays between these events. These delays are described as variable-length quantities. The idea is that values could be very different in their range and it seems not wise to use some fixed size integers, say 2 bytes or 4 bytes. Instead every number starts from the least significant byte and adds bytes as necessary.

How can we understand where is the end of this byte sequence? Highest bit of bytes is used for that. Last byte has its highest bit cleared (0), while all except the last have it set (1). Which means every byte only utilizes 7 bits for the number data itself, for example:

0 is 0x00
1 is 0x01
100 is 0x64
300 is 0xAC, 0x02
1000000 is 0xC0, 0x84, 0x3D
You see in this way smaller (below 128) values are represented just the same way as normal single-byte integers.

Input data will contain a sequence of bytes describing a series of delays. It ends with zero delay.

Answer just please output the total "duration" (sum of all delays) as a single decimal integer.

Example:

input:
1 100 172 2 192 132 61 0

answer:
1000401

*/

#include <assert.h>
#include <stdio.h>
#include <stdint.h>

typedef long long vlong;

vlong
solve(uint8_t *data, size_t size)
{
	vlong sum;
	vlong value;
	vlong shift;
	size_t i;

	sum = 0;
	value = 0;
	shift = 0;
	for (i = 0; i < size; i++) {
		value |= (data[i] & 0x7f) << shift;
		shift += 7;
		if (!(data[i] & 0x80)) {
			sum += value;
			value = 0;
			shift = 0;
		}
	}
	return sum;
}

int
main()
{
	uint8_t data[] = { 1, 100, 172, 2, 192, 132, 61, 0 };

	assert(solve(data, sizeof(data)) == 1000401);

	return 0;
}
