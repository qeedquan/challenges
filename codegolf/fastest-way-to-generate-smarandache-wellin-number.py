#!/usr/bin/env python3

"""

Given a number n find the Smarandache–Wellin number for n. Ex:

for n=2 output=23

for n=5 output=235711

Answer it in ruby or python.

given constraints are n<=70000

"""

from sympy import *

# https://oeis.org/A019518
def sw(n):
    if n < 1:
        return 0

    s = ""
    for i in range(n):
        s += str(prime(i + 1))
    return int(s)

def main():
    tab = [2, 23, 235, 2357, 235711, 23571113, 2357111317, 235711131719, 23571113171923, 2357111317192329, 235711131719232931, 23571113171923293137, 2357111317192329313741, 235711131719232931374143, 23571113171923293137414347]

    for i in range(len(tab)):
        assert(sw(i + 1) == tab[i])

main()
