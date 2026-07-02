#!/usr/bin/env python3

"""

If you've ever learned about primes in math class, you've probably have had to, at one point, determine if a number is prime.
You've probably messed up while you were still learning them, for example, mistaking 39 for a prime.
Well, not to worry, as 39 is a semiprime, i.e., that it is the product of two primes.

Similarly, we can define a k-almost prime as being the product of k prime numbers. For example, 40 is the 4th 4-almost prime; 40 = 5*2*2*2, the product of 4 factors.

Your task is to write a program/function that accepts two integers n and k as input and output/return the nth k-almost prime number. This is a code-golf, so the shortest program in bytes wins.

Test cases
n, k => output
n, 1 => the nth prime number
1, 1 => 2
3, 1 => 5
1, 2 => 4
3, 2 => 9
5, 3 => 27

Miscellaneous
You have to generate the primes yourself by any means other than a simple closed form, if such a closed form exists.

"""

from sympy import factorint

def almost_prime(n, k):
    z = 1
    c = 0
    while c < n: 
        z += 1
        f = factorint(z)
        if sum(f.values()) == k:
            c += 1
    return z

def main():
    assert(almost_prime(1, 1) == 2)
    assert(almost_prime(3, 1) == 5)
    assert(almost_prime(1, 2) == 4)
    assert(almost_prime(3, 2) == 9)
    assert(almost_prime(5, 3) == 27)

main()
