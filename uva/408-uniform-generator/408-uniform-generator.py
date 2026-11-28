#!/usr/bin/env python3

import math

def choice(s, m):
    d = "Bad Choice"
    if math.gcd(s, m) == 1:
        d = "Good Choice"
    return "{:10} {:10} {:>14}".format(s, m, d)

def main():
    print(choice(3, 5))
    print(choice(15, 20))
    print(choice(63923, 99999))

main()
