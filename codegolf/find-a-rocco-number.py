#!/usr/bin/env python3

"""

I was asked this question in an interview but I was unable to figure out any solution. I don't know whether the question was right or not. I tried a lot but couldn't reach any solution. Honestly speaking, nothing came to my mind.

Rocco numbers
A positive integer n is a Rocco number if it can be represented either as n=p(p+14) or n=p(p-14), where p is a prime number.

The first 10 Rocco numbers are:

32,51,95,147,207,275,351,435,527,627

Task
Your code must accept a positive integer as input and determine if it is a Rocco number or not.

Brownie points
Write a function that calculates and prints the count of Rocco numbers less than or equal to 1 million.
Write a function that calculates and prints the count of Rocco numbers from the bonus question (above one) that are prime.

"""

from sympy import *

def rocco(n):
    if n < 1:
        return False

    p = 2
    while True:
        u = p * (p - 14)
        v = p * (p + 14)
        if u > n:
            return False
        if u == n or v == n:
            return True
        p = nextprime(p)

def gen(n):
    r = []
    i = 2
    while len(r) < n:
        if rocco(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [32, 51, 95, 147, 207, 275, 351, 435, 527, 627]
    assert(gen(len(tab)) == tab)

main()
