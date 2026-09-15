#!/usr/bin/env python3

"""

You are given three integers n, m, k. A good array arr of size n is defined as follows:

Each element in arr is in the inclusive range [1, m].
Exactly k indices i (where 1 <= i < n) satisfy the condition arr[i - 1] == arr[i].
Return the number of good arrays that can be formed.

Since the answer may be very large, return it modulo 10^9 + 7.

Example 1:

Input: n = 3, m = 2, k = 1

Output: 4

Explanation:

There are 4 good arrays. They are [1, 1, 2], [1, 2, 2], [2, 1, 1] and [2, 2, 1].
Hence, the answer is 4.

Example 2:

Input: n = 4, m = 2, k = 2

Output: 6

Explanation:

The good arrays are [1, 1, 1, 2], [1, 1, 2, 2], [1, 2, 2, 2], [2, 1, 1, 1], [2, 2, 1, 1] and [2, 2, 2, 1].
Hence, the answer is 6.

Example 3:

Input: n = 5, m = 2, k = 0

Output: 2

Explanation:

The good arrays are [1, 2, 1, 2, 1] and [2, 1, 2, 1, 2]. Hence, the answer is 2.

Constraints:

1 <= n <= 10^5
1 <= m <= 10^5
0 <= k <= n - 1

Hint 1
The first position arr[0] has m choices.

Hint 2
For each of the remaining n - 1 indices, 0 < i < n, select k positions from left to right and set arr[i] = arr[i - 1].

Hint 3
For all other indices, set arr[i] != arr[i - 1] with (m - 1) choices for each of the n - 1 - k positions.

"""

from math import comb

def count(n, m, k):
    mod = 1_000_000_007
    return (comb(n - 1, k) * m * (m - 1)**(n - 1 - k)) % mod

def main():
    assert(count(3, 2, 1) == 4)
    assert(count(4, 2, 2) == 6)
    assert(count(5, 2, 0) == 2)

main()

