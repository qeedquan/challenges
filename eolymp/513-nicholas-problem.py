#!/usr/bin/env python3

"""

Nicholas must deliver gifts to n children (n≤10^18).
He wants to know in how many ways he can do this.
Since this number may be very large, output the result modulo m (m≤2009).

Input
The input consists of two natural numbers n and m given in a single line.

Output
Print the number of ways to deliver the gifts.

Examples

Input #1
1 100

Answer #1
1

Input #2
5 1000

Answer #2
120

"""

from sympy import factorial

def solve(n, m):
    return factorial(n) % m

def main():
    assert(solve(1, 100) == 1)
    assert(solve(5, 1000) == 120)

main()
