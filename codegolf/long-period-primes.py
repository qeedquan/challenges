#!/usr/bin/env python3

"""

A long period prime is a prime number p such that decimal expansion of 1/p has period of length (p-1). Your task is to output this number sequence. For purposes of this challenge we will consider only odd primes.

Period of a decimal expansion of a rational number is the smallest period k that makes the decimal representation periodic (repeating at regular intervals k).

This is A001913, or A006883 without leading 2.

Examples
13=0.33333…, so the period is 1 (although the number is also 2-periodic, 3-periodic etc., but we take the minimum). 3−1=2≠1, so 3 won't appear in our sequence.

17=0.14285714…- the period is 6=7−1.

Rules
This is a standard code-golfsequence challenge, so please comply with the defaults.

With floating point errors, let's stick to the highest voted decisive answer here on meta, so I'll allow them.

Test cases
First 10 entries:

7, 17, 19, 23, 29, 47, 59, 61, 97, 109
For more visit: A001913's b-file.

Inspired by recent Numberphile video.

"""

"""

https://oeis.org/A001913
https://oeis.org/A006883

ported from @ovs solution

"""
def isfrp(n):
    if n < 3:
        return False

    i = 1
    while i < n and (10**i)%n > 1:
        i += 1
    return i == n - 1

def gen(n):
    r = []
    i = 0
    while len(r) < n:
        if isfrp(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [7, 17, 19, 23, 29, 47, 59, 61, 97, 109, 113, 131, 149, 167, 179, 181, 193, 223, 229, 233, 257, 263, 269, 313, 337, 367, 379, 383, 389, 419, 433, 461, 487, 491, 499, 503, 509, 541, 571, 577, 593, 619, 647, 659, 701, 709, 727, 743, 811, 821, 823, 857, 863, 887, 937, 941, 953, 971, 977, 983, 1019, 1021, 1033, 1051, 1063, 1069, 1087, 1091, 1097, 1103]

    assert(gen(len(tab)) == tab)

main()
