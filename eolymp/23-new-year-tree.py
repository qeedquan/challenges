#!/usr/bin/env python3

"""

Petryk has a circular garland consisting of n lamps, and he has k different colors to paint them.
He wants to color the garland so that no two adjacent lamps are the same color.
How many ways can Petryk color the garland under this condition?

Input
The first line contains two integers n and k (1≤n,k≤15): the number of lamps and the number of colors, respectively.

Output
Print the number of possible ways to color the garland. If it is impossible to color the garland according to the described requirements, print -1.

Examples
Input #1
6 2

Answer #1
2

"""

"""

https://www.cs.tufts.edu/comp/150GT/documents/The%20Chromatic%20Polynomial%20for%20Cycle%20Graphs.pdf
https://math.stackexchange.com/questions/91009/prove-that-the-chromatic-polynomial-of-a-cycle-graph-c-n-equals-k-1n
https://en.wikipedia.org/wiki/Chromatic_polynomial

"""

def solve(n, k):
    return (k - 1)**n + (-1)**n*(k - 1)

def main():
    assert(solve(6, 2) == 2)
    assert(solve(3, 3) == 6)

main()
