#!/usr/bin/env python3

"""

Create a function which checks a number for three different properties.

is the number prime?
is the number even?
is the number a multiple of 10?
Each should return either true or false, which should be given as an array. Remark: The Haskell variant uses data Property.

Examples
numberProperty(7)  // ==> [true,  false, false]
numberProperty(10) // ==> [false, true,  true]
The number will always be an integer, either positive or negative. Note that negative numbers cannot be primes, but they can be multiples of 10:

numberProperty(-7)  // ==> [false, false, false]
numberProperty(-10) // ==> [false, true,  true]

"""

from sympy import isprime

def number_property(n):
    return [isprime(n), n%2 == 0, n%10 == 0]

def main():
    assert(number_property(7) == [True, False, False])
    assert(number_property(10) == [False, True, True])
    assert(number_property(-7) == [False, False, False])
    assert(number_property(-10) == [False, True, True])

main()
