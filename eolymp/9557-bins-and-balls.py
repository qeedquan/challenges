#!/usr/bin/env python3

"""

There are n boxes arranged in a row.
You have an unlimited supply of balls in n different colors.
Place one ball in each box in such a way that no two adjacent boxes contain balls of the same color.
How many different arrangements of balls in the boxes are possible?

Input
One integer n (1≤n≤10^9).

Output
Print the number of different arrangements of balls in the boxes, computed modulo 10^9+7.

Examples
Input #1
3

Answer #1
12

"""

# https://oeis.org/A055897
def solve(n):
    mod = 1_000_000_007
    r = pow(n-1, n-1, mod)
    r = (r * n) % mod
    return r

def main():
    tab = [
        1, 2, 12, 108, 1280, 18750, 326592, 6588344, 150994944, 3874204890,
        110000000000, 3423740047332, 115909305827328, 4240251492291542,
        166680102383370240, 7006302246093750000, 313594649253062377472,
        14890324713954061755186, 747581753430634213933056
    ]

    assert(solve(3) == 12)

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i] % 1_000_000_007)

main()
