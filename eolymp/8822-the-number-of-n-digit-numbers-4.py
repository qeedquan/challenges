#!/usr/bin/env python3

"""

The program receives a natural number n as input.

Your task is to determine how many natural numbers with exactly n digits do not include the digit 6.

Input
A natural number n.

Output
The solution to the problem.

Examples

Input #1
1

Answer #1
8

"""

# https://oeis.org/A055275
def solve(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    return 8 * 9**(n - 1)

def main():
    tab = [
        1, 8, 72, 648, 5832, 52488, 472392, 4251528, 38263752, 344373768,
        3099363912, 27894275208, 251048476872, 2259436291848, 20334926626632,
        183014339639688, 1647129056757192, 14824161510814728, 133417453597332552,
        1200757082375992968, 10806813741383936712, 97261323672455430408,
        875351913052098873672
    ]

    assert(solve(1) == 8)

    for i in range(len(tab)):
        assert(solve(i) == tab[i])

main()
