#!/usr/bin/env python3

"""

Given an integer N, you have to prime factorize N! (factorial N).

Input
Input starts with an integer T (≤ 125), denoting the number of test cases.

Each case contains an integer N (2 ≤ N ≤ 100).

Output
For each case, print the case number and the factorization of the factorial in the following format as given in samples.

Case x: N = p1 (power of p1) * p2 (power of p2) * ...

Here x is the case number, p1, p2 ... are primes in ascending order.

Sample
Input	Output
3
2
3
6

Case 1: 2 = 2 (1)
Case 2: 3 = 2 (1) * 3 (1)
Case 3: 6 = 2 (4) * 3 (2) * 5 (1)

Notes
The output for the 3rd case is (if we replace spaces with .s) Case.3:.6.=.2.(4).*.3.(2).*.5.(1)

"""

from functools import lru_cache
from sympy import factorint

@lru_cache(maxsize=None)
def solve(n):
    if n < 2:
        return {}
    
    fo = solve(n - 1)
    fn = factorint(n)
    for p in fo:
        if p not in fn:
            fn[p] = 0
        fn[p] += fo[p]
    return fn

def main():
    print(solve(2))
    print(solve(3))
    print(solve(6))

main()
