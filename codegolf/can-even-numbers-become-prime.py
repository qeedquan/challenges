#!/usr/bin/env python3

"""

The Sequence
Everyone knows the only even prime number is 2. Ho-hum. But, there are certain even numbers n where, when concatenated with n-1, they become a prime number.

For starters, 1 isn't in the list, because 10 isn't prime. Similarly with 2 (21), and 3 (32). However, 4 works because 43 is prime, so it's the first number in the sequence a(1) = 4. The next number that works (neither 6 (65) nor 8 (87) work) is 10, because 109 is prime, so a(2) = 10. Then we skip a bunch more until 22, because 2221 is prime, so a(3) = 22. And so on.

Obviously all terms in this sequence are even, because any odd number n when concatenated with n-1 becomes even (like 3 turns into 32), which will never be prime.

This is sequence A054211 on OEIS.

The Challenge
Given an input number n that fits somewhere into this sequence (i.e., n concatenated with n-1 is prime), output its position in this sequence. You can choose either 0- or 1-indexed, but please state which in your submission.

Rules
The input and output can be assumed to fit in your language's native integer type.
The input and output can be given in any convenient format.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
If possible, please include a link to an online testing environment so other people can try out your code!
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

Examples
The below examples are 1-indexed.

n = 4
1

n = 100
11

n = 420
51

"""

from sympy import *

# https://oeis.org/A054211
def enbp(n):
    if n < 1:
        return False
    s = str(n) + str(n - 1)
    x = int(s)
    return isprime(x)

def gen(n):
    r = []
    i = 0
    while len(r) < n:
        if enbp(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [4, 10, 22, 24, 34, 42, 58, 70, 78, 88, 100, 102, 108, 112, 114, 124, 148, 154, 160, 172, 180, 192, 198, 202, 208, 210, 214, 238, 244, 262, 264, 268, 270, 282, 294, 300, 304, 312, 328, 330, 334, 340, 342, 354, 372, 384, 390, 394, 412, 414, 420, 424, 444, 454]

    assert(gen(len(tab)) == tab)

main()
