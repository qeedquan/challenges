"""

The circuit shown here is commonly referred to as a current divider. Calculate the voltage dropped across each resistor, the current drawn by each resistor, and the total amount of electrical resistance ßeen” by the 9-volt battery:


• Current through the 2 kΩ resistor =
• Current through the 3 kΩ resistor =
• Current through the 5 kΩ resistor =
• Voltage across each resistor =
• Rtotal =
Can you think of any practical applications for a circuit such as this?

"""
R1 = 2e3
R2 = 3e3
R3 = 5e3
Rt = 1/(1/R1 + 1/R2 + 1/R3)
Vt = 9
V1 = Vt
V2 = Vt
V3 = Vt
I1 = V1 / R1
I2 = V2 / R2
I3 = V3 / R3
print(I1, I2, I3)
print(Rt)
