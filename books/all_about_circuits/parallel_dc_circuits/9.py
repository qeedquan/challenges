#!/usr/bin/env python3

"""

According to Ohm’s Law, how much current goes through each of the two resistors in this circuit?

"""

Vt = 24
R1 = 2.2e3
R2 = 4.7e3
Rt = 1/(1/R1 + 1/R2)
I1 = Vt / R1
I2 = Vt / R2
It = Vt / Rt
print(I1)
print(I2)
print(It, I1+I2)
