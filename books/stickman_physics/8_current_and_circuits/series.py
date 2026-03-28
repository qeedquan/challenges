#!/usr/bin/env python3

def p1():
    Vt = 80
    R1 = 15
    R2 = 20
    R3 = 5
    Rt = R1 + R2 + R3
    It = Vt / Rt
    I1 = It
    I2 = It
    I3 = It
    V1 = I1 * R1
    V2 = I2 * R2
    V3 = I3 * R3
    print("P1")
    print(V1, V2, V3, Vt)
    print(I1, I2, I3, It)
    print(R1, R2, R3, Rt)
    print()

def p2():
    V1 = 6
    Vt = 12
    R1 = 3
    R2 = 2
    I1 = V1 / R1
    I2 = I1
    I3 = I1
    It = I1
    V2 = I2 * R2
    V3 = Vt - V1 - V2
    R3 = V3 / I3
    Rt = R1 + R2 + R3
    print("P2")
    print(V1, V2, V3, Vt)
    print(I1, I2, I3, It)
    print(R1, R2, R3, Rt)
    print()

def p3():
    Rt = 20
    V1 = 12
    R2 = 10
    R3 = 4
    R1 = Rt - R2 - R3
    I1 = V1 / R1
    I2 = I1
    I3 = I1
    It = I1
    V2 = I2 * R2
    V3 = I3 * R3
    Vt = V1 + V2 + V3
    print("P3")
    print(V1, V2, V3, Vt)
    print(I1, I2, I3, It)
    print(R1, R2, R3, Rt)
    print()

p1()
p2()
p3()
