#!/usr/bin/env python3

"""

Write a program or function that outputs/returns the first 10000 prime-indexed prime numbers.

If we call the nth prime p(n), this list is

3, 5, 11, 17, 31, 41, 59 ... 1366661
because

p(p(1)) = p(2) = 3
p(p(2)) = p(3) = 5
p(p(3)) = p(5) = 11
p(p(4)) = p(7) = 17
...
p(p(10000)) = p(104729) = 1366661

Standard loopholes are forbidden, and standard output methods are allowed. You may answer with a full program, a named function, or an anonymous function.

"""

from sympy import prime

# https://oeis.org/A006450
def p(n):
    if n < 1:
        return 0
    if n == 1:
        return 3
    return prime(prime(n))

def main():
    tab = [
        3, 5, 11, 17, 31, 41, 59, 67, 83, 109, 127, 157, 179, 191, 211, 241,
        277, 283, 331, 353, 367, 401, 431, 461, 509, 547, 563, 587, 599, 617,
        709, 739, 773, 797, 859, 877, 919, 967, 991, 1031, 1063, 1087, 1153,
        1171, 1201, 1217, 1297, 1409, 1433, 1447, 1471
    ]

    for i in range(len(tab)):
        assert(p(i + 1) == tab[i])

main()
