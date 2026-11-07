#!/usr/bin/env python3

"""

As you know, dividing by zero is not permitted. But are there other numbers you cannot divide by? Your task is to determine this under stricter conditions.

Input
You are given two signed 32-bit integers a and b on a single line.

Output
Output the quotient obtained by dividing a by b, ensuring the result is a signed 32-bit integer.
If it is not possible to represent the result of the division in this format, output ERROR.

Examples

Input #1
10 2

Answer #1
5

"""

def solve(a, b):
    if b == 0 or abs(a)%abs(b) != 0:
        return "ERROR"
    
    r = a // b
    if r < -2147483648 or r > 2147483647:
        return "ERROR"

    return r

def main():
    assert(solve(10, 2) == 5)

main()
