#!/usr/bin/env python3

"""

Boolean Satisfiability problems are problems where we wish to find solutions to boolean equations such as

(x_1 or not x_3) and (x_2 or x_3) and (x_1 or not x_2) = true
These problems are notoriously difficult, and k-SAT where k (the number of variables in an or expression) is 3 or higher is known to be NP-complete.

However, 2-SAT instances (like the problem above) are NOT NP-complete (if P!=NP), and even have linear time solutions.

You can encode an instance of 2-SAT as a list of pairs of integers by letting the integer represent which variable is in the expression,
with a negative integer representing the negation of that variable.
For example, the problem above could be represented in list of pair of ints form as

[(1,-3),(2,3),(1,-2)]

Write a function that can take in an instance of 2-SAT encoded as a list of pairs of integers and return a boolean for whether or not there are any true solutions to the formula.

"""

from z3 import *

def sat2(X):
    B = {}
    S = Solver()
    for x1, x2 in X:
        n1 = 'x_%d' % abs(x1)
        n2 = 'x_%d' % abs(x2)
        if n1 not in B:
            B[n1] = Bool(n1)
        if n2 not in B:
            B[n2] = Bool(n2)
        
        X1 = B[n1]
        X2 = B[n2]
        if x1 < 0:
            X1 = Not(X1)
        if x2 < 0:
            X2 = Not(X2)
        
        S.add(Or(X1, X2))
    
    return S.check()

def main():
    assert(sat2([(1, -3), (2, 3), (1, -2)]) == sat)
    assert(sat2([(1, 2), (-2, 3), (-1, -2), (3, 4), (-3, 5), (-4, 5), (-3, 4)]) == sat)
    assert(sat2([(1, 2), (2, -1), (-1, -2)]) == sat)
    assert(sat2([(1, 2), (-1, 2), (1, -2), (-1, -2)]) == unsat)

main()
