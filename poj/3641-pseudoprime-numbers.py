#!/usr/bin/env python3

"""

Description

Fermat's theorem states that for any prime number p and for any integer a > 1, a^p = a (mod p). That is, if we raise a to the pth power and divide by p, the remainder is a. Some (but not very many) non-prime values of p, known as base-a pseudoprimes, have this property for some a. (And some, known as Carmichael Numbers, are base-a pseudoprimes for all a.)

Given 2 < p ≤ 1000000000 and 1 < a < p, determine whether or not p is a base-a pseudoprime.

Input

Input contains several test cases followed by a line containing "0 0". Each test case consists of a line containing p and a.

Output

For each test case, output "yes" if p is a base-a pseudoprime; otherwise output "no".

Sample Input

3 2
10 3
341 2
341 3
1105 2
1105 3
0 0

Sample Output

no
no
yes
no
yes
yes

Source

Waterloo Local Contest, 2007.9.23

"""

from sympy import *

def bap(p, a):
    return not isprime(p) and (a**p)%p == a

def main():
    assert(bap(3, 2) == False)
    assert(bap(10, 3) == False)
    assert(bap(341, 2) == True)
    assert(bap(341, 3) == False)
    assert(bap(1105, 2) == True)
    assert(bap(1105, 3) == True)

main()
