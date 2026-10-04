#!/usr/bin/env python3

"""

Description

Current work in cryptography involves (among other things) large prime numbers and computing powers of numbers among these primes. Work in this area has resulted in the practical use of results from number theory and other branches of mathematics once considered to be only of theoretical interest.
This problem involves the efficient computation of integer roots of numbers.
Given an integer n>=1 and an integer p>= 1 you have to write a program that determines the n th positive root of p. In this problem, given such integers n and p, p will always be of the form k to the nth. power, for an integer k (this integer is what your program must find).

Input

The input consists of a sequence of integer pairs n and p with each integer on a line by itself. For all such pairs 1<=n<= 200, 1<=p<10101 and there exists an integer k, 1<=k<=109 such that kn = p.

Output

For each integer pair n and p the value k should be printed, i.e., the number k such that k n =p.

Sample Input

2 16
3 27
7 4357186184021382204544

Sample Output

4
3
1234
Source

México and Central America 2004

"""

from sympy import *

def nroot(x, n):
    (r, _) = integer_nthroot(x, n)
    return r

def main():
    assert(nroot(16, 2) == 4)
    assert(nroot(27, 3) == 3)
    assert(nroot(4357186184021382204544, 7) == 1234)

main()
