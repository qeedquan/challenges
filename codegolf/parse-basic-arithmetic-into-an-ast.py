#!/usr/bin/env python3

"""

Introduction
An abstract syntax tree (AST) is a tree of tokens that shows their connection to each other and syntactical meaning. They are commonly used in compilers and static analysis tools, as parsing a language into an AST helps remove any ambiguity and can be helpful for optimizations. Many ASTs are large and complex, but in this thread, your task is to create a basic parser to convert an arithmetic expression into a basic AST.

Challenge
The main part of this challenge is resolving the order of operations. In this challenge, assume PEMDAS so that multiplication is before division and addition is before subtraction. Also, assume left associativity. Every node in the tree should either be an operator or a number. Operators with other operators as children resolve their children first, so nodes at the bottom of the tree resolve first. Number nodes should have no children. Your solution may assume the input is valid, all numbers are positive, and that the input contains no parentheses (unless you'd like to add support for fun).

The input will be a string with only the characters 0123456789+-*/ (and optionally ()). Your program/function may return nested objects/dictionaries, nested arrays/lists, or even a built-in data structure; as long as your output can be interpreted as a tree you're OK (note: if you are going to abuse this rule by using weird formats, then explain how it represents a tree).

Test cases
1+2+3*5-7 -> ['-', ['+', ['+', 1, 2], ['*', 3, 5]], 7], where the first element of the array is the operator, and the second and third are the children.

13*7+9-4+1 -> {op: '-', left: {op: '+', left: {op: '*', left: 13, right: 7}, right: 9}, right: {op: '+', left: 4, right: 1}}

8/2*6+4-1 -> ['-', ['+', ['/', 8, ['*', 2, 6]], 4], 1]

This is code-golf, so the shortest code wins!

"""

import ast

def parse(expr):
    tree = ast.parse(expr)
    print(ast.dump(tree, indent=2))
    print()

def main():
    parse("1+2+3*5-7")
    parse("13*7+9-4+1")
    parse("8/2*6+4-1")

main()
