/*

Play the initial section of the Final Fantasy Prelude. This is a 4-octave up-down arpeggio of the following chords:

Cadd2, Amadd2, Cadd2, Amadd2, Fadd2, Gadd2, G♯maj7, A♯maj7

Rules:

Actual sound must play when running your code. What environment is used is up to you, for example it could be a fantasy console, or a computer with an IBM PC compatible internal speaker.
Any instrument is fine, including simple beeps, as long as the melody is clearly recognizable.
The tempo is 80 bpm, and the individual notes are sixteenth notes, so playing the arpeggio of the 8 chords should take 48 seconds.
Looping the song is allowed but not mandatory.
The first note is a C3, which has a frequency of 440*2^(-21/12) ≈ 130.8 Hz.
After 4 octaves of going up, the arpeggio goes back down starting at C7, using the notes of the same chord.
Then the next chord starts. The other chords start at: A2, C3, A2, F2, G2, G♯2 and A♯2.Slight inaccuracies in frequencies and tempo are allowed.
If it makes things easier, you may substitute A♭maj7 and B♭maj7 for the last two chords.

Scoring:

This is code golf, so shortest code wins.
The score is multiplied by the number of languages and external tools you are using. So calling system("sox …") from C has a multiplier of 3, as it uses C, a shell and sox.
The interpreter (if any) of your program does not count for the multiplier. So if your program is just an MP3 file, its interpreter can be a music player, so it has a multiplier of 1.
Music theory quickstart:

A note, like C, can appear in many octaves. If you go one octave up, its frequency doubles, if you go one down, the frequency halves.
Most "western" music uses the 12 tone equal temperament, which means there are twelve notes in one octave,
such that the ratio of frequencies between any two consecutive notes is the same, so pow(2, 1/12) or equivalently 2^(1/12).

Chords are combination of notes that are normally played simultaneously, but in this case they are meant to be played individually.
To avoid having to learn chord notation, here are the note numbers for the first octave of each chord:

0, 2, 4, 7
-3, -1, 0, 4
0, 2, 4, 7
-3, -1, 0, 4
-7, -5, -3, 0
-5, -3, -1, 2
-4, 0, 3, 7
-2, 2, 5, 9

Where number 0 has been chosen for C3. So to convert a given note number n to a frequency,
use the formula 440⋅ * 2^((n − 21)/12) To go one octave up, just add 12 to n.

*/

var note_duration = 0.2;
var note_deltas = [
   0,  2,  2,  3,  5,  2,  2,  3,  5,  2,  2,  3,
   5,  2,  2,  3,  5, -5, -3, -2, -2, -5, -3, -2,
  -2, -5, -3, -2, -2, -5, -3, -2, -5,  2,  1,  4,
   5,  2,  1,  4,  5,  2,  1,  4,  5,  2,  1,  4,
   5, -5, -4, -1, -2, -5, -4, -1, -2, -5, -4, -1,
  -2, -5, -4, -1,  1,  2,  2,  3,  5,  2,  2,  3,
   5,  2,  2,  3,  5,  2,  2,  3,  5, -5, -3, -2,
  -2, -5, -3, -2, -2, -5, -3, -2, -2, -5, -3, -2,
  -5,  2,  1,  4,  5,  2,  1,  4,  5,  2,  1,  4,
   5,  2,  1,  4,  5, -5, -4, -1, -2, -5, -4, -1,
  -2, -5, -4, -1, -2, -5, -4, -1, -6,  2,  2,  3,
   5,  2,  2,  3,  5,  2,  2,  3,  5,  2,  2,  3,
   5, -5, -3, -2, -2, -5, -3, -2, -2, -5, -3, -2,
  -2, -5, -3, -2,  0,  2,  2,  3,  5,  2,  2,  3,
   5,  2,  2,  3,  5,  2,  2,  3,  5, -5, -3, -2,
  -2, -5, -3, -2, -2, -5, -3, -2, -2, -5, -3, -2,
  -1,  4,  3,  4,  1,  4,  3,  4,  1,  4,  3,  4,
   1,  4,  3,  4,  1, -1, -4, -3, -4, -1, -4, -3,
  -4, -1, -4, -3, -4, -1, -4, -3, -2,  4,  3,  4,
   1,  4,  3,  4,  1,  4,  3,  4,  1,  4,  3,  4,
   1, -1, -4, -3, -4, -1, -4, -3, -4, -1, -4, -3,
  -4, -1, -4, -3
];

// ported from @rougepied solution
function play() {
    let audio = new AudioContext();
    let oscillator = audio.createOscillator();

    oscillator.type = "sine";
    let note = 3;
    for (let index = 0; index < note_deltas.length; index++) {
        let freq = 110 * Math.pow(2, note / 12);
        let time = index * note_duration;

        oscillator.frequency.setValueAtTime(freq, time);
        note += note_deltas[index];
    }

    oscillator.addEventListener("ended", function() {
        play();
    });

    oscillator.connect(audio.destination);
    oscillator.start();
    oscillator.stop(note_deltas.length * note_duration);
}