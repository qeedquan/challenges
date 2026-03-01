"""

Given that the current in a given circuit is 3.90 - 6.04j mA and the impedance is 5.16 + 1.14j kΩ, find the magnitude of the voltage.

"""
def p1():
    I = (3.9 - 6.04j) * 1e-3
    Z = (5.16 + 1.14j) * 1e3
    V = abs(I) * abs(Z)
    print(V)

"""

A resistor, an inductor and a capacitor are connected in series across an ac voltage source. A voltmeter measures 12, 15.5, and 10.5 when placed across each element separately. What is the magnitude of the voltage of the source?


"""
def p2():
    # total reactance V_rlc = Vr + j*(Vl - Vc)
    Vr = 12
    Vl = 15.5
    Vc = 10.5
    Vrlc = Vr + (Vl - Vc)*1j
    print(abs(Vrlc))

p1()
p2()
