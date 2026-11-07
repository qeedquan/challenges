#!/usr/bin/env python3

"""

The task is to compute the divisor sum of a number given its prime factorisation.

Input
Two arrays (or something equivalent) of length n, one containing the prime factor and the other containing the corresponding exponent.

Output
The sum of all divisors (including the number itself).

Example
The number 240 has 2, 3, and 5 as prime factors with 4, 1, and 1 as the respective exponents. The expected output would then be 744.

Input: [2,3,5] [4,1,1]
Output: 744
Scoring
Shortest code in bytes wins!

If your solution's run time complexity is O(sum of exponents) rather than O(product of exponents), your score may be multiplied by 0.8.

There was a similar question posted here, but it wasn't a challenge. I think the problem is interesting enought to be golfed.

The winner will be choosen this weekend

"""

def solve(primes, exponents):
    if len(primes) == 0 or len(primes) != len(exponents):
        return 0

    result = 1
    for prime, exponent in zip(primes, exponents):
        result *= (prime**(exponent + 1) - 1) // (prime - 1)
    return result

def main():
    assert(solve([2, 3, 5], [4, 1, 1]) == 744)
    assert(solve([2, 3, 7, 11], [4, 2, 3, 2]) == 21439600)

main()
