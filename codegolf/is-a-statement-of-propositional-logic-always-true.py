#!/usr/bin/env python3

"""

The challenge is to golf a program that checks if a statement of propositional calculus/logic is a logical tautology (i.e. it is true for all possible values of the variables).

Input
Input formulas will use P, P', P'' ect. as variables. They can either be true or false.

(P and P') means both P and P' are true.

(P or P') means at least one of P and P' is true.

(P implies P') means that if P is true, than P' must be true.

(not P) means that P is false.

These forms can be nested.

Example input: (P implies ((P' or P'') and P'''))

Output
Output will be a truthy value if the input is a tautology, and a falsy value if it is not. (i.e True/False 1/0)

Test Cases
P: False

(P implies P): True

((P implies P') implies ((P' implies P'') implies (P implies P''))): True

(P implies (P or P')): True

(P implies (P and P')): False

(P or (not P)): True

and, or, not, and implies are the ONLY operators.

This is code-golf. Shortest program in bytes wins.

Clarification
The type of logic used here is Classical logic.

"""

import re

def tautology(s):
    s = s.replace("implies", "<=", -1)
    m = re.findall(r"P'*", s)
    v = sorted(list(set(m)))
    n = len(v)
    for i in range(1<<n):
        t = s
        for j in range(n-1, -1, -1):
            x = "0"
            if i&(1<<j) != 0:
                x = "1"
            t = t.replace(v[j], x, -1)

        if not eval(t):
            return False

    return True

def main():
    assert(tautology("(P and P')") == False)
    assert(tautology("(P or P')") == False)
    assert(tautology("(P implies P')") == False)
    assert(tautology("(not P)") == False)
    assert(tautology("P") == False)
    assert(tautology("(P implies P)") == True)
    assert(tautology("((P implies P') implies ((P' implies P'') implies (P implies P'')))") == True)
    assert(tautology("(P implies (P or P'))") == True)
    assert(tautology("(P implies (P and P'))") == False)
    assert(tautology("(P or (not P))") == True)

main()
