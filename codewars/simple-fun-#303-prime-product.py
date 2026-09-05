#!/usr/bin/env python3

"""

Task
We know that some numbers can be split into two primes. ie. 5 = 2 + 3, 10 = 3 + 7. But some numbers are not. ie. 17, 27, 35, etc..

Given a positive integer n. Determine whether it can be split into two primes. If yes, return the maximum product of two primes. If not, return 0 instead.

Input/Output
[input] integer n

A positive integer.

0 ≤ n ≤ 100000

[output] an integer

The possible maximum product of two primes. or return 0 if it's impossible split into two primes.

Example
For n = 1, the output should be 0.

1 can not split into two primes

For n = 4, the output should be 4.

4 can split into two primes 2 and 2. 2 x 2 = 4

For n = 20, the output should be 91.

20 can split into two primes 7 and 13 or 3 and 17. The maximum product is 7 x 13 = 91

"""

from sympy import factorint

# https://oeis.org/A099303
def prime_product(n):
    for m in range(n**2//4, 0, -1):
        f = factorint(m)
        s = 0
        for p, e in f.items():
            s += m*e//p
        if s == n:
            return m
    return 0

def main():
    tab = [
        0, 0, 0, 0, 4, 6, 9, 10, 15, 14, 25, 0, 35, 22, 49, 26, 55, 0, 77, 34,
        91, 38, 121, 0, 143, 46, 169, 27, 187, 0, 221, 58, 247, 62, 289, 0, 323,
        0, 361, 74, 391, 42, 437, 82, 403, 86, 529, 0, 551, 94, 589, 63, 667,
        0, 713, 106, 703, 0, 841, 70, 899, 118, 961, 122, 943, 0, 1073, 0
    ]

    for i in range(len(tab)):
        assert(prime_product(i) == tab[i])

    assert(prime_product(100) == 2491)

main()
