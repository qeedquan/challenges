#!/usr/bin/env python3

"""

Battery Orientation In Series
Battery voltage causes current to flow from the positive to negative terminal.  When placed in the same direction in series, current adds up.
If a battery were placed backwards the flow would be in an opposite direction and subtract. 
Observe the overall charge when placing batteries in series in different orientations.

-1.5v+       = 1.5v
-1.5v+-1.5v+ = 3.0v (1.5 + 1.5)
-1.5v++1.5v- = 0.0v (1.5 - 1.5)
-1.5v+-1.5v++1.5v- = 1.5v (1.5 + 1.5 - 1.5)

Batteries follows series/parallel rules and ohms laws for circuits

"""

# What is the resistance of a light bulb that has 0.3 amps of current flow when 1.5 volts drop across it?
def p1():
    I = 0.3
    V = 1.5
    R = V / I
    print("P1")
    print(R)
    print()

# What is the power of a light bulb that has 0.3 amps of current flow when 1.5 volts drop across it?
def p2():
    I = 0.3
    V = 1.5
    P = V * I
    print("P2")
    print(P)
    print()

# You want to place a strand of 500 of these lights that will have 0.3 amps of current flow when in the presence of a 1.5 voltage drop.
# The cost per kilowatt hour is 12 cents per kilowatt hour according to you power bill.
# How much will it cost to run these lights for 5 hours each night?
def p3():
    I = 0.3
    V = 1.5
    N = 500
    KWH = 0.12
    T = 5
    P = (I * V * N) / 1e3
    C = P * KWH * T
    print("P3")
    print(C)
    print()

# What is the voltage of 5 batteries placed in series with a correct orientation as seen below, and would current flow right or left?
# Battery Voltage = 1.5V each
# -+|-+|-+|-+|-+
def p4():
    V = 1.5
    N = 5
    print("P4")
    print(V * N)
    print()

# What is the voltage of 5 batteries placed in series with two having an incorrect orientation as seen below and which way would current flow?
# -+|-+|-+|+-|+-
def p5():
    V = 1.5
    print("P5")
    print(3*V - 2*V)
    print()

# Would two AA and one C battery create a current if placed in series in a closed circuit and if so what would the voltage be?
# Yes, they would create a current.
# The difference is size and length of time they would provide current because of the charge.
# The total voltage would be 4.5V and current would run to the right because of the orientation of the positive terminals.
# 1.5V + 1.5V + 1.5V = 4.5V
def p6():
    AA = 1.5
    C = 1.5
    print("P6")
    print(AA + AA + C)
    print()

p1()
p2()
p3()
p4()
p5()
p6()
