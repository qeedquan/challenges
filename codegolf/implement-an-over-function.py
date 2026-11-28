#!/usr/bin/env python3

"""

Over is a higher-order function in multiple languages such as APL (⍥). It takes 2 functions and 2 values as arguments, applies the first function to both values, then applies the second to their result. For example, using ⍥ to represent Over:

1 ²⍥+ 2
We would first calculate ² of each argument: 1² = 1 and 2² = 4. We then apply + to these, yielding 5.

You are to take as input:

A black box function, f, which takes an integer as input and returns an integer
A black box function, g, which takes 2 integers as input and returns a single integer 2 integers, a and b.
You should then return the result of g(f(a), f(b)).

If you have a builtin specifically for this (e.g. APL's ⍥, Husk's ¤ etc.), consider including a non-builtin answer as well. It might even get you an upvote :)

You may input and output in the most convenient format for your language, and in any convenient method, including taking a and b as a pair/list/tuple [a, b]

For the sake of simplicity, you can assume that the black-box function will always input and output integers within your language's integer domain, and that a,b and the output will be with your language's integer domain.

This is code-golf, so the shortest code in bytes wins

Test cases
f
g
a, b -> out

f(x) = x²
g(x,y) = x - y
-2, 2 -> 0

f(x) = φ(x)     (Euler totient function)
g(x,y) = 2x + y
5, 9 -> 14

f(x) = x³-x²-x-1
g(x,y) = y⁴-x³-y²-x
-1, -1 -> 22

f(x) = x
g(x,y) = x / y   (Integer division)
-25, 5 -> -5

"""

from sympy import totient

def over(f, g, x, y):
    return g(f(x), f(y))

def main():
    f1 = lambda x: x * x
    g1 = lambda x, y: x - y

    f2 = lambda x: totient(x)
    g2 = lambda x, y: 2*x + y

    f3 = lambda x: x**3 - x**2 - x - 1
    g3 = lambda x, y: y**4 - x**3 - y**2 - x

    f4 = lambda x: x
    g4 = lambda x, y: x//y
    
    assert(over(f1, g1, -2, 2) == 0)
    assert(over(f2, g2, 5, 9) == 14)
    assert(over(f3, g3, -1, -1) == 22)
    assert(over(f4, g4, -25, 5) == -5)

main()
