#!/usr/bin/env python3

"""

You are given two positive integers n and limit.

Return the total number of ways to distribute n candies among 3 children such that no child gets more than limit candies.

Example 1:

Input: n = 5, limit = 2
Output: 3
Explanation: There are 3 ways to distribute 5 candies such that no child gets more than 2 candies: (1, 2, 2), (2, 1, 2) and (2, 2, 1).

Example 2:

Input: n = 3, limit = 3
Output: 10
Explanation: There are 10 ways to distribute 3 candies such that no child gets more than 3 candies: (0, 0, 3), (0, 1, 2), (0, 2, 1), (0, 3, 0), (1, 0, 2), (1, 1, 1), (1, 2, 0), (2, 0, 1), (2, 1, 0) and (3, 0, 0).

Constraints:

1 <= n <= 50
1 <= limit <= 50

Hint 1
Use three nested for loops to check all the triplets.

"""

from math import comb

def nhr(n, r):
    if n < 0 or r < 0:
        return 0
    return comb(n + r - 1, r - 1)

def candies(n, limit):
    R = 3
    c = 0
    for r in range(R + 1):
        s = 1
        if r%2 != 0:
            s = -1
        c += s * comb(R, r) * nhr(n - r*(limit + 1), R)
    return c

def candiesbf(n, limit):
    c = 0
    for i in range(min(limit, n) + 1):
        for j in range(min(limit, n - i) + 1):
            if n-i-j <= limit:
                c += 1
    return c

def main():
    assert(candies(5, 2) == 3)
    assert(candies(3, 3) == 10)

    for n in range(100):
        for limit in range(100):
            assert(candies(n, limit) == candiesbf(n, limit))

main()

