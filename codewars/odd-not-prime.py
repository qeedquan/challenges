#!/usr/bin/env python3

"""

For "x", determine how many positive integers less than or equal to "x" are odd but not prime. Assume "x" is an integer between 1 and 10000.

Example: 5 has three odd numbers (1,3,5) and only the number 1 is not prime, so the answer is 1

Example: 10 has five odd numbers (1,3,5,7,9) and only 1 and 9 are not prime, so the answer is 2

"""

from sympy import primepi

# https://oeis.org/A033271
def odd_not_prime(n):
    if n < 1:
        return 0
    if n == 1:
        return 1
    return ((n + 1) // 2) - primepi(n) + 1 

def main():
    tab = [
        1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4,
        5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 10, 10, 10,
        10, 11, 11, 12, 12, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14, 15, 15, 16,
        16, 16, 16, 17, 17, 17, 17, 17, 17, 18, 18, 19, 19, 19, 19
    ]

    for i in range(len(tab)):
        assert(odd_not_prime(i + 1) == tab[i])

    assert(odd_not_prime(1) == 1)
    assert(odd_not_prime(5) == 1)
    assert(odd_not_prime(9) == 2)
    assert(odd_not_prime(10) == 2)
    assert(odd_not_prime(99) == 26)

main()

