#!/usr/bin/env python3

"""

It is necessary to find and output the number of even natural n-digit numbers that do not belong to the interval [a,b].

Input
Three natural numbers n, a, b in one line separated by a space (1≤n≤12), (1≤a,b≤10^12)

Output
The answer to the problem.

Examples

Input #1
2 23 45

Answer #1
34

"""

def seq(a, b):
    if a > b:
        return 0
    
    k = b - a + 1
    r = k//2
    if k%2 != 0 and a%2 == 0 and b%2 == 0:
        r += 1
    return r

def solve(n, a, b):
    n0 = 10**(n - 1)
    n1 = 10**n - 1
    return seq(n0, n1) - seq(max(n0, a), min(n1, b))

def main():
    assert(solve(2, 23, 45) == 34)
    assert(solve(2, 20, 500) == 5)
    assert(solve(3, 100, 999) == 0)
    assert(solve(10, 20, 30) == 4500000000)
    assert(solve(11, 200000, 300000) == 45000000000)

main()

