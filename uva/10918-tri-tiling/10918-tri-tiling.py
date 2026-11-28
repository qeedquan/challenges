#!/usr/bin/env python3

from math import sqrt

# https://oeis.org/A001835
def seq(n):
    return int(round(((3 + sqrt(3))**(2*n - 1) + (3 - sqrt(3))**(2*n - 1))/6**n))

def solve(n):
    if n < 0 or n%2 != 0:
        return 0
    return seq(n//2 + 1)

def main():
    tab = [
        1, 1, 3, 11, 41, 153, 571, 2131, 7953, 29681, 110771, 413403, 1542841,
        5757961, 21489003, 80198051, 299303201, 1117014753, 4168755811, 15558008491,
        58063278153, 216695104121, 808717138331, 3018173449203, 11263976658481,
        42037733184721
    ]

    assert(solve(2) == 3)
    assert(solve(8) == 153)
    assert(solve(12) == 2131)

    for i in range(len(tab)):
        assert(seq(i) == tab[i])

main()

