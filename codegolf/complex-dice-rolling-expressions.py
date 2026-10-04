#!/usr/bin/env python3

r"""

Background
I play D&D on a regular basis with some friends. While talking about the complexity of some systems/versions when it comes to rolling dice and applying bonuses and penalties, we jokingly came up with some additional complexity for dice rolling expressions. Some of them were too outrageous (like extending simple dice expressions like 2d6 to matrix arguments1), but the rest make for an interesting system.

The Challenge
Given a complex dice expression, evaluate it according to the following rules and output the result.

Basic Evaluation Rules
Whenever an operator expects an integer but receives a list for an operand, the sum of that list is used
Whenever an operator expects a list but receives an integer for an operand, the integer is treated as a one-element list containing that integer
Operators
All operators are binary infix operators. For the purpose of explanation, a will be the left operand, and b will be the right operand. List notation will be used for examples where operators can take lists as operands, but actual expressions consist only of positive integers and operators.

d: output a independent uniform random integers in the range [1, b]
Precedence: 3
Both operands are integers
Examples: 3d4 => [1, 4, 3], [1, 2]d6 => [3, 2, 6]
t: take the b lowest values from a
Precedence: 2
a is a list, b is an integer
If b > len(a), all values are returned
Examples: [1, 5, 7]t1 => [1], [5, 18, 3, 9]t2 => [3, 5], 3t5 => [3]
T: take the b highest values from a
Precedence: 2
a is a list, b is an integer
If b > len(a), all values are returned
Examples: [1, 5, 7]T1 => [7], [5, 18, 3, 9]T2 => [18, 9], 3T5 => [3]
r: if any elements in b are in a, reroll those elements, using whatever d statement generated them
Precedence: 2
Both operands are lists
Rerolling is done only once, so it is possible to still have elements of b in the result
Examples: 3d6r1 => [1, 3, 4] => [6, 3, 4], 2d4r2 => [2, 2] => [3, 2], 3d8r[1,8] => [1, 8, 4] => [2, 2, 4]
R: if any elements in b are in a, reroll those elements repeatedly until no elements of b are present, using whatever d statement generated them
Precedence: 2
Both operands are lists
Examples: 3d6R1 => [1, 3, 4] => [6, 3, 4], 2d4R2 => [2, 2] => [3, 2] => [3, 1], 3d8R[1,8] => [1, 8, 4] => [2, 2, 4]
+: add a and b together
Precedence: 1
Both operands are integers
Examples: 2+2 => 4, [2]+[2] => 4, [3, 1]+2 => 6
-: subtract b from a
Precedence: 1
Both operands are integers
b will always be less than a
Examples: 2-1 => 1, 5-[2] => 3, [8, 3]-1 => 10
.: concatenate a and b together
Precedence: 1
Both operands are lists
Examples: 2.2 => [2, 2], [1].[2] => [1, 2], 3.[4] => [3, 4]
_: output a with all elements of b removed
Precedence: 1
Both operands are lists
Examples: [3, 4]_[3] => [4], [2, 3, 3]_3 => [2], 1_2 => [1]
Additional Rules
If the final value of an expression is a list, it is summed before output
Evaluation of terms will only result in positive integers or lists of positive integers - any expression that results in a non-positive integer or a list containing at least one non-positive integer will have those values replaced by 1s
Parentheses can be used to group terms and specify order of evaluation
Operators are evaluated in order of highest precedence to lowest precedence, with evaluation proceeding from left to right in the case of tied precedence (so 1d4d4 would be evaluated as (1d4)d4)
The order of elements in lists does not matter - it is perfectly acceptable for an operator that modifies a list to return it with its elements in a different relative order
Terms that cannot be evaluated or would result in an infinite loop (like 1d1R1 or 3d6R[1, 2, 3, 4, 5, 6]) are not valid
Test Cases
Format: input => possible output

1d20 => 13
2d6 => 8
4d6T3 => 11
2d20t1 => 13
5d8r1 => 34
5d6R1 => 20
2d6d6 => 23
3d2R1d2 => 3
(3d2R1)d2 => 11
1d8+3 => 10
1d8-3 => 4
1d6-1d2 => 2
2d6.2d6 => 12
3d6_1 => 8
1d((8d20t4T2)d(6d6R1r6)-2d4+1d2).(1d(4d6_3d3)) => 61
All but the last test case were generated with the reference implementation.

Worked Example
Expression: 1d((8d20t4T2)d(6d6R1r6)-2d4+1d2).(1d(4d6_3d3))

8d20t4T2 => [19, 5, 11, 6, 19, 15, 4, 20]t4T2 => [4, 5, 6, 11]T2 => [11, 6] (full: 1d(([11, 6])d(6d6R1r6)-2d4+1d2).(1d(4d6_3d3)))
6d6R1r6 => [2, 5, 1, 5, 2, 3]r1R6 => [2, 5, 3, 5, 2, 3]R6 => [2, 5, 3, 5, 2, 3] (1d([11, 6]d[2, 5, 3, 5, 2, 3]-2d4+1d2).(1d(4d6_3d3)))
[11, 6]d[2, 5, 3, 5, 2, 3] => 17d20 => [1, 6, 11, 7, 2, 8, 15, 3, 4, 18, 11, 11, 1, 10, 8, 6, 11] (1d([1, 6, 11, 7, 2, 8, 15, 3, 4, 18, 11, 11, 1, 10, 8, 6, 11]-2d4+1d2).(1d(4d6_3d3)))
2d4 => 7 (1d([1, 6, 11, 7, 2, 8, 15, 3, 4, 18, 11, 11, 1, 10, 8, 6, 11]-7+1d2).(1d(4d6_3d3)))
1d2 => 2 (1d([1, 6, 11, 7, 2, 8, 15, 3, 4, 18, 11, 11, 1, 10, 8, 6, 11]-7+2).(1d(4d6_3d3)))
[1, 6, 11, 7, 2, 8, 15, 3, 4, 18, 11, 11, 1, 10, 8, 6, 11]-7+2 => 133-7+2 => 128 (1d128).(1d(4d6_3d3)))
4d6_3d3 => [1, 3, 3, 6]_[3, 2, 2] => [1, 3, 3, 6, 3, 2, 2] (1d128).(1d[1, 3, 3, 6, 3, 2, 2]))
1d[1, 3, 3, 6, 3, 2, 2] => 1d20 => 6 (1d128).(6))
1d128 => 55 (55.6)
55.6 => [55, 6] ([55, 6])
[55, 6] => 61 (done)
Reference Implementation
This reference implementation uses the same constant seed (0) for evaluating each expression for testable, consistent outputs. It expects input on STDIN, with newlines separating each expression.

#!/usr/bin/env python3

import re
from random import randint, seed
from collections import Iterable
from functools import total_ordering

def as_list(x):
    if isinstance(x, Iterable):
        return list(x)
    else:
        return [x]

def roll(num_sides):
    return Die(randint(1, num_sides), num_sides)

def roll_many(num_dice, num_sides):
    num_dice = sum(as_list(num_dice))
    num_sides = sum(as_list(num_sides))
    return [roll(num_sides) for _ in range(num_dice)]

def reroll(dice, values):
    dice, values = as_list(dice), as_list(values)
    return [die.reroll() if die in values else die for die in dice]

def reroll_all(dice, values):
    dice, values = as_list(dice), as_list(values)
    while any(die in values for die in dice):
        dice = [die.reroll() if die in values else die for die in dice]
    return dice

def take_low(dice, num_values):
    dice = as_list(dice)
    num_values = sum(as_list(num_values))
    return sorted(dice)[:num_values]

def take_high(dice, num_values):
    dice = as_list(dice)
    num_values = sum(as_list(num_values))
    return sorted(dice, reverse=True)[:num_values]

def add(a, b):
    a = sum(as_list(a))
    b = sum(as_list(b))
    return a+b

def sub(a, b):
    a = sum(as_list(a))
    b = sum(as_list(b))
    return max(a-b, 1)

def concat(a, b):
    return as_list(a)+as_list(b)

def list_diff(a, b):
    return [x for x in as_list(a) if x not in as_list(b)]

@total_ordering
class Die:
    def __init__(self, value, sides):
        self.value = value
        self.sides = sides
    def reroll(self):
        self.value = roll(self.sides).value
        return self
    def __int__(self):
        return self.value
    __index__ = __int__
    def __lt__(self, other):
        return int(self) < int(other)
    def __eq__(self, other):
        return int(self) == int(other)
    def __add__(self, other):
        return int(self) + int(other)
    def __sub__(self, other):
        return int(self) - int(other)
    __radd__ = __add__
    __rsub__ = __sub__
    def __str__(self):
        return str(int(self))
    def __repr__(self):
        return "{} ({})".format(self.value, self.sides)

class Operator:
    def __init__(self, str, precedence, func):
        self.str = str
        self.precedence = precedence
        self.func = func
    def __call__(self, *args):
        return self.func(*args)
    def __str__(self):
        return self.str
    __repr__ = __str__

ops = {
    'd': Operator('d', 3, roll_many),
    'r': Operator('r', 2, reroll),
    'R': Operator('R', 2, reroll_all),
    't': Operator('t', 2, take_low),
    'T': Operator('T', 2, take_high),
    '+': Operator('+', 1, add),
    '-': Operator('-', 1, sub),
    '.': Operator('.', 1, concat),
    '_': Operator('_', 1, list_diff),
}

def evaluate_dice(expr):
    return max(sum(as_list(evaluate_rpn(shunting_yard(tokenize(expr))))), 1)

def evaluate_rpn(expr):
    stack = []
    while expr:
        tok = expr.pop()
        if isinstance(tok, Operator):
            a, b = stack.pop(), stack.pop()
            stack.append(tok(b, a))
        else:
            stack.append(tok)
    return stack[0]

def shunting_yard(tokens):
    outqueue = []
    opstack = []
    for tok in tokens:
        if isinstance(tok, int):
            outqueue = [tok] + outqueue
        elif tok == '(':
            opstack.append(tok)
        elif tok == ')':
            while opstack[-1] != '(':
                outqueue = [opstack.pop()] + outqueue
            opstack.pop()
        else:
            while opstack and opstack[-1] != '(' and opstack[-1].precedence > tok.precedence:
                outqueue = [opstack.pop()] + outqueue
            opstack.append(tok)
    while opstack:
        outqueue = [opstack.pop()] + outqueue
    return outqueue

def tokenize(expr):
    while expr:
        tok, expr = expr[0], expr[1:]
        if tok in "0123456789":
            while expr and expr[0] in "0123456789":
                tok, expr = tok + expr[0], expr[1:]
            tok = int(tok)
        else:
            tok = ops[tok] if tok in ops else tok
        yield tok

if __name__ == '__main__':
    import sys
    while True:
        try:
            dice_str = input()
            seed(0)
            print("{} => {}".format(dice_str, evaluate_dice(dice_str)))
        except EOFError:
            exit()
[1]: Our definition of adb for matrix arguments was to roll AdX for each X in a * b, where A = det(a * b). Clearly that's too absurd for this challenge.

"""

import re
import sys
from collections.abc import Iterable
from random import randint, seed
from functools import total_ordering

def as_list(x):
    if isinstance(x, Iterable):
        return list(x)
    else:
        return [x]

def roll(num_sides):
    return Die(randint(1, num_sides), num_sides)

def roll_many(num_dice, num_sides):
    num_dice = sum(as_list(num_dice))
    num_sides = sum(as_list(num_sides))
    return [roll(num_sides) for _ in range(num_dice)]

def reroll(dice, values):
    dice, values = as_list(dice), as_list(values)
    return [die.reroll() if die in values else die for die in dice]

def reroll_all(dice, values):
    dice, values = as_list(dice), as_list(values)
    while any(die in values for die in dice):
        dice = [die.reroll() if die in values else die for die in dice]
    return dice

def take_low(dice, num_values):
    dice = as_list(dice)
    num_values = sum(as_list(num_values))
    return sorted(dice)[:num_values]

def take_high(dice, num_values):
    dice = as_list(dice)
    num_values = sum(as_list(num_values))
    return sorted(dice, reverse=True)[:num_values]

def add(a, b):
    a = sum(as_list(a))
    b = sum(as_list(b))
    return a+b

def sub(a, b):
    a = sum(as_list(a))
    b = sum(as_list(b))
    return max(a-b, 1)

def concat(a, b):
    return as_list(a)+as_list(b)

def list_diff(a, b):
    return [x for x in as_list(a) if x not in as_list(b)]

@total_ordering
class Die:
    def __init__(self, value, sides):
        self.value = value
        self.sides = sides
    def reroll(self):
        self.value = roll(self.sides).value
        return self
    def __int__(self):
        return self.value
    __index__ = __int__
    def __lt__(self, other):
        return int(self) < int(other)
    def __eq__(self, other):
        return int(self) == int(other)
    def __add__(self, other):
        return int(self) + int(other)
    def __sub__(self, other):
        return int(self) - int(other)
    __radd__ = __add__
    __rsub__ = __sub__
    def __str__(self):
        return str(int(self))
    def __repr__(self):
        return "{} ({})".format(self.value, self.sides)

class Operator:
    def __init__(self, str, precedence, func):
        self.str = str
        self.precedence = precedence
        self.func = func
    def __call__(self, *args):
        return self.func(*args)
    def __str__(self):
        return self.str
    __repr__ = __str__

ops = {
    'd': Operator('d', 3, roll_many),
    'r': Operator('r', 2, reroll),
    'R': Operator('R', 2, reroll_all),
    't': Operator('t', 2, take_low),
    'T': Operator('T', 2, take_high),
    '+': Operator('+', 1, add),
    '-': Operator('-', 1, sub),
    '.': Operator('.', 1, concat),
    '_': Operator('_', 1, list_diff),
}

def evaluate_dice(expr):
    return max(sum(as_list(evaluate_rpn(shunting_yard(tokenize(expr))))), 1)

def evaluate_rpn(expr):
    stack = []
    while expr:
        tok = expr.pop()
        if isinstance(tok, Operator):
            a, b = stack.pop(), stack.pop()
            stack.append(tok(b, a))
        else:
            stack.append(tok)
    return stack[0]

def shunting_yard(tokens):
    outqueue = []
    opstack = []
    for tok in tokens:
        if isinstance(tok, int):
            outqueue = [tok] + outqueue
        elif tok == '(':
            opstack.append(tok)
        elif tok == ')':
            while opstack[-1] != '(':
                outqueue = [opstack.pop()] + outqueue
            opstack.pop()
        else:
            while opstack and opstack[-1] != '(' and opstack[-1].precedence > tok.precedence:
                outqueue = [opstack.pop()] + outqueue
            opstack.append(tok)
    while opstack:
        outqueue = [opstack.pop()] + outqueue
    return outqueue

def tokenize(expr):
    while expr:
        tok, expr = expr[0], expr[1:]
        if tok in "0123456789":
            while expr and expr[0] in "0123456789":
                tok, expr = tok + expr[0], expr[1:]
            tok = int(tok)
        else:
            tok = ops[tok] if tok in ops else tok
        yield tok

def main():
    print(evaluate_dice("1d20"))
    print(evaluate_dice("2d6"))
    print(evaluate_dice("4d6T3"))
    print(evaluate_dice("2d20t1"))
    print(evaluate_dice("5d8r1"))
    print(evaluate_dice("5d6R1"))
    print(evaluate_dice("2d6d6"))
    print(evaluate_dice("3d2R1d2"))
    print(evaluate_dice("(3d2R1)d2"))
    print(evaluate_dice("1d8+3"))
    print(evaluate_dice("1d8-3"))
    print(evaluate_dice("1d6-1d2"))
    print(evaluate_dice("2d6.2d6"))
    print(evaluate_dice("3d6_1"))
    print(evaluate_dice("1d((8d20t4T2)d(6d6R1r6)-2d4+1d2).(1d(4d6_3d3))"))

main()
