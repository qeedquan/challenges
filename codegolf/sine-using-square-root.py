#!/usr/bin/env python3

"""

Given input x∈{0,3,6,...,90}, output sin(x°) using integer and +−×÷()⋅√(square root), e.g. sin(45) = sqrt(1/2).

Flexible output format. You needn't do any simplification to output, aka. it's fine to output sin(0°)=sqrt(42)-sqrt(6*sqrt(-9+58)).

Complex intermediate value is fine but please mention.

Shortest code wins.

"""

from sympy import *

def main():
    for i in range(0, 93, 3):
        print(i, sin(rad(i)))

main()
