#!/usr/bin/env python3

"""

You are given an even number of people num_people that stand around a circle and each person shakes hands with someone else, so that there are num_people / 2 handshakes total.

Return the number of ways these handshakes could occur such that none of the handshakes cross.

Since this number could be very big, return the answer mod 10^9 + 7

Example 1:
Input: num_people = 2
Output: 1

Example 2:
https://assets.leetcode.com/uploads/2019/07/11/5125_example_2.png
Input: num_people = 4
Output: 2
Explanation: There are two ways to do it, the first way is [(1,2),(3,4)] and the second one is [(2,3),(4,1)].

Example 3:
https://assets.leetcode.com/uploads/2019/07/11/5125_example_3.png
Input: num_people = 6
Output: 5

Example 4:
Input: num_people = 8
Output: 14

Constraints:

2 <= num_people <= 1000
num_people % 2 == 0

"""

from math import comb

# https://oeis.org/A000108 
def catalan(n):
    return comb(2*n, n) // (n + 1)

def ways(n):
    mod = 1_000_000_007
    return catalan(n//2) % mod

def main():
    assert(ways(2) == 1)
    assert(ways(4) == 2)
    assert(ways(6) == 5)
    assert(ways(8) == 14)

main()

