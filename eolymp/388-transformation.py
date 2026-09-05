#!/usr/bin/env python3

"""

Let's take a positive integer n. We will change it as follows: if the number is even, divide it by 2; if it is odd, add 1 to it.
After several such changes, we will always obtain 1. For example, starting from 11, we obtain 12, then 6, 3, 4, 2, and finally 1.
Thus, to obtain 1 from 11, we need to make 6 changes.

Given a positive integer, determine the number of changes required to obtain 1.

Input
One positive integer n (1≤n≤10^9).

Output
Print the number of changes required to obtain 1 from n.

Examples

Input #1
11

Answer #1
6

"""

# https://oeis.org/A061313
def solve(n):
    r = 0
    while n > 1:
        if n%2 == 0:
            n //= 2
        else:
            n += 1
        r += 1
    return r

def main():
    tab = [
        0, 1, 3, 2, 5, 4, 4, 3, 7, 6, 6, 5, 6, 5, 5, 4, 9, 8, 8, 7, 8, 7, 7, 6,
        8, 7, 7, 6, 7, 6, 6, 5, 11, 10, 10, 9, 10, 9, 9, 8, 10, 9, 9, 8, 9, 8,
        8, 7, 10, 9, 9, 8, 9, 8, 8, 7, 9, 8, 8, 7, 8, 7, 7, 6, 13, 12, 12, 11,
        12, 11, 11, 10, 12, 11, 11, 10, 11, 10, 10, 9, 12, 11, 11, 10, 11, 10,
        10, 9, 11, 10
    ]

    assert(solve(11) == 6)

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i])

main()
