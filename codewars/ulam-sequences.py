#!/usr/bin/env python3

"""

The Ulam sequence U is defined by u0 = u, u1 = v, with the general term uN for N > 2 given by the least integer expressible uniquely as the sum of two distinct earlier terms. In other words, the next number is always the smallest, unique sum of any two previous terms.

Complete the function that creates an Ulam Sequence starting with the given u0 and u1, and contains n terms.

Example
The first 10 terms of the sequence U(u0=1, u1=2) are: 1, 2, 3, 4, 6, 8, 11, 13, 16, 18.

Let's see it in details:

The first term after the initial 1, 2 is obviously 3, because 1 + 2 = 3
The next term is 1 + 3 = 4 (we don't have to worry about 4 = 2 + 2 since it is a sum of a single term instead of distinct terms)
5 is not a member of the sequence since it is representable in two ways: 1 + 4 and 2 + 3
6 is a memeber, as 2 + 4 = 6
etc.

Description Reference: http://mathworld.wolfram.com/UlamSequence.html

Performance version: https://www.codewars.com/kata/ulam-sequences-performance-edition

"""

def ulam_sequence(u0, u1, n):
    r = [u0, u1]
    c = {u0 + u1: 1}
    while len(r) < n:
        x = r[-1] + 1
        while c.get(x, 0) != 1:
            x += 1
        for y in r:
            c[y + x] = c.get(y + x, 0) + 1
        r.append(x)
    return r[:n]

def main():
    assert(ulam_sequence(1, 2, 10) == [1, 2, 3, 4, 6, 8, 11, 13, 16, 18])
    assert(ulam_sequence(1, 2, 5) == [1, 2, 3, 4, 6])
    assert(ulam_sequence(3, 4, 5) == [3, 4, 7, 10, 11])
    assert(ulam_sequence(5, 6, 8) == [5, 6, 11, 16, 17, 21, 23, 26])
    assert(ulam_sequence(3, 4, 5) == [3, 4, 7, 10, 11])

    a = [1, 2, 3, 4, 6, 8, 11, 13, 16, 18, 26, 28, 36, 38, 47, 48, 53, 57, 62, 69]
    assert(ulam_sequence(1, 2, 20) == a)

    a = [
        1, 3, 4, 5, 6, 8, 10, 12, 17, 21, 23, 28, 32, 34, 39, 43, 48, 52, 54,
        59, 63, 68, 72, 74, 79, 83, 98, 99, 101, 110, 114, 121, 125, 132, 136,
        139, 143, 145, 152, 161, 165, 172, 176, 187, 192, 196, 201, 205, 212,
        216, 223, 227, 232, 234, 236, 243, 247, 252, 256, 258
    ]
    assert(ulam_sequence(1, 3, 60) == a)

main()
