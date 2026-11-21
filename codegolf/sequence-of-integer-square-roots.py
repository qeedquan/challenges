#!/usr/bin/env python3

"""

Let's define a sequence of integer square roots. First, a(1) = 1. Then, a(n) is the smallest positive integer not seen before such that

sqrt(a(n) + sqrt(a(n-1) + sqrt(... + sqrt(a(1)))))
is an integer. Some examples:

a(2) is 3 because it's the smallest integer such that sqrt(a(2) + sqrt(a(1))) = sqrt(a(2) + 1) is integer, and 3 hasn't occured in the sequence before.

a(3) is 2 because it's the smallest integer such that sqrt(a(3) + sqrt(a(2) + sqrt(a(1)))) = sqrt(a(3) + 2) is integer, and 2 hasn't occured in the sequence before.

a(4) is 7 because sqrt(a(4) + 2) is integer. We couldn't have a(4) = 2 because 2 already occured in our sequence.

Write a program or function that given a parameter n returns a sequence of numbers a(1) to a(n).

The sequence starts 1,3,2,7,6,13,5, ....

Source of this sequence is from this Math.SE question.

A plot of the first 1000 elements in the sequence:

"""

from math import sqrt

# https://oeis.org/A323635
def gen(L):
    if L < 1:
        return []

    t = 1
    s = [1]
    for n in (L+1)*s:
        while (n in s) + sqrt(t+n) % 1:
            n += 1
        s.append(n)
        t = sqrt(t + n)
    return s[:L]

def main():
    tab = [
        1, 3, 2, 7, 6, 13, 5, 22, 4, 33, 10, 12, 21, 11, 32, 19, 20, 31, 30, 43,
        9, 45, 18, 44, 29, 58, 8, 60, 17, 59, 28, 75, 16, 76, 27, 94, 15, 95,
        26, 115, 14, 116, 25, 138, 24, 163, 23, 190, 35, 42, 57, 41, 74, 40,
        93, 39, 114, 38, 137, 37, 162, 36, 189, 50, 56, 73, 55, 92, 54, 113,
        53, 136
    ]

    assert(gen(len(tab)) == tab)

main()
