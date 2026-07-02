#!/usr/bin/env python3

"""

In this circuit, three resistors receive the same amount of voltage (24 volts) from a single source.
Calculate the amount of current "drawn" by each resistor, as well as the amount of power dissipated by each resistor:

"""

Vt = 24
R1 = 1
R2 = 2
R3 = 3

Rt = 1/(1/R1 + 1/R2 + 1/R3)
It = Vt/Rt

# In a parallel circuit, all voltages between loads are the same
V1 = Vt
V2 = Vt
V3 = Vt

I1 = V1 / R1
I2 = V2 / R2
I3 = V3 / R3

P1 = V1 * I1
P2 = V2 * I2
P3 = V3 * I3

print("I1", I1)
print("I2", I2)
print("I3", I3)
print("P1", P1)
print("P2", P2)
print("P3", P3)

# The current splits into different values in a parallel circuit,
# but they all should add up to the total current
print("It", It, I1+I2+I3)
