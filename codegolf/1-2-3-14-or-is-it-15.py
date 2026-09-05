#!/usr/bin/env python3

"""

A well known song by the Irish rock band U2 starts with the singer Bono saying "1, 2, 3, 14" in Spanish ("uno, dos, tres, catorce").

There are various theories as to the significance of those numbers. Apparently the official explanation is "we drank too much that night". But there's a more interesting hypothesis: Bono is referring to some integer sequence from OEIS, such as

A107083:

Integers k such that 10^k + 31 is prime.
1, 2, 3, 14, 18, 44, 54, ...

In an interview, when asked the inevitable question "why 14", Bono admitted he was a bit tired of that number.
The journalist suggested "15" instead, and in that night's concert the lyrics were indeed changed into "1, 2, 3, 15". (The story can be read here, in Spanish). Quite likely the journalist took inspiration from

A221860:

Indices k such that prime(k) - k is a power of 2, where prime(k) is the k-th prime.
1, 2, 3, 15, 39, 2119, 4189897, ...

The challenge
Write two programs in the same language. The first should take an input n and output the n-th term of A107083, or the first n terms. Similarly, the second should output the n-th term of A221860, or the first n terms.

The score is the sum of lengths of the two programs, in bytes, plus the square of the Levenshtein distance between the byte representations of the two programs.

If a character encoding is used such that each character corresponds to one byte, this script can be used to measure Levenshtein distance.

For example, if the two programs are abcdefgh and bcdEEfg, the score is 8 + 7 + 4^2 = 31.

Lowest score wins.

Aditional rules
The output can be 1-based or 0-based, independently for each sequence (so it is allowed if one of the programs is 1-based and the other is 0-based).

Each program can, consistently but independently of the other, either output the n-th term or the first n terms.

Programs or functions are allowed, independently for each sequence.

Input and output means and format are flexible as usual. Standard loopholes are forbidden.

"""

from sympy import *

# https://oeis.org/A107083
def A107083(n):
    r = 0
    p = 1
    i = 0
    while i <= n:
        if isprime(10**p + 31):
            i += 1
            r = p
        p += 1
    return r

# https://oeis.org/A221860
def A221860(n):
    tab = [1, 2, 3, 15, 39, 2119, 4189897, 5812974437]
    if n < 0 or n >= len(tab):
        return -1
    return tab[n]

def main():
    for i in range(9):
        print(A107083(i))
    
    print()

    for i in range(8):
        print(A221860(i))

main()
