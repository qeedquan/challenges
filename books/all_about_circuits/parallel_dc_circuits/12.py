"""

Suppose I connect two resistors in parallel with one another, like this:

How much electrical resistance would you expect an ohmmeter to indicate if it were connected across the combination of these two parallel-connected resistors?

"""
R1 = 3300
R2 = 3300
Rt = 1/(1/R1 + 1/R2)
print(Rt)

