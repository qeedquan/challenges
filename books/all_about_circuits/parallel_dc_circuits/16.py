R1 = 10e3
R2 = 3.3e3
Rt = 1/(1/R1 + 1/R2)
Vt = 30
V1 = Vt
V2 = Vt
I1 = V1 / R1
I2 = V2 / R2
It = I1 + I2
P1 = V1 * I1
P2 = V2 * I2
Pt = Vt * It
print(V1, V2, Vt)
print(I1, I2, It)
print(R1, R2, Rt)
print(P1, P2, Pt)
