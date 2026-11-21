#!/usr/bin/env python3

"""

One positive integer n is given. Represent it as the sum of the minimum number of positive cubes. Print this minimum number.

Input
One positive integer n (1≤n≤10^6).

Output
Print one integer — the minimum number of positive cubes whose sum equals n.

Examples

Input #1
33

Answer #1
5

"""

from itertools import product

def nonzeros(a):
    r = 0
    for x in a:
        if x != 0:
            r += 1
    return r

"""

https://en.wikipedia.org/wiki/Waring%27s_problem
https://oeis.org/A002376

Every natural number is the sum of at most 9 cubes.

"""

def solve(n):
    if n < 1:
        return 0

    d = []
    for i in range(1, n + 1):
        if i**3 > n:
            break
        d.append(i**3)

    for i in range(1, 9):
        for x in product(d, repeat=i):
            if sum(x) == n:
                return i
    return 9

def main():
    tab = [
        1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 8, 2, 3, 4, 5, 6, 7, 8, 9, 3,
        4, 5, 1, 2, 3, 4, 5, 4, 5, 6, 2, 3, 4, 5, 6, 5, 6, 7, 3, 4, 5, 6, 7, 6,
        7, 8, 4, 5, 6, 2, 3, 4, 5, 6, 5, 6, 7, 3, 4, 1, 2, 3, 4, 5, 6, 4, 5, 2,
        3, 4, 5, 6, 7, 5, 6, 3, 3, 4, 5, 6, 7, 6, 7, 4, 4, 5, 2, 3, 4, 5, 6, 5,
        5, 6, 3, 4, 5, 6, 7, 6, 6
    ]

    assert(solve(33) == 5)
    assert(solve(1000) == 1)
    assert(solve(1000000) == 1)

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i])

main()
