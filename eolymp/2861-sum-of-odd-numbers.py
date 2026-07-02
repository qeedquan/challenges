#!/usr/bin/env python3

"""

Find the sum of odd numbers in the range from a to b.

Input
Two integers a and b, with ∣a∣≤10^9 and ∣b∣≤10^9.

Output
Print the sum of odd numbers in the range from a to b.

Examples

Input #1
2 5

Answer #1
8

Input #13
-1987655734 1999999734

Answer #13
12305904774248000

"""

def solve(a, b):
    if a%2 == 0:
        a += 1
    if b%2 == 0:
        b -= 1

    if a > b:
        return 0
    
    n = (b-a)//2 + 1;
    return (2*a + 2*(n-1))*n // 2

def main():
    assert(solve(2, 5) == 8)
    assert(solve(-1987655734, 1999999734) == 12305904774248000)

main()

