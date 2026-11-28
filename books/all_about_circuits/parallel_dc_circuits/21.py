"""

There is a simple equation that gives the equivalent resistance of two resistances connected in parallel. Write this equation.

Secondly, apply this two-resistance equation to the solution for total resistance in this three-resistor network:

No, this is not a “trick” question! There is a way to apply a two-resistance equation to solve for three resistances connected in parallel.

"""
R1 = 100
R2 = 100
R3 = 50
Rt = 1/(1/R1 + 1/R2 + 1/R3)

"""

A way of reducing 3 parallel resistance to two step 2 parallel resistance problem

"""
R12 = 1/(1/R1 + 1/R2)
Rt1 = 1/(1/R12 + 1/R3)

print(Rt, Rt1)
