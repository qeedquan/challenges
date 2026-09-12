#!/usr/bin/env python3

"""

Introduction
Your goal is to find the least number of ones you need to add or multiply together to get the input value, this is A005245.

Input
One positive integer N.

Output
The smallest number of ones that must be added/multiplied to get N.

Sample Input
7

Sample Output
6

Explanation
(1 + 1 + 1) * (1 + 1) + 1 = 7

Because this requires 6 ones, the output is 6

Test cases
 1  1
 2  2
 3  3
 5  5
10  7
20  9
50 12
As this is a code-golf challenge, lowest number of bytes wins.

"""

def memoized(f):
    memo = {}
    def m_fun(*args):
        if args in memo:
            return memo[args]
        res = f(*args)
        memo[args] = res
        return res

    return m_fun

# https://oeis.org/A005245
@memoized
def mahler_popken(n):
    r = n
    for i in range(2, n):
        a = n*(n % i) + mahler_popken(n // i)
        b = mahler_popken(n - i)
        r = min(r, mahler_popken(i) + min(a, b))
    return r

def main():
    tab = [
        1, 2, 3, 4, 5, 5, 6, 6, 6, 7, 8, 7, 8, 8, 8, 8, 9, 8, 9, 9, 9, 10, 11, 9,
        10, 10, 9, 10, 11, 10, 11, 10, 11, 11, 11, 10, 11, 11, 11, 11, 12, 11,
        12, 12, 11, 12, 13, 11, 12, 12, 12, 12, 13, 11, 12, 12, 12, 13, 14, 12,
        13, 13, 12, 12, 13, 13, 14, 13, 14, 13, 14, 12, 13, 13, 13, 13, 14, 13, 14
    ]

    for i in range(len(tab)):
        assert(mahler_popken(i+1) == tab[i])

main()
