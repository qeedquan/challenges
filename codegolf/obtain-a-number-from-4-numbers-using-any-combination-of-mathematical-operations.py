#!/usr/bin/env python3

r"""

Given 4 numbers n1, n2, n3, n4, and a goal n5, obtain n5 using n1 through n4 combined with any operations.

Eg. Given four numbers 2,3,4,5 and the goal as 8, output (one of many) is 2-3+4+5

EDIT: This is a variation of a game played at my son's school. Paranthesis, powers, unary operations (log, factorial) are allowed; the expressions tend to get complicated. However, unary operations can be applied only once on a number. Essentially, the tree should be:

                          goal
                           /\
                          /  \
                         /    \
                expression1   expression2
                   /\                /\
                  /  \              /  \
                 /    \            /    \
               term1  term2     term3  term4
where term#i is either
1. one of the numbers, or 2. one of the numbers with an unary operation.

"""

from itertools import *

def gen(n1, n2, n3, n4, n5):
    r = []
    for x1, x2, x3, x4 in permutations(map(str, [n1, n2, n3, n4])):
        for op1, op2, op3 in product(['+', '-', '//', '*'], repeat=3):
            eq = x1 + op1 + x2 + op2 + x3 + op3 + x4
            if eval(eq) == n5:
                r.append(eq.replace('//', '/'))
    return r

def main():
    for x in gen(2, 3, 4, 5, 8):
        print(x)

main()
