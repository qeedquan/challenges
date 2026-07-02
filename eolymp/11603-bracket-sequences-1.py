#!/usr/bin/env python3

"""

Calculate the number of valid bracket sequences of length n.

For example, when n=6, there are 5 sequences:

()()()
()(())
(())()
((()))
(()())

Input
One integer n (1≤n≤10^6).

Output
Print the number of sequences modulo 10^9+7.

Examples
Input #1
6
Answer #1
5

"""

from math import comb

def catalan(n):
    return comb(2*n, n) // (n+1)

# https://www.naukri.com/code360/library/count-number-of-valid-parentheses
def solve(n):
    if n%2 != 0:
        return 0
    return catalan(n//2)

def main():
    assert(solve(6) == 5)

main()
