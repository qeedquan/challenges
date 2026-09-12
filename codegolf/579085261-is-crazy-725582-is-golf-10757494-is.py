#!/usr/bin/env python3

"""

Your task is to translate a 103-smooth number into an English word, using the method described below.

How?
Generate the list of prime factors (with repetition) of the input number.
Sort the list:
If 2 is not one of the prime factors, sort the list in ascending order.
If 2 is one of the prime factors, remove it from the list and sort the remaining factors in descending order.
Translate each factor into a letter, using the following table:

 3 = S   13 = L   29 = X   43 = O   61 = Z   79 = H  101 = K
 5 = P   17 = Q   31 = N   47 = R   67 = T   83 = V  103 = Y
 7 = M   19 = U   37 = C   53 = A   71 = E   89 = D
11 = F   23 = I   41 = W   59 = G   73 = J   97 = B
Note: This table was built empirically to maximize the number of possible words. For the curious, here is a list of 2,187 words that can be encoded that way (may include rude language). It's definitely not guaranteed to be optimal, but it's good enough for this challenge.

Examples
Example 1: 579085261 (ascending order)

The prime factors are [ 37, 47, 53, 61, 103 ].
2 is not a prime factor, so we keep the list sorted in ascending order.
37 = C, 47 = R, etc. The output is "CRAZY".
Example 2: 725582 (descending order)

The prime factors are [ 2, 11, 13, 43, 59 ].
2 is a prime factor, so we remove it and sort the list in descending order, which gives:
[ 59, 43, 13, 11 ].
59 = G, 43 = O, etc. The output is "GOLF".
Example 3: 10757494 (with a repeated factor)

The prime factors are [ 2, 11, 71, 71, 97 ].
2 is a prime factor, so we remove it and sort the list in descending order, which gives:
[ 97, 71, 71, 11 ].
97 = B, 71 = E, 11 = F. The output is "BEEF".
Clarifications and rules
The input number is guaranteed to be 103-smooth and divisible by 2 at most once.
By definition, a smooth-number is a positive integer.
Input and output can be handled in any reasonable format. The output can be in lowercase or uppercase. Trailing whitespace is acceptable. Leading whitespace is not.
If your program/function can't support large inputs, please specify it in your answer.
This is code golf, so the shortest answer in bytes wins.

Test cases
34874          --> ARM
483254         --> BAR
353722         --> EAR
494302         --> EGG
39061          --> FAT
6479           --> FUN
60421          --> ICE
54166          --> JAM
48911474       --> BETA
2510942        --> BOOM
2303854        --> DOOM
844261         --> FIRE
1606801        --> MAZE
1110085        --> PAGE
5212974        --> BALLS
67892046       --> BEANS
885396199      --> CREEK
67401037       --> FUNKY
27762173       --> QUICK
1238440506     --> ARROWS
33045832681    --> CRAGGY
1362714005     --> PIRATE
137302698      --> TROLLS
358310128062   --> BEGGARS
40255151586    --> DETAILS
164633248153   --> FIXATED
621172442227   --> UNRATED
2467812606     --> VACUUMS
86385078330    --> GROWNUPS
26607531423091 --> UNWORTHY

"""

from sympy import *

def translate(n):
    chars = {
        3: 'S',
        5: 'P',
        7: 'M',
        11: 'F',
        13: 'L',
        17: 'Q',
        19: 'U',
        23: 'I',
        29: 'X',
        31: 'N',
        37: 'C',
        41: 'W',
        43: 'O',
        47: 'R',
        53: 'A',
        59: 'G',
        61: 'Z',
        67: 'T',
        71: 'E',
        73: 'J',
        79: 'H',
        83: 'V',
        89: 'D',
        97: 'B',
        101: 'K',
        103: 'Y',
    }
    p = factorint(n)
    f = False
    if 2 in p:
        f = True
        del p[2]

    r = []
    for x in p:
        r.extend([x]*p[x])

    if f:
        r = sorted(r, reverse=True)
    else:
        r = sorted(r)

    s = ""
    for c in r:
        if c in chars:
            s += chars[c]
    return s

def main():
    assert(translate(579085261) == "CRAZY")
    assert(translate(725582) == "GOLF")
    assert(translate(10757494) == "BEEF")
    assert(translate(34874) == "ARM")
    assert(translate(483254) == "BAR")
    assert(translate(353722) == "EAR")
    assert(translate(494302) == "EGG")
    assert(translate(39061) == "FAT")
    assert(translate(6479) == "FUN")
    assert(translate(60421) == "ICE")
    assert(translate(54166) == "JAM")
    assert(translate(48911474) == "BETA")
    assert(translate(2510942) == "BOOM")
    assert(translate(2303854) == "DOOM")
    assert(translate(844261) == "FIRE")
    assert(translate(1606801) == "MAZE")
    assert(translate(1110085) == "PAGE")
    assert(translate(5212974) == "BALLS")
    assert(translate(67892046) == "BEANS")
    assert(translate(885396199) == "CREEK")
    assert(translate(67401037) == "FUNKY")
    assert(translate(27762173) == "QUICK")
    assert(translate(1238440506) == "ARROWS")
    assert(translate(33045832681) == "CRAGGY")
    assert(translate(1362714005) == "PIRATE")
    assert(translate(137302698) == "TROLLS")
    assert(translate(358310128062) == "BEGGARS")
    assert(translate(40255151586) == "DETAILS")
    assert(translate(164633248153) == "FIXATED")
    assert(translate(621172442227) == "UNRATED")
    assert(translate(2467812606) == "VACUUMS")
    assert(translate(86385078330) == "GROWNUPS")
    assert(translate(26607531423091) == "UNWORTHY")

main()
