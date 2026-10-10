#!/usr/bin/env python3

"""

This is a math problem which takes quite many things into question, making it rather challenging,
and as you might have guessed, it's a code golf, so it should be as short as possible as well.

The input, n, is any integer number (should at least support integers, but needn't be limited to). The output is the average of:

n

The square of n, n^2

The closest prime number to n, p

The closest number to n in the Fibonacci sequence, f

Shortly, the program should print to the standard output channel the result of

(n + n^2 + p + f) / 4

You don't have to care about possible overflows etc. Normal floating point precision is also ok.

The way the input is given is completely up to you. Shortest program (in characters) wins, as always with code golfs.

In the case a tie occurs when you are looking for the closest, choose one of the following:

Go up
Go down
Choose one randomly

"""

from sympy import prevprime, nextprime

def nearest_prime(n):
    if n <= 2:
        return 2
    p1 = prevprime(n)
    p2 = nextprime(n)
    d1 = abs(p1 - n)
    d2 = abs(p2 - n)
    if d1 <= d2:
        return p1
    return p2

def nearest_fib(n):
    f1 = 0
    f2 = 1
    while f2 < n:
        f3 = f1 + f2
        f1 = f2
        f2 = f3
    d1 = abs(f1 - n)
    d2 = abs(f2 - n)
    if d1 <= d2:
        return f1
    return f2

def solve(n):
    p = nearest_prime(n)
    f = nearest_fib(n)
    return (n + n*n + p + f) / 4

def main():
    for i in range(101):
        print(i, solve(i))

main()
