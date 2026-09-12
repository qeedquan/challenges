#!/usr/bin/env python3

"""

Given an array (ints) of n integers, find three integers in arr such that the sum is closest to a given number (num), target.

Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

closest_sum([-1, 2, 1, -4], 1) # 2 (-1 + 2 + 1 = 2)
Note: your solution should not modify the input array.

"""

def closest_sum(a, t):
    r = 0
    m = 3*abs(max(a)) + 1
    n = len(a)
    for i in range(n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                v = a[i] + a[j] + a[k]
                d = abs(t - v)
                if d < m or (d == m and v < r):
                    r, m = v, d
    return r

def main():
    assert(closest_sum([-1, 2, 1, -4], 1) == 2)
    assert(closest_sum([5, 4, 0, 3], 3) == 7)
    assert(closest_sum([1, 2, 3, 4], 4) == 6)
    assert(closest_sum([-2, 2, -3, 1], 3) == 1)

main()

