#!/usr/bin/env python3

"""

Cat and dog together weigh a kg, dog and hare weigh b kg, cat and hare weigh c kg. What is the weight of cat, dog and hare separately?

Input
One line contains three integers a, b, c.

Output
Print three numbers - the weight of cat, dog and hare with 2 decimal digits.

Examples

Input #1
4 5 3

Answer #1
1.00 3.00 2.00

"""

def solve(a, b, c):
    x = (a - b + c) / 2
    y = a - x
    z = b - y
    return (x, y, z)

def main():
    print(solve(4, 5, 3))

main()
