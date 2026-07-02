#!/usr/bin/env python3

from sympy import catalan

# https://oeis.org/A000108 
def main():
    assert(catalan(2) == 2)
    assert(catalan(3) == 5)

main()
