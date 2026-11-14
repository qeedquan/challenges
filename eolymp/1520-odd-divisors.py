#!/usr/bin/env python3

"""

Let f(n) be the greatest odd divisor of a positive integer n. Find the value of the sum:

f(1) + f(2) + ... + f(n)

Input
Each line contains one positive integer n (n≤10^9).

Output
For each value of n, print the value of the sum f(1) + f(2) + ... + f(n) on a separate line.

Examples

Input #1
7
1
777

Answer #1
21
1
201537

"""

from functools import lru_cache

# https://oeis.org/A135013
@lru_cache(maxsize=None)
def f(n):
    if n < 1:
        return 0
    if n == 1:
        return 1
    if n%2 != 0:
        return (n + 1)//2 * ((n - 1)//2 + 1) + f(n//2)
    return (n//2)**2 + f(n//2)

def solve(n):
    return f(n)

def main():
    tab = [
        1, 2, 5, 6, 11, 14, 21, 22, 31, 36, 47, 50, 63, 70, 85, 86, 103, 112,
        131, 136, 157, 168, 191, 194, 219, 232, 259, 266, 295, 310, 341, 342,
        375, 392, 427, 436, 473, 492, 531, 536, 577, 598, 641, 652, 697, 720,
        767, 770, 819, 844, 895, 908, 961, 988, 1043, 1050, 1107, 1136
    ]

    assert(solve(7) == 21)
    assert(solve(1) == 1)
    assert(solve(777) == 201537)

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i])

main()

