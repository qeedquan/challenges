/*

Today, November 11, 2015, is Veterans Day in the United States. "Taps" is the bugle call played at U.S. military funerals:

("Taps" on SoundCloud from vtmiller)
https://soundcloud.com/vtmiller/taps-bugle-call

It is a simple melody, only twenty-four notes long and using only four different notes. Here is the sheet music:
https://i.sstatic.net/QSYEP.jpg

#Challenge

Write a program or function that plays "Taps" or outputs an audio file of "Taps" in any common audio file format (e.g. MP3, WAV, MIDI). It may be played in any key, using any type of instrument or beep noise available to your language. For example, it might sound like a piano instead of a bugle. (Though still only one instrument type should be used.)

All twenty-four notes must be played with accurate pitch, duration, and spacing. Someone who is familiar with "Taps" should be able to run your code and easily recognize the song being played.

The duration of the melody (from the start of the first note to the end of the last note) must be between 30 and 70 seconds. You may optionally have up to 5 seconds of silence padding the start and/or end of your sound file, so an 80 second file is the longest allowed.

You may not, of course, simply download the song online somewhere or extract it from an audio library that happens to have it as as sample. You may, however, use audio libraries that can play/compose individual notes and create audio files.

#Scoring

This is code-golf, so the shortest answer in bytes wins. However, for this particular challenge I encourage you to not focus on your byte count, especially at the expense of sound quality. Golf your submissions but allow yourself to be creative with your instrument choice or sound output methodology. This challenge is meant to be about honoring veterans, not about screeching out a barely recognizable version of "Taps".

Note that you can embed SoundCloud audio files directly into posts by just pasting the link on an empty line. If you have a SoundCloud account this would be a great way to share your output.

*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
put4(uint32_t value)
{
	fputc(value & 0xff, stdout);
	fputc((value >> 8) & 0xff, stdout);
	fputc((value >> 16) & 0xff, stdout);
	fputc((value >> 24) & 0xff, stdout);
}

// ported from @Runium solution
void
taps()
{
	static const uint32_t wavhdr[] = {
		0x46464952, 1570852, 0x45564157, 544501094, 16, 65537, 44800, 44800, 524289, 0x61746164, 1505280
	};

	static const uint64_t notes[] = { 27863, 37193, 46860, 55727 };

	uint64_t envelope[] = { 0x422422c13c13, 0xc13c44813c22 };
	uint64_t index;
	uint64_t i, decay;

	double step, amplitude, loudness, phase;

	for (i = 0; i < nelem(wavhdr); i++)
		put4(wavhdr[i]);

	index = 0x406e64924910;
	loudness = 40;
	for (i = 0; i < 24; i++) {
		step = notes[index & 3] / 1e6;
		phase = 0;
		index >>= 2;
		amplitude = 0;
		if (i > 18) {
			loudness -= 1;
			amplitude = loudness;
		} else if (i < 14)
			amplitude = loudness + (i / 2);
		else
			amplitude = loudness + 30;

		decay = (envelope[i / 12] & 15) * 13440;
		while (decay) {
			phase += step;
			putchar(amplitude * sin(phase) + 128);

			decay -= 1;
			if (decay < 7e3 && amplitude > 0)
				amplitude -= 0.01;
		}

		envelope[i / 12] >>= 4;
	}
}

int
main()
{
	taps();
	return 0;
}
