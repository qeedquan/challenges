#!/usr/bin/env python3

"""

A super prime is a prime whose index in the list of primes is also a prime:

3, 5, 11, 17, 31, 41, 59, 67, 83, 109, 127, 157, 179, 191, 211, 241, 277, 283, 331, 353, 367, 401, 431, 461, 509, 547, 563, 587, 599, 617, 709, 739, 773, 797, 859, 877, 919, 967, 991, ...
For this challenge, an "order 2" super prime is defined as a super prime whose index in the list of super primes is a super prime:

11, 31, 127, 277, 709, 1063, 1787, 2221, 3001, 4397, ...
An "order 3" super prime is an order 2 super prime whose index in the list of order 2 super primes is an order 2 super prime:

5381, 52711, 648391, ...
And so on.

Task
Your task is to write a program or function, which, when given a prime, outputs/returns the highest order of super primes that the prime is a part of.

In other words, how "super" is the prime?

Rules
This is code-golf so the solution with the lowest byte count wins
Standard loopholes are forbidden
The index of each prime in the list of primes, super primes, and so on, is assumed to be 1-indexed
You must output:
0 for primes which are not super primes
1 for super primes which are not order 2 super primes
2 for order 2 super primes which are not order 3 super primes
And so on
You can assume inputs will always be prime numbers
Test Cases
2 -> 0
3 -> 1
11 -> 2
211 -> 1
277 -> 2
823 -> 0
4397 -> 2
5381 -> 3
171697 -> 2
499403 -> 2
648391 -> 3
Your program must in theory be able to handle any order of super prime from 0 to infinity, even if it can only do the first few in a reasonable time.

"""

from sympy import *

"""

@att

Primes of order n are those that are a result of applying Prime (with Prime[x] the xth prime) on an integer 2^n times.

"""
def superprime_order(number, order):
    for _ in range(2**order):
        number = prime(number)
    return number

def solve(number):
    order = 0
    while True:
        found = False
        for index in range(number + 1):
            value = superprime_order(index + 1, order)
            if value > number:
                return order - 1
            if value == number:
                break
        order += 1

def main():
    assert(solve(2) == 0)
    assert(solve(3) == 1)
    assert(solve(11) == 2)
    assert(solve(211) == 1)
    assert(solve(277) == 2)
    assert(solve(823) == 0)
    assert(solve(4397) == 2)
    assert(solve(5381) == 3)
    assert(solve(171697) == 2)
    assert(solve(499403) == 2)
    assert(solve(648391) == 3)

main()
