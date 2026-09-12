#!/usr/bin/env python3

"""

In the processing of radioactive materials, two types of waste are produced: highly hazardous (type A) and safe (type B).
Both types are stored in identical containers, which are then stacked vertically.
A stack becomes explosive if it includes more than one consecutive container of type A.
Given a total of N containers, calculate the number of possible configurations for safe stacks.

Input
The first line contains the number N (1≤N≤1000).

Output
Output a single integer representing the number of safe stack configurations.

Examples

Input #1
3

Answer #1
5

"""

from sympy import fibonacci

def solve(n):
    return fibonacci(n + 2)

def main():
    assert(solve(3) == 5)

main()
