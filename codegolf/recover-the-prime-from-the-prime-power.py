#!/usr/bin/env python3

"""

Definition: a prime power is a natural number that can be expressed in the form pn where p is a prime and n is a natural number.

Task: Given a prime power pn > 1, return the prime p.

Testcases:

input output
9     3
16    2
343   7
2687  2687
59049 3

Scoring: This is code-golf. Shortest answer in bytes wins.

"""

from sympy import factorint

# https://oeis.org/A025473
def primepower(n):
    if n < 1:
        return -1

    f = factorint(n)
    if len(f) != 1:
        return -1
    return list(f)[0]

def gen(n):
    if n < 1:
        return []

    r = [1]
    i = 0
    while len(r) < n:
        p = primepower(i)
        if p > 0:
            r.append(p)
        i += 1
    return r[:n]

def main():
    tab = [
        1, 2, 3, 2, 5, 7, 2, 3, 11, 13, 2, 17, 19, 23, 5, 3, 29, 31, 2, 37, 41,
        43, 47, 7, 53, 59, 61, 2, 67, 71, 73, 79, 3, 83, 89, 97, 101, 103, 107,
        109, 113, 11, 5, 127, 2, 131, 137, 139, 149, 151, 157, 163, 167, 13,
        173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239
    ]

    assert(primepower(9) == 3)
    assert(primepower(16) == 2)
    assert(primepower(343) == 7)
    assert(primepower(2687) == 2687)
    assert(primepower(59049) == 3)

    assert(gen(len(tab)) == tab)

main()
