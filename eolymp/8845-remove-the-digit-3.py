#!/usr/bin/env python3

"""

The program takes a natural number n (n>99) as input. The task is to remove the third digit from the right (the hundreds place) of the number n.

Input
A natural number n (n>99).

Output
The result after removing the specified digit.

Examples

Input #1
4625

Answer #1
425

"""

def solve(n):
    r = 0
    i = 1
    p = 1
    while n > 0:
        if i != 3:
            r += ((n % 10) * p)
            p *= 10
        n //= 10
        i += 1
    return r

def main():
    assert(solve(4625) == 425)
    assert(solve(9899) == 999)

main()
