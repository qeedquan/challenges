#!/usr/bin/env python3

"""

Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers.

Input
Starts with the number of test cases t (t≤10) in a single line. In each of the next t lines there are two numbers m and n (1≤m≤n≤10^9,n−m≤10^5).

Output
For every test case print all prime numbers p such that m≤p≤n, one number per line, test cases separated by an empty line.

Examples
Input #1
2
1 10
3 5

Answer #1
2
3
5
7

3
5

"""

from sympy import primerange

def solve(m, n):
    return list(primerange(m, n + 1))

def main():
    print(solve(1, 10))
    print(solve(3, 5))

main()
