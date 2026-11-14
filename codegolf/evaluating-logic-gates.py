#!/usr/bin/env python3

"""

Logic gates are functions which perform basic logic operations.
In this problem, we will account for the following 6 logic gates: AND, OR, XOR, NAND, NOR, and XNOR.
Each of these takes two boolean inputs a and b, and outputs a boolean.
Below are the truth tables which show the output of each gate given two inputs.

https://i.sstatic.net/U89H0.jpg

Task
Given two boolean inputs a and b, return/output a list of the names of all gates which would return a Truthy value.
The order doesn't matter, but the names must be in the exact format as given in the 2nd sentence of the above paragraph (not the ones in the diagram).
You are also allowed to output them exclusively in lowercase, if desired.

Clarifications
You may also output a delimiter-separated string
I will allow leading/trailing spaces

Test Cases
Input
0 0
0 1
1 0
1 1

Output
[NOR, NAND, XNOR]
[OR, NAND, XOR]
[OR, NAND, XOR]
[OR, AND, XNOR]

This is code-golf, so the shortest code in bytes wins!

"""

def band(a, b):
    return a & b

def bnand(a, b):
    return ~(a & b)

def bor(a, b):
    return a | b

def bnor(a, b):
    return ~(a | b)

def bxor(a, b):
    return a ^ b

def bxnor(a, b):
    return ~(a ^ b)

def logic(a, b):
    GATES = ["OR", "NOR", "AND", "NAND", "XOR", "XNOR"]
    FUNCS = [bor, bnor, band, bnand, bxor, bxnor]

    r = []
    for i in range(len(FUNCS)):
        f = FUNCS[i]
        if f(a, b)&1 != 0:
            r.append(GATES[i])
    return r

def main():
    assert(logic(0, 0) == ["NOR", "NAND", "XNOR"])
    assert(logic(0, 1) == ["OR", "NAND", "XOR"])
    assert(logic(1, 0) == ["OR", "NAND", "XOR"])
    assert(logic(1, 1) == ["OR", "AND", "XNOR"])

main()
