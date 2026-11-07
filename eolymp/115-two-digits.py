#!/usr/bin/env python3

"""

How many n-digit numbers can be formed using only the digits 5 and 9, such that no three identical digits appear consecutively?

Input
One integer n (n≤30).

Output
Print the number of such n-digit numbers.

Examples
Input #1
3

Answer #1
6

"""

from sympy import fibonacci

# https://oeis.org/A055389
def seq(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    return 2 * fibonacci(n)

def solvebf(n):
    p = [0] * max(3, n + 2)
    p[0] = 0
    p[1] = 2
    p[2] = 4
    for i in range(3, n + 1):
        p[i] = p[i - 1] + p[i - 2]
    return p[n]

def solve(n):
    n += 1
    if n < 2:
        return 0
    return seq(n)

def main():
    tab = [
        1, 2, 2, 4, 6, 10, 16, 26, 42, 68, 110, 178, 288, 466, 754, 1220, 1974,
        3194, 5168, 8362, 13530, 21892, 35422, 57314, 92736, 150050, 242786,
        392836, 635622, 1028458, 1664080, 2692538, 4356618, 7049156, 11405774,
        18454930, 29860704, 48315634, 78176338
    ]

    assert(solve(3) == 6)

    for i in range(len(tab)):
        assert(seq(i) == tab[i])

    for i in range(1000):
        assert(solve(i) == solvebf(i))

main()
