#!/usr/bin/env python3

"""

In the yard, builders left two piles of sand, with volumes n and m liters.
Janitor Mr. Miller wants to clean the playground, but for this he needs a bucket to carry the sand away.
Mr. Miller wants to take the largest possible bucket such that, for each pile, the sand can be moved using only a whole number of fully filled buckets.
On Monday, he plans to remove the first pile, and on Wednesday, the second pile. The sand from each pile will be removed separately and independently from the other.

You need to find the capacity (in liters) of such a bucket so that Mr. Miller uses the minimal number of buckets and completely cleans the playground.

Input
In a single line, two numbers are given: n and m (0<n,m≤2^16).

Output
Print one number — the answer to the problem.

Examples
Input #1
2 1

Answer #1
1

"""

from math import gcd

def solve(n, m):
    return gcd(n, m)

def main():
    assert(solve(2, 1) == 1)

main()
