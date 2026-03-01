#!/usr/bin/env python3

"""

Math Object Madness
You are a(n) novice/average/experienced/senior/professional/world-class Developer (choose one) who specialises in Javascript. One day, your naughty little brother/sister/whatever gets hold of your precious computer with all the software and functionality in it and manages to utterly destroy the Javascript Math object! Being the Developer that you are, you decide to recover as much of the functionality as possible.

Objective
Most, if not all, of the functionality of Javascript's built-in Math object is disabled. Your goal is to recover the following:

Math.ceil(x)
Math.floor(x)
Math.round(x)
Math.abs(x)
Math.max(args[]) (CAUTION: A variable number of arguments will be passed into the function)
Math.min(args[]) (CAUTION: A variable number of arguments will be passed into the function)
Math.pow(x,y) (you may assume the exponent is always a positive integer)

You may also attempt to fix other methods such as Math.random() or Math.cos() but your code for the other methods will not be tested.

Credits
The idea of this Kata is not entirely original; credits go to BattleRattle's "Math Issues" ( http://www.codewars.com/kata/5267faf57526ea542e0007fb/train/javascript ) for inspiring me to make this Kata.

"""

import math

class Math:
    def ceil(self, x):
        return math.ceil(x)
    
    def floor(self, x):
        return math.floor(x)

    def round(self, x):
        return math.round(x)

    def abs(self, x):
        return math.abs(x)

    def max(self, *args):
        return max(*args)

    def min(self, *args):
        return min(*args)

    def pow(self, x, p):
        return x**p

def main():
    m = Math()
    print(m.max(1, 2, 3))
    print(m.min(1, 2, 3))
    print(m.ceil(.45))

main()
