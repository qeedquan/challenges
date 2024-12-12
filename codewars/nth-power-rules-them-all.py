#!/usr/bin/env python3

"""

You are provided with an array of positive integers and an additional integer n (n > 1).

Calculate the sum of each value in the array to the nth power. Then subtract the sum of the original array.

Examples
{1, 2, 3}, 3  -->  (1^3 + 2^3 + 3^3 ) - (1 + 2 + 3)  -->  36 - 6  -->  30
{1, 2}, 5     -->  (1^5 + 2^5) - (1 + 2)             -->  33 - 3  -->  30

"""

def solve(a, n):
    r = 0
    for x in a:
        r += x**n - x
    return r

def main():
    assert(solve([1, 2, 3], 3) == 30)
    assert(solve([1, 2], 5) == 30)

main()
