#!/usr/bin/env python3

"""

Definition
A square-free semiprime is a natural number that is the product of two distinct prime numbers.

The task
Given a natural number n, count all square-free semiprimes less than or equal to n.

Details
Please write a function or procedure that accepts a single integer parameter and counts all square-free semiprimes less than or equal to its parameter. The count must either be a return value of a function call or be printed to STDOUT.

Scoring
The answer with the fewest number of characters wins.

In the event of a tie, the following criteria will be used in order:

Tallest person

Best time-complexity

Worst space-complexity

Examples
f(1)     = 0
f(62)    = 18
f(420)   = 124
f(10000) = 2600

"""


from math import isqrt
from sympy import prime, primepi

# https://oeis.org/A072613
def sqfsp(n):
    s = 0
    for k in range(1, primepi(isqrt(n)) + 1):
        s += primepi(n//prime(k)) - k + 1
    return s - primepi(isqrt(n))

def main():
    tab = [
        0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 4, 4, 4, 4, 4, 4, 5, 6, 6, 6,
        6, 7, 7, 7, 7, 7, 7, 7, 8, 9, 10, 10, 10, 11, 12, 12, 12, 12, 12, 12,
        12, 13, 13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 16, 17, 17, 17, 17, 18,
        18, 18, 19, 19, 19, 19, 20, 20, 20, 20, 20, 21, 21, 21, 22, 22, 22, 22
    ]

    assert(sqfsp(1) == 0)
    assert(sqfsp(62) == 18)
    assert(sqfsp(420) == 124)
    assert(sqfsp(10000) == 2600)

    for i in range(len(tab)):
        assert(sqfsp(i + 1) == tab[i])

main()
