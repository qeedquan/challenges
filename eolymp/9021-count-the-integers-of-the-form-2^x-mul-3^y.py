#!/usr/bin/env python3

"""

Find the number of integers in the range [a,b] that can be represented in the form 2^x*3^y where x≥0 and y≥0.

Input
Contains no more than 10^6 lines. Each line contains two integers a and b (0≤a≤b≤10^18), representing a single query.

Output
For each query, print on a separate line the number of integers within the range [a,b] inclusive that can be written in the form 2x*3^y.

Examples

Input #1
1 10
100 200

Answer #1
7
5

"""

# https://oeis.org/A071521
def solve(a, b):
    if a > b:
        a, b = b, a

    r = 0
    for x in range(b):
        u = 2**x
        if u > b:
            break
        for y in range(b):
            v = 3**y
            c = u * v
            if c > b:
                break
            if a <= c and c <= b:
                r += 1
    return r

def main():
    tab = [
        1, 2, 3, 4, 4, 5, 5, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 10, 10, 10, 10, 10,
        10, 11, 11, 11, 12, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14, 14,
        14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16,
        16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18
    ]

    assert(solve(1, 10) == 7)
    assert(solve(100, 200) == 5)

    for i in range(len(tab)):
        assert(solve(0, i + 1) == tab[i])

main()
