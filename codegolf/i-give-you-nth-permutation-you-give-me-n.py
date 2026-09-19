#!/usr/bin/env python3

"""

Input: a sequence of uppercase letters (ASCII [65;90]) which is the Nth* lexicographical permutation of the multiset of its characters

*permutations are numbered from 0 or 1 upwards

Output: base-10 integer N

Rulez
There might be duplicates (that's how this challenge differs from this one)
The characters are ordered by their ASCII value
In case of an input of length less than or equal to 1, the input is the first permutation and the result is 0 or 1 respectively
First permutation is that in which the leftmost character has the lowest value, the rightmost character has the highest value, and the sequence of characters between the first and the last character is the first permutation of the multiset of its characters (recursive definition!)

Shortest entry wins

Example
Input AAB produces output 0
Input ABA produces output 1
Input BAA produces output 2

EDIT
Extra kudos to the one who can come up with a solution which doesn't produce all permutations and then search for the input. That's some challenge.

"""

from math import factorial
from itertools import groupby

"""

@PM 2Ring

This solution does not generate all of the permutations. It can rapidly calculate the permutation index of a rather large string; it also handles an empty string correctly.

"""

def nth(a, b=""):
    if len(a) < 2:
        return 0

    z = 0
    if b == "":
        b = sorted(a)
    
    for i, c in enumerate(b):
        w = b[:i] + b[i + 1:]
        if c == a[0]:
            return z + nth(a[1:], w)

        if i < 1 or c != b[i - 1]:
            n = factorial(len(w))
            for _, v in groupby(w):
                n //= factorial(len(list(v)))
            z += n
    return 0

def main():
    assert(nth("AAB") == 0)
    assert(nth("ABA") == 1)
    assert(nth("BAA") == 2)
    assert(nth("ZZZ") == 0)
    assert(nth("DCBA") == 23)
    assert(nth("a quick brown fox jumps over the lazy dog") == 436629906477779191275460617121351796379337)

main()
