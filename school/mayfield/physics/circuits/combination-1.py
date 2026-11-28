#!/usr/bin/env python3

def p1():
    Vt = 100
    R1 = 100
    R2 = 1500
    R4 = 150
    R3 = 1500
    R23 = 1/(1/R2 + 1/R3)
    Rt = R1 + R23 + R4
    It = Vt / Rt
    I1 = It
    I4 = It
    V23 = R23*It
    V2 = V23
    V3 = V23
    I2 = V2 / R2
    I3 = V3 / R3
    V1 = I1 * R1
    V4 = I4 * R4
    Pt = Vt * It
    P1 = V1 * I1
    P2 = V2 * I2
    P3 = V3 * I3
    P4 = V4 * I4

    print("P1")
    print("Vt", Vt)
    print("V1", V1)
    print("V2", V2)
    print("V3", V3)
    print("V4", V4)
    print("It", It)
    print("I1", I1)
    print("I2", I2)
    print("I3", I3)
    print("I4", I4)
    print("Rt", Rt)
    print("R1", R1)
    print("R2", R2)
    print("R3", R3)
    print("R4", R4)
    print("Pt", Pt, P1 + P2 + P3 + P4)
    print()

def p2():
    Vt = 100
    R1 = 250
    R2 = 1500
    R3 = 500
    R4 = 1000
    R34 = R3 + R4
    R234 = 1/(1/R2 + 1/R34)
    Rt = R1 + R234
    It = Vt / Rt
    I1 = It
    V1 = I1 * R1
    V2 = Vt - V1
    I2 = V2 / R2
    I3 = It - I2
    I4 = I3
    V3 = I3 * R3
    V4 = I4 * R4
    Pt = Vt * It
    P1 = V1 * I1
    P2 = V2 * I2
    P3 = V3 * I3
    P4 = V4 * I4

    print("P2")
    print("Vt", Vt)
    print("V1", V1)
    print("V2", V2)
    print("V3", V3)
    print("V4", V4)
    print("It", It)
    print("I1", I1)
    print("I2", I2)
    print("I3", I3)
    print("I4", I4)
    print("Rt", Rt)
    print("R1", R1)
    print("R2", R2)
    print("R3", R3)
    print("R4", R4)
    print("Pt", Pt, P1 + P2 + P3 + P4)
    print()

def p3():
    Vt = 50
    R1 = 500
    R2 = 200
    R3 = 200
    R4 = 400
    R23 = 1/(1/R2 + 1/R3)
    Rt = R1 + R23 + R4
    It = Vt / Rt
    I1 = It
    I4 = It
    V1 = I1 * R1
    V4 = I4 * R4
    V23 = Vt - V1 - V4
    V2 = V23
    V3 = V23
    I2 = V2 / R2
    I3 = V3 / R3
    Pt = Vt * It
    P1 = V1 * I1
    P2 = V2 * I2
    P3 = V3 * I3
    P4 = V4 * I4

    print("P3")
    print("Vt", Vt)
    print("V1", V1)
    print("V2", V2)
    print("V3", V3)
    print("V4", V4)
    print("It", It)
    print("I1", I1)
    print("I2", I2)
    print("I3", I3)
    print("I4", I4)
    print("Rt", Rt)
    print("R1", R1)
    print("R2", R2)
    print("R3", R3)
    print("R4", R4)
    print("Pt", Pt, P1 + P2 + P3 + P4)
    print()

def p4():
    Vt = 400
    R1 = 500
    R2 = 6000
    R3 = 500
    R4 = 1000
    R5 = 1500
    R6 = 1500
    R345 = R3 + R4 + R5
    R2345 = 1/(1/R2 + 1/R345)
    Rt = R1 + R2345 + R6
    It = Vt / Rt
    I1 = It
    I6 = It
    V1 = I1 * R1
    V6 = I6 * R6
    V2345 = Vt - V1 - V6
    V2 = V2345
    I345 = V2345 / R345
    I3 = I345
    I4 = I345
    I5 = I345
    I2 = V2 / R2
    V3 = I3 * R3
    V4 = I4 * R4
    V5 = I5 * R5
    Pt = Vt * It
    P1 = V1 * I1
    P2 = V2 * I2
    P3 = V3 * I3
    P4 = V4 * I4
    P5 = V5 * I5
    P6 = V6 * I6

    print("P4")
    print("Vt", Vt)
    print("V1", V1)
    print("V2", V2)
    print("V3", V3)
    print("V4", V4)
    print("V5", V5)
    print("V6", V6)
    print("It", It)
    print("I1", I1)
    print("I2", I2)
    print("I3", I3)
    print("I4", I4)
    print("I5", I5)
    print("I6", I6)
    print("Rt", Rt)
    print("R1", R1)
    print("R2", R2)
    print("R3", R3)
    print("R4", R4)
    print("R5", R5)
    print("R6", R6)
    print("Pt", Pt, P1 + P2 + P3 + P4 + P5 + P6)
    print()

def p5():
    Vt = 100
    R1 = 2500
    R2 = 10000
    R3 = 1000
    R4 = 1500
    R5 = 500
    R34 = R3 + R4
    R234 = 1/(1/R2 + 1/R34)
    Rt = R1 + R234 + R5
    It = Vt / Rt
    I1 = It
    I5 = It
    V1 = I1 * R1
    V5 = I5 * R5
    V234 = Vt - V1 - V5
    V2 = V234
    I2 = V2 / R2
    I34 = It - I2
    I3 = I34
    I4 = I34
    V3 = I3 * R3
    V4 = I4 * R4
    Pt = Vt * It
    P1 = V1 * I1
    P2 = V2 * I2
    P3 = V3 * I3
    P4 = V4 * I4
    P5 = V5 * I5

    print("P5")
    print("Vt", Vt)
    print("V1", V1)
    print("V2", V2)
    print("V3", V3)
    print("V4", V4)
    print("V5", V5)
    print("It", It)
    print("I1", I1)
    print("I2", I2)
    print("I3", I3)
    print("I4", I4)
    print("I5", I5)
    print("Rt", Rt)
    print("R1", R1)
    print("R2", R2)
    print("R3", R3)
    print("R4", R4)
    print("R5", R5)
    print("Pt", Pt, P1 + P2 + P3 + P4 + P5)
    print()

p1()
p2()
p3()
p4()
p5()
