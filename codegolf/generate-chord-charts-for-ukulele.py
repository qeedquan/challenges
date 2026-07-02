#!/usr/bin/env python3

"""

Your task is to write a function which outputs a ukulele chord chart in the following format for a given chord symbol. For instance, for input "G7", it must output:

 G C E A
---------
| | |#| |
---------
| |#| |#|
---------
| | | | |
---------
| | | | |
---------
| | | | |
---------
It must support all chords of these forms: X Xm X7 Xm7 Xmaj7 Xsus4 Xdim Xdim7

where X is any of A A# B C C# D D# E F F# G G#

(Supporting flats, such as Bb and Eb, is not required.)

The rest of the challenge description (until "Output and scoring") is purely explanatory: if you know ukulele chords already, you don't need it.

There are three steps parts to producing the chart for a chord.

First, work out which notes are in the chord.
Choose the correct fret for each string to match the notes.
Draw the chart.
Work out which notes are in the chord
There are 12 notes in the cyclical music scale, each a semitone apart: A, A#, B, C, C#, D, D#, E, F, F#, G, G#, then A, A#....

(If you're not into music, just mentally translate every "A" into a 0, every "A#" into a 1, etc, and everything will work out just fine.)

A chord is a set of 3 or 4 notes, according to a defined pattern of intervals starting from the base note:

X: 0 + 4 + 3 ("major"). Example: C, C+E+G
Xm: 0 + 3 + 4 ("minor"). Example: Cm, C+D#+G
X7: 0 + 4 + 3 + 3 ("seven"). Example: C7, C+E+G+A#
Xm7: 0 + 3 + 4 + 3 ("minor seven"). Example: Cm7, C+D#+G+A#
Xmaj7: 0 + 4 + 3 + 4 ("major seven") . Example: Cmaj7, C+E+G+B
Xsus4: 0 + 5 + 2 ("sus four"): Example: Csus4, C+F+G
Xdim: 0 + 3 + 3 ("diminished"). Example: Cdim, C+D#+F#
Xdim7: 0 + 3 + 3 + 3 ("diminished seven"). Example: C+D#+F#+A#. [You may find it helpful to know that this is the same chord as A#dim7, D#dim7 and F#dim7].
(The name in parentheses is just for your music education, it's not relevant to the challenge.)

For instance: "Am" is a chord, where "A" is the base note, and "m" is the chord type. Looking up the table ("Xm: 0 + 3 + 4"), we see it has 3 notes:

the base note (A),
the note 3 semitones above (C, counting A# and B), and
the note 4 semitones above that (E).
(Chords that have 3 notes will by necessity be repeating one of the notes across the 4 strings. That's fine.)

Choose the correct frets for the notes
Ukulele is an instrument with four strings, that play the notes G, C, E and A. Pressing the string against a fret makes it sound higher, one semitone per fret. (Pressing fret 1 on the A string turns it to A#, fret 2 turns it to B, etc).

Chord charts
The chord chart represents the first few frets, played by the left hand, read from top to bottom ("higher" frets are lower down the page). The strings are the columns separated by | symbols. The frets are the rows separated by - symbols. The symbol # means that the string is pressed against that fret ("is fretted"), while the right hand strums.

So in the chord chart at the start:

The G string is not fretted (it is "open"), so it sounds like G.
The C string is fretted on fret 2 (two semitones up), so it sounds like D.
The E string is on fret 1 (one semitone up), and sounds like F.
The A string is on fret 2, so sounds like B.
So this chord has notes: G, D, F, B. (It's G7, G+B+D+F - the order of the pitches doesn't matter.)

Calculating chords
To calculate which fret to play for a given string, for a given chord:

if the string's base note (G, E, A or C) is not already in the chord, play the lowest fret that belongs to the chord
repeat for each of the four strings.
Example #1
For instance, let's play E7 (consisting of E + G# + B + D).

The G string is not in the chord. Raise it to G# (fret 1).
The C string is not in the chord. Raise it to D (fret 2).
The E string is in the chord. Don't fret it. (Leave the string open.)
The A string is not in the chord. Raise it to B (fret 2).
So we are playing: G#, D, E, B.

So we output:

 G C E A
---------
|#| | | |
---------
| |#| |#|
---------
| | | | |
---------
| | | | |
---------
| | | | |
---------
Example #2
Another example: G# (consisting of G# + B# + D#):

The G string is not in the chord, raise it to G# (fret 1).
The C string is in the chord (B#), don't fret it.
The E string is not in the chord, raise it to G# (fret 4).
The A string is not in the chord, raise it to B#(C) (fret 3)
So we are playing G#, C, G#, C

 G C E A
---------
|#| | | |
---------
| | | | |
---------
| | | |#|
---------
| | |#| |
---------
| | | | |
---------
(You may notice that sometimes not every note in the chord ends up getting played. Don't worry about it. "Proper" ukulele chords are slightly more complicated than this basic algorithm.)

Output and scoring
Your output must closely match the above. (You can use other characters instead of |, - and #, such as em-dashes or ASCII line-drawing characters, if they are visually superior. An unfilled circle character would be better than #). Trailing linespace on each line is ok. Whitespace before the first line or after the last line is not ok. Final linefeed is optional.

Normal forms of input and output. You will receive one chord name, guaranteed to be in the table above, in the correct case.

Standard loopholes disallowed. Online services are disallowed. If your language has music functions in its standard library, you may use them (but not if they're plugins, packages, etc.)

This is code-golf. Lowest score (in bytes) wins.

Extra credit
This simple algorithm sometimes produces useless chord fingerings that don't include all the important notes of the chord. (For instance, for Dm, it produces ACFA, the same as Fm.)

For extra credit, modify the algorithm so that:

For all chords, the root and third (first two notes, usually 0 and 3 or 0 and 4) are played on at least one string each.
For 4-note chords (X7, Xm7, Xmaj7, Xdim7), the root, third and seventh (first, second and fourth notes) are played on at least one string each.

"""

"""

Ported from @CCB60 solution

Commentary
Thanks for a fun challenge. My daughter and I are off to buy a uke this weekend. I've never played the uke, but I play mandolin, and the theory is similar.

For this submission (my first), I addressed the original challenge without the extra credit components. I fear addressing the extra credit questions will add a lot of of bytes to the code. I hope to submit again with the extra credit bits, time permitting.

The logic is pretty simple if you trace your way back through the successive functions: 1. Parse the chord description. 2. Identify what notes are in that chord. 3. Figure out what frets on each string would fit 4. Assemble a chord by selecting the lowest fret that works on each string 5. Print out the chart fret by fret.

The core of the golfed code lies in the gnarly mess of nested list comprehensions in the eighth -- now seventh -- line of the code. The best way I can explain what's going on is by presenting the ungolfed version.

(Wheat Wizard suggested a shift from list comprehensions to generators that was not reflected in this ungolfed code)

"""

STRINGS = 'GCEA' # Ukelele
#STRINGS = 'GDAE' # Mandolin
NOTES = ['A','A#','B','C','C#','D','D#','E','F','F#','G','G#']
TYPES = {
    '': (0, 4, 7),
    'm': (0, 3, 7),
    '7': (0, 4, 7, 10),
    'm7': (0, 3, 7, 10),
    'maj7': (0, 4, 7, 11),
    'sus4': (0, 5, 7),
    'dim': (0, 3, 6),
    'dim7': (0, 3, 6, 9)
}

def parse(x):
    # Parses the chord into the root and the chord type
    i = 2 if '#' in x else 1
    return (x[:i], x[i:])

def strng(string, notes):
    # Return a list of possible fret locations based on notes in a chord
    # This will return all possible fret locations, including those
    # beyond the fifth fret, where this code stops drawing.
    return sorted([(NOTES.index(i) - NOTES.index(string))%12 for i in notes])

def chordnotes(note, typ):
    # Return the list of Notes that belong to the chord
    return  [NOTES[(a + NOTES.index(note))%12] for a in TYPES[typ]]

def chord(note, typ):
    # Returns a list of four fret locations, in order of the strings.
    # This is the heart of the musical logic of the code. Here I use a naive
    # approach, and simply grab the lowest note on each string that fits the
    # chord.  This function needs to be rewritten to address the extra
    # credit parts of the challenge.
    # The extra parentheses in the function declaration allow us to pass in
    # the results of the parse function directly.
    x = []
    for s in STRINGS:
        x.append(min(strng(s, chordnotes(note,typ))))
    return x

def printchart(x):
    # Do the heavy lifting of formatting the output
    # I calculate the layout of each fret, and print them in turn.
    note, typ = parse(x)
    ch = chord(note, typ)
    print(' ' + ''.join([a + ' ' for a in STRINGS]))
    fret = '-' * 9
    for f in range(5):
        note = ['|o' if i == f+1 else '| ' for i in ch]
        print(fret + '\n' + ''.join(note) + '|')
    print()

def main():
    printchart('G')
    printchart('C')
    printchart('E')
    printchart('A')

main()
