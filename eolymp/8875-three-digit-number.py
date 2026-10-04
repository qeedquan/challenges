#!/usr/bin/env python3

"""

The program should read an integer N from the console. It should output Ok if N is a three-digit number, and No otherwise.

Input
A single integer.

Output
Output Ok if the number N is a three-digit number; otherwise output No.

Examples

Input #1
123

Answer #1
Ok

Input #2
-27

Answer #2
No

"""

def solve(n):
    s = str(abs(n))
    if len(s) == 3:
        return "Ok"
    return "No"

def main():
    assert(solve(123) == "Ok")
    assert(solve(-27) == "No")

main()
