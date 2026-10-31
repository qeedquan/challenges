#!/usr/bin/env python3

"""

Coding decimal numbers with factorials is a way of writing out numbers in a base system that depends on factorials, rather than powers of numbers.

In this system, the last digit is always 0 and is in base 0!. The digit before that is either 0 or 1 and is in base 1!. The digit before that is either 0, 1, or 2 and is in base 2!, etc. More generally, the nth-to-last digit is always 0, 1, 2, ..., n and is in base n!.

Read more about it at: http://en.wikipedia.org/wiki/Factorial_number_system

Example
The decimal number 463 is encoded as "341010", because:

463 = 3×5! + 4×4! + 1×3! + 0×2! + 1×1! + 0×0!

If we are limited to digits 0..9, the biggest number we can encode is 10!-1 (= 3628799). So we extend 0..9 with letters A..Z. With these 36 digits we can now encode numbers up to 36!-1 (= 3.72 × 1041)

Task
We will need two functions. The first one will receive a decimal number and return a string with the factorial representation.

The second one will receive a string with a factorial representation and produce the decimal representation.

Given numbers will always be positive.

"""

from math import factorial

def dec2fac(n):
    s = ""
    m = 1
    while n > 0:
        c = n % m
        if c > 9:
            c = c + ord('A') - 10
            s = "%c%s" % (c, s)
        else:
            s = "%d%s" % (c, s)
        n //= m
        m += 1
    return s

def fac2dec(s):
    r = 0
    for i in range(len(s)):
        c = ord(s[i])
        if ord('A') <= c and c <= ord('Z'):
            c = c - ord('A') + 10
        elif ord('0') <= c and c <= ord('9'):
            c = c - ord('0')
        r += c * factorial(len(s) - i - 1)
    return r
    
def main():
    assert(dec2fac(463) == "341010")
    assert(dec2fac(2982) == "4041000")
    assert(dec2fac(36288000) == "A0000000000")
    assert(dec2fac(371993326789901217467999448150835199999999) == "ZYXWVUTSRQPONMLKJIHGFEDCBA9876543210")

    assert(fac2dec("341010") == 463)
    assert(fac2dec("4042100") == 2990)
    assert(fac2dec("A0000000000") == 36288000)
    assert(fac2dec("ZYXWVUTSRQPONMLKJIHGFEDCBA9876543210") == 371993326789901217467999448150835199999999)

    for i in range(100000):
        assert(i == fac2dec(dec2fac(i)))

main()
