#!/usr/bin/env python3

"""

https://prefetch.eu/know/concept/toffoli-gate/

"""

def toffolli(a, b, c):
    return (c ^ (a & b)) & 1

def toffolli_nand(a, b):
    return toffolli(a, b, 1)

def toffolli_nor(a, b):
    return toffolli(toffolli(a, 1, toffolli(b, a, b)), 1, 1)

def toffolli_and(a, b):
    return toffolli(a, b, 0)

def toffolli_or(a, b):
    return toffolli(1, b, toffolli(a, b, a))

def toffolli_xor(a, b):
    return toffolli(a, 1, b)

def toffolli_nota(a, b):
    return toffolli(a, 1, 1)

def toffolli_notb(a, b):
    return toffolli(b, 1, 1)

def nand(a, b):
    return ~(a & b) & 1

def nor(a, b):
    return ~(a | b) & 1

def and_(a, b):
    return (a & b) & 1

def or_(a, b):
    return (a | b) & 1

def xor(a, b):
    return (a ^ b) & 1

def nota(a, b):
    return (a ^ 1) & 1

def notb(a, b):
    return (b ^ 1) & 1

def main():
    gates = ["NAND", "NOR", "AND", "OR", "XOR", "NOTA", "NOTB"]
    funcst = [toffolli_nand, toffolli_nor, toffolli_and, toffolli_or, toffolli_xor, toffolli_nota, toffolli_notb]
    funcsc = [nand, nor, and_, or_, xor, nota, notb]

    index = 0
    for gate in gates:
        print(f"{gate}:")
        for a in range(2):
            for b in range(2):
                print(f"{a} {b} | %s %s" % (funcsc[index](a, b), funcst[index](a, b))) 
        index += 1
        print()

main()
