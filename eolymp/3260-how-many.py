#!/usr/bin/env python3

"""

You have a collection of n different books, and you want to pack k of them to take on a trip. In how many ways can you select k books from the n available?

Input
The input consists of two integers, n (1≤n≤12) — the total number of books, and k (0≤k≤n) — the number of books you want to take with you.

Output
Print the number of ways to choose k books from n.

Examples

Input #1
3 2

Answer #1
3

Input #2
4 1

Answer #2
4

"""

from math import factorial

def solve(n, k):
    return factorial(n) // (factorial(k) * factorial(n - k))

def main():
    assert(solve(3, 2) == 3)
    assert(solve(4, 1) == 4)

main()
