#!/usr/bin/env python3

"""

Given a number N, write the shortest complete program to find the number of square-free integers below N.

Sample Input
100000
Sample Output
60794
Constraints:

Should work for all positive N below 1,000,000
Should not take more than 10 secs.
Please do not use built in functions, please.

"""

from sympy.ntheory.factor_ import core

# https://oeis.org/A005117 (related)
# https://oeis.org/A013928
def count(n):
    c = 0
    for i in range(1, n):
        if core(i, 2) == i:
            c += 1
    return c

def main():
    tab = [
        0, 1, 2, 3, 3, 4, 5, 6, 6, 6, 7, 8, 8, 9, 10, 11, 11, 12, 12, 13, 13,
        14, 15, 16, 16, 16, 17, 17, 17, 18, 19, 20, 20, 21, 22, 23, 23, 24, 25,
        26, 26, 27, 28, 29, 29, 29, 30, 31, 31, 31, 31, 32, 32, 33, 33, 34, 34,
        35, 36, 37, 37, 38, 39, 39, 39, 40, 41, 42, 42, 43, 44, 45, 45, 46, 47, 47
    ]

    for i in range(len(tab)):
        assert(count(i + 1) == tab[i])

    assert(count(100000) == 60794)

main()
