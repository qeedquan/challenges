#!/usr/bin/env python3

"""

Related, but not dupe (Asking about the n-th k-smooth number whereas I'm only asking if a certain number is 5-smooth.)
Source: Partially inspired by Leetcode's 5-smooth Number problem, but partially inpsired by my newfound interest in Befunge-93.

Problem statement
An "ugly number" (also commonly known as "regular numbers" or "5-smooth numbers") is a positive number of the form 2^i3^k5^j, where i,j,k≥0.

Your goal is given an integer X, to determine if X is ugly or not.

If X is ugly, output True. Otherwise, output False.

For languages that don't have built-in truthy/falsy values, such as Befunge 93/98, outputting T/F is perfectly fine.*
Constraints
−1≤X≤2^32 (although really any negative number constraint works, as it's basically the same output for any X≤0)

*For example in Befunge 93, "T",@ outputs the ASCII character T and then ends the program, which in this case can be taken to be truthy.

Test-cases

# Test cases all tested with my golfed Befunge-93 program

IN:  -1
OUT: False
# Note: I could NOT believe that the program
#       supported negative numbers until I tested it :D

IN:  0
OUT: False

IN:  1
OUT: True
Explanation: 1 == (2**0)(3**0)(5**0)

IN:  2
OUT: True
Explanation: 2 == (2**1)(3**0)(5**0)

IN:  7
OUT: False

IN:  -4294967296
OUT: False
Explanation: -4294967296 == [-1]*(2**32).
             Since there is a factor of -1, it is false.

IN:  4294967296
OUT: True

IN:  42050
OUT: False

IN:  60060
OUT: False

IN:  60
OUT: True
Rules
This is code-golf, so the shortest answer wins!!
Standard loopholes forbidden.

"""

from math import log2

"""

https://oeis.org/A051037

@l4m2

Technically **n work but would too slow so I use that n<=2^32

"""

def ugly(n):
    return n > 0 and (30**int(log2(n)))%n == 0

def main():
    tab = [
        1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24, 25, 27, 30, 32, 36,
        40, 45, 48, 50, 54, 60, 64, 72, 75, 80, 81, 90, 96, 100, 108, 120, 125,
        128, 135, 144, 150, 160, 162, 180, 192, 200, 216, 225, 240, 243, 250,
        256, 270, 288, 300, 320, 324, 360, 375, 384, 400, 405
    ]

    assert(ugly(-1) == False)
    assert(ugly(0) == False)
    assert(ugly(1) == True)
    assert(ugly(2) == True)
    assert(ugly(7) == False)
    assert(ugly(-4294967296) == False)
    assert(ugly(4294967296) == True)
    assert(ugly(42050) == False)
    assert(ugly(60060) == False)
    assert(ugly(60) == True)

    for i in range(max(tab)):
        if i in tab:
            assert(ugly(i) == True)
        else:
            assert(ugly(i) == False)

main()
