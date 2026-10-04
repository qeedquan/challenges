#!/usr/bin/env python3

"""

You are given 2 positive integers l and r. For any number x, all positive divisors of x except x are called the proper divisors of x.

A number is called special if it has exactly 2 proper divisors. For example:

The number 4 is special because it has proper divisors 1 and 2.
The number 6 is not special because it has proper divisors 1, 2, and 3.
Return the count of numbers in the range [l, r] that are not special.

Example 1:

Input: l = 5, r = 7

Output: 3

Explanation:

There are no special numbers in the range [5, 7].

Example 2:

Input: l = 4, r = 16

Output: 11

Explanation:

The special numbers in the range [4, 16] are 4 and 9.

Constraints:

1 <= l <= r <= 10^9

Hint 1
A special number must be a square of a prime number.

Hint 2
We need to find all primes in the range [sqrt(l), sqrt(r)].

Hint 3
Use sieve to find primes till sqrt(109).

"""

from sympy import isprime
from math import *

def nonspecial(a, b):
    lo = int(ceil(sqrt(a)))
    hi = int(floor(sqrt(b)))
    c = 0
    for i in range(lo, hi + 1):
        if isprime(i):
            c += 1
    return b - a + 1 - c

def main():
    assert(nonspecial(5, 7) == 3)
    assert(nonspecial(4, 16) == 11)

main()

