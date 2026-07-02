#!/usr/bin/env python3

"""

Find the sum of even numbers on a segment from a to b inclusively.

Input
Two integers a and b (a≤b), no more than 10^9 by absolute value.

Output
Print the sum of even numbers on a segment from a to b inclusively.

Examples

Input #1
1 5

Answer #1
6

"""

def solve(a, b):
    if a%2 != 0:
        a += 1
    if b%2 != 0:
        b -= 1
    
    if a > b:
        return 0
    return (a+b)*((b-a)//2 + 1) // 2

def main():
    assert(solve(1, 5) == 6)

main()
