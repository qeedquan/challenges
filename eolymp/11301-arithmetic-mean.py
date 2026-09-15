#!/usr/bin/env python3

"""

Petya has two numbers a and b (a≤b).
He found the arithmetic mean of these numbers (let it be the number c), that also turned out to be an integer.
That is, c=(a+b)/2.

You are given the number a (that is, the smallest of two numbers), and you are also given the number c. Find b.

Input
The first line contains one integer a (1≤a≤100).

The second line contains a single integer c (a≤c≤100).

Output
Print one integer b.

Examples
Input #1
3
7

Answer #1
11

"""

def solve(a, c):
    return c*2 - a

def main():
    assert(solve(3, 7) == 11)

main()
