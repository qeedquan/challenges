#!/usr/bin/env python3

"""

A non-negative integer n is given. Using all its digits, form the largest possible number, and then the smallest one. Print the sum of these two numbers.

For example, for n=56002, the largest number is 65200, and the smallest one is 256 (leading zeros in the number 00256 are not considered).
The required sum is 65200+256=65456.

Input
One integer n (0≤n≤10^8).

Output
Print the sum of the largest and the smallest numbers that can be obtained from n by rearranging its digits.

Examples

Input #1
56002

Answer #1
65456

"""

# https://oeis.org/A056964
def solve(n):
    s = sorted(str(n))
    x = int(''.join(s))
    y = int(''.join(s[::-1]))
    return x + y

def main():
    assert(solve(56002) == 65456)

main()

