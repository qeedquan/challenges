#!/usr/bin/env python3

"""

For this challenge, you are given two complex numbers, and you have to print the result of their addition, subtraction, multiplication, division and modulus operations.

The real and imaginary precision part should be correct up to two decimal places.

Input Format

One line of input: The real and imaginary part of a number separated by a space.

Output Format

For two complex numbers C and D, the output should be in the following sequence on separate lines:

C + D
C - D
C * D
C / D
mod(C)
mod(D)

For complex numbers with non-zero real A and complex part B, the output should be in the following format:
A + Bi

Replace the plus symbol (+) with a minus symbol (-) when B < 0.
For complex numbers where the real part is zero and the complex part (B) is non-zero, the output should be:
0.00 + Bi

Sample Input
2 1
5 6

Sample Output
7.00+7.00i
-3.00-5.00i
4.00+17.00i
0.26-0.11i
2.24+0.00i
7.81+0.00i

Concept

Python is a fully object-oriented language like C++, Java, etc. For reading about classes, refer here.

Methods with a double underscore before and after their name are considered as built-in methods. They are used by interpreters and are generally used in the implementation of overloaded operators or other built-in functionality.

__add__-> Can be overloaded for + operation

__sub__ -> Can be overloaded for - operation

__mul__ -> Can be overloaded for * operation

"""

import math

class Complex(object):
    def __init__(self, r, i):
        self.r = r
        self.i = i

    def __add__(self, other):
        return Complex(self.r + other.r, self.i + other.i)

    def __sub__(self, other):
        return Complex(self.r - other.r, self.i - other.i)

    def __mul__(self, other):
        return Complex(self.r*other.r - self.i*other.i, self.r*other.i + self.i*other.r)

    def __truediv__(self, other):
        a, b = self.r, self.i
        c, d = other.r, other.i
        s = c*c + d*d
        return Complex((a*c + b*d) / s, (b*c - a*d) / s)

    def mod(self):
        return Complex(math.hypot(self.r, self.i), 0)

    def __str__(self):
        if self.i == 0:
            s = "%.2f+0.00i" % (self.r)
        elif self.r == 0:
            if self.i >= 0:
                s = "0.00+%.2fi" % (self.i)
            else:
                s = "0.00-%.2fi" % (abs(self.i))
        elif self.i > 0:
            s = "%.2f+%.2fi" % (self.r, self.i)
        else:
            s = "%.2f-%.2fi" % (self.r, abs(self.i))
        return s

def main():
    a = Complex(2, 1)
    b = Complex(5, 6)
    print(a + b)
    print(a - b)
    print(a * b)
    print(a / b)
    print(a.mod())
    print(b.mod())

main()
