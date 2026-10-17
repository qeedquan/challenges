#!/usr/bin/env python3

"""

Task
Consider the following operation:

We take a positive integer n and replace it with the sum of its prime factors (if a prime number is presented multiple times in the factorization of n, then it's counted the same number of times in the sum).

This operation is applied sequentially first to the given number, then to the first result, then to the second result and so on.., until the result remains the same.

Given number n, find the final result of the operation.

Example
For n = 24, the output should be 5.

 24 -> (2 + 2 + 2 + 3) = 9 -> (3 + 3) = 6 -> (2 + 3) = 5 -> 5. So the answer for n = 24 is 5.

Input/Output
[input] integer n

Constraints: 2 ≤ n ≤ 10000.

[output] an integer

"""

from sympy import factorint

# https://oeis.org/A029908
def factorsum(n, m=0):
    if n < 0:
        return 0
    if n == m:
        return n
    
    r = 0
    f = factorint(n)
    for x, p in f.items():
        r += x * p
    return factorsum(r, n)

def main():
    tab = [
        0, 2, 3, 4, 5, 5, 7, 5, 5, 7, 11, 7, 13, 5, 5, 5, 17, 5, 19, 5, 7, 13,
        23, 5, 7, 5, 5, 11, 29, 7, 31, 7, 5, 19, 7, 7, 37, 7, 5, 11, 41, 7, 43,
        5, 11, 7, 47, 11, 5, 7, 5, 17, 53, 11, 5, 13, 13, 31, 59, 7, 61, 5, 13,
        7, 5, 5, 67, 7, 5, 5, 71, 7, 73, 5, 13, 23, 5, 5, 79, 13, 7, 43, 83, 5, 13
    ]

    for i in range(len(tab)):
        assert(factorsum(i + 1) == tab[i])
    
main()
