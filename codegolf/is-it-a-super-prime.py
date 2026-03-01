#!/usr/bin/env python3

"""

Background
A super-prime is a prime number whose index in the list of all primes is also prime. The sequence looks like this:

3, 5, 11, 17, 31, 41, 59, 67, 83, 109, 127, 157, 179, 191, ...

This is sequence A006450 in the OEIS.

Challenge
Given a positive integer, determine whether it is a super-prime.

Test Cases
2: false
3: true
4: false
5: true
7: false
11: true
13: false
17: true
709: true
851: false
991: true

Scoring
This is code-golf, so the shortest answer in each language wins.

"""

from sympy import *

# https://oeis.org/A006450
def gen(n):
    r = []
    p = 2
    pi = 1
    while len(r) < n:
        if isprime(pi):
            r.append(p)
        p = nextprime(p)
        pi += 1
    return r

def superprime(n):
    p = gen(n)
    if n in p:
        return True
    return False

def main():
    assert(superprime(2) == False)
    assert(superprime(3) == True)
    assert(superprime(4) == False)
    assert(superprime(5) == True)
    assert(superprime(7) == False)
    assert(superprime(11) == True)
    assert(superprime(13) == False)
    assert(superprime(17) == True)
    assert(superprime(709) == True)
    assert(superprime(851) == False)
    assert(superprime(991) == True)

main()
