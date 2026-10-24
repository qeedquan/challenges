#!/usr/bin/env python3

"""

For this challenge, your task is to write a program that takes a musical chord name from input (like Gm7) and outputs the notes found in that chord (G A# D F). If you're no musician, don't worry -- the progress is quite simple. The first thing you need to know about is the 12 notes of the chromatic scale:

C C# D D# E F F# G G# A A# B
The intervals between two notes is expressed in semitones. For example, there are three semitones between the D and the F on this scale. Next, you'll need to know about the different kinds of chords themselves:

chord	symbol	tones
| |major |(nothing) |[0, 4, 7]| |minor |m |[0, 3, 7]| |dom. 7th |7 |[0, 4, 7, 10]| |minor 7th |m7 |[0, 3, 7, 10]| |major 7th |maj7 |[0, 4, 7, 11]|

To find out the notes in a chord, take the base note, then select the tones from the chromatic scale relative to the numbers in the list of tone intervals. For example, for F7, we look up the chord:

7 → dom. 7th → [0, 4, 7, 10]
Then we step [0, 4, 7, 10] semitones up from F in the scale, wrapping if necessary:

[F+0, F+4, F+7, F+10] → [F, A, C, D#]
Those are the notes in our chord.

If you know a thing or two about music theory: for extra credit, tweak your program so that it...

outputs the chords "correctly", using b and bb and x where necessary

supports more complex chords like A9sus4 or Emadd13.

(Bad submission timing, and I have to go right now -- expect [easy] and [difficult] problems tomorrow. Sorry!)

"""

def chord(name):
    notes = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
    table = {
        '': [0, 4, 7],
        'm': [0, 3, 7],
        '7': [0, 4, 7, 10],
        'm7': [0, 3, 7, 10],
        'maj7': [0, 4, 7, 11]
    }

    if len(name) == 0:
        return []

    note = name[0]
    start = 1
    if len(name) > 1 and name[1] == '#':
        note += '#'
        start += 1
    position = notes.index(note)
    tones = table[name[start:]]
    return [notes[(position + tone) % len(notes)] for tone in tones]

def main():
    print(chord("C#"))
    print(chord("F"))
    print(chord("F7"))
    print(chord("Gm7"))
    print(chord("G#maj7"))
    print(chord("D#maj7"))

main()
