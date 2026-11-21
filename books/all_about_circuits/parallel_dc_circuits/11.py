#!/usr/bin/env python3

"""

Calculate the total amount of current that the battery must supply to this parallel circuit:

Now, using Ohm’s Law, calculate total resistance (Rtotal) from total (source) voltage Vtotal and total (source) current Itotal.

"""

R1 = 500
R2 = 500
Vt = 10
Rt = 1/(1/R1 + 1/R2)
It = Vt / Rt
print(It)
print(Rt)
