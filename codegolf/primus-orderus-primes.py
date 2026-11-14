#!/usr/bin/env python3

"""

Who are they?
Primus-Orderus Primes (POP) are primes which contain their order in the sequence of primes.
So the nth prime, in order to be POP, must contain all the digits of n in a certain way which I'll explain.

Examples
Let's get things clearer: All digits of n must appear among the digits of POP in the same order they appear in n

The 6469th prime is 64679 which is POP because it contains all digits of 6469 in the right order .
1407647 is POP because it is the 107647th prime number

14968819 is POP (968819th prime).So this challenge is NOT OEIS (A114924)

1327 is NOT POP because it is the 217th prime (digits are not in the right order)

The Challenge
You guessed right!
Given an integer n, output the nth POP

Test Cases
input-> output

1->17
3->14723    
5->57089
10->64553 
29->284833  
34->14968819
This is code-golf so the shortest answer in bytes wins!

All these should be 1-Indexed

"""

from sympy import nextprime

def matches(a, b):
    i = 0
    for ch in b:
        if i < len(a) and a[i] == ch:
            i += 1
    return "0" > a[i:]

def solve(remaining):
    number = 1
    prime = 1
    while remaining:
        prime = nextprime(prime)
        remaining -= matches(str(number), str(prime))
        number += 1
    return prime

def main():
    assert(solve(1) == 17)
    assert(solve(3) == 14723)
    assert(solve(5) == 57089)
    assert(solve(10) == 64553)
    assert(solve(29) == 284833)
    assert(solve(34) == 14968819)

main()
