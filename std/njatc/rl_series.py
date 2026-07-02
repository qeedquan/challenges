#!/usr/bin/env python3

from math import *

def p1():
    R = 750
    Et = 120
    F = 50
    L = 5
    Xl = 2*pi*F*L
    Z = sqrt(R*R + Xl*Xl)
    It = Et / Z
    Il = It
    Ir = It
    Er = Ir * R
    El = Il * Xl
    print("P1")
    print("It", It)
    print("Er", Er)
    print("Xl", Xl)
    print("El", El)
    print("Z", Z)
    print()

def p2():
    R = 900
    Xl = 500
    Et = 120
    F = 65
    Z = sqrt(R*R + Xl*Xl)
    It = Et / Z
    Il = It
    Ir = It
    Er = Ir * R
    El = Il * Xl
    L = Xl / (2*pi*F)
    W = Et * It
    VAR = El * Il
    VA = sqrt(W*W + VAR*VAR)
    PF = W / VA
    print("P2")
    print("It", It)
    print("Er", Er)
    print("Z", Z)
    print("L", L)
    print("El", El)
    print("%PF", PF*100)
    print()

# values given are inconsistent (maybe due to rounding; since the values are close enough)
def p3():
    R = 2500
    El = 118
    Et = 240
    F = 100
    It = 0.0835
    Ir = It
    Il = It
    Er = Ir * R
    Xl = El / Il
    L = Xl / (2*pi*F)
    W = Er * Ir
    VA = Et * It
    PF = W / VA
    Z = sqrt(R*R + Xl*Xl)
    # this should be equal to El*Il but it is not (it is close to it)
    VAR = sqrt(VA*VA - W*W)
    ANGLE = degrees(acos(PF))
    print("P3")
    print("Z", Z)
    print("Xl", Xl)
    print("L", L)
    print("PF", PF)
    print("%PF", PF*100)
    print("Angle", ANGLE)
    print()

def p9():
    print("P9")
    # Xl = 2*pi*F*L
    print("a. Xl increases as F increases")
    # It = Et / Z
    # Z = sqrt(R*R + Xl*Xl)
    print("b. It decreases as F increases since Xl increases")
    print("c. Z increases as F increases")
    # PF = W / VA
    # VAR = sqrt(VA*VA - W*W)
    # VA = El * Il
    # Il = It
    print("d. PF decreases s F increases since Il gets smaller")
    # angle = acos(PF)
    print("e. Angle increases since PF decreases")
    print()

p1()
p2()
p3()
p9()
