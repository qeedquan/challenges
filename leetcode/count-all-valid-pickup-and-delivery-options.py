#!/usr/bin/env python3

"""

Given n orders, each order consists of a pickup and a delivery service.

Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i).

Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:

Input: n = 1
Output: 1
Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.

Example 2:

Input: n = 2
Output: 6
Explanation: All possible orders:
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.

Example 3:

Input: n = 3
Output: 90



Constraints:

    1 <= n <= 500

Hint 1
Use the permutation and combination theory to add one (P, D) pair each time until n pairs.

"""

from math import factorial

def countbf(n):
    if n < 0:
        return 0

    r = 1
    i = 2 * n
    while i > 0:
        r *= i*(i-1)//2
        i -= 2
    return r % 1_000_000_007

# https://oeis.org/A000680
def count(n):
    if n < 0:
        return 0
    
    r = factorial(2*n) // (1<<n)
    r %= 1_000_000_007
    return r

def main():
    assert(count(1) == 1)
    assert(count(2) == 6)
    assert(count(3) == 90)

    for i in range(1000):
        assert(count(i) == countbf(i))

main()
