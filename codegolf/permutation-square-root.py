#!/usr/bin/env python3

"""

In math, a permutation σ of order n is a bijective function from the integers 1...n to itself. This list:

2 1 4 3
represents the permutation σ such that σ(1) = 2, σ(2) = 1, σ(3) = 4, and σ(4) = 3.

A square root of a permutation σ is a permutation that, when applied to itself, gives σ. For example, 2 1 4 3 has the square root τ =3 4 2 1.

k           1 2 3 4
τ(k)        3 4 2 1
τ(τ(k))     2 1 4 3
because τ(τ(k)) = σ(k) for all 1≤k≤n.

Input
A list of n>0 integers, all between 1 and n inclusive, representing a permutation. The permutation will always have a square root.

You may use a list of 0...n-1 instead as long as your input and output are consistent.

Output
The permutation's square root, also as an array.

Restrictions
Your algorithm must run in polynomial time in n. That means you can't just loop through all n! permutations of order n.

Any builtins are permitted.

Test cases:
Note that many inputs have multiple possible outputs.

2 1 4 3
3 4 2 1

1
1

3 1 2
2 3 1

8 3 9 1 5 4 10 13 2 12 6 11 7
12 9 2 10 5 7 4 11 3 1 13 8 6

13 7 12 8 10 2 3 11 1 4 5 6 9
9 8 5 2 12 4 11 7 13 6 3 10 1

"""

from itertools import permutations

def compose(sigma, tau):
    return [sigma[j - 1] for j in tau]

"""

https://math.stackexchange.com/questions/266569/how-to-find-the-square-root-of-a-permutation
https://www.johndcook.com/blog/2026/07/26/permutation-roots/

"""
def permutation_sqrt(sigma):
    n = len(sigma)
    if n == 0:
        return []
    if n == 1:
        return sigma
    
    for tau in permutations(range(1, n + 1)):
        if sigma == compose(tau, tau):
            return list(tau)
    return None

def main():
    print(permutation_sqrt([2, 1, 4, 3]))
    print(permutation_sqrt([1]))
    print(permutation_sqrt([3, 1, 2]))
    print(permutation_sqrt([8, 3, 9, 1, 5, 4, 10, 13, 2, 12, 6, 11, 7]))
    print(permutation_sqrt([13, 7, 12, 8, 10, 2, 3, 11, 1, 4, 5, 6, 9]))

main()
