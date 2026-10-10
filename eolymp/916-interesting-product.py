#!/usr/bin/env python3

"""

Determine all possible unique values of the product i⋅j, where the integer variables i and j range from a to b, and c to d, respectively.

1≤a,b,c,d≤10. Note that a may be greater than b, and c may be greater than d.

Input
One line contains four integers a, b, c, and d.

Output
Print the number of unique possible values of the product.

Examples
Input #1
1 10 1 10

Answer #1
42

Input #2
4 2 5 2

Answer #2
9

"""

def solve(a, b, c, d):
    if a > b:
        a, b = b, a
    if c > d:
        c, d = d, c

    r = []
    for i in range(a, b + 1):
        for j in range(c, d + 1):
            r.append(i * j)
    return len(set(r))

def main():
    assert(solve(1, 10, 1, 10) == 42)
    assert(solve(4, 2, 5, 2) == 9)

main()
