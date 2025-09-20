#!/usr/bin/env python3

"""

Write a program that takes a string and outputs all the characters in alphabetical order. Spaces and symbols can be ignored or deleted, but the upper‑ and lowercase letters must remain the same case.

Sample input:

Johnny walked the dog to the park.
Sample output:

aaddeeeghhhJkklnnoooprtttwy

Rules:

Any language.
Shortest code wins.

"""

def alphabetical(s):
    m = {}
    for c in s:
        if c not in m:
            m[c] = 0
        m[c] += 1
    
    r = ""
    for i in range(26):
        c0 = chr(ord('a') + i)
        c1 = chr(ord('A') + i)
        l0 = 0
        l1 = 0
        if c0 in m:
            l0 = m[c0]
        if c1 in m:
            l1 = m[c1]
        r += c0*l0 + c1*l1
    return r

def main():
    assert(alphabetical("Johnny walked the dog to the park.") == "aaddeeeghhhJkklnnoooprtttwy")

main()
