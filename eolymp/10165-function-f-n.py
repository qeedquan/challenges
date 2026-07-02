#!/usr/bin/env python3

"""

Function f(n) is given with recurrent relation:

f(n) = f(n-1) + f(n - 2) + ... + f(2) + f(1),
f(1) = 1

Find the value of f(n) mod 123456789.

Input
One positive integer n (1≤n≤10^9).

Output
Print the value of f(n) mod 123456789.

Examples

Input #3
3

Answer #3
2

Input #4
10

Answer #4
256

"""

# https://oeis.org/A000079
def solve(n):
    mod = 123456789
    if n < 1:
        return 0
    if n == 1:
        return 1
    return (1 << (n - 2)) % mod

def main():
    assert(solve(3) == 2)
    assert(solve(10) == 256)

main()
