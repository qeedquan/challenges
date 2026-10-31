#!/usr/bin/env python3

"""

In this Kata, you will be given two numbers, a and b, and your task is to determine if the first number a is divisible by all the prime factors of the second number b.
For example: solve(15,12) = False because 15 is not divisible by all the prime factors of 12 (which include2).

See test cases for more examples.

Good luck!

"""

from sympy import factorint

def solve(a, b):
    f = factorint(b)
    for p in f:
        if a%p != 0:
            return False
    return True

def main():
    assert(solve(15, 12) == False)
    assert(solve(2, 256) == True)
    assert(solve(2, 253) == False)
    assert(solve(9, 243) == True)
    assert(solve(15, 12) == False)
    assert(solve(21, 2893401) == True)
    assert(solve(21, 2893406) == False)
    assert(solve(54, 2834352) == True)
    assert(solve(54, 2834359) == False)
    assert(solve(1000013, 7187761) == True)
    assert(solve(1000013, 7187762) == False)

main()

