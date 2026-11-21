#!/usr/bin/env python3

"""

When I was a kid, there was a time when I thought that raising a to the bth power worked differently. For example, to calculate 2^3, I'd think "Okay, 2^2=2*2=4, so 2^3=4*4=16" If I was doing 3^4, I'd do: 3*3=9 9*9=81 81*81=6561

So, given two BigIntegers, raise a to the bth power the same way I used to. If the power is less than 1, return -1 as a BigInteger.

"""

def kidpow(base, exponent):
    if exponent < 1:
        return -1
    return base**(2**(exponent - 1))

def main():
    assert(kidpow(-1, -1) == -1)
    assert(kidpow(2, -1) == -1)
    assert(kidpow(2, 2) == 4)
    assert(kidpow(2, 3) == 16)
    assert(kidpow(3, 3) == 81)
    assert(kidpow(3, 4) == 6561)

main()
