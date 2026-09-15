#!/usr/bin/env python3

"""

The famous Fibonacci sequence is F(0) = 0; F(1) = 1; F(N+1) = F(N) + F(N-1) (for this challenge we are beginning with 0).

Your challenge: Given n, output the sum of all the dth Fibonacci numbers for all divisors d of the nth Fibonacci number. If you prefer more formal notation,

https://latex.codecogs.com/png.latex?%5Cdpi%7B300%7D&space;%5Csum_%7Bd|F(n)%7DF(d)

Input: a positive integer n

Output: the sum

For example, consider n=4. F(4) = 3The divisors of 3 are 1 and 3, so the output should be F(1) + F(3) = 1 + 2 = 3.

For n=6, F(6) = 8, and the divisors of 8 are 1, 2, 4, 8, so the output is F(1) + F(2) + F(4) + F(8) = 1 + 1 + 3 + 21 = 26.

Test Cases:

1 => 1
2 => 1
3 => 2
4 => 3
5 => 6
6 => 26

This is code-golf, shortest answer in bytes wins. Standard loopholes apply.

"""

from sympy import fibonacci, divisors

def sfd(n):
    r = 0
    for d in divisors(fibonacci(n)):
        r += fibonacci(d)
    return r

def main():
    assert(sfd(1) == 1)
    assert(sfd(2) == 1)
    assert(sfd(3) == 2)
    assert(sfd(4) == 3)
    assert(sfd(5) == 6)
    assert(sfd(6) == 26)

main()
