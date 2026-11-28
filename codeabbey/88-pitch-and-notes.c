/*

https://codeabbey.github.io/data/cat_violin.png

Playing violin is difficult because it can produce sound of every possible frequency
not necessarily bounded to subset of conventional notes...
The music could be represented as a stream of different sounds. We can distinguish these sounds as they have different tones. For example if we listen to "Moonlight Sonata" of Beethoven, its 1st movement (find it on youtube if you forget what it is) - our ear easily catch in the beginning the same pattern of 3 tones played several times.

These tones are called notes in music. From physical point of view they are just stable oscillations (of a string or some other part of instrument) in the air.

Such oscillations are characterized firstly by the frequency - i.e. simply the amount of "forth-and-back" movements performed during a second. If the string make 440 such oscillations per second, we say it has a pitch (or frequency) of 440 Hz (the measurement unit is called Hertz after famous German scientist who discovered electromagnetic waves while trying to prove they could not exist).

What is important, notes have not some randomly assigned pitch, but rather one defined by simple mathematical law. This task is dedicated to calculation of note frequencies.

NOTE NAMES

In music the whole range of possible pitches is divided in octaves. Each octave have frequency range twice larger compared to preceding one, i.e. if one octave covers the range 110 ... 220 Hz, the next will cover the range 220 ... 440 Hz, while third - 440 ... 880 Hz.

Each octave has 12 notes in it, of them 7 have proper names, C D E F G A B in English musical notation. Other 5 notes are added between some of these and have derived names, so the whole octave looks like:

C  C#  D  D#  E  F  F#  G  G#  A  A#  B
Notes with # sign are read as C-sharp for example. You see, there are no "sharps" for E and B - strictly speaking E# has the same pitch as F and B# has the same pitch as C of the next octave.

So the full title of the note consists of its own name and the number of octave, e.g.:

A2 G#5 G#2 A1 F3 D4 D2 E5 C#3 D#1 E3 C2 F4 B2 A#3 D3 D1 B5 A#4
(do not try to play this on piano - it would not yield nice music, ha-ha)

FREQUENCY LAW

You see, the frequency range of octave is not constant. Rathe the ratio between ranges of octaves is a constant factor of 2. The same with notes - the ratio of frequencies of two neighbor notes is a constant - and has such a value that if we multiply it by itself for 12 times (i.e. raising note for 12 steps) whe get the value of 2, i.e. the whole octave.

You may guess that since the ratios of octave steps is represented by a sequence of powers of 2, i.e.:

2 ^ 1 = 2   2 ^ 2 = 4   2 ^ 3 = 8 ...
then the ratios of single note steps are created similarly:

2 ^ (1/12)   2 ^ (2/12)   2 ^ (3/12)   ...   2 ^ (12/12) = 2 ^ 1
Calculator will help us to see that the ratio for a single pitch step is 1.059463094, though it is not important.

Now we can find the frequency for any note, though we need some basis point. Internationaly it is chosen as the pitch for A4 note which is exactly 440 Hz, so that A3 is 220 Hz and C4 is about 261.63 Hz etc.

PROBLEM STATEMENT

You are given a sequence of notes - calculate frequencies for them using the explanations above.

Input data will have the number of notes in the first line.
Next line contains note names separated by spaces.
Answer should contain frequencies for these notes, rounded to nearest integer.

Example:

input data:
22
G#4 F#1 G#2 A#1 E5 A4 A#3 E1 A3 A2 D#5 G#5 B2 A1 F2 D5 F4 C#3 D1 B3 F#2 C#5

answer:
415 46 104 58 659 440 233 41 220 110 622 831 123 55 87 587 349 139 37 247 92 554

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[4];
	double frequency[9];
} Note;

int
find_frequency(const char *name)
{
	// https://muted.io/note-frequencies/
	static const Note notes[] = {
		{ "C", { 16.35, 32.7, 65.41, 130.81, 261.63, 523.25, 1046.5, 2093, 4186 } },
		{ "C#", { 17.32, 34.65, 69.3, 138.59, 277.18, 554.37, 1108.73, 2217.46, 4434.92 } },
		{ "D", { 18.35, 36.71, 73.42, 146.83, 293.66, 587.33, 1174.66, 2349.32, 4698.63 } },
		{ "D#", { 19.45, 38.89, 77.78, 155.56, 311.13, 622.25, 1244.51, 2489, 4978 } },
		{ "E", { 20.6, 41.2, 82.41, 164.81, 329.63, 659.25, 1318.51, 2637, 5274 } },
		{ "F", { 21.83, 43.65, 87.31, 174.61, 349.23, 698.46, 1396.91, 2793.83, 5587.65 } },
		{ "F#", { 23.12, 46.25, 92.5, 185, 369.99, 739.99, 1479.98, 2959.96, 5919.91 } },
		{ "G", { 24.5, 49, 98, 196, 392, 783.99, 1567.98, 3135.96, 6271.93 } },
		{ "G#", { 25.96, 51.91, 103.83, 207.65, 415.3, 830.61, 1661.22, 3322.44, 6644.88 } },
		{ "A", { 27.5, 55, 110, 220, 440, 880, 1760, 3520, 7040 } },
		{ "A#", { 29.14, 58.27, 116.54, 233.08, 466.16, 932.33, 1864.66, 3729.31, 7458.62 } },
		{ "B", { 30.87, 61.74, 123.47, 246.94, 493.88, 987.77, 1975.53, 3951, 7902.13 } },
	};

	const Note *note;
	char buffer[16];
	size_t i, j;

	for (i = 0; i < nelem(notes); i++) {
		note = notes + i;
		for (j = 0; j < nelem(note->frequency); j++) {
			snprintf(buffer, sizeof(buffer), "%s%zu", note->name, j);
			if (!strcmp(name, buffer)) {
				return round(note->frequency[j]);
			}
		}
	}
	return -1;
}

void
solve(const char **names, size_t num_names)
{
	size_t i;

	for (i = 0; i < num_names; i++)
		printf("%d ", find_frequency(names[i]));
	printf("\n");
}

int
main()
{
	static const char *names[] = {
		"G#4", "F#1", "G#2", "A#1", "E5",
		"A4", "A#3", "E1", "A3", "A2", "D#5", "G#5", "B2",
		"A1", "F2", "D5", "F4", "C#3", "D1", "B3", "F#2", "C#5"
	};

	solve(names, nelem(names));

	return 0;
}
