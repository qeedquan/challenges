#!/usr/bin/env python3

"""

2013 has the prime factorization 3*11*61. 2014 has the prime factorization 2*19*53. An interesting property regarding these factorizations is that there exist distinct primes in the factorizations of 2013 and 2014 that sum to the same number: 11+61=19+53=72.

Write a program or function that takes as its input two positive integers greater than 1 and returns a truthy value if there exist a sum of selected prime factors of one number that is equal to a sum of selected prime factors in the second number, and a falsey value otherwise.

Clarifications

More than two prime factors can be used. Not all of the prime factors of the number need to be used in the sum. It is not necessary for the number of primes used from the two numbers to be equal.
Even if a prime is raised to some power greater than 1 in the factorization of a number, it can only be used once in the sum of primes for the number.
1 is not prime.
Both input numbers will be less than 2^32-1.
Test cases

5,6
    5=5
    6=2*3
    5=2+3
==>True

2013,2014
    2013=3*11*61
    2014=2*19*53
    11+61=19+53
==>True

8,15
    8=2^3
    15=3*5
    No possible sum
==>False

21,25
    21=3*7
    25=5^2
    No possible sum (can't do 3+7=5+5 because of exponent)
==>False
This is code golf. Standard rules apply. Shortest code in bytes wins.

"""

from itertools import permutations
from sympy import factorint

def distinct_prime_factors(number):
    return set(factorint(number))

def subset_sums(factors):
    result = set()
    for size in range(1, len(factors) + 1):
        for permutation in permutations(factors, size):
            result.add(sum(permutation))
    return result

def common_subset_prime_factor_sums(a, b):
    p1 = distinct_prime_factors(a)
    p2 = distinct_prime_factors(b)
    return len(subset_sums(p1) & subset_sums(p2)) > 0

def main():
    assert(common_subset_prime_factor_sums(5, 6) == True)
    assert(common_subset_prime_factor_sums(2013, 2014) == True)
    assert(common_subset_prime_factor_sums(8, 15) == False)
    assert(common_subset_prime_factor_sums(21, 25) == False)

main()
