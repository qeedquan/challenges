#!/usr/bin/env python3

"""

This is my republished first kata(with issues fixed!), hope you guys will enjoy it!

For input, you will be given a string in the form "(mx+n)(px+q)" where the character x can be any single lowercase alphabet from a-z, while m, n, p and q are integers(can be negative).

Task
Return a string in the format ax^2+bx+c where a, b and c are integers, eg. 5x^2-6x+8
If a or b is 1, the '1' in front of the variable should be omitted. eg. x^2+x-20
If a or b is -1, only the minus sign - should be shown, eg. -x^2-x+6
Examples:
KataSolution.quadraticBuilder("(x+2)(x+3)");  //return "x^2+5x+6"
KataSolution.quadraticBuilder("(x-2)(x+7)");  //return "x^2+5x-14"
KataSolution.quadraticBuilder("(3y+2)(y+5)");  //return "3y^2+17y+10"
KataSolution.quadraticBuilder("(-h-7)(4h+3)");  //return "-4h^2-31h-21"
Good luck and have fun!

"""

from sympy import expand, parse_expr

def quadratic_builder(s):
    s = parse_expr(s, transformations='implicit')
    r = str(expand(s))
    r = r.replace("**", "^")
    r = r.replace("*", "")
    r = r.replace(" ", "")
    return r

def main():
    assert(quadratic_builder("(x+2)(x+3)") == "x^2+5x+6")
    assert(quadratic_builder("(x-2)(x+7)") == "x^2+5x-14")
    assert(quadratic_builder("(3y+2)(y+5)") == "3y^2+17y+10")
    assert(quadratic_builder("(-h-7)(4h+3)") == "-4h^2-31h-21")

main()
