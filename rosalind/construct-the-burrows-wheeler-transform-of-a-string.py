#!/usr/bin/env python3

"""

Our goal is to further improve on the memory requirements of the suffix array introduced in “Construct the Suffix Array of a String” for multiple pattern matching.

Given a string Text, form all possible cyclic rotations of Text; a cyclic rotation is defined by chopping off a suffix from the end of Text and appending this suffix to the beginning of Text.
Next — similarly to suffix arrays — order all the cyclic rotations of Text lexicographically to form a |Text| × |Text| matrix of symbols that we call the Burrows-Wheeler matrix and denote by M(Text).

Note that the first column of M(Text) contains the symbols of Text ordered lexicographically.
In turn, the second column of M(Text) contains the second symbols of all cyclic rotations of Text, and so it too represents a (different) rearrangement of symbols from Text.
The same reasoning applies to show that any column of M(Text) is some rearrangement of the symbols of Text.
We are interested in the last column of M(Text), called the Burrows-Wheeler transform of Text, or BWT(Text).

Burrows-Wheeler Transform Construction Problem
Construct the Burrows-Wheeler transform of a string.

Given: A string Text.

Return: BWT(Text).

Sample Dataset
GCGTGCCTGGTCA$
Sample Output
ACTGGCT$TGCGGC

Note
Although it is possible to construct the Burrows-Wheeler transform in O(|Text|) time and space, we do not expect you to implement such a fast algorithm.
In other words, it is perfectly fine to produce BWT(Text) by first producing the complete Burrows-Wheeler matrix M(Text).

"""

def rotations(s):
    n = len(s)
    p = [""] * n
    for i in range(n):
        for j in range(n):
            p[i] += s[(j+i)%n]
    return p

def bwt(s):
    p = sorted(rotations(s))
    t = ""
    for i in range(len(p)):
        t += p[i][-1]
    return t

def main():
    assert(bwt("banana$") == "annb$aa")
    assert(bwt("mississippi$") == "ipssm$pissii")
    assert(bwt("abaaba$") == "abba$aa")
    assert(bwt("acccgtttgtttcaatagatccatcaa$") == "aacc$tacgttctaccatcaatatttgg")
    assert(bwt("") == "")
    assert(bwt("GCGTGCCTGGTCA$") == "ACTGGCT$TGCGGC")

main()
