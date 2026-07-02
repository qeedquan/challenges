R1 = 1e3
R2 = 2.2e3
R3 = 6.8e3
R4 = 470
Rt = 1/(1/R1 + 1/R2 + 1/R3 + 1/R4)
Vt = 4
V1 = Vt
V2 = Vt
V3 = Vt
V4 = Vt
I1 = V1 / R1
I2 = V2 / R2
I3 = V3 / R3
I4 = V4 / R4
P1 = V1 * I1
P2 = V2 * I2
P3 = V3 * I3
P4 = V4 * I4
It = Vt / Rt
Pt = Vt * It
print(V1, V2, V3, V4, Vt)
print(I1, I2, I3, I4, It)
print(R1, R2, R3, R4, Rt)
print(P1, P2, P3, P4, Pt)
