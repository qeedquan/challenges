#!/usr/bin/env python3

"""

Background
The Fibonacci sequence is defined as

f(1) = 1
f(2) = 1
f(n) = f(n-1) + f(n-2)

The Fibonorial, similar to the factorial, is the product of the first n Fibonacci numbers.

g(n)=f(1) * f(2) * ... * f(n-1) * f(n)

The Fibonomial coefficient, similar to the binomial coefficient is defined as

a(n, 0) = 1
a(n, k) = g(n) / (g(n-k)*g(k))

Task
Your goal is to create a function or program to compute the Fibonomial coefficient given two non-negative integers n and k with l≤n.

Test Cases
a(0, 0) = 1
a(1, 1) = 1
a(2, 0) = 1
a(3, 2) = 2
a(8, 3) = 1092
a(11, 5) = 1514513
a(22, 7) = 7158243695757340957617
a(25, 3) = 49845401197200
a(50, 2) = 97905340104793732225
a(100, 1) = 354224848179261915075

Rules
This is code-golf so the shortest code wins.
Builtins are allowed.

Related
A000045 - Challenge - Fibonacci Sequence
A003266 - Challenge - Fibonorial
A010048 - Fibonomial coefficient

"""

def seq(n, a=1, b=1):
    if n < 1:
        return 1
    return a * seq(n - 1, b, a + b)

def fibonomial(n, k):
    return seq(n) // (seq(k) * seq(n - k))

def main():
    assert(fibonomial(0, 0) == 1)
    assert(fibonomial(1, 1) == 1)
    assert(fibonomial(2, 0) == 1)
    assert(fibonomial(3, 2) == 2)
    assert(fibonomial(8, 3) == 1092)
    assert(fibonomial(11, 5) == 1514513)
    assert(fibonomial(22, 7) == 7158243695757340957617)
    assert(fibonomial(25, 3) == 49845401197200)
    assert(fibonomial(50, 2) == 97905340104793732225)
    assert(fibonomial(100, 1) == 354224848179261915075)

main()
