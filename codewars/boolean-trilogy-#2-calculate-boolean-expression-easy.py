#!/usr/bin/env python3

"""

Task
You get a Boolean expression and the values of its variables as input. Your task is to calculate this Boolean expression with a given set of variable values.

Details
The input expression consists of variables represented by uppercase letters A-F and operations "&" (logical AND) and "|" (logical OR).
Parentheses and other operations are missing from the expression.
Variables can be repeated and placed in any order.
The expression contains at least one variable
Variable values are represented as a dictionary {name: value}.
Example
calculate("A & B & C", {"A": 0, "B": 1, "C": 0})   # returns 0
# A & B & C = 0 & 1 & 0 = 0

calculate("B & A | C", {"A": 1, "B": 0, "C": 1})   # returns 1
# B & A | C = 0 & 1 | 1 = 0 | 1 = 1

"""

def calculate(expression, values):
    for index in range(26):
        try:
            variable = str(chr(ord('A') + index))
            expression = expression.replace(variable, str(values[variable]))
        except:
            pass
    return eval(expression)

def main():
    assert(calculate("A & B & C", { "A": 0, "B": 1, "C": 0 }) == 0)
    assert(calculate("A | B | C", { "A": 0, "B": 0, "C": 0 }) == 0)
    assert(calculate("A & C & B", { "A": 1, "B": 1, "C": 1 }) == 1)
    assert(calculate("B & A | C", { "A": 1, "B": 0, "C": 0 }) == 0)
    assert(calculate("D", { "D": 1 }) == 1)
    assert(calculate("A & A | A", { "A": 0 }) == 0)

main()
