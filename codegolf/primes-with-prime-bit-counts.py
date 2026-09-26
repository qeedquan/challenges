#!/usr/bin/env python3

"""

Task
Find all the non-negative integers up to and including a given non-zero positive integer n, that are prime and the count of 1's and 0's in their binary representation (having no leading zeroes) are prime too.

Here are the first five such primes,

17, 19, 37, 41, 79

10001, 10011, 100101, 101001, 1001111
Clarifications and rules
Default I/O methods are accepted.
The answer can be a program or a function.
If there are no such primes then output garbage or nothing.
Standard loopholes are forbidden.
2 3 5 7 did not make it to the list because in their binary representation number of occurrences of 0's and 1's are not prime. Consider 7whose binary representation is 111, here 0 occurs zero times and zero is not prime.
Built-ins are allowed.

The shortest code in bytes wins!

Test cases
10
[]

100
[17, 19, 37, 41, 79]

150
[17, 19, 37, 41, 79, 103, 107, 109, 131, 137]

"""

from sympy import *

# https://oeis.org/A144214
def primebits(n):
    c = n.bit_count()
    l = n.bit_length()
    return isprime(c) and isprime(l - c) and isprime(n)

def main():
    tab = [17, 19, 37, 41, 79, 103, 107, 109, 131, 137, 151, 157, 167, 173, 179, 181, 193, 199, 211, 227, 229, 233, 241, 257, 367, 379, 431, 439, 443, 463, 487, 491, 499, 521, 541, 557, 563, 569, 577, 587, 601, 607, 613, 617, 631, 641, 647, 653, 659, 661, 677, 701, 709]

    i, n = 0, 0
    while n < len(tab):
        if primebits(i):
            assert(i == tab[n])
            n += 1
        i += 1

main()
