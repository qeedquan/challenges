#!/usr/bin/env python3

"""

Given a positive integer n > 1 determine how many numbers can be made by adding integers greater than 1 whose product is n. For example if n = 24 we can express n as a product in the following ways

24 = 24             -> 24            = 24
24 = 12 * 2         -> 12 + 2        = 14
24 = 6 * 2 * 2      -> 6 + 2 + 2     = 10
24 = 6 * 4          -> 6 + 4         = 10
24 = 3 * 2 * 2 * 2  -> 3 + 2 + 2 + 2 = 9
24 = 3 * 4 * 2      -> 3 + 4 + 2     = 9
24 = 3 * 8          -> 3 + 8         = 11
We can get the following numbers this way:

24, 14, 11, 10, 9
That is a total of 5 numbers, so our result is 5.

Task
Write a program or function that takes n as input and returns the number of results that can be obtained this way.

This is a code-golf question so answers will be scored in bytes, with fewer bytes being better.

OEIS sequence
OEIS A069016

"""

from itertools import combinations

def prime_factors(number):
    factors = []
    divisor = 2
    while divisor * divisor <= number:
        while number % divisor == 0:
            factors.append(divisor)
            number //= divisor
        divisor += 1

    if number > 1:
        factors.append(number)
    return factors


def possible_sums(numbers):
    results = {sum(numbers)}
    for first, second in combinations(range(len(numbers)), 2):
        combined = (
            numbers[:first]
            + [numbers[first] * numbers[second]]
            + numbers[first + 1:second]
            + numbers[second + 1:]
        )
        results.update(possible_sums(combined))
    return results

# https://oeis.org/A069016
def count_possible_sums(number):
    return len(possible_sums(prime_factors(number)))

def main():
    table = [
        1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 3, 1, 2, 2, 3, 1, 4, 1, 3, 2, 2, 1, 5,
        2, 2, 3, 3, 1, 5, 1, 4, 2, 2, 2, 7, 1, 2, 2, 5, 1, 5, 1, 3, 4, 2, 1, 8,
        2, 4, 2, 3, 1, 7, 2, 5, 2, 2, 1, 9, 1, 2, 4, 6, 2, 5, 1, 3, 2, 5, 1, 10,
        1, 2, 4, 3, 2, 5, 1, 8, 5, 2, 1, 8, 2, 2, 2, 5, 1, 10, 2, 3, 2, 2, 2,
        12, 1, 4, 4, 7, 1, 5, 1
    ]

    for i in range(len(table)):
        assert(count_possible_sums(i + 1) == table[i])

main()
