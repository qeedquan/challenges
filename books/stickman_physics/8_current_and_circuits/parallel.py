#!/usr/bin/env python3

# 1. What is the resistance of a 5Ω and 10Ω resistor in parallel?
def p1():
    R1 = 5
    R2 = 10
    Rt = 1/(1/R1 + 1/R2)
    print("P1")
    print(Rt)
    print()

# 2. What is the resistance of a 5Ω, 10Ω, and 15Ω resistor in parallel?
def p2():
    R1 = 5
    R2 = 10
    R3 = 15
    Rt = 1/(1/R1 + 1/R2 + 1/R3)
    print("P2")
    print(Rt)
    print()

def p3():
    Vt = 12
    R1 = 4
    R2 = 3
    Rt = 1/(1/R1 + 1/R2)
    V1 = Vt
    V2 = Vt
    It = Vt / Rt
    I1 = V1 / R1
    I2 = V2 / R2
    print("P3")
    print(V1, V2, Vt)
    print(I1, I2, It)
    print(R1, R2, Rt)
    print()

def p4():
    It = 10
    R1 = 30
    R2 = 30
    R3 = 30
    Rt = R1 / 3
    Vt = It * Rt
    V1 = Vt
    V2 = Vt
    V3 = Vt
    I1 = V1 / R1
    I2 = V2 / R2
    I3 = V3 / R3
    print("P4")
    print(V1, V2, V3, Vt)
    print(I1, I2, I3, It)
    print(R1, R2, R3, Rt)
    print()

def p5():
    Rt = 40
    I1 = 1
    I2 = 2
    I3 = 1
    It = I1 + I2 + I3
    Vt = It * Rt
    V1 = Vt
    V2 = Vt
    V3 = Vt
    R1 = V1 / I1
    R2 = V2 / I2
    R3 = V3 / I3
    print("P5")
    print(V1, V2, V3, Vt)
    print(I1, I2, I3, It)
    print(R1, R2, R3, Rt)
    print()

def p6():
    Rt = 50
    R1 = 100
    I2 = 5
    R3 = 200
    R2 = 1/(1/Rt - 1/R1 - 1/R3)
    V2 = I2 * R2
    V1 = V2
    V3 = V2
    Vt = V2
    I1 = V1 / R1
    I3 = V3 / R3
    It = Vt / Rt
    print("P6")
    print(V1, V2, V3, Vt)
    print(I1, I2, I3, It)
    print(R1, R2, R3, Rt)
    print()

p1()
p2()
p3()
p4()
p5()
p6()
