#!/usr/bin/env python3

"""

A powerful number is a positive integer n such that for every prime p that divides n, p^2 also divides n. Or equivalently, n is powerful if and only if it can be written in the form n=a^2b^3, where a and b are positive integers.

For example, 972=22×35 is powerful, because 22 and 32 both divide 972. And we have 972=62×33.

961=312 is also powerful, because 312 divides 961. And we have 961=312×13.

On the other hand, 1001=7×11×13 is not powerful, because 72 does not divide 1001. It is not possible to write 1001 in the form a^2b^3.

Here is a list of all the powerful numbers less than 1000:

1, 4, 8, 9, 16, 25, 27, 32, 36, 49, 64, 72, 81, 100, 108, 121, 125, 128, 144, 169, 196, 200, 216, 225, 243, 256, 288, 289, 324, 343, 361, 392, 400, 432, 441, 484, 500, 512, 529, 576, 625, 648, 675, 676, 729, 784, 800, 841, 864, 900, 961, 968, 972
This is sequence A001694 in the OEIS.

Task
Given a positive integer n, determine whether or not it is a powerful number.

This is code-golf, so the shortest code in bytes wins.

This is also a decision-problem so you may use your language's convention for truthy/falsy (swapping truthy and falsy is allowed), or use two distinct, fixed values to represent true or false.

"""

from sympy import *

# https://oeis.org/A001694
def powerful(n):
    if n == 1:
        return True

    f = factorint(n)
    return min(f.values()) > 1

def gen(n):
    r = []
    i = 1
    while len(r) < n:
        if powerful(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [1, 4, 8, 9, 16, 25, 27, 32, 36, 49, 64, 72, 81, 100, 108, 121, 125, 128, 144, 169, 196, 200, 216, 225, 243, 256, 288, 289, 324, 343, 361, 392, 400, 432, 441, 484, 500, 512, 529, 576, 625, 648, 675, 676, 729, 784, 800, 841, 864, 900, 961, 968, 972, 1000]
    
    assert(gen(len(tab)) == tab)

main()
