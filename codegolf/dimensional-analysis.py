#!/usr/bin/env python3

"""

Calculate a product or ratio of SI units.

For example, kg m / s s (kilogram-meter per second squared) should return N (newton).

The input will always be either:

A list of symbols for SI units, space-separated (representing a product) or
The above, /, and the above (representing a ratio).
The input will never contain any other characters (such as numeric literals or other punctuation).

You may assume that this will always equal a single SI unit.

Use the following symbols:

Base quantities:
s               # second
m               # meter
kg              # kilogram
A               # ampere

Derived quantities:
N  = kg m / s s # newton
J  = N m        # joule
W  = J / s      # watt
Hz = W / J      # hertz
Pa = N / m m    # pascal
C  = s A        # coulomb
V  = J / C      # volt
F  = C / V      # farad
Ω  = V / A      # ohm      (you may use the O symbol instead, for a penalty of +3 bytes)
S  = A / V      # siemens
Wb = J / A      # weber
T  = Wb / m m   # tesla
H  = Wb / A     # henry

Examples:
m            => m
N m          => J
J / W        => s
A J / W      => C
T m m        => Wb
N / A m      => T
V s / A      => H
J S / F A    => V
s / s s      => Hz
Hz kg m Hz   => N
Hz s / Ω     => S
Wb / H       => A
V Pa S s / C => Pa
N s / m Hz   => kg
V A          => W
s / Ω        => F
J / A s A    => Ω

Shortest code (in bytes) wins.

"""

from sympy import symbols

def analyze(equation):
    s = symbols('s')
    m = symbols('m')
    kg = symbols('kg')
    A = symbols('A')

    N = kg*m/s**2
    J = N*m
    W = J/s
    Hz = W/J
    Pa = N/m**2
    C = s*A
    V = J/C
    F = C/V
    Ω = V/A
    S = A/V
    Wb = J/A
    T = Wb/m**2
    H = Wb/A

    UNITS = [s, m, kg, A, N, J, W, Hz, Pa, C, V, F, Ω, S, Wb, T, H]
    STRINGS = ["s", "m", "kg", "A", "N", "J", "W", "Hz", "Pa", "C", "V", "F", "Ω", "S", "Wb", "T", "H"]

    unit = ""
    try:
        unit = eval(equation)
    except:
        pass
    
    for i in range(len(UNITS)):
        if unit == UNITS[i]:
            return STRINGS[i]
    return "unknown"

def main():
    assert(analyze("m") == "m")
    assert(analyze("N * m") == "J")
    assert(analyze("J / W") == "s")
    assert(analyze("A * J / W") == "C")
    assert(analyze("T * m * m") == "Wb")
    assert(analyze("N / (A * m)") == "T")
    assert(analyze("V * s / A") == "H")
    assert(analyze("J * S / (F * A)") == "V")
    assert(analyze("s / (s * s)") == "Hz")
    assert(analyze("Hz * kg * m * Hz") == "N")
    assert(analyze("Hz * s / Ω") == "S")
    assert(analyze("Wb / H") == "A")
    assert(analyze("V * Pa * S * s / C") == "Pa")
    assert(analyze("N * s / (m * Hz)") == "kg")
    assert(analyze("V * A") == "W")
    assert(analyze("s / Ω") == "F")
    assert(analyze("J / (A*s*A)") == "Ω")

main()
