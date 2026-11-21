#!/usr/bin/env python3

"""

Challenge
This is a simple one: Given a positive integer up to 1,000,000, return the closest prime number.

If the number itself is prime, then you should return that number; if there are two primes equally close to the provided number, return the lower of the two.

Input is in the form of a single integer, and output should be in the form of an integer as well.

I don't care how you take in the input (function, STDIN, etc.) or display the output (function, STDOUT, etc.), as long as it works.

This is code golf, so standard rules apply—the program with the least bytes wins!

Test Cases
Input  =>  Output
------    -------
80     =>      79
100    =>     101
5      =>       5
9      =>       7
532    =>     523
1      =>       2

"""

from sympy import *

def closest_prime(n):
    if n < 2:
        return 2
    
    if isprime(n):
        return n
    
    p1 = prevprime(n)
    p2 = nextprime(n)
    if n - p1 <= p2 - n:
        return p1
    return p2

def main():
    assert(closest_prime(80) == 79)
    assert(closest_prime(100) == 101)
    assert(closest_prime(5) == 5)
    assert(closest_prime(9) == 7)
    assert(closest_prime(532) == 523)
    assert(closest_prime(1) == 2)

main()
