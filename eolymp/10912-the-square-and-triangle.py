#!/usr/bin/env python3

"""

Given a square with side a, in which an isosceles triangle is inscribed. Determine the area of this triangle.

https://static.e-olymp.com/content/ac/acc88a96f75579fb05df7a8ceea8ba3335932038.jpg

Input
The input contains one real number a (1≤a≤10^18).

Output
Print one number — the area of the triangle.

Examples

Input #1
2

Answer #1
2

Input #2
4.4

Answer #2
9.68

"""

def solve(a):
    return a * a * 0.5

def main():
    print(solve(2))
    print(solve(4.4))

main()
