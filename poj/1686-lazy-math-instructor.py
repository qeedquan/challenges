#!/usr/bin/env python3

"""

Description

A math instructor is too lazy to grade a question in the exam papers in which students are supposed to produce a complicated formula for the question asked. Students may write correct answers in different forms which makes grading very hard. So, the instructor needs help from computer programmers and you can help.

You are to write a program to read different formulas and determine whether or not they are arithmetically equivalent.

Input

The first line of the input contains an integer N (1 <= N <= 20) that is the number of test cases. Following the first line, there are two lines for each test case. A test case consists of two arithmetic expressions, each on a separate line with at most 80 characters. There is no blank line in the input. An expression contains one or more of the following:
Single letter variables (case insensitive).
Single digit numbers.
Matched left and right parentheses.
Binary operators +, - and * which are used for addition, subtraction and multiplication respectively.
Arbitrary number of blank or tab characters between above tokens.

Note: Expressions are syntactically correct and evaluated from left to right with equal precedence (priority) for all operators. The coefficients and exponents of the variables are guaranteed to fit in 16-bit integers.

Output

Your program must produce one line for each test case. If input expressions for each test data are arithmetically equivalent, "YES", otherwise "NO" must be printed as the output of the program. Output should be all in upper-case characters.

Sample Input

3
(a+b-c)*2
(a+a)+(b*2)-(3*c)+c
a*2-(a+c)+((a+c+e)*2)
3*a+c+(2*e)
(a-b)*(a-b)
(a*a)-(2*a*b)-(b*b)
Sample Output

YES
YES
NO

Source

Tehran 2000

"""

from sympy import *
from sympy.abc import *

def equivalent(e1, e2):
    return expand(e1) == expand(e2)

def main():
    assert(equivalent((a+b-c)*2, (a+a)+(b*2)-(3*c)+c) == True)
    assert(equivalent(a*2-(a+c)+((a+c+e)*2), 3*a+c+(2*e)) == True)
    assert(equivalent((a-b)*(a-b), (a*a)-(2*a*b)-(b*b)) == False)

main()
