#!/usr/bin/env python3

"""

This challenge is based on this Stackoverflow question.

With a positive number as input, output it as the sum of each digit multiplied by its power-of-10 representation.

Input
A number, as an integer, a string or a list of digits/characters.

The number will be strictly positive.
If you accept the number as a string or list, it will not start with a 0.
Output
A string representing a sum of each relevant base-10 digits, each multiplied by its respective base-10 power. A sum is represented as a + b.
You may use up to one space around each side of the + sign if you want. The operands are listed in descending order.

0 can never be a valid operand.
The + sign (surrounded or not by spaces) may not be the leading or trailing part.
Examples
Input       Output
12          10 + 2
         or 10+2
         or 10 +2
         or 10+ 2
9           9
123         100 + 20 + 3
10          10
101         100 + 1
Invalid outputs
2           1 + 1
10          10 + 0
1           0 + 1
12          + 10 + 2
12          10 + 2 +
12          2 + 10
This is code-golf so the shortest code in bytes wins!

"""

def expand(n):
    if n < 0:
        return ""
    if n == 0:
        return "0"

    s = ""
    p = 1
    while n != 0:
        v = n % 10
        if v != 0:
            s = "%d + %s" % (p*v, s)
        n //= 10
        p *= 10

    return s[:len(s)-3]

def main():
    assert(expand(12) == "10 + 2")
    assert(expand(9) == "9")
    assert(expand(123) == "100 + 20 + 3")
    assert(expand(10) == "10")
    assert(expand(101) == "100 + 1")

main()
