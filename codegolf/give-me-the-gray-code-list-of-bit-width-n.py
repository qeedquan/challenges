#!/usr/bin/env python3

"""

You can count 0, 1, 2, 3, 4. But to get from 3 to 4 you have to change 3 bits at once. Given a number of bits, how can you go through all numbers once, but change at each step only 1! bit.

Here is an example for 3 bits:

000 100 110 010 011 111 101 001

so the output is:

0 1 3 2 6 7 5 4

Rules:
given a number of bits n, return a list of 2^n unique numbers
between to consecutive numbers only one bit is different
the shorter the code the better

"""

def gen(n):
    print("n=%d" %(n))
    for i in range(2**n):
        print(bin(2**n + (i//2 ^ i))[3:])
    print()

def main():
    for i in range(5):
        gen(i)

main()
