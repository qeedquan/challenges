#!/usr/bin/env python3

"""

Given an integer n, in how many ways you can tile a 4×n rectangle with 3×1 tiles?

Because the answer can be large, we are interested in the remainder after answer is divided by 1000000007.

Input
First line contains the number of test cases t (1≤t≤100). Each test case consist of a single line containing an integer n (1≤n≤10000).

Output
For each test case print the remainder after answer is divided by 1000000007.

Examples

Input #1
2
3
6

Answer #1
3
13

"""

from functools import lru_cache

# https://oeis.org/A049086
@lru_cache(maxsize=None)
def f(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    if n == 1:
        return 3
    if n == 2:
        return 13
    return 5*f(n - 1) - 3*f(n - 2) + f(n - 3)

# https://mathoverflow.net/questions/223833/generating-function-for-number-of-different-tessellation-checkered-rectangle
def solve(n):
    if n%3 != 0:
        return 0
    return f(n // 3) % 1000000007

def main():
    tab = [
        1, 3, 13, 57, 249, 1087, 4745, 20713, 90417, 394691, 1722917, 7520929,
        32830585, 143313055, 625594449, 2730863665, 11920848033, 52037243619,
        227154537661, 991581805481, 4328482658041, 18894822411423, 82480245888473,
        360045244866137, 1571680309076689, 6860746056673507
    ]

    assert(solve(3) == 3)
    assert(solve(6) == 13)

    for i in range(len(tab)):
        assert(f(i) == tab[i])

main()

