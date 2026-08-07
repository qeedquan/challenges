#!/usr/bin/env python3

"""

The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways:
(i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?

"""

from sympy import *

def isperm(a, b):
    return sorted(str(a)) == sorted(str(b))

def prime_chain(d, h):
    if d == 1 and h == 1:
        return [2, 3]

    P = list(primerange(10**(d-1), 10**d))
    S = set(P)
    L = len(P)

    r = []
    for i in range(L):
        for j in range(i+1, L):
            c = 1
            k = P[j] - P[i]
            p = [P[i]]
            x = P[i]
            while True:
                x += k
                if x >= 10**d or x not in S or not isperm(P[i], x):
                    break
                p.append(x)
                c += 1
            
            if c == h:
                r.append(p)

    return r

def solve():
    p = prime_chain(4, 3)
    s = list(map(str, p[1]))
    return ''.join(s)

def main():
    print(solve())

main()
