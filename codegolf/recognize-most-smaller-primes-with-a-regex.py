#!/usr/bin/env python3

"""

This time, you are working on a regex. Your regex is meant to approximately full-match the base-10 representations of primes 0≤p<1000, while ignoring any non-numeric string or composite in the range. You can full-match 2, 53 or 419, but not 0, 82 or example.

The approximately is important -- a minimum of 900 numbers have to produce the right output. You can match more numbers correctly (but as this is a code-golf challenge you probably shouldn't). For clarification, how numbers above 1000 are matched doesn't matter and they can produce whatever output you like.

Test cases part 1, strings which should be matched (primes under 1000):

5
739
211
617
103
503
11
13
17
23
71
89
257
Part 2: strings that shouldn't be matched

five
5o
2q11
716
102_3
42 + 1
term in A000040
16
204
Your score is the number of characters in your regex. Lowest score wins. Have fun!

"""

import re
import sympy

def regex(n):
    r = r"^("
    for i in range(2, n+1):
        if sympy.isprime(i):
            if r[-1] != '(':
                r += "|"
            r += str(i)
    r += ")$"
    return r

def main():
    N = 1000
    p = re.compile(regex(N))
    for i in range(N):
        b = p.match(str(i)) != None
        assert(b == sympy.isprime(i))

main()
