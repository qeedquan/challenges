#!/usr/bin/env python3

"""

As you may know it, the factorial of a positive integer n is the product of all the positive integers which are equal or smaller to n.

For instance :

6! = 6*5*4*3*2*1 = 720
0! = 1
We will now define a special operation with an irrelevant name like sumFac:

Given a positive integer n, sumFac(n) is the sum of the factorials of the digits.

For instance :

sumFac(132) = 1! + 3! + 2! = 9

Task
Your mission, whether or not you choose to accept it, is to return the sequence (potentially infinite) of the applications of sumFac to an integer given in input.

Example : 132 -> 132, 9, 362880, 81369, 403927, ...

But that's not all! Indeed, the applications of sumFac will eventually create a cycle. You must also return this cycle!

If your language has a built in factorial you can use it. I'm not picky about the return type, you just have to return the sequence of sumFac applications and the cycle in a format understandable by a human.

EDIT : To help you visualize better what should the output look like I copied Leaky Nun's just below:

[132, 9, 362880, 81369, 403927, 367953, 368772, 51128, 40444, 97, 367920, 368649, 404670, 5810, 40442, 75, 5160, 842, 40346, 775, 10200, 6, 720, 5043, 151, 122, 5, 120, 4, 24, 26, 722, 5044, 169, 363601, 1454]
You just need to stop the sequence when the cycle is about to start for the second time!

But this is code-golf so the shortest answer in bytes wins!

"""

from math import factorial

def next(n):
    r = 0
    while n > 0:
        r += factorial(n % 10)
        n //= 10
    return r

def sumfac(n):
    r = []
    m = {}
    while n not in m:
        r.append(n)
        m[n] = True
        n = next(n)
    return r

def main():
    assert(sumfac(132) == [132, 9, 362880, 81369, 403927, 367953, 368772, 51128, 40444, 97, 367920, 368649, 404670, 5810, 40442, 75, 5160, 842, 40346, 775, 10200, 6, 720, 5043, 151, 122, 5, 120, 4, 24, 26, 722, 5044, 169, 363601, 1454])

main()

