#!/usr/bin/env python3

"""

At the input of the program, we have two non-zero integers n and m, written in a single line separated by a space. The program should output 1 if the number n is divisible by m without a remainder, and 0 otherwise.

Input
Two integers written in a single line.

Output
The solution to the problem.

Examples

Input #1
7 4

Answer #1
0

Input #2
8 -2

Answer #2
1

"""

def solve(n, m):
    return n%m == 0

def main():
    assert(solve(7, 4) == 0)
    assert(solve(8, -2) == 1)

main()
