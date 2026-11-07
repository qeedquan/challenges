#!/usr/bin/env python3

"""

For the purpose of this challenge, a Prime Power of a Prime (PPP) is defined as a number that can be defined as a prime number to the power of a prime number. For example, 9 is a PPP because it can be represented as 3^2. 81 on the other hand is not a PPP because it can only be represented as 3^4, and 4 is not prime. The first few PPPs are: 4, 8, 9, 25, 27, 32, 49, 121, 125, 128, 169, 243, 289, 343... This is OEIS sequence A053810

Your Task:
Write a program or function that for an input integer n returns/outputs the nth PPP, either 1-indexed or 0-indexed, whichever you prefer.

Input:
An integer between 0 and 1,000, received through any reasonable method.

Output:
The PPP at the index indicated by the input.

Test Cases:
These are 1-indexed, and so, if your program takes 0-indexed input, the same output should be arrived at for the stated input - 1.

3  -> 9
6  -> 32
9  -> 125

Scoring:
This code-golf,lowest score in bytes wins!

"""

from sympy import *

def check(n, x):
    s = sum(primepi(integer_nthroot(x, p)[0]) for p in primerange(x.bit_length()))
    return n - 1 + x - s

# https://oeis.org/A053810
def prime_powers_of_prime(n):
    kmin, kmax = 1, 2
    while check(n, kmax) >= kmax:
        kmax *= 2
    while True:
        kmid = (kmax + kmin) // 2
        if check(n, kmid) < kmid:
            kmax = kmid
        else:
            kmin = kmid
        if kmax-kmin <= 1:
            break
    return kmax

def main():
    tab = [
        4, 8, 9, 25, 27, 32, 49, 121, 125, 128, 169, 243, 289, 343, 361, 529,
        841, 961, 1331, 1369, 1681, 1849, 2048, 2187, 2197, 2209, 2809, 3125,
        3481, 3721, 4489, 4913, 5041, 5329, 6241, 6859, 6889, 7921, 8192, 9409,
        10201, 10609, 11449, 11881, 12167, 12769, 16129, 16807
    ]

    assert(prime_powers_of_prime(3) == 9)
    assert(prime_powers_of_prime(6) == 32)
    assert(prime_powers_of_prime(9) == 125)

    for i in range(len(tab)):
        assert(prime_powers_of_prime(i + 1) == tab[i])

main()
