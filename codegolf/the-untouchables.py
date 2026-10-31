#!/usr/bin/env python3

"""

Untouchable Numbersα
An untouchable number is a positive integer that cannot be expressed as the sum of all the proper divisors of any positive integer (including the untouchable number itself).

For example, the number 4 is not untouchable as it is equal to the sum of the proper divisors of 9: 1 + 3 = 4. The number 5 is untouchable as it is not the sum of the proper divisors of any positive integer. 5 = 1 + 4 is the only way to write 5 as the sum of distinct positive integers including 1, but if 4 divides a number, 2 does also, so 1 + 4 cannot be the sum of all of any number's proper divisors (since the list of factors would have to contain both 4 and 2).

The number 5 is believed to be the only odd untouchable number, but this has not been proven: it would follow from a slightly stronger version of the Goldbach conjecture. β

There are infinitely many untouchable numbers, a fact that was proven by Paul Erdős.

A few properties of untouchables:

No untouchable is 1 greater than a prime
No untouchable is 3 greater than a prime, except 5
No untouchable is a perfect number
Up to now, all untouchables aside from 2 and 5 are composite.
Objective
Create a program or function that takes a natural number n via standard input or function parameters and prints the first n untouchable numbers.

The output must have separation between the numbers, but this can be anything (i.e. newlines, commas, spaces, etc).

This should be able to work at least 1 <= n <= 8153. This is based on the fact that the b-file provided for the OEIS entryγ goes up to n = 8153.

Standard loopholes are disallowed, as per usual.

Example I/O
1    -> 2
2    -> 2, 5
4    -> 2, 5, 52, 88
10   -> 2, 5, 52, 88, 96, 120, 124, 146, 162, 188
8153 -> 2, 5, 52, 88, 96, 120, ..., ..., ..., 59996
This is code-golf, so least number of bytes wins.

α - Wikipedia, β - MathWorld, γ - OEIS

For some reason this was marked as a duplicate to the 'finding semiperfect numbers' question, however the tasks are completely different. In this case, you must check to make sure that no sum of perfect divisors of any natural number can equal a certain number.

"""

from sympy import divisor_sigma
from functools import cache

@cache
def sigmadelta(m):
    return divisor_sigma(m) - m

# https://oeis.org/A005114
def untouchable(n):
    if n < 2:
        return False
    return not any(sigmadelta(m) == n for m in range(1, (n-1)**2 + 1)) 

def gen(n):
    r = []
    i = 2
    while len(r) < n:
        if untouchable(i):
            r.append(i)
        i += 1
    return r

def main():
    assert(gen(1) == [2])
    assert(gen(2) == [2, 5])
    assert(gen(4) == [2, 5, 52, 88])
    assert(gen(10) == [2, 5, 52, 88, 96, 120, 124, 146, 162, 188])

main()
