#!/usr/bin/env python3

"""

Create a program that outputs a hollow rectangle with dimensions n×m, using asterisks for the edges.

Input
You will receive two integers n and m (1≤n,m≤50), which specify the dimensions of the rectangle.

Output
Display a hollow rectangle with dimensions n×m, where the perimeter is formed by asterisks.

Examples
Input #1
3 3

Answer #1
***
* *
***

Input #2
3 5

Answer #2
*****
*   *
*****

"""

def at(x, y, w, h):
    if x == 0 or y == 0 or x == w-1 or y == h-1:
        return '*'
    return ' '

def solve(n, m):
    for y in range(n):
        for x in range(m):
            print(at(x, y, m, n), end='')
        print()
    print()

def main():
    solve(3, 3)
    solve(3, 5)

main()
