"""

Recall Ohm's law for pure resistances:

V = IR

In the case of AC circuits, we represent the impedance (effective resistance) as a complex number, Z.
The units are ohms (Ω).

In this case, Ohm's Law becomes:
V = IZ

Recall also, if we have several resistors (R1, R2, R3, R4, …) connected in parallel, then the total resistance RT, is given by:
1/Rt = 1/R1 + 1/R2 + 1/R3 + ...

In the case of AC circuits, this becomes:
1/Zt = 1/Z1 + 1/Z2 + 1/Z3 + ...

In case of 2 impedances:
1/Zt = Z1*Z2 / (Z1+Z2)

"""

import cmath
import math

def p1():
    # This assumes that the inductor and capacitor are given in Ohms already
    # If they are given in Henries or Farads, need to convert them to Ohms using formula described in problem 3
    # The resistor and inductor becomes a imaginary number of the form Resistor + i*Inductor
    Z1 = 70 + 60j
    # The capacitor and inductor becomes a imaginary number of the form Resistor - i*Capacitor
    Z2 = 40 - 25j
    Zt = 1/(1/Z1 + 1/Z2)
    print(Zt)
    print()

def p2():
    # Resistance is complex, voltage is an AC source
    Z1 = 200 - 40j
    Z2 = 60 + 130j
    Zt = 1/(1/Z1 + 1/Z2)
    Vt = 12
    It = Vt / Zt
    # Total Impedance
    print(Zt)
    # The phase angle
    print(math.degrees(cmath.phase(Zt)))
    # Total line current (in polar form)
    print(cmath.polar(It))
    print()

def p3():
    f = 60
    L = 0.02
    C1 = 1.2e-6
    R1 = 100
    R2 = 110
    C2 = 2.4e-6
    Vt = 150

    # Note that inductors and capacitors are frequency dependent when converting them to Ohms from Henries/Farads
    Xl = 2*math.pi*f*L
    Xc = 1/(2*math.pi*f*C1)
    Z1 = R1 + (Xl - Xc)*1j
    
    Xc = 1/(2*math.pi*f*C2)
    Z2 = R2 + (-Xc)*1j

    Zt = 1/(1/Z1 + 1/Z2)
    It = Vt / Zt
    print(cmath.polar(Zt))
    print(cmath.polar(It))

p1()
p2()
p3()
