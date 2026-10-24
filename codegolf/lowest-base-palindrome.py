#!/usr/bin/env python3

"""

Given a number n, write a program that finds the smallest base b≥2 such that n is a palindrome in base b.
For example, an input of 28 should return the base 3 since  28_10 = 1001_3.
Although 93 is a palindrome in both base  2 and base 5, the output should be 2 since  2<5.

Input
A positive integer  n<2^31.

Output
Return the smallest base  b≥2 such that the base b representation of n is a palindrome.
Do not assume any leading zeros.

Samples (input => output):

11→10


32→7


59→4


111→6


Rules
The shortest code wins.

"""

# Ported from @xnor solution
def lowest_base_palindrome(number, base=2):
    digits = []
    value = number
    while value > 0:
        digits.append(value % base)
        value //= base
    
    if digits == digits[::-1]:
        return base
    return lowest_base_palindrome(number, base+1)

def main():
    assert(lowest_base_palindrome(11) == 10)
    assert(lowest_base_palindrome(32) == 7)
    assert(lowest_base_palindrome(59) == 4)
    assert(lowest_base_palindrome(111) == 6)

main()
