#!/usr/bin/env python3

def p1a():
    Vt = 10
    Ra = 15
    Rb = 25
    Rc = 17
    Rd = 5
    Rt = 1/(1/Ra + 1/Rb + 1/Rc) + Rd
    It = Vt / Rt
    Id = It
    Vd = Id * Rd
    Vabc = Vt - Vd
    Va = Vabc
    Vb = Vabc
    Vc = Vabc
    Ia = Va / Ra
    Ib = Vb / Rb
    Ic = Vc / Rc

    print("1a")
    print(Ra, Ia, Va)
    print(Rb, Ib, Vb)
    print(Rc, Ic, Vc)
    print(Rd, Id, Vd)
    print()

def p1b():
    Vt = 10
    R1 = 17
    R2 = 25
    R3 = 15
    R4 = 12
    R5 = 5
    R6 = 8
    R34 = R3 + R4
    R1234 = 1/(1/R1 + 1/R34 + 1/R2)
    Rt = R1234 + R5 + R6
    It = Vt / Rt
    I5 = It
    I6 = It
    V5 = I5 * R5
    V6 = I6 * R6
    V1234 = Vt - V5 - V6
    V1 = V1234
    V2 = V1234
    I1 = V1 / R1
    I2 = V2 / R2
    I3 = It - I1 - I2
    I4 = I3
    V3 = I3 * R3
    V4 = I4 * R4
    
    print("1b")
    print(R1, V1, I1)
    print(R2, V2, I2)
    print(R3, V3, I3)
    print(R4, V4, I4)
    print(R5, V5, I5)
    print(R6, V6, I6)
    print()

def p2():
    Vt = 10
    R1 = 15
    R2 = 12
    R3 = 25
    R4 = 17
    R5 = 10
    R6 = 8
    R7 = 5
    R8 = 5
    R9 = 8
    
    R12 = R1 + R2
    R56 = 1/(1/R5 + 1/R6)
    R456 = R4 + R56
    R78 = 1/(1/R7 + 1/R8)
    R123456 = 1/(1/R12 + 1/R3 + 1/R456)
    
    Rt = R123456 + R78 + R9
    It = Vt / Rt
    
    I9 = It
    V9 = I9 * R9

    I7 = It / 2
    I8 = It / 2
    V7 = I7 * R7
    V8 = I8 * R8

    V78 = V7
    V123456 = Vt - V78 - V9
    V3 = V123456
    I3 = V3 / R3

    V12 = V123456
    I12 = V12 / R12
    I1 = I12
    I2 = I12
    V1 = I1 * R1
    V2 = I2 * R2

    V456 = V123456
    I456 = V456 / R456
    I4 = I456
    V4 = I4 * R4
    V5 = V456 - V4
    V6 = V5
    I5 = V5 / R5
    I6 = V6 / R6
    
    P1 = V1 * I1
    P2 = V2 * I2
    P3 = V3 * I3
    P4 = V4 * I4
    P5 = V5 * I5
    P6 = V6 * I6
    P7 = V7 * I7
    P8 = V8 * I8
    P9 = V9 * I9
    Pt = Vt * It

    print("2")
    print("I1", I1)
    print("I2", I2)
    print("I3", I3)
    print("I4", I4)
    print("I5", I5)
    print("I6", I6)
    print("I7", I7)
    print("I8", I8)
    print("I9", I9)
    print("V1", V1)
    print("V2", V2)
    print("V3", V3)
    print("V4", V4)
    print("V5", V5)
    print("V6", V6)
    print("V7", V7)
    print("V8", V8)
    print("V9", V9)
    print("Pt", Pt, P1 + P2 + P3 + P4 + P5 + P6 + P7 + P8 + P9)
    print("P6", P6)
    print()

def p3():
    R1 = 4
    R2 = 8
    R3 = 16
    R4 = 10
    I4 = 0.5
    V4 = I4 * R4
    I3 = I4
    V3 = I3 * R3
    V2 = V3 + V4
    I2 = V2 / R2
    I34 = I3
    I1 = I2 + I34
    V1 = I1 * R1

    print("3")
    print(R2, V2, I2)
    print(R1, V1, I1)

p1a()
p1b()
p2()
p3()
