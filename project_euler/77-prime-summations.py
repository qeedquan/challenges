#!/usr/bin/env python3

"""

It is possible to write ten as the sum of primes in exactly five different ways:

7 + 3
5 + 5
5 + 3 + 2
3 + 3 + 2 + 2
2 + 2 + 2 + 2 + 2

What is the first value which can be written as the sum of primes in over five thousand different ways?

"""

from sympy import primefactors

# https://oeis.org/A000607
def gen(l):
    if l < 2:
        return ([1], 1)

    r = [1, 0]
    i = 2
    while True:
        x = sum(sum(primefactors(k)) * r[i - k] for k in range(1, i + 1)) // i
        r.append(x)
        if x >= l:
            break
        i += 1
    return (r, i)

def solve(l):
    (_, i) = gen(l)
    return i

def main():
    print(solve(5000))

main()
