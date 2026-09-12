#!/usr/bin/env python3

"""

Physics Challenge
This program should be able to solve for ANY two of the following variables the user wants to solve.

s (displacement)
v (velocity)
u (initial velocity)
a (acceleration)
t (time)
At start the user must choose two variables they want to solve for and what variables they can supply. You are limited to using the following equations.

Equations Permitted
v = u + a*t
s = u*t + 0.5*a*t^2
s = 0.5*(u + v)*t
v^2 = u^2 + 2*a*s
s = v*t - 0.5*a*t^2

(http://en.wikipedia.org/wiki/Equations_of_motion)

The entrant with the least amount of code and posts the quickest will win.

Rules
This is code-golf. The shortest code wins.
Your program must terminate in reasonable time for all reasonable inputs.
You are allowed to transform the equations algebraically if need be
The program must be able to interpret a variable of which the user cannot supply (See Example 2)
Input Example
The program will start and ask which variable the user will like to calculate: (s, v, u, a, t) - the user selects this via a char type or string. It then supplies all values for the other unknowns and the program will solve for the variables.

Example 1:
*What would you like to calculate? (s, v, u, a, t)*
Input: a, u     // This could also be s,v s,u, s,a v,u (ANY COMBINATION)

*Enter value for s:*
Input: 7        // The input will always be random

*Enter value for v:*
Input: 5

// Repeat for others

//program calculates

Var a = answer
Var u = answer
Example 2:
*What would you like to calculate? (s, v, u, a, t)*
Input: a, t

*Enter value for u:*
Input: 5

*Enter value for s:*
Input: UNKNOWN

*Enter value for v:*
Input: 7

*The answers for a and t are 464 and 742*

Edit
I think everyone here is overcomplicating the question. It simply asks to solve any 2 variables from the list of (s, v, u, a, t) and solve them using the equations. As the programmer you must be able to allow values to be taken for the variables that are not being solved. I will clarify that the program must be able to solve for any variable supplied by the user on startup. I also removed the somewhat correct equation s=v/t because people are becoming confused by it.

"""

from sympy import *
from sympy.abc import *

def resolve(sub, var):
    eq1 = Eq(v, u + a*t)
    eq2 = Eq(s, u*t + 0.5*a*t*t)
    eq3 = Eq(s, 0.5*(u+v)*t)
    eq4 = Eq(v*v, u*u + 2*a*s)
    eq5 = Eq(s, v*t - 0.5*a*t*t)
    
    eq = [eq1, eq2, eq3, eq4, eq5]
    for i in range(len(eq)):
        eq[i] = eq[i].subs(sub)
    return solve(eq, var, dict=True)

def main():
    print(resolve({'u': 5, 'v': 7}, (a, t)))
    print(resolve({'u': 1, 'v': 2, 't': 3}, (a, s)))
    print(resolve({'u': 1, 's': 0, 'a': -1}, (v, t)))

main()
