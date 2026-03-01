#!/usr/bin/env python3

# Solve for the total resistance of the complex circuit below.
def p1():
    R1 = 5
    R2 = 10
    R3 = 10
    R4 = 5
    R5 = 20
    R34 = R3 + R4
    R2345 = 1/(1/R2 + 1/R34 + 1/R5)
    Rt = R1 + R2345

    print("P1")
    print(Rt)
    print()

def p2():
    R1 = 5
    R2 = 30
    R3 = 30
    Vt = 40
    R23 = 1/(1/R2 + 1/R3)
    Rt = R1 + R23
    It = Vt / Rt
    I1 = It
    V1 = I1 * R1
    V2 = Vt - V1
    V3 = V2
    I2 = V2 / R2
    I3 = V3 / R3

    print("P2")
    print(V1, V2, V3, Vt)
    print(I1, I2, I3, It)
    print(R1, R2, R3, Rt)
    print()

def p3():
    V4 = 16
    Vt = 76
    I2 = 4
    R1 = 8
    R3 = 1
    R4 = 16
    R5 = 4
    I4 = V4 / R4
    I3 = I2
    V3 = I3 * R3
    V2 = V4 - V3
    R2 = V2 / I2
    R23 = R2 + R3
    R234 = 1/(1/R23 + 1/R4)
    Rt = R1 + R234 + R5
    It = Vt / Rt
    I1 = It
    I5 = It
    V1 = I1 * R1
    V5 = I5 * R5

    print("P3")
    print(V1, V2, V3, V4, V5, Vt)
    print(I1, I2, I3, I4, I5, It)
    print(R1, R2, R3, R4, R5, Rt)
    print()

p1()
p2()
p3()
