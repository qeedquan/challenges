#!/usr/bin/env python3

"""

Given a positive integer n, output a number meter formatted like this:

                  0 1 2 3 4 5 6 7 8 9 0
1 2 3 4 5 6 7 8 9 1 1 1 1 1 1 1 1 1 1 2
The input number is 20 in this example.

More formally, the decimal representations of the numbers are arranged vertically, from most significant digits on the last row to least significant digits at the top, using space-padding.

All numbers should be printed, and any size of number is allowed.

An example solution in Python 3 follows:

def meter(top: int):
    initial = list(str(str(n).ljust(len(str(top + 1)))) for n in range(1, top + 1))
    rotated = list(zip(*initial))[::-1]

    return "\n".join(" ".join(n) for n in rotated)

This is Code Golf! Make the answer with the lowest bytes to win.

"""

def meter(top):
    initial = list(str(str(n).ljust(len(str(top + 1)))) for n in range(1, top + 1))
    rotated = list(zip(*initial))[::-1]
    return "\n".join(" ".join(n) for n in rotated)

def main():
    print(meter(20))

main()
