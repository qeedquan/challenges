#!/usr/bin/env python3

"""

723=3×241 is a semi-prime (the product of two primes) whose prime factors include all digits from 1 to n, where n is the total number of digits between them.
Another way to look at this is that the (sorted) digits in the factorisation of 723 are all consecutive.
The first 10 such semi-primes and their factorisations are

[26, 62, 723, 862, 943, 1263, 2906, 3086, 7082, 7115]
[2×13, 2×31, 3×241, 2×431, 23×41, 3×421, 2×1453, 2×1543, 2×3541, 5×1423]
We will call the numbers that have this feature all-inclusive semi-primes

You may choose whether to:

Take an integer n and output the nth all-inclusive semi-prime (0 or 1 indexed)
Take an integer n and output the first n all-inclusive semi-primes
Output the sequence of all-inclusive semi-primes indefinitely
This is code-golf so the shortest code in bytes wins!

This is a Jelly program which takes an integer n and outputs the first n all-inclusive semi-primes and their factorisations.
Spoilers for any Jelly based solutions.

The first 100 all-inclusive semi-primes are

[26, 62, 723, 862, 943, 1263, 2906, 3086, 7082, 7115, 8306, 9026, 10715, 10793, 10826, 10862, 11705, 12443, 12773, 21155, 21443, 22313, 22403, 29126, 29306, 31286, 32906, 69302, 70922, 72902, 73082, 87302, 90722, 91226, 91262, 92306, 92702, 104903, 106973, 108326, 108722, 109262, 112862, 116213, 123086, 123155, 127082, 128306, 129026, 129743, 130826, 132155, 135683, 142283, 148373, 155123, 157373, 161393, 171305, 181205, 206315, 216305, 225833, 226223, 230543, 237023, 241103, 241223, 244913, 259433, 270934, 271294, 273094, 274913, 275903, 280403, 287134, 291274, 310715, 312694, 312874, 316205, 317105, 320615, 321155, 328714, 330874, 335003, 335086, 335243, 337111, 340313, 349306, 350926, 355741, 359881, 373701, 379371, 379641, 380581]

"""

from sympy import *

def check(n):
    r = []
    f = factorint(n)
    for p in f:
        for _ in range(f[p]):
            r.append(p)

    if len(r) != 2:
        return False

    s = ""
    for i in r:
        s += str(i)
    s = ''.join(sorted(s))

    t = ""
    for i in range(1, len(s) + 1):
        t += str(i)
        if s == t:
            return True
    return False

def gen(n):
    r = []
    i = 0
    while len(r) < n:
        if check(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [
        26, 62, 723, 862, 943, 1263, 2906, 3086, 7082, 7115, 8306, 9026, 10715,
        10793, 10826, 10862, 11705, 12443, 12773, 21155, 21443, 22313, 22403,
        29126, 29306, 31286, 32906, 69302, 70922, 72902, 73082, 87302, 90722,
        91226, 91262, 92306, 92702, 104903, 106973, 108326, 108722, 109262,
        112862, 116213, 123086, 123155, 127082, 128306, 129026, 129743, 130826,
        132155, 135683, 142283, 148373, 155123, 157373, 161393, 171305, 181205,
        206315, 216305, 225833, 226223, 230543, 237023, 241103, 241223, 244913,
        259433, 270934, 271294, 273094, 274913, 275903, 280403, 287134, 291274,
        310715, 312694, 312874, 316205, 317105, 320615, 321155, 328714, 330874,
        335003, 335086, 335243, 337111, 340313, 349306, 350926, 355741, 359881,
        373701, 379371, 379641, 380581
    ]

    assert(gen(len(tab)) == tab)

main()
