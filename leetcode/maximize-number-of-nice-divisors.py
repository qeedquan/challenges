#!/usr/bin/env python3

"""

You are given a positive integer primeFactors. You are asked to construct a positive integer n that satisfies the following conditions:

The number of prime factors of n (not necessarily distinct) is at most primeFactors.
The number of nice divisors of n is maximized. Note that a divisor of n is nice if it is divisible by every prime factor of n.
For example, if n = 12, then its prime factors are [2,2,3], then 6 and 12 are nice divisors, while 3 and 4 are not.
Return the number of nice divisors of n. Since that number can be too large, return it modulo 10^9 + 7.

Note that a prime number is a natural number greater than 1 that is not a product of two smaller natural numbers.
The prime factors of a number n is a list of prime numbers such that their product equals n.

Example 1:

Input: primeFactors = 5
Output: 6
Explanation: 200 is a valid value of n.
It has 5 prime factors: [2,2,2,5,5], and it has 6 nice divisors: [10,20,40,50,100,200].
There is not other value of n that has at most 5 prime factors and more nice divisors.
Example 2:

Input: primeFactors = 8
Output: 18

Constraints:

1 <= primeFactors <= 10^9

"""

# https://oeis.org/A000792
def max_nice_divisors(n):
    if n < 0:
        return 0
    if n <= 3:
        return max(n, 1)

    m = n // 3
    if n%3 == 0:
        r = 3**m
    elif n%3 == 1:
        r = 4 * 3**(m - 1)
    else:
        r = 2 * 3**m
    return r % 1_000_000_007

def main():
    tab = [
        1, 1, 2, 3, 4, 6, 9, 12, 18, 27, 36, 54, 81, 108, 162, 243, 324, 486,
        729, 972, 1458, 2187, 2916, 4374, 6561, 8748, 13122, 19683, 26244, 39366,
        59049, 78732, 118098, 177147, 236196, 354294, 531441, 708588, 1062882,
        1594323, 2125764, 3188646, 4782969, 6377292
    ]

    for i in range(len(tab)):
        assert(max_nice_divisors(i) == tab[i])

main()

