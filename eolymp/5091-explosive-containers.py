#!/usr/bin/env python3

"""

All containers in the world fall into two categories — with TNT and without.

Only a fool would place a TNT box on top of another TNT box. Since you're clearly not one of them (right?), you know very well that TNT explodes, especially if another TNT box is placed on top of it.

You find yourself in a room filled with a vast number of boxes of both types. Suddenly, a lift emerges from a hatch in the floor. Unfortunately, it is malfunctioning. It has decided to build a tower of n boxes. To assess your chances of survival, you need to calculate the number of possible configurations in which nothing explodes.

By the way, think about it: what is a rational person like you doing in a room full of TNT?

Input
One integer n (1≤n<45).

Output
Print the number of safe ways to build the tower.

Examples

Input #1
1

Answer #1
2

Input #2
2

Answer #2
3

"""

from sympy import fibonacci

def solve(n):
    return fibonacci(n + 2)

def main():
    assert(solve(1) == 2)
    assert(solve(2) == 3)

main()
