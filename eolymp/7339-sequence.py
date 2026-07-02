#!/usr/bin/env python3

"""

Find the N-th term in the sequence: 1,10,11,100,101,110,111,1000,….

Input
The input contains a single natural number N (N≤10000).

Output
Output the N-th term of the sequence.

Examples
Input #1
7

Answer #1
111

"""

def solve(n):
    return bin(n)[2:]

def main():
    assert(solve(7) == "111")

main()
