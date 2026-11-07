#!/usr/bin/env python3

"""

The k-multifactorial of n is denoted by fac[k](n) and is defined as the product of every positive number of the form n−k⋅x, where x=0,1,2,….

A formal definition of multifactorial is:

fac[k](n) = n                  if k >= n
            n * fac[k](n - k)  if k < n

You will be given n and k and have to evaluate the value of fac[k](n).
If the result is strictly greater than 10^18, you must print overflow.

Input
Two integers n and k (1≤n,k≤2×10^9).

Output
Print the value of fac[k](n). If it is strictly greater than 10^18, print overflow.

Examples

Input #1
14 3

Answer #1
12320

Input #2
1000 2

Answer #2
overflow

"""

def solve(n, k):
    s = 1
    while n > 0:
        s *= n
        n -= k
        if s >= 10**18:
            return "overflow"
    return s

def main():
    assert(solve(14, 3) == 12320)
    assert(solve(1000, 2) == "overflow")

main()

