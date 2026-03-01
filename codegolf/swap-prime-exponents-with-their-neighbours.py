#!/usr/bin/env python3

"""

(Follow-up to my question about swapping bits with their neighbours.)

Task
Given a positive integer x = (2^a · 3^b) · (5^c · 7^d) · (11^e · 13^f) · …, print the integer obtained by swapping the exponents in this factorization for each successive pair of primes, y = (2^b · 3^a) · (5^d · 7^c) · (11^f · 13^e) · …

A061898 in the OEIS. This is code-golf, so the shortest program (in bytes) wins!

Test cases
1 -> 1
2 -> 3
3 -> 2
10 -> 21
37 -> 31
360 -> 756
12345 -> 11578
67895678 -> 125630871

"""

from sympy import *

# https://oeis.org/A061898
def spewtn(n):
    if n < 1:
        return 0
    
    if n == 1:
        return 1

    r = 1
    f = factorint(n)
    p = list(primerange(max(f) + 1))
    p.append(nextprime(p[-1]))
    for x in f:
        i = p.index(x)
        if i&1 != 0:
            y = p[i - 1]
        else:
            y = p[i + 1]
        r *= y**f[x]
    return r

def main():
    tab = [1, 3, 2, 9, 7, 6, 5, 27, 4, 21, 13, 18, 11, 15, 14, 81, 19, 12, 17, 63, 10, 39, 29, 54, 49, 33, 8, 45, 23, 42, 37, 243, 26, 57, 35, 36, 31, 51, 22, 189, 43, 30, 41, 117, 28, 87, 53, 162, 25, 147, 38, 99, 47, 24, 91, 135, 34, 69, 61, 126, 59, 111, 20, 729, 77, 78, 71, 171, 58]

    for i in range(len(tab)):
        assert(spewtn(i + 1) == tab[i])

    assert(spewtn(1) == 1)
    assert(spewtn(2) == 3)
    assert(spewtn(3) == 2)
    assert(spewtn(10) == 21)
    assert(spewtn(37) == 31)
    assert(spewtn(360) == 756)
    assert(spewtn(12345) == 11578)
    assert(spewtn(67895678) == 125630871)

main()
