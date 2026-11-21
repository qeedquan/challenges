/*

This task is the reverse of Pitch and Notes (so perhaps you may want to read or solve it first) - suppose you are building the electronic tuner for guitar, violin or piano - and you already connected microphone to microcontroller and succeeded in registering the sound wave, smoothering it and measuring its frequency.

Now the only thing remained is to write a part of program responsible for determining the note played by its frequency.
I.e. if the device have detected sound of 440 Hz it should be able to tell that note A4 is played.

Since in reality instruments could be slightly out of tune, you need not expect that pitch will be mathematically exact. Nevertheless you'll be able to determine the nearest note. I.e. frequencies of 433 Hz or 449 Hz should anyway be classified as A4.

Input data contains number of notes to identify.
The next line will provide the frequencies, separated by spaces.
Answer should contain identified note names.

Example:

input data:
16
185.4 115.3 203.9 55.2 52.7 86.6 932.3 229.8 61.8 66.1 363.7 771.4 594.4 48.2 102.6 222.4

answer:
F#3 A#2 G#3 A1 G#1 F2 A#5 A#3 B1 C2 F#4 G5 D5 G1 G#2 A3

*/

#include <stdio.h>
#include <math.h>
#include <float.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[4];
	double frequency[9];
} Note;

char *
find_note(double frequency, char *output)
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
	double distance;
	double minimum;
	size_t i, j;

	sprintf(output, "ERROR");
	minimum = FLT_MAX;
	for (i = 0; i < nelem(notes); i++) {
		note = notes + i;
		for (j = 0; j < nelem(note->frequency); j++) {
			distance = fabs(note->frequency[j] - frequency);
			if (distance < minimum) {
				sprintf(output, "%s%zu", note->name, j);
				minimum = distance;
			}
		}
	}
	return output;
}

void
solve(const double *frequencies, size_t num_frequencies)
{
	char output[16];
	size_t i;

	for (i = 0; i < num_frequencies; i++)
		printf("%s ", find_note(frequencies[i], output));
	printf("\n");
}

int
main()
{
	static const double frequencies[] = {
		185.4, 115.3, 203.9, 55.2, 52.7, 86.6, 932.3, 229.8, 61.8, 66.1, 363.7, 771.4, 594.4, 48.2, 102.6, 222.4
	};

	solve(frequencies, nelem(frequencies));

	return 0;
}
