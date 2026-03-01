"""

Find the magnitude of the impedance and the phase difference between the current and the voltage.

R = 10 Ohms
L = 0.6 Henries
C = 200 Microfarad
w = 50 rad/s

"""

from cmath import *
from math import *

R = 10
L = 0.6
C = 200e-6
w = 50
Xc = 1/(w*C)
Xl = w * L
Z = R + (Xl - Xc)*1j
print(Xc)
print(Xl)
print(Z)
print(abs(Z), degrees(phase(Z)))
