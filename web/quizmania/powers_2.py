#!/usr/bin/env python3

"""

x^x = 3^324

Find x

x = 81

"""

a = 3
b = 324
while a < b:
    a = a**2
    b = b//2

print(a, b)
