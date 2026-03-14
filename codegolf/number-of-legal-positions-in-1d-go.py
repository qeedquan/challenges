#!/usr/bin/env python3

"""

A 1D go position on a board of size n is a sequence of length n consisting of the numbers0, 1, 2. Not all numbers need to appear in the sequences.

A sequence is legal if every block of 1's has at least one 0 next to it and every block of 2's has at least one 0 next to it. Think of 1 as white, 2 as black and 0 as empty cells.

Examples:

0         Legal
1         Illegal: `1` has no `0`'s next to it
10        Legal
22        Illegal: `22` has no `0`'s next to it
12022     Illegal: `1` has no `0`'s next to it
1022102   Legal
Input: n

Output: Number of legal sequences of length n. Note that a sequence and its reversal may be different (in which case they are counted as different sequences).

Test cases:

1 1
2 5
3 15
4 41
5 113
6 313
7 867
8 2401
9 6649
10 18413

"""

from functools import lru_cache

# https://oeis.org/A102620
@lru_cache(maxsize=None)
def f(n):
    if n < -1:
        return 0
    if n == -1:
        return 3
    if n == 0:
        return 1
    if n == 1:
        return 1
    return 3*f(n - 1) - f(n - 2) + f(n - 3)

def main():
    tab = [1, 5, 15, 41, 113, 313, 867, 2401, 6649, 18413]
    for i in range(len(tab)):
        assert(f(i + 1) == tab[i])

main()
