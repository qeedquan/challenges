#!/usr/bin/env python3

"""

Recursively define a "valid arithmetic expression":

Any natural number is a valid arithmetic expression.
If s is a valid arithmetic expression, then so is (-s).
If p and q are valid arithmetic expressions, then so is (p+q).
In the above, a "natural number" is recursively defined as follows:

0 1 2 3 4 5 6 7 8 9 are natural numbers.
If a natural number n is not 0, then n0 n1 n2 n3 n4 n5 n6 n7 n8 n9 are natural numbers.
Alternatively, via the regex /^(0|[1-9][0-9]*)$/

Examples of valid arithmetic expressions:

0
314
(-7)
(0+0)
(314+(-314))
Examples of invalid arithmetic expressions:

01
-5
5+10
The challenge is to print every valid arithmetic expression line by line, i.e. create a program that will output strings line by line with the constraint that every valid arithmetic expression is eventually printed, and that no invalid arithmetic expression is ever printed.

The valid arithmetic expressions can be printed more than once.

The challenge is to do so in as few bytes as possible, since this is code-golf.

Standard loopholes apply.

"""

import itertools

def parentheses(x):
    return '(' + x + ')'

# ported from @DELETE_ME solution
def expansion(expressions, register):
    result = list(itertools.product(expressions, repeat=2))
    result = [parentheses("+".join(expr)) for expr in result]
    result.extend(expressions)
    result.extend([parentheses("-" + expr) for expr in expressions])
    result.append(str(register))
    return result

def main():
    expressions = ["0"]
    register = 0
    for i in range(4):
        expressions = expansion(expressions, register)
        for expr in expressions:
            print(expr)
        register += 1

main()

