#!/usr/bin/env python3

"""

Random number generator

There is an ideal random number generator, which given a positive integer M can generate any real number between 0 to M, and probability density function is uniform in [0, M].

Given two numbers A and B and we generate x and y using the random number generator with uniform probability density function [0, A] and [0, B] respectively, what's the probability that x + y is less than C? where C is a positive integer.

Input Format

The first line of the input is an integer N, the number of test cases.

N lines follow. Each line contains 3 positive integers A, B and C.

Constraints

All the integers are no larger than 10000.

Output Format

For each output, output a fraction that indicates the probability. The greatest common divisor of each pair of numerator and denominator should be 1.

Sample Input

3
1 1 1
1 1 2
1 1 3

Sample Output

1/2
1/1
1/1

"""

from fractions import Fraction

"""

@tmatsuzawa

1. Think of a coordinate system (x, y). Draw a rectangle of width a and height b. Set the bottom left of the rectangle as the origin.

2. Any combination of a and b that sum up to c can be expressed by a line: y = -x + c.
   The question becomes how to find the area under this curve that overlaps with the area of the rectangle. 

3. Find the area, divide it by the area of the rectangle. That is the probability we want.

"""

def solve(a, b, c):
    if c >= a+b:
        return Fraction(1, 1)
    
    t = c**2
    if c > a:
        t -= (c-a)**2
    if c > b:
        t -= (c-b)**2
    return Fraction(t, 2*a*b)

def main():
    assert(solve(1, 1, 1) == Fraction(1, 2))
    assert(solve(1, 1, 2) == Fraction(1, 1))
    assert(solve(1, 1, 3) == Fraction(1, 1))

main()
