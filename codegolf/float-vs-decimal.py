#!/usr/bin/env python3

"""

You will be given a decimal number n in the form of a string. You must determine if that number, when stored in standard number type T in your language, is greater than, equal to, or less than the decimal representation. T can be anything appropriate for your language, such as a float, a double, or a generic "number" type etc, as long as it can represent the numbers to a reasonable accuracy and is not a decimal type.

For example, in python:

0.1
Is represented internally exactly by the value

0.1000000000000000055511151231257827021181583404541015625
The value 2 is represented internally by exactly the value 2.

You must determine, for a given decimal number, is the internal representation of that number greater than, equal to, or less than the decimal representation?

Input
A string containing the decimal representation of the number
Output
An indication of if the internal representation of that number is greater than, equal to, or less than to the input.
Rules
Code golf scoring
While T must not be a decimal type, you can use decimal types in your code to facilitate your comparison.

"""

from decimal import *

def compare(n):
    x = Decimal(n)
    y = Decimal(float(n))
    return x.compare(y)

def main():
    print(compare("0.1"))
    print(compare("2"))
    print(compare("3"))

main()
