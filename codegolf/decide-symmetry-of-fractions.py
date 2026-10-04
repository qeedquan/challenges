#!/usr/bin/env python3

"""

Objective
Given a nonnegative fraction whose denominator is a power of 2, decide whether its (finite-length) binary expansion is symmetric by the radix point.

I/O format
It is assumed that the input is a reduced fraction. Inputs that don't fit into this format fall in don't care situation. Otherwise flexible.

Examples
Truthy
Input = Binary expansion
0/1 = 0.0
3/2 = 1.1
9/4 = 10.01
15/4 = 11.11

Falsy
1/1 = 1.0
2/1 = 10.0
1/2 = 0.1
5/2 = 10.1
1/4 = 0.01

Don't care (Invalid inputs)
1/3
2/3
1/5
1/6
-1

"""

# ported from @tsh solution
def symmetric(a, b):
    return (int(bin(a//b*2 + 1)[:1:-1], 2) ^ (a%b) ^ b) == 0

def main():
    assert(symmetric(0, 1) == True)
    assert(symmetric(3, 2) == True)
    assert(symmetric(9, 4) == True)
    assert(symmetric(15, 4) == True)

    assert(symmetric(1, 1) == False)
    assert(symmetric(2, 1) == False)
    assert(symmetric(1, 2) == False)
    assert(symmetric(5, 2) == False)
    assert(symmetric(1, 4) == False)

main()
