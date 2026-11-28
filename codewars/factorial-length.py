#!/usr/bin/env python3

"""

In this Kata, you will implement a function count that takes an integer and returns the number of digits in factorial(n).

For example, count(5) = 3, because 5! = 120, and 120 has 3 digits.

More examples in the test cases.

Brute force is not possible. A little research will go a long way, as this is a well known series.

Good luck!

Please also try:

"""

from math import *

# https://oeis.org/A034886
def digfact(n):
    if n < 0:
        return 0

    if n < 2:
        return 1

    ln10 = log(10)
    a = log(2*pi*n) / (2*ln10)
    b = n*log(n/e) / ln10
    return int(a + b) + 1

def main():
    tab = [
        1, 1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 18, 19,
        20, 22, 23, 24, 26, 27, 29, 30, 31, 33, 34, 36, 37, 39, 41, 42, 44, 45,
        47, 48, 50, 52, 53, 55, 57, 58, 60, 62, 63, 65, 67, 68, 70, 72, 74, 75,
        77, 79, 81, 82, 84, 86, 88, 90, 91, 93, 95, 97, 99, 101, 102
    ]

    for i in range(len(tab)):
        assert(digfact(i) == tab[i])

    assert(digfact(5) == 3)
    assert(digfact(50) == 65)
    assert(digfact(500) == 1135)
    assert(digfact(5000) == 16326)
    assert(digfact(50000) == 213237)

    assert(digfact(500000) == 2632342)
    assert(digfact(5000000) == 31323382)
    assert(digfact(50000000) == 363233781)

main()
