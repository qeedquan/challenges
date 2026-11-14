#!/usr/bin/env python3

"""

Input
The code should take an integer n between 1 and 1000.

Output
The code should output positive integers with n bits. Accompanying each integer should be its full factorization. Each integer should be a uniformly random n bit number.

Score
The score for your code will be the number of integers it outputs, with their factorizations, in ten seconds on my Ubuntu PC when n=500.

Primality testing
If you need to test if a number is prime, you can use any method that is any of:

Provably always correct
Not proven to always be correct but for which there is no known example where it is incorrect
Provably has probability at most 2^-30 of giving the wrong answer.
As always,this challenge is per language and I will keep a scoreboard for the answers given.

Is this possible?
The two best known methods are Bach's algorithm and a simpler one by Kalai.

"""

import math
import random
import sympy

def factors(N):
    while True:
        j = random.randint(1, N.bit_length()-1)
        q = (1 << j) + random.randrange(1 << j)
        if q > N:
            continue
        p, a = sympy.perfect_power(q) or (q, 1)
        if not sympy.isprime(p):
            continue
        Nt = N // q
        if random.random()*N < math.log(q, N) * (((Nt + 1) >> 1) << j):
            return p, a, Nt

"""

https://en.wikipedia.org/wiki/Bach%27s_algorithm

Ported from @Command Master solution

"""

def bach(N):
    if N <= 10000000:
        x = random.randint((N + 1) >> 1, N)
        return x, sympy.factorint(x)

    while True:
        p, a, Nt = factors(N)
        newx, factx = bach(Nt)
        newx *= p ** a
        if random.random() < math.log(N / 2, newx):
            factx[p] = factx.get(p, 0) + a
            return newx, factx

def gen(n):
    return bach((1 << n) - 1)

def main():
    print(gen(1000))

main()
