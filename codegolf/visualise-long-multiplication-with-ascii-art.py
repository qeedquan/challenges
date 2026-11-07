#!/usr/bin/env python3

"""

The challenge
Write a program that takes two integers from standard input, separated by a comma, and then prints a visualisation of long multiplication of those two integers to standard output.

Eg:

Input

14, 11
Program output

     14
    x11
   _____
     14
    14
  ______
    154
Input

-7, 20
Program output

     -7
    x20
   _____
     00
    14
   _____
   -140
Assume always correct inputs and numbers in the range [-999, 999]

Winning criteria
Shortest code wins!

"""

def vis(a, b):
    sep = "-" * 6
    
    p = []
    for d in str(b)[::-1]:
        p.append(f"{a * int(d):6d}")
    print(f"{a:6d}")
    print(f"x{b:5d}")
    print(sep)
    print("\n".join(p))
    print(sep)
    print(f"{a * b:6d}")
    print()

def main():
    vis(14, 11)
    vis(-7, 20)
    vis(999, 999)

main()
