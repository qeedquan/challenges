#!/usr/bin/env python3

# ported from https://gist.github.com/awadalaa/7ef7dc7e41edb501d44d1ba41cbf0dc6

class InfixConverter:
    def __init__(self):
        self.stack = []
        self.precedence = { '+': 1, '-': 1, '*': 2, '/': 2, '^': 3 }

    def has_less_or_equal_priority(self, a, b):
        if a not in self.precedence:
            return False
        if b not in self.precedence:
            return False
        return self.precedence[a] <= self.precedence[b]

    def is_operator(self, x):
        ops = ['+', '-', '/', '*']
        return x in ops

    def is_operand(self, ch):
        return ch.isalpha() or ch.isdigit()

    def is_open_parenthesis(self, ch):
        return ch == '('

    def is_close_parenthesis(self, ch):
        return ch == ')'

    def to_postfix(self, expr):
        expr = expr.replace(" ", "")
        self.stack = []
        output = ""
        for c in expr:
            if self.is_operand(c):
                output += c
            else:
                if self.is_open_parenthesis(c):
                    self.stack.append(c)
                elif self.is_close_parenthesis(c):
                    operator = self.stack.pop()
                    while not self.is_open_parenthesis(operator):
                        output += operator
                        operator = self.stack.pop()              
                else:
                    while len(self.stack) > 0 and self.has_less_or_equal_priority(c, self.stack[-1]):
                        output += self.stack.pop()
                    self.stack.append(c)

        while len(self.stack) > 0:
            output += self.stack.pop()
        return output
    
    """
     1. Reverse expression string
     2. Replace open paren with close paren and vice versa
     3. Get Postfix and reverse it
    """
    def to_prefix(self, expr):
        reverse_expr =''
        for c in expr[::-1]:
            if c == '(':
                reverse_expr += ")"
            elif c == ')':
                reverse_expr += "("
            else:
                reverse_expr += c

        reverse_postfix = self.to_postfix(reverse_expr)
        return reverse_postfix[::-1]

def main():
    infix = InfixConverter()
    print(infix.to_postfix("(3+2)*5"))
    print(infix.to_postfix("3/4/5/6*2"))

main()

