#!/usr/bin/env python3

"""

Challenge
For a given positive integers range, find the first and last prime number entirely composed of prime number digits, exceptionally including 0 (for the digits, a range of 0-2 should output 2-2). The range is inclusive. If no number is found, the expected output is 0. If there is only one such number, the expected output is that number twice.

Examples
For the range 1–100, the first prime number is 2 and the last is 73 (7 and 3 are prime numbers).
For the range 70–80, the first prime number is 73 and the last is also 73 (Since there is only one correct number in the given range, we return it twice).
For the range 190–200, there is no correct answer, so you return 0.
For the range 2000-2100, the first prime number is 2003 and the last is 2053 (we omit the digit 0, but all the other digits are prime)
This is code-golf, so the shortest code in bytes win!

All standard loopholes apply.

Input
You are free to accept two integers as input however you may see fit, stack, function argument(s), CLI argument, stdin.
You must only receive two integers.
Output
You must either return the result (a tuple, an array, multi-return if your language supports it), leave it on the stack, or print it (in this case, they must be separated somehow).
The order of the outputs is irrelevant.
You are allowed leading/trailing brackets and newlines.
You must return two numbers, if there is an answer, even if they are the same.
You must return 0 if there is no answer.

"""

from sympy import isprime

def pnr(a, b):
    r = []
    for i in range(a, b + 1):
        if set(str(i)) <= set('02357') and isprime(i):
            r.append(i)
    if len(r) == 0:
        return (0, 0)
    return (r[0], r[-1])

def main():
    assert(pnr(1, 100) == (2, 73))
    assert(pnr(70, 80) == (73, 73))
    assert(pnr(190, 200) == (0, 0))
    assert(pnr(2000, 2100) == (2003, 2053))

main()

