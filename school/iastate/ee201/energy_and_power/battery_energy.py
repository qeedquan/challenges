"""

Q: A 3.6 V battery is rated at 1.1 A·hr. How much energy is stored in the battery?
A: P = I * V (3.6 * 1.1 = 3.96 W*hr), to convert to joules, 1 watt = 1 joule/second, so 3.96 * 3600 = ~14.3 kJ (rounded up)

"""

V = 3.6
I = 1.1
P = V * I
E = P * 3600
print(P)
print(E)

