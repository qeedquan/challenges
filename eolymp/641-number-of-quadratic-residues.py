#!/usr/bin/env python3

"""

Let m be a natural number. A number a∈{0,1,…,m−1} is called a quadratic residue modulo m if there exists an integer x such that x^2-a is divisible by m.
You are given m and required to find the number of quadratic residues modulo m.

Input
The first line contains a natural number T (1≤T≤100), the number of test cases. Each of the following T lines contains a number m.
It is guaranteed that each m does not exceed 10^12.

Output
For each m from the input, output the number of quadratic residues modulo m on a separate line.

Examples

Input #1
5
1
2
3
4
12

Answer #1
1
2
2
2
4

"""

from sympy.ntheory import is_quad_residue

# https://oeis.org/A000224
def solve(n):
    r = 0
    for i in range(n):
        if is_quad_residue(i, n):
            r += 1
    return r

def main():
    tab = [
        1, 2, 2, 2, 3, 4, 4, 3, 4, 6, 6, 4, 7, 8, 6, 4, 9, 8, 10, 6, 8, 12, 12,
        6, 11, 14, 11, 8, 15, 12, 16, 7, 12, 18, 12, 8, 19, 20, 14, 9, 21, 16,
        22, 12, 12, 24, 24, 8, 22, 22, 18, 14, 27, 22, 18, 12, 20, 30, 30, 12,
        31, 32, 16, 12, 21, 24, 34, 18, 24, 24, 36, 12
    ]

    assert(solve(1) == 1)
    assert(solve(2) == 2)
    assert(solve(3) == 2)
    assert(solve(4) == 2)
    assert(solve(12) == 4)

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i])

main()
