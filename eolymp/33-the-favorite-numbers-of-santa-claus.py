#!/usr/bin/env python3

"""

Saint Nicholas enjoyed playing with numbers and digits. His favourite was the digit 1, because the New Year begins on 1.01.

Years passed, but he remained superstitious—he did not like numbers where 3 follows 1, that is, the number 13.
For the New Year, he decided to give a new task: count how many of Saint Nicholas's favourite prime numbers are contained in the interval [a,b].

Input
The only line contains two numbers a and b: the start and the end of the given interval (1≤a≤b≤500000).

Output
Print a single number — the count of Saint Nicholas's favourite prime numbers.

Examples
Input #1
9 23

Answer #1
4

"""

from sympy import nextprime

def solve(a, b):
    c = 0
    p = nextprime(a - 1)
    while p <= b:
        if "13" not in str(p):
            c += 1
        p = nextprime(p)
    return c

def main():
    assert(solve(9, 23) == 4)
    assert(solve(13, 14) == 0)
    assert(solve(-50, -25) == 0)

main()
