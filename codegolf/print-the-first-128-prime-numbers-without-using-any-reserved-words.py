#!/usr/bin/env python3

"""

The obvious solution would be to just print them as a string, but is it possible to write a shorter code?

Requirements:

No input should be processed, and the output should be in the form of 2 3 5 7 11 13 ... etc.
No reserved words in the language are used at all
The language should at least allow structured programming, and have reserved words (otherwise point 2 would be moot).
first I had exclusively C/C++ in mind, but extended the question while still trying to prevent cheating

"""

from math import factorial

# https://en.wikipedia.org/wiki/Formula_for_primes
def f(n):
    if n < 1:
        return 0
    p = factorial(n) % (n + 1)
    return (p//n * (n - 1)) + 2

def gen(n):
    if n < 1:
        return 0

    r = [2]
    i = 2
    while len(r) < n:
        x = f(i)
        if x != 2:
            r.append(x)
        i += 1
    return r

def main():
    print(gen(128))

main()
