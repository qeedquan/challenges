#!/usr/bin/env python3

"""

Euler's totient function, φ(n), counts the number of integers 1≤k≤n such that gcd(k,n)=1. For example, φ(9)=6 as 1,2,4,5,7,8 are all coprime to 9.
However, φ(n) is not injective, meaning that there are distinct integers m,n such that φ(m)=φ(n). For example, φ(7)=φ(9)=6.

The number of integers n such that φ(n)=k, for each positive integer k, is given by A014197. To clarify this, consider the table

k       Integers n such that φ(n)=k   How many? (aka A014197)
1       1,2                           2
2       3,4,6                         3
3                                     0
4       5,8,10,12                     4
5                                     0
6       7,9,14,18                     4
7                                     0
8       15,16,20,24,30                5
9       0
10      11,22                         2

You are to implement A014197.

This is a standard sequence challenge. You may choose to do one of these three options:

Take a positive integer k, and output the kth integer in the sequence (i.e. the number of integers n such that φ(n)=k). Note that, due to this definition, you may not use 0 indexing.
Take a positive integer k and output the first k integers in the sequence
Output the entire sequence, in order, indefinitely
This is code-golf, so the shortest code in bytes wins.

The first 92 elements in the sequence are

2,3,0,4,0,4,0,5,0,2,0,6,0,0,0,6,0,4,0,5,0,2,0,10,0,0,0,2,0,2,0,7,0,0,0,8,0,0,0,9,0,4,0,3,0,2,0,11,0,0,0,2,0,2,0,3,0,2,0,9,0,0,0,8,0,2,0,0,0,2,0,17,0,0,0,0,0,2,0,10,0,2,0,6,0,0,0,6,0,0,0,3

"""

from sympy import *

# https://oeis.org/A014197
def invtotient(n):
    if n < 1:
        return 0
    if n == 1:
        return 2
    if n%2 != 0:
        return 0

    p = (x + 1 for x in divisors(n))
    l = n * prod(i / (i - 1) for i in p if isprime(i))

    r = 0
    for i in range(n, int(l + 1)):
        if totient(i) == n:
            r += 1
    return r

def main():
    tab = [2, 3, 0, 4, 0, 4, 0, 5, 0, 2, 0, 6, 0, 0, 0, 6, 0, 4, 0, 5, 0, 2, 0, 10, 0, 0, 0, 2, 0, 2, 0, 7, 0, 0, 0, 8, 0, 0, 0, 9, 0, 4, 0, 3, 0, 2, 0, 11, 0, 0, 0, 2, 0, 2, 0, 3, 0, 2, 0, 9, 0, 0, 0, 8, 0, 2, 0, 0, 0, 2, 0, 17, 0, 0, 0, 0, 0, 2, 0, 10, 0, 2, 0, 6, 0, 0, 0, 6, 0, 0, 0, 3]

    for i in range(len(tab)):
        assert(invtotient(i + 1) == tab[i])

main()
