#!/usr/bin/env python3

"""

You are given three integers n, m, and k.

An array arr is called k-even if there are exactly k indices such that, for each of these indices i (0 <= i < n - 1):

(arr[i] * arr[i + 1]) - arr[i] - arr[i + 1] is even.
Return the number of possible k-even arrays of size n where all elements are in the range [1, m].

Since the answer may be very large, return it modulo 109 + 7.

Example 1:

Input: n = 3, m = 4, k = 2

Output: 8

Explanation:

The 8 possible 2-even arrays are:

[2, 2, 2]
[2, 2, 4]
[2, 4, 2]
[2, 4, 4]
[4, 2, 2]
[4, 2, 4]
[4, 4, 2]
[4, 4, 4]

Example 2:

Input: n = 5, m = 1, k = 0

Output: 1

Explanation:

The only 0-even array is [1, 1, 1, 1, 1].

Example 3:

Input: n = 7, m = 7, k = 5

Output: 5832

Constraints:

1 <= n <= 750
0 <= k <= n - 1
1 <= m <= 1000

"""

from math import comb

def choices(n, k):
    return comb(n + k - 1, k)

def count(n, m, k):
    mod = 1_000_000_007

    e = m // 2
    o = (m + 1) // 2
    r = 0
    if k == 0:
        r = (r + o**n) % mod

    for x in range(1, (n + 1 - k) // 2 + 1):
        a = choices(x, k) * choices(x + 1, n - k - 2*x + 1)
        b = e**(k + x) * o**(n - k - x)
        r = r + a*b
    return r % mod

def main():
    assert(count(3, 4, 2) == 8)
    assert(count(5, 1, 0) == 1)
    assert(count(7, 7, 5) == 5832)

main()

