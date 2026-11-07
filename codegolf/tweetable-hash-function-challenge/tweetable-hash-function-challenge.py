#!/usr/bin/env python3

"""

In this code-challenge you will write a hash function in 140 bytes1 or less of source code. The hash function must take an ASCII string as input, and return a 24-bit unsigned integer ([0, 2^24-1]) as output.

Your hash function will be evaluated for every word in this large British English dictionary2. Your score is the amount of words that share a hash value with another word (a collision).

The lowest score wins, ties broken by first poster.
Test case
Before submitting, please test your scoring script on the following input:

duplicate
duplicate
duplicate
duplicate
If it gives any score other than 4, it is buggy.

Clarifying rules:

Your hash function must run on a single string, not a whole array. Also, your hash function may not do any other I/O than the input string and output integer.
Built-in hash functions or similar functionality (e.g. encryption to scramble bytes) is disallowed.
Your hash function must be deterministic.
Contrary to most other contests optimizing specifically for the scoring input is allowed.
1 I am aware Twitter limits characters instead of bytes, but for simplicity we will use bytes as a limit for this challenge.
2 Modified from Debian's wbritish-huge, removing any non-ASCII words.

"""

import binascii

# Ported @kasperd hash function
def H(s):
    lut = '+%:5O![/5;QwrXsIf]\'k#!__u5O}nQ~{;/~{CutM;ItulA{uOk_7"ud-o?y<Cn~-`bl_Yb'
    h = binascii.hexlify(str.encode(s))
    n = int(h, 16)
    return n % (0x1000000 - ord(lut[n % len(lut)]))

def collisions():
    f = open("british-english-huge.txt")
    l = 0
    m = {}
    for s in f:
        l += 1
        s = s.strip('\n')
        i = H(s)
        if i not in m:
            m[i] = []
        m[i].append(s)

    c = 0
    for i in m:
        if len(m[i]) > 1:
            c += len(m[i])

    print("%d words collided out of %d words (%f%%)" % (c, l, c/l*100))

    f.close()

def main():
    collisions()

main()
