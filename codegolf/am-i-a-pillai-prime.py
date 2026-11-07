#!/usr/bin/env python3

"""

A Pillai prime is a prime number p for which there exists some positive m such that (m!+1)≡0(mod p) and p≢1(mod m)


In other words, an integer p is a Pillai prime if it is a prime number, if there exists another positive integer m such that the factorial of m, plus 1 is divisible by p and if p−1 isn't divisible by m.

Given a positive integer as input, decide whether it is a Pillai prime. The sequence of Pillai primes is OEIS A063980.

For example, 23 is a Pillai prime because:

It is a prime number, having only 2 factors.
m=14 and m=18 satisfy the above conditions: 23∣(14!+1) and 14 does not divide 22; 23∣(18!+1) and 18 does not divide 22 either.

Test cases

Truthy:

23
59
83
109
139
593

Falsy:

5
7
8
73
89
263
437

For the truthy cases, the respective m's are [(23, [14, 18]), (59, [15, 40, 43]), (83, [13, 36, 69]), (109, [86]), (139, [16]), (593, [274])].

You can either follow the standard decision-problem output format (that is, truthy / falsy values) or have a consistent value for Pillai primes and a non-consistent value otherwise or vice-versa.

You can compete in any programming language and can take input and provide output through any standard method, while taking note that these loopholes are forbidden by default. This is code-golf, so the shortest submission (in bytes) for every language wins.

"""

from sympy import *

# https://oeis.org/A063980
def pillai_prime(n):
    if not isprime(n):
        return False

    for m in range(1, n):
        f = factorial(m)
        if (f + 1) % n == 0 and (n - 1) % m != 0:
            return True
    return False

def gen(n):
    r = []
    i = 0
    while len(r) < n:
        if pillai_prime(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [23, 29, 59, 61, 67, 71, 79, 83, 109, 137, 139, 149, 193, 227, 233, 239, 251, 257, 269, 271, 277, 293, 307, 311, 317, 359, 379, 383, 389, 397, 401, 419, 431, 449, 461, 463, 467, 479, 499, 503, 521, 557, 563, 569, 571, 577, 593, 599, 601, 607]

    assert(gen(len(tab)) == tab)

main()
