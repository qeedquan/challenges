#!/usr/bin/env python3

"""

Vasya has a younger brother, Petya, who is in first grade, and a sister, Tanya, who is in kindergarten.
Tanya has just started learning about numbers and asked Petya to play a numbers game with her.
Petya, who has learned a bit about computers from Vasya, asked him to write a special program for their number game.

Vasya decided to take up the challenge and wrote a program to compare non-negative numbers, not only in decimal, but in numeral systems of arbitrary base.

Input
The first line contains a single positive integer — the base of the numeral system, not exceeding 16.

The second line contains the first number to be compared. The length of this line does not exceed 50 characters.

The third line contains the second number to be compared. The length of this line also does not exceed 50 characters.

In numeral systems with a base greater than 10, digits greater than 9 are represented by uppercase Latin letters from A (10) to F (15).
The numbers are guaranteed to be valid and to contain no leading zeros (i.e., a value equal to zero is given as the single character 0).

Output
Print the maximum of the two given numbers (in the same numeral system as provided).

Examples
Input #1
10
10
5

Answer #1
10

"""

def solve(base, value1, value2):
    number1 = int(value1, base)
    number2 = int(value2, base)
    if number1 > number2:
        return value1
    return value2

def main():
    assert(solve(10, "10", "5") == "10")

main()
