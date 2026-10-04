#!/usr/bin/env python3

"""

Terence Tao recently proved a weak form of Goldbach's conjecture! Let's exploit it!

Given an odd integer n > 1, write n as a sum of up to 5 primes. Take the input however you like, and give output however you like. For example,

def g(o):
    for l in prime_range(o+1):
        if l == o:
            return l,
        for d in prime_range(l+1):
            for b in prime_range(d+1):
                if l+d+b == o:
                    return l,d,b
                for c in prime_range(b+1):
                    for h in prime_range(c+1):
                        if l+d+b+c+h == o:
                            return l,d,b,c,h
is Sage code that takes an integer as input, and returns a list of integers as output whose sum is n. By Tao's theorem, this will always terminate!

Input

An odd integer n. You decide how to take the input, but if it's weird, explain it.

Output

Rather open-ended. Return a list. Print a string. Gimme one, a few, or all. Leave crap lying around on the stack (GS, Piet, etc) or in a consecutive (reachable) memory block (BF, etc) in a predictable manner. For these later cases, explain the output. In all cases, what you return / print / whathaveyou should be a straightforward representation of a partition of n into primes with fewer than 6 parts.

Scoring

This is code golf, smallest byte count wins.

Bonus! if the word 'goldbach' appears as a subsequence (not necessarily consecutive; just in order. Case doesn't matter) of your program subtract 8 points. The code above is an example of this.

"""

from sympy import *

def recurse(n, r, l):
    if sum(r) == n:
        return r

    if len(r) >= l:
        return []
    
    for x in primerange(n + 1):
        r.append(x)
        p = recurse(n, r, l)
        if len(p) > 0:
            return p
        r.pop()
    return []

def goldbach5(n):
    return recurse(n, [], 5)

def main():
    for i in range(2, 1000):
        x = goldbach5(i)
        print(i, x)
        assert(sum(x) == i)

main()
