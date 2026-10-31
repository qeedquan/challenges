#!/usr/bin/env python3

"""

NATO phonetic alphabet is a spelling alphabet that associate to each of the 26 letters of the English alphabet one word (table below) that is easy to understand over the radio or telephone. For example, if you want to communicate the word CAT over the telephone, you do the following spelling:

CHARLIE ALFA TANGO

But what if you are unsure if the spelling was understood correctly? Well, you do the spelling of the spelling:

CHARLIE HOTEL ALFA ROMEO LIMA INDIA ECHO ALFA LIMA FOXTROT ALFA TANGO ALFA NOVEMBER GOLF OSCAR

But now you are worry that the spelling of the spelling was not understood correctly, so you cannot help yourself but doing the spelling of the spelling of the spelling:

CHARLIE HOTEL ALFA ROMEO LIMA INDIA ECHO HOTEL OSCAR TANGO ECHO LIMA   ALFA LIMA FOXTROT ALFA ROMEO OSCAR MIKE ECHO OSCAR LIMA INDIA MIKE ALFA   INDIA NOVEMBER DELTA INDIA ALFA ECHO CHARLIE HOTEL OSCAR ALFA LIMA FOXTROT ALFA LIMA INDIA MIKE ALFA FOXTROT OSCAR XRAY TANGO ROMEO OSCAR TANGO   ALFA LIMA FOXTROT ALFA TANGO ALFA NOVEMBER GOLF OSCAR ALFA LIMA FOXTROT ALFA NOVEMBER OSCAR VICTOR ECHO MIKE BRAVO ECHO ROMEO GOLF OSCAR LIMA FOXTROT OSCAR SIERRA CHARLIE ALFA ROMEO

Challenge: Write a function that takes as input a word and returns as output the number of letters of the 100th iteration of NATO spelling. Examples:

MOUSE -> 11668858751132191916987463577721689732389027026909488644164954259977441
CAT -> 6687458044694950536360209564249657173012108297161498990598780221215929
DOG -> 5743990806374053537155626521337271734138853592111922508028602345135998
Notes:

Whitespaces do not count. Only letters do.
Both uppercase and lowercase letters are fine (including combinations of uppercase and lowercase).
If you want to use a programming language without support for large integers, returning the result modulo 2³² is fine too.
The result must be an exact integer, not an approximation (like floating point).
The first iteration of CAT is CHARLIE ALFA TANGO (CAT is the 0th iteration).
Big Note:
If your program stores the spelling string, there's no way it is not going to run out of memory: the 100th iteration of MOUSE requires more than 10⁷⁰ bytes; the whole data on the Internet is estimated to be below 10³⁰ bytes.

NATO spelling Table:

A -> ALFA
B -> BRAVO
C -> CHARLIE
D -> DELTA
E -> ECHO
F -> FOXTROT
G -> GOLF
H -> HOTEL
I -> INDIA
J -> JULIETT
K -> KILO
L -> LIMA
M -> MIKE
N -> NOVEMBER
O -> OSCAR
P -> PAPA
Q -> QUEBEC
R -> ROMEO
S -> SIERRA
T -> TANGO
U -> UNIFORM
V -> VICTOR
W -> WHISKEY
X -> XRAY
Y -> YANKEE
Z -> ZULU

"""

from sympy import Matrix

"""

@Robin Houston

This constructs the transition matrix

[2 1 1 1 0 0 0 0 1 0 0 1 0 0 1 2 0 0 1 1 0 0 0 1 1 0]
[0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0]
[0 0 1 0 1 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 1 0 0 0 0]
[0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[0 0 1 1 1 0 0 1 0 1 0 0 1 2 0 0 2 1 1 0 0 0 1 0 2 0]
[1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0]
[0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0]
[0 0 1 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0]
[0 0 1 0 0 0 0 0 2 1 1 1 1 0 0 0 0 0 1 0 1 1 1 0 0 0]
[0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 1 0 1 0]
[1 0 1 1 0 0 1 1 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1]
[0 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 1 0 0 1 0 0 0 0 0]
[0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 1 0]
[0 1 0 0 1 2 1 1 0 0 1 0 0 1 1 0 0 2 0 1 1 1 0 0 0 0]
[0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 0 0 0]
[0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0]
[0 1 1 0 0 1 0 0 0 0 0 0 0 1 1 0 0 1 2 0 1 1 0 1 0 0]
[0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0]
[0 0 0 1 0 2 0 1 0 2 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0]
[0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 2]
[0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0]
[0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0]
[0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0]
[0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 0]
[0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1]

and raises it to the 100th power, then multiplies the matrix by the column vector representing the letter-frequencies of the input word, and finally computes the 1-norm.

"""

def solve(s):
    M = Matrix([
        [2, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 2, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0],
        [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0],
        [0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 2, 0, 0, 2, 1, 1, 0, 0, 0, 1, 0, 2, 0],
        [1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0],
        [0, 0, 1, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0],
        [1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0],
        [0, 1, 0, 0, 1, 2, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 2, 0, 1, 1, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 2, 0, 1, 1, 0, 1, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0],
        [0, 0, 0, 1, 0, 2, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 2],
        [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    ])

    x = Matrix([0] * 26)
    a = ord('a')
    z = ord('z')
    for c in s:
        c = ord(c.lower())
        if a <= c and c <= z:
            x[c - a] += 1
    return sum(M**100 * x)

def main():
    assert(solve("MOUSE") == 11668858751132191916987463577721689732389027026909488644164954259977441)
    assert(solve("CAT") == 6687458044694950536360209564249657173012108297161498990598780221215929)
    assert(solve("DOG") == 5743990806374053537155626521337271734138853592111922508028602345135998)

main()
