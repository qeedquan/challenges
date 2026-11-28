/*

Yup, you read the title right. play the sound of pi.

More specifically, for every digit of pi in the first 1000, map it to a musical note and output the resulting melody to a file.

Basically, each digit turns to a note on the C Major scale (basically the normal scale). so 1 turns to Middle C, 2 turns to D4, 3 turns to E4, 9 turns to D5 and so on.

Rules
Each note should be exactly 0.5 seconds long.
The melody should contain the first 1000 digits of pi, including the starting 3.
1 to 7 represent Middle C to B4, 8 is C5, 9 is D5 and 0 is E5
All well supported file formats are allowed, as long as they were created before this challenge.
There may be no pauses anywhere in the file, including the start and end.
The instrument played does not matter. It could be a piano, sine wave, anything really, as long as the correct sound is easily hearable.
It must take no input and produce no output except for the file. Reading from other files is disallowed.
Standard loopholes are forbidden.
Example mathematica code:

(*please forgive me for this horrible, horrible mess of code*)
digits = RealDigits[Pi, 10, 1000][[1]] /. {0 -> 10};
weights = {0, 2, 4, 5, 7, 9, 11, 12, 14, 16};
melody = {};
For[i = 1, i < 1001, i++, melody = {melody , Sound[SoundNote[weights[[digits[[i]]]], 0.5]]}]
final = Sound[Flatten[melody]];
Export["C:\\Mathematica Shenanigans\\pi.wav", final];
Example melody showing first 100 digits: http://vocaroo.com/i/s0cfEILwYb8M

For your sanity, A table of pitches for each note and what note does each digit represent:

Digit 1: C: 261.63 Hz
Digit 2: D: 293.66 Hz
Digit 3: E: 329.63 Hz
Digit 4: F: 349.23 Hz
Digit 5: G: 392.00 Hz
Digit 6: A: 440.00 Hz
Digit 7: B: 493.88 Hz
Digit 8: C5: 523.25 Hz
Digit 9: D5: 587.33 Hz
Digit 0: E5: 659.25 Hz

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

#define TAU (2 * M_PI)

// Ported from @Abel Tom solution

void
play(float freq)
{
	char buffer[10000];
	int i;

	for (i = 0; i < 5000; i++) {
		buffer[i] = 35 * sin(freq * (TAU * i) / 10000);
		putchar(buffer[i]);
	}
}

void
melody(const char *song)
{
	float note[10];
	size_t i;

	note[0] = 261.63;
	for (i = 1; i <= 6; i++) {
		if (i == 3)
			note[i] = 349.23;
		else
			note[i] = 1.12231 * note[i - 1];
	}

	for (i = 7; i <= 9; i++)
		note[i] = 2 * note[i - 7];

	for (i = 0; song[i]; i++) {
		switch (song[i]) {
		case '1':
			play(note[0]);
			break;
		case '2':
			play(note[1]);
			break;
		case '3':
			play(note[2]);
			break;
		case '4':
			play(note[3]);
			break;
		case '5':
			play(note[4]);
			break;
		case '6':
			play(note[5]);
			break;
		case '7':
			play(note[6]);
			break;
		case '8':
			play(note[7]);
			break;
		case '9':
			play(note[8]);
			break;
		case '0':
			play(note[9]);
			break;
		default:
			play(note[0]);
			break;
		}
	}
}

int
main()
{
	const char *pi = "314159265358979323846264338327950288419716939937510"
	                 "58209749445923078164062862089986280348253421170679"
	                 "82148086513282306647093844609550582231725359408128"
	                 "48111745028410270193852110555964462294895493038196"
	                 "44288109756659334461284756482337867831652712019091"
	                 "45648566923460348610454326648213393607260249141273"
	                 "72458700660631558817488152092096282925409171536436"
	                 "78925903600113305305488204665213841469519415116094"
	                 "33057270365759591953092186117381932611793105118548"
	                 "07446237996274956735188575272489122793818301194912"
	                 "98336733624406566430860213949463952247371907021798"
	                 "60943702770539217176293176752384674818467669405132"
	                 "00056812714526356082778577134275778960917363717872"
	                 "14684409012249534301465495853710507922796892589235"
	                 "42019956112129021960864034418159813629774771309960"
	                 "51870721134999999837297804995105973173281609631859"
	                 "50244594553469083026425223082533446850352619311881"
	                 "71010003137838752886587533208381420617177669147303"
	                 "59825349042875546873115956286388235378759375195778"
	                 "18577805321712268066130019278766111959092164201989";
	melody(pi);
	return 0;
}
