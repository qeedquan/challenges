#!/usr/bin/env python3

"""

Task
Let's define a parameter of number n as the least common multiple (LCM) of the sum of its digits and their product.

Calculate the parameter of the given number n.

Input/Output
[input] integer n

A positive integer. It is guaranteed that no zero appears in n.

[output] an integer

The parameter of the given number.

Example
For n = 22, the output should be 4.

Both the sum and the product of digits equal 4, and LCM(4, 4) = 4.

For n = 1234, the output should be 120.

1+2+3+4=10 and 1*2*3*4=24, LCM(10,24)=120

"""

from math import lcm

def digop(n, r0, op):
    r = r0
    while n > 0:
        r = op(r, n % 10)
        n //= 10
    return r

def digsum(n):
    return digop(n, 0, lambda x, y: x + y)

def digprod(n):
    return digop(n, 1, lambda x, y: x * y)

def parameter(n):
    return lcm(digsum(n), digprod(n))

def main():
    assert(parameter(22) == 4)
    assert(parameter(1234) == 120)
    assert(parameter(123) == 6)
    assert(parameter(11) == 2)
    assert(parameter(239) == 378)
    assert(parameter(999999999) == 387420489)
    assert(parameter(91) == 90)
    assert(parameter(344) == 528)
    assert(parameter(123456789) == 362880)

main()
