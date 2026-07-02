#!/usr/bin/env python3

"""

Inspired by this SO question.

Challenge:
Input:

A string s
A character c
Output:

Create a diamond-square ASCII art of the string in all four directions, with the first character of the string in the center and going outwards.
Which is inside a square ASCII-art carpet, with the character as filler. This may sound pretty vague, so here's an example:

Input: s = string, c = .
Output:

..........g..........
........g.n.g........
......g.n.i.n.g......
....g.n.i.r.i.n.g....
..g.n.i.r.t.r.i.n.g..
g.n.i.r.t.s.t.r.i.n.g
..g.n.i.r.t.r.i.n.g..
....g.n.i.r.i.n.g....
......g.n.i.n.g......
........g.n.g........
..........g..........

Challenge rules:
Input-string may also be a list of characters
Output may also be a list of string-lines or matrix of characters
Input-string and character are guaranteed to be non-empty
The string is guaranteed to not contain the character
Both string and character will only be printable ASCII (unicode range [32,126], space ' ' to and including tilde '~')

General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer with default I/O rules, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code (i.e. TIO).
Also, adding an explanation for your answer is highly recommended.

Test cases:

Input: s = 11111, c = 0
Output:

00000000100000000
00000010101000000
00001010101010000
00101010101010100
10101010101010101
00101010101010100
00001010101010000
00000010101000000
00000000100000000

Input: s = 12345ABCDEF, c = #
Output:

####################F####################
##################F#E#F##################
################F#E#D#E#F################
##############F#E#D#C#D#E#F##############
############F#E#D#C#B#C#D#E#F############
##########F#E#D#C#B#A#B#C#D#E#F##########
########F#E#D#C#B#A#5#A#B#C#D#E#F########
######F#E#D#C#B#A#5#4#5#A#B#C#D#E#F######
####F#E#D#C#B#A#5#4#3#4#5#A#B#C#D#E#F####
##F#E#D#C#B#A#5#4#3#2#3#4#5#A#B#C#D#E#F##
F#E#D#C#B#A#5#4#3#2#1#2#3#4#5#A#B#C#D#E#F
##F#E#D#C#B#A#5#4#3#2#3#4#5#A#B#C#D#E#F##
####F#E#D#C#B#A#5#4#3#4#5#A#B#C#D#E#F####
######F#E#D#C#B#A#5#4#5#A#B#C#D#E#F######
########F#E#D#C#B#A#5#A#B#C#D#E#F########
##########F#E#D#C#B#A#B#C#D#E#F##########
############F#E#D#C#B#C#D#E#F############
##############F#E#D#C#D#E#F##############
################F#E#D#E#F################
##################F#E#F##################
####################F####################

Input: s = @+-|-o-|-O, c = :
Output:

::::::::::::::::::O::::::::::::::::::
::::::::::::::::O:-:O::::::::::::::::
::::::::::::::O:-:|:-:O::::::::::::::
::::::::::::O:-:|:-:|:-:O::::::::::::
::::::::::O:-:|:-:o:-:|:-:O::::::::::
::::::::O:-:|:-:o:-:o:-:|:-:O::::::::
::::::O:-:|:-:o:-:|:-:o:-:|:-:O::::::
::::O:-:|:-:o:-:|:-:|:-:o:-:|:-:O::::
::O:-:|:-:o:-:|:-:+:-:|:-:o:-:|:-:O::
O:-:|:-:o:-:|:-:+:@:+:-:|:-:o:-:|:-:O
::O:-:|:-:o:-:|:-:+:-:|:-:o:-:|:-:O::
::::O:-:|:-:o:-:|:-:|:-:o:-:|:-:O::::
::::::O:-:|:-:o:-:|:-:o:-:|:-:O::::::
::::::::O:-:|:-:o:-:o:-:|:-:O::::::::
::::::::::O:-:|:-:o:-:|:-:O::::::::::
::::::::::::O:-:|:-:|:-:O::::::::::::
::::::::::::::O:-:|:-:O::::::::::::::
::::::::::::::::O:-:O::::::::::::::::
::::::::::::::::::O::::::::::::::::::

Input: s = AB, c = c
Output:

ccBcc
BcAcB
ccBcc

Input: s = ~, c = X
Output:

~

Input: s = /\^/\, c = X
Output:

XXXXXXXX\XXXXXXXX
XXXXXX\X/X\XXXXXX
XXXX\X/X^X/X\XXXX
XX\X/X^X\X^X/X\XX
\X/X^X\X/X\X^X/X\
XX\X/X^X\X^X/X\XX
XXXX\X/X^X/X\XXXX
XXXXXX\X/X\XXXXXX
XXXXXXXX\XXXXXXXX

"""

def layout(s, c):
    n = len(s)
    for m in range(-n + 1, n):
        i = abs(m)
        print(c.join(c*i + s[:i:-1] + s[i:] + c*i))
    print()

def main():
    layout("11111", "0")
    layout("12345ABCDEF", "#")
    layout("@+-|-o-|-O", ":")
    layout("AB", "c")
    layout("~", "X")
    layout("/\\^/\\", "X")

main()
