#!/usr/bin/env python3

"""

Landau's function g(n) (OEIS A000793) gives the maximum order of an element of the symmetric group Sn.
Here, the order of a permutation π is the smallest positive integer k such that πk is the identity - which is equal to the least common multiple of the lengths of the cycles in the permutation's cycle decomposition.
For example, g(14)=84 which is achieved for example by (1,2,3)(4,5,6,7)(8,9,10,11,12,13,14).

Therefore, g(n) is also equal to the maximum value of lcm(a1,…,ak) where a1+⋯+ak=n with a1,…,ak positive integers.

Problem
Write a function or program that calculates Landau's function.

Input
A positive integer n.

Output
g(n), the maximum order of an element of the symmetric group Sn.

Examples
n    g(n)
1    1
2    2
3    3
4    4
5    6
6    6
7    12
8    15
9    20
10   30
11   30
12   60
13   60
14   84
15   105
16   140
17   210
18   210
19   420
20   420

Score
This is code-golf: Shortest program in bytes wins. (Nevertheless, shortest implementations in multiple languages are welcome.)

Note that there are no requirements imposed on run-time; therefore, your implementation does not necessarily need to be able to generate all the above example results in any reasonable time.

Standard loopholes are forbidden.

"""

from sympy import primerange

# https://oeis.org/A000793
def landau(n):
    if n < 1:
        return []

    r = [1 for j in range(n + 1)]
    for i in primerange(2, n + 1):
        for j in range(n, i - 1, -1):
            h = r[j]
            p = i
            while p <= j:
                h = max((p if j == p else r[j - p] * p), h)
                p *= i
            r[j] = h
    return r[:n]

def main():
    tab = [1, 1, 2, 3, 4, 6, 6, 12, 15, 20, 30, 30, 60, 60, 84, 105, 140, 210, 210, 420, 420, 420, 420, 840, 840, 1260, 1260, 1540, 2310, 2520, 4620, 4620, 5460, 5460, 9240, 9240, 13860, 13860, 16380, 16380, 27720, 30030, 32760, 60060, 60060, 60060, 60060, 120120]

    assert(landau(len(tab)) == tab)

main()
