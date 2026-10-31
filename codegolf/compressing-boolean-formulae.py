#!/usr/bin/env python3

r"""

Syntax
~ not
/\ and
\/ or
t true
f false
P, Q, FISH, etc: variables

(Operators are given in order of precedence)

Introduction
Some boolean formulae can be changed to different forms to make them shorter. For example, the formula

~(~P /\ ~Q)
can be changed to the shorter form

P\/Q
while the formula

P \/ ~P
can be changed to the shorter form

t
Challenge
In this challenge, you are required to write a program that, given any boolean formula using only /\, \/, ~, t, f, parentheses, boolean variables (in uppercase), and whitespace, outputs a shortest form (since there may be more than one shortest form) in characters of that expression which is equivalent for all assignments of the variables. Shortest code (in any language) wins. I/O can be done in any reasonable manner.

Also, since answers are difficult to verify, it would be helpful (but isn't required) to include a brief explanation of how the code works.

"""

from sympy import symbols
from sympy.logic import simplify_logic

def main():
    P, Q = symbols("P Q")

    print(simplify_logic(~(~P & ~Q)))
    print(simplify_logic(P | ~P))

main()
