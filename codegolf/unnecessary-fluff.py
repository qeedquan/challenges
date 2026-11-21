#!/usr/bin/env python3

"""

Following the great advice (what do you mean it's not advice?!) on Adding unnecessary fluff we can devise the following task:

Take a list of positive integers and a positive integer m as input.

Only keep the prime values from the list.
Define f(n) = F[n^2 + 1] (the n^2+1-th element in the fibonacci sequence, starting from
F0 = 0
F1 = 1
g(n) = f(f(f(...f(n)))) and
       m applications of f

h(n) = h(g(n) mod n) + 1 if n != 0
       0                 if n = 0

Apply h to each element on the list.
Return the median (you can assume the input contained an odd number of primes).

Test cases
[2,7,11,10,14,4,9], 1 -> 2
[2,7,11,5,13,10,14,4,9], 1 -> 2
[5,5,11,5,13,93,94,95,9], 1 -> 3
[5,7,11], 2 -> 2
[5,5,11], 2 -> 1
[5,43,67], 2 -> 3
[5,43,67], 2 -> 3
[977], 2 -> 5
[719, 727, 733, 739, 743], 2 -> 4
[967], 10 -> 4
[977], 10 -> 3
[5], 10 -> 1
Standard loopholes are forbidden. You can use any reasonable I/O format.

This is code golf, so the shortest answer in each language wins.

"""

from functools import lru_cache
from statistics import median
from sympy import fibonacci, isprime

@lru_cache(maxsize=None)
def iterate(m, n):
    if m <= 0:
        return n
    return iterate(m - 1, fibonacci(n*n + 1))

@lru_cache(maxsize=None)
def count_steps(m, n):
    if n <= 0:
        return 0
    return count_steps(m, iterate(m, n) % n) + 1

# Ported from @Fmbalbuena solution
def solve(values, m):
    primes = filter(isprime, values)
    return median(map(lambda n: count_steps(m, n), primes))

def main():
    assert(solve([2, 3, 4, 5, 6], 1) == 2)
    assert(solve([2, 3, 5, 3, 2], 1) == 2)
    assert(solve([2, 4, 6, 8, 10], 2) == 2)
    assert(solve([5], 1) == 3)
    assert(solve([2], 1) == 2)
    assert(solve([2, 7, 11, 10, 14, 4, 9], 1) == 2)
    assert(solve([2, 7, 11, 5, 13, 10, 14, 4, 9], 1) == 2)
    assert(solve([5, 5, 11, 5, 13, 93, 94, 95, 9], 1) == 3)
    assert(solve([5, 7, 11], 2) == 2)
    assert(solve([5, 5, 11], 2) == 1)
    assert(solve([5, 43, 67], 2) == 3)
    assert(solve([977], 5) == 5)
    assert(solve([719, 727, 733, 739, 743], 2) == 4)
    assert(solve([967], 4) == 4)
    assert(solve([977], 3) == 3)
    assert(solve([5], 1) == 1)

main()

