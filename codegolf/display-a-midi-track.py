#!/usr/bin/env python3

"""

Background
MIDI files are quite different from WAV or MP3 audio files. MP3 and WAV files contain bytes representing a "recording" of the audio, while MIDI files have a series of MIDI messages stored in MIDI events informing a MIDI synthesizer which virtual instrument to play or a MIDI sequencer the playback tempo that should be used. These messages are stored in tracks, and a collection of tracks makes up a MIDI sequence, whose events can be analyzed by a sequencer and have its messages transmitted from the sequencer to a synthesizer's receiver.

Most of the time the MIDI messages stored in MIDI events are Note On messages which tell the synthesizer to play a particular note, or Note Off messages which tell the synthesizer to stop playing the note. These messages contain two track bytes, the first of which informs the synthesizer of the velocity of the note (higher velocity results in a louder note), and the second of which tells the synthesizer the note to play (i.e. Middle C). The events themselves also contain ticks which serve the purpose of telling the sequencer when to send the messages.

The Challenge
The challenge is to write a full program or a function that analyzes a series of Note On and Note Off MIDI messages in a single-track MIDI sequence and outputs to STDOUT a chart showing when particular notes are on, when they are off, and the velocity of these notes. The vertical axis of the chart represents the note value and should be labeled as described below, and the horizontal axis represents time in MIDI ticks (though it should remain unlabeled to reduce complexity and spacing issues).

Your input may be four separate arrays or lists, each containing a series of integer values; a two-dimensional array or list containing four sub-arrays/sub-lists with a series of integer values; or any other convenient means; this represents the collection MIDI events with Note On and Note Off messages in the track. The values in the first of these arrays specifies the note, the second the velocity, the third the note on event tick, and the fourth the note off event tick. For instance, given four arrays such as these:

{60, 62, 64, 65,  67}
{20, 40, 60, 80, 100}
{ 0,  4,  8, 12,  16}
{ 2,  6, 10, 14,  18}
Analyzing the first element of each array gives two events: an event at tick 0 with a message that has a Note On command, note 60 (Middle C), and note velocity of 20; and an event at tick 2 with a message that has a Note Off command with the same note and velocity.

Rules
The chart should feature the numbers 0 through 127 displayed in decreasing order on the left side (representing the note value), when the note starts, the duration of each note (Note Off tick minus Note On tick), and the note's velocity. The symbols representing the notes are dependent on their velocity:

0-15: O
16-31: =
32-47: #
48-63: -
64-79: @
80-95: +
96-111: 0
112-127: *
You can assume the following:

The values for note and velocity will be within the range [0, 127].
The lengths of each of the four arrays will always equal each other.
Here are a few examples:

{60, 62, 64, 65,  67}
{20, 40, 60, 80, 100}
{ 0,  4,  8, 12,  16}
{ 2,  6, 10, 14,  18}

127|
126|
125|
...
67 |                00
66 |
65 |            ++
64 |        --
63 |
62 |    ##
61 |
60 |==
59 |
...
2  |
1  |
0  |


{60, 48, 62, 47, 64, 45,  65,  43, 67, 41, 65, 43, 64, 45,  62, 47, 60, 48}
{63, 31, 75, 90, 12, 23, 122, 104, 33, 19, 57, 42,  5, 82, 109, 86, 95, 71}
{0,   0,  2,  2,  4,  4,   6,   6,  8,  8, 10, 10, 12, 12,  14, 14, 16, 16}
{2,   2,  4,  4,  6,  6,   8,   8, 10, 10, 12, 12, 14, 14,  16, 16, 18, 18}

127|
126|
...
68 |
67 |        ##
66 |
65 |      **  --
64 |    OO      OO
63 |
62 |  @@          00
61 |
60 |--              ++
59 |
...
49 |
48 |==              @@
47 |  ++          ++
46 |
45 |    ==      ++
44 |
43 |      00  ##
42 |
41 |        ==
40 |
...
1  |
0  |
Here's an example that displays the first few notes of Ode to Joy:

{48, 55, 64, 64, 65, 67, 55, 67, 65, 64, 62, 52, 55,  60,  60,  62,  64,  55, 64, 62, 62}
{45, 45, 63, 63, 63, 63, 89, 66, 66, 66, 66, 30, 30, 103, 103, 103, 103, 127, 55, 55, 55}
{ 0,  0,  0,  4,  8, 12, 16, 16, 20, 24, 28, 32, 32,  32,  36,  40,  44,  48, 48, 54, 56}
{16, 16,  2,  6, 10, 14, 32, 18, 22, 26, 30, 48, 48,  34,  38,  42,  46,  64, 50, 55, 64}

127|
...
67 |            --  @@
66 |
65 |        --          @@
64 |--  --                  @@                  00  --
63 |
62 |                            @@          00            - --------
61 |
60 |                                00  00
59 |
58 |
57 |
56 |
55 |################++++++++++++++++================****************
54 |
53 |
52 |                                ================
51 |
50 |
49 |
48 |################
...
0  |
You can reduce your score by 25% if your submission takes an actual MIDI sequence as input, analyzes the Note On and Note Off messages of any track of your choosing provided it contains at least four events with Note On and Note Off messages, and outputs a chart as described above.

I'll nix the bonus as it is not very practical and pose the above part as a side challenge instead. In as few bytes as you can muster, create a program that takes an actual MIDI sequence as input, analyzes the Note On and Note Off messages of any track of your choosing provided it contains at least four events with Note On and Note Off messages, and outputs a chart as described above.

This is code golf, so shortest code wins. Good luck!

"""

def display(track):
    symbols = "O=#-@+0*"
    width = max(track[3])
    rows = [" " * width for _ in range(128)]

    for number, value, start, end in zip(*track):
        character = symbols[value // 16]
        rows[number] = rows[number][:start] + character*(end - start) + rows[number][end:]

    for number in range(127, -1, -1):
        print(f"{number:3d}|{rows[number]}")
    print()

def main():
    track1 = [
        [60, 62, 64, 65,  67],
        [20, 40, 60, 80, 100],
        [ 0,  4,  8, 12,  16],
        [ 2,  6, 10, 14,  18],
    ]

    track2 = [
        [60, 48, 62, 47, 64, 45,  65,  43, 67, 41, 65, 43, 64, 45,  62, 47, 60, 48],
        [63, 31, 75, 90, 12, 23, 122, 104, 33, 19, 57, 42,  5, 82, 109, 86, 95, 71],
        [0,   0,  2,  2,  4,  4,   6,   6,  8,  8, 10, 10, 12, 12,  14, 14, 16, 16],
        [2,   2,  4,  4,  6,  6,   8,   8, 10, 10, 12, 12, 14, 14,  16, 16, 18, 18],
    ]

    track3 = [
        [48, 55, 64, 64, 65, 67, 55, 67, 65, 64, 62, 52, 55,  60,  60,  62,  64,  55, 64, 62, 62],
        [45, 45, 63, 63, 63, 63, 89, 66, 66, 66, 66, 30, 30, 103, 103, 103, 103, 127, 55, 55, 55],
        [ 0,  0,  0,  4,  8, 12, 16, 16, 20, 24, 28, 32, 32,  32,  36,  40,  44,  48, 48, 54, 56],
        [16, 16,  2,  6, 10, 14, 32, 18, 22, 26, 30, 48, 48,  34,  38,  42,  46,  64, 50, 55, 64],
    ]


    display(track1)
    display(track2)
    display(track3)

main()
