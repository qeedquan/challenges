#!/usr/bin/env python3

"""

Display the first n numbers of the sequence: 1 2 3 4 5 …

Input
A natural number n, where 1≤n≤100.

Output
The sequence numbers should be printed on a single line, separated by spaces.

Examples
Input #1
7

Answer #1
1 2 3 4 5 6 7

"""

def solve(n):
    for i in range(1, n + 1):
        print(i, end=' ')
    print()

def main():
    solve(7)

main()
