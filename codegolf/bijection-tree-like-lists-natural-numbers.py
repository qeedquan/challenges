#!/usr/bin/env python3

"""

We define a tree-like list, or trist for short, as the empty list or a list containing only previously constructed trists.

The natural numbers can either include 0 or not, according to your preference.

The task is to create a pair of functions or complete programs f and g (they don't have to be named like this or even named at all) that implement a bijection between trists and the natural numbers. In other words:

f must be able to turn any trist into a natural number

g must be able to turn any natural number into a trist

f(g(n)) must equal n for any natural number n

g(f(l)) must be equivalent to l for any trist l

You can assume that all arguments and results fit in the usual numeric type for your language.
Alternatively, instead of the numeric type you could represent a natural number as a list of binary digits, either consistently little- or consistently big-endian.

The shortest solution per language wins. If your functions are recursive, you must name them. If your language requires a statement separator or a newline between the two functions/programs, you don't have to count it.

This is a sample algorithm in Python3 (you are free to implement the bijection in any way you like):

def f(x):
    r = 0
    for y in x:
        r = (2 * r + 1) * 2**f(y)
    return r

def g(n):
    r = []
    while n:
        m = 0
        while n % 2 == 0:
            n //= 2
            m += 1
        n //= 2
        r = [g(m)] + r
    return r

tests = [
    [],
    [[]],
    [[],[]],
    [[[]],[],[[[]],[]]],
    [[[[[]]]]],
]
for l in tests: print(g(f(l)) == l)

for n in range(20): print(f(g(n)) == n)
It uses the following representation:

f([]) = 0
f([a0, a1, ..., a[n-1]]) = 10...0 10...0 ... 10...0(2)
                            f(a0)  f(a1)       f(a2)
                            zeroes zeroes      zeroes

Challenge inspired by @LeakyNun's question in chat.

"""

def f(x):
    r = 0
    for y in x:
        r = (2 * r + 1) * 2**f(y)
    return r

def g(n):
    r = []
    while n > 0:
        m = 0
        while n%2 == 0:
            n //= 2
            m += 1
        n //= 2
        r = [g(m)] + r
    return r

def main():
    tests = [[], [[]], [[], []], [[[]], [], [[[]], []]], [[[[[]]]]]]
    for l in tests:
        assert(g(f(l)) == l)

    for n in range(256):
        assert(f(g(n)) == n)

main()
