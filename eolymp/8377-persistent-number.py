#!/usr/bin/env python3

"""

Given a number x, we define a function p(x) as the product of the digits of x.
We can then form a sequence x,p(x),p(p(x))... .
The persistence of x is then defined as the index (0-based) of the first single digit number in the sequence.
For example, using 99, we get the sequence 99,9⋅9=81,8⋅1=8.
Thus, the persistence of 99 is 2. You will be given n, and you must find its persistence.

Input
Each line contains one integer n(0≤n≤2⋅10^9).

Output
For each number n print on a separate line its persistence.

Examples
Input #1
99
268
6

Answer #1
2
4
0

"""

from operator import mul
from functools import reduce

# https://oeis.org/A031346
def solve(n):
    r = 0
    while n > 9:
        n = reduce(mul, (int(d) for d in str(n)))
        r += 1
    return r

def main():
    tab = [
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 1, 1, 1, 2, 2, 2, 2, 3,
        2, 3, 1, 1, 2, 2, 2, 3, 2, 3, 2, 3, 1, 1, 2, 2, 2, 2, 3, 2, 3, 3, 1, 1,
        2, 2, 3, 3, 2, 4, 3, 3, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 1, 1, 2, 3, 3, 3,
        3, 3, 3, 2
    ]

    assert(solve(99) == 2)
    assert(solve(268) == 4)
    assert(solve(6) == 0)

    for i in range(len(tab)):
        assert(solve(i) == tab[i])

main()
