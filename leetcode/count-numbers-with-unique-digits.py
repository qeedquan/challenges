#!/usr/bin/env python3

"""

Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10^n.

Example 1:

Input: n = 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99

Example 2:

Input: n = 0
Output: 1


Constraints:

0 <= n <= 8

"""

# https://oeis.org/A344389
def unique_digits(n):
    if n < 0:
        return 0
    if n == 0:
        return 1

    r = 10
    u = 9
    v = 9
    while n > 1 and v > 0:
        u *= v
        r += u
        n -= 1
        v -= 1
    return r

def main():
    tab = [
        1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851, 5611771, 8877691,
        8877691, 8877691, 8877691, 8877691, 8877691, 8877691, 8877691, 8877691,
        8877691, 8877691, 8877691, 8877691, 8877691, 8877691, 8877691, 8877691,
        8877691, 8877691, 8877691, 8877691, 8877691
    ]

    assert(unique_digits(2) == 91)
    assert(unique_digits(0) == 1)

    for i in range(len(tab)):
        assert(unique_digits(i) == tab[i])

main()
