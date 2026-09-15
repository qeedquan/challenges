#!/usr/bin/env python3

"""

The program takes a natural number n and a piece of text, such as a String.
Your task is to display this text as n lines, each prefixed with the marker "-", as demonstrated in the test case.

Input
The first line contains a natural number n, and the second line contains text made up of Latin letters.

Output
Display this text as n lines of a list with each item prefixed by a dash "-" marker, as in the example.

Examples

Input #1
4
String

Answer #1
- String
- String
- String
- String

"""

def solve(n, s):
    for i in range(n):
        print(f"- {s}")

def main():
    solve(4, "String")

main()
