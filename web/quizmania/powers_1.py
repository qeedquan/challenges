#!/usr/bin/env python3

"""

y^y = 4^1024

Find y

y = 256

"""

a = 4
b = 1024
while a < b:
    a = a**2
    b = b//2

print(a, b)
