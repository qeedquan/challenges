#!/usr/bin/env python3

"""

The Prime Signature of a number is the list of the exponents of the prime factors of a number, sorted in descending order (exponents of 0 are ignored). Inspired by Combo Class's "The Magnificent Patterns of Prime Signatures" video.

For example, the prime factorization of 6860 is 2 * 2 * 5 * 7 * 7 * 7, or 2^2 + 5^1 + 7^3. The exponents are 2, 1, and 3, so the Prime Signature is {3, 2, 1}

I/O
You will be given an integer on the interval [1, 10,000,000].

You must output an array/list/vector or a string (in the format below) of the input's prime signature.

Examples/Test Cases
Numbers	Signature
1	∅ or {}
2, 3, 5, 7, 11	{1}
4, 9, 25, 49, 121	{2}
6, 10, 14, 15, 21	{1, 1}
8, 27, 125, 343	{3}
12, 18, 20, 28	{2, 1}
16, 81, 625, 2401	{4}
24, 40, 54, 56	{3, 1}
30, 42, 66, 70	{1, 1, 1}
32, 243, 3125	{5}
36, 100, 196, 225	{2, 2}
12345	{1, 1, 1}
123456	{6, 1, 1}
1234567	{1, 1}
5174928	{5, 4, 3}
8388608	{23}
9999991	{1}
Note that these are not sets in the computer science sense because they can contain duplicate values and have an ordering (admittedly, some set implementations are ordered).

Scoring
This is code-golf, so the fewest bytes wins!

"""

from sympy import *

def prime_signature(n):
    f = factorint(n)
    r = []
    for p in f:
        r.append(f[p])
    return sorted(r, reverse=True)

def test(a, r):
    for v in a:
        assert(prime_signature(v) == r)

def main():
    test([1], [])
    test([2, 3, 5, 7, 11], [1])
    test([4, 9, 25, 49, 121], [2])
    test([6, 10, 14, 15, 21], [1, 1])
    test([8, 27, 125, 343], [3])
    test([12, 18, 20, 28], [2, 1])
    test([16, 81, 625, 2401], [4])
    test([24, 40, 54, 56], [3, 1])
    test([30, 42, 66, 70], [1, 1, 1])
    test([32, 243, 3125], [5])
    test([36, 100, 196, 225], [2, 2])
    test([12345], [1, 1, 1])
    test([123456], [6, 1, 1])
    test([1234567], [1, 1])
    test([5174928], [5, 4, 3])
    test([8388608], [23])
    test([9999991], [1])

main()
