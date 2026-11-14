#!/usr/bin/env python3

"""

Consider this sequence {1, 2, 3 ... N}, as an initial sequence of first N natural numbers. You can rearrange this sequence in many ways. There will be a total of N! arrangements. You have to calculate the number of arrangements of first N natural numbers, where in first M positions; exactly K numbers are in their initial position.

For Example, N = 5, M = 3, K = 2. You should count this arrangement {1, 4, 3, 2, 5}, here in first 3 positions 1 is in 1st position and 3 in 3rd position. So exactly 2 of its first 3 are in their initial position. But you should not count {1, 2, 3, 4, 5}.

Input
Input starts with an integer T (≤ 1000), denoting the number of test cases.

Each case contains three integers N (1 ≤ N ≤ 1000), M (M ≤ N), K (0 < K ≤ M).

Output
For each case, print the case number and the total number of possible arrangements modulo 1000000007 (10^9 + 7).

Sample
Input	Output
2
5 3 2
10 6 3

Case 1: 12
Case 2: 64320

"""

from sympy import subfactorial
from math import comb

def solve(n, m, k):
    mod = 1000000007
    r = 0
    for i in range(n - m + 1):
        r += comb(n - m, i) * subfactorial(n - i - k)
    r *= comb(m, k)
    return r % mod

def main():
    assert(solve(5, 3, 2) == 12)
    assert(solve(10, 6, 3) == 64320)

main()
