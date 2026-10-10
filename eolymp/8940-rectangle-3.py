#!/usr/bin/env python3

"""

Two positive integers n and m are given. Print the rectangle of size n×m from symbols # as shown in the sample.

Input
Two positive integers n and m (n, m ≤ 100).

Output
Print the rectangle of size n×m from symbols #.

Examples

Input #1
2 3

Answer #1
###
###

"""

def solve(n, m):
    for _ in range(n):
        for _ in range(m):
            print('#', end='')
        print()
    print()

def main():
    solve(2, 3)

main()
