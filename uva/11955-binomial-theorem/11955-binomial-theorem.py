#!/usr/bin/env python3

from sympy import var, expand
import re

def solve(equation):
    terms = re.findall(r"[a-z]+", equation)
    exponent = re.findall(r"[0-9]+", equation)
    if len(terms) != 2 or len(exponent) != 1:
        return "invalid"
    
    lhs = var(terms[0])
    rhs = var(terms[1])
    output = expand((lhs + rhs)**int(exponent[0]))

    result = str(output)
    result = result.replace("**", "^")
    result = result.replace(" ", "")
    return result

def main():
    assert(solve("(a+b)^1") == "a+b")
    assert(solve("(alpha+omega)^2") == "alpha^2+2*alpha*omega+omega^2")
    assert(solve("(acm+icpc)^3") == "acm^3+3*acm^2*icpc+3*acm*icpc^2+icpc^3")

main()

