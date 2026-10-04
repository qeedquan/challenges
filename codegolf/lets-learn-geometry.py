#!/usr/bin/env python3

"""

Today our lesson is about rectangles and triangles.

you will be given as an input an n x n grid that is based on two characters # and * you have to classify it into : triangle or rectangle. where # represents a point and * represents a blank space.

Example input:
 #***
 ##**
 ###*
 ####

Output:
 triangle

Another example
  ##**
  ##**
  ##**
  ##**

Output:
  rectangle

Rules:

You should assume that the input is always either a triangle or a rectangle.
The only two characters you will receive are: * and #.
Assume that n < 100.
Be creative, this is a popularity-contest so the most up-voted answer will win.

"""

import sympy

"""

@Abhijit

if s if the number of "#" in the input stream

Triangle: n**2 + n - 2s = 0 -> n should be an integer

"""
def classify(s):
    n = len(s)
    y = 0
    for i in range(n):
        if len(s[i]) != n:
            return "invalid"
        for c in s[i]:
            if c == '#':
                y += 1
            elif c != '*':
                return "invalid"

    x = sympy.Symbol('x')
    r = sympy.solve(x**2 + x - 2*y)
    if float(r[0]).is_integer():
        return "triangle"
    return "rectangle"

def main():
    assert(classify(["#***", "##**", "###*", "####"]) == "triangle")
    assert(classify(["****", "***#", "**##", "*###"]) == "triangle")
    assert(classify(["##**", "##**", "##**", "##**"]) == "rectangle")
    assert(classify(["#***", "#***", "#***", "#***"]) == "rectangle")
    assert(classify(["####", "####", "####", "####"]) == "rectangle")

main()
