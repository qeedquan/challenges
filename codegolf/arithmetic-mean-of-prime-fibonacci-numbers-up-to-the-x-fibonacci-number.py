#!/usr/bin/env python3

"""

You should have heard about the Fibonacci Numbers, often called the Fibonacci Sequence. In this sequence the first two terms are 0 and 1, and every number after the first two is the sum of the two preceding ones. In other words, F(n) = F(n-1) + F(n-2).

Here are the first 20 Fibonacci numbers:

0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181
Task:
Given an integer x, compute the arithmetic mean (the average) of the prime Fibonacci Numbers up to the x number of the Fibonacci Sequence.

Rules:
the Fibonacci sequence starts with 0 and 1 for this challenge
3 < x < 40, because higher values of x might cause some huge execution time or overflows and smaller values have no output
1 is NOT prime, since it only has 1 divisor
the arithmetic mean should include decimals, if it's the case, or should be displayed as an exact fraction
you are only allowed to take x as input and the code needed to take the input does not count (e.g: if you need something like x = input(), you should not take it into consideration when counting the bytes)
Examples:
Ex. 1: For x=10, the output is 5.75, because the 10th Fibonacci number is 55 and the prime Fibonacci numbers up to 55 are 2, 3, 5, 13, their average being 5.75

Following the explanation from example 1, other examples are:

Ex. 2: For x=15, the output is 57.5

Ex. 3: For x=20, the output is 277.428571428571, or any other close approximation. In this case 277.4286, for instance, is an accepted value

Ex. 4: For x=11, the output is 22.4

Ex. 5: For x=30, the output is 60536.4444444444, or any other close approximation, such as 60536.444

"""

from sympy import isprime

def f(n):
    if n < 2:
        return 0

    s = 2
    a = b = c = 1
    for _ in range(n):
        if isprime(a) and a != 2:
            c += 1
            s += a
        a, b = b, a + b
    return s/c

def test(n, r):
    v = f(n)
    print(v)
    assert(abs(v - r) < 1e-9)

def main():
    test(10, 5.75)
    test(15, 57.5)
    test(20, 277.428571428571)
    test(11, 22.4)
    test(30, 60536.4444444444)

main()
