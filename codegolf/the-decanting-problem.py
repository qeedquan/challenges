#!/usr/bin/env python3

"""

Given N decanters (0 < N < 10) with that can hold C0 ... CN-1 liters (0 < C < 50) and a goal G liters, please determine if it is possible to reach that goal using only the following actions:

Fill a decanter
Empty a decanter
Pour from one decanter to another until the one being poured to is full or the one being poured from is empty
The goal amount G must be the amount of water in one of the containers at the end. You cannot have a 'output decanter'.

Examples
N: 2
C0: 5
C1: 12
G: 1
Result: Yes

N: 3
C0: 6
C1: 9
C2: 21
G: 5
Result: No

Hint: To calculate if it is possible, check to see if G is divisible by the GCD of the capacities. Also, make sure it will fit in a container.

Remember, this is code-golf, so the code with the lowest number of bytes wins.

"""

from math import *

"""

@xnor

This paper proves a result that vastly simplifies the problem. Prop 1 says that
https://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.96.6047&rep=rep1&type=pdf

You can achieve a goal exactly when it's both:

A multiple of the greatest common divisor (gcd) of the capacities,
At most the maximum capacity
It's clear why both of these are necessary: all amounts remain multiples of the gcd, and the goal must fit in a container. The key of the result is an algorithm to produce any goal amount that fits these conditions.

"""

def decant(C, G):
    return max(C) >= G  and G%gcd(*C) == 0

def main():
    assert(decant([5, 12], 1) == True)
    assert(decant([6, 9, 21], 5) == False)

main()
