#!/usr/bin/env python3

from math import *

# https://math.stackexchange.com/questions/3821443/continuous-fibonacci-number-fn
def fib(n):
    phi = (1 + sqrt(5)) / 2
    r = (phi**n - cos(pi*n)*phi**(-n)) / sqrt(5)
    return int(r)

def main():
    assert(fib(2) == 1)
    assert(fib(3) == 2)
    assert(fib(4) == 3)

main()

