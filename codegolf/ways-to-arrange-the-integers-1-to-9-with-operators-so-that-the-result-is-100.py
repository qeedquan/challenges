#!/usr/bin/env python3

"""

Prelude:
This task is taken from Five Problems Every Software Engineer Should Be Able to Solve in Less Than an Hour, which I really recommend.
https://gist.github.com/agrison/1a27a50c22a7f46df17c

The task:
Write a program that outputs all possibilities to put + or - or nothing between the numbers 1, 2, ..., 9 (in this order) such that the result is always 100.

Winning Criteria:
Shortest code in bytes wins.

"""

def recurse(expr, value, target):
    if value <= 9:
        for op in ("+", "-", ""):
            recurse(expr + op + str(value), value + 1, target)
    if eval(expr) == target:
        print(expr)

def solve(target):
    recurse("1", 2, target)

def main():
    solve(100)

main()
