#!/usr/bin/env python3

"""

Two binary numbers, each with N digits, are provided.

Your task is to compute the XOR of these two numbers.

Input
First, the number N is given. Following this, two binary numbers are provided, each on a separate line (1≤N≤500).

Output
Output a single binary number, which is the result of the XOR operation, having N digits.

Examples

Input #1
3
101
111

Answer #1
010

"""

def solve(a, b):
    r = ""
    for i in range(len(a)):
        if a[i] != b[i]:
            r += '1'
        else:
            r += '0'
    return r

def main():
    assert(solve("101", "111") == "010")

main()
