#!/usr/bin/env python3

r"""

Slope fields or direction fields, are a graphical representation of the solutions to a first-order differential equation of a scalar function.
A slope field shows the slope of a differential equation at certain vertical and horizontal intervals on the cartesian plane,
and can be used to determine the approximate tangent slope at a point on a curve, where the curve is some solution to the differential equation.
For example consider the differential equation:

dy/dx = (y - 4x) / (x - y)

The corresponding slope field will look like:

https://i.stack.imgur.com/MWhDy.gif

Another example with this differential equation:

dy/dx = (x - y) / (x - 2y)

    https://i.stack.imgur.com/VkK7m.gif

Your task is to generate such slope fields in the console with characters of text. You are to print the following for each coordinate pair:

/ If the differential equation evaluated at the point (x,y) is positive.
\ If the differential equation evaluated at the point (x,y) is negative.
- If the differential equation evaluated at the point (x,y) = 0.
| If the differential equation evaluated at the point (x,y) is undefined.
The inputs are a string and a number consisting of:

Expression string that can be evaluated (or parsed if you have to).
A number that outlines the radius of the plot from (0,0).
The expression string can use any built-in mathematical function and will only either x or y as variables.
Any combination of logarithms, (inverse and/or hyperbolic) trigonometric functions, or functions like sqrt(), pow(), exp(), abs() may be used in the expression.
The plot radius may also be 0, which means only print one character containing the slope at the origin. A sample input may look something like:

plotRadius = 10
expression = "(x - y) / (x - 2 * y)"
Notice how both the boundaries of the plot follow: −plotRadius ≤ x,y ≤ plotRadius. This results in the following slope field being displayed:

/ / / / / / / / / / / / / / / / / / / / —
/ / / / / / / / / / / / / / / / / / / — \
/ / / / / / / / / / / / / / / / / / — \ \
/ / / / / / / / / / / / / / / / / — \ \ \
/ / / / / / / / / / / / / / / / — \ \ \ \
/ / / / / / / / / / / / / / / — \ \ \ \ |
/ / / / / / / / / / / / / / — \ \ \ | / /
/ / / / / / / / / / / / / — \ \ | / / / /
/ / / / / / / / / / / / — \ | / / / / / /
/ / / / / / / / / / / — | / / / / / / / /
/ / / / / / / / / / | / / / / / / / / / /
/ / / / / / / / | — / / / / / / / / / / /
/ / / / / / | \ — / / / / / / / / / / / /
/ / / / | \ \ — / / / / / / / / / / / / /
/ / | \ \ \ — / / / / / / / / / / / / / /
| \ \ \ \ — / / / / / / / / / / / / / / /
\ \ \ \ — / / / / / / / / / / / / / / / /
\ \ \ — / / / / / / / / / / / / / / / / /
\ \ — / / / / / / / / / / / / / / / / / /
\ — / / / / / / / / / / / / / / / / / / /
— / / / / / / / / / / / / / / / / / / / /
Please separate each point with a space.

"""

from math import *

def at(eq, x, y):
    c = '|'
    try:
        v = eval(eq)
        if v > 0:
            c = '/'
        elif v < 0:
            c = '\\'
        else:
            c = '-'
    except:
        pass
    return c

def slopefields(r, eq):
    print("equation='%s' radius=%s" % (eq, r))
    for y in range(r, -r - 1, -1):
        for x in range(-r, r + 1):
            print(at(eq, x, y), end=' ')
        print()
    print()

def main():
    slopefields(10, "(y - 4*x) / (x - y)")
    slopefields(10, "(x - y) / (x - 2*y)")
    slopefields(10, "(x - y) / (x - 2*y)")
    slopefields(10, "sqrt(x + y)")
    slopefields(10, "sin(x*y) + cos(y*y)")
    slopefields(10, "log(x*x) + log(y*y)")

main()
