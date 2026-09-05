#!/usr/bin/env python3

"""

You have a string of numbers; starting with the third number each number is the result of an operation performed using the previous two numbers.

Complete the function which returns a string of the operations in order and separated by a comma and a space, e.g. "subtraction, subtraction, addition"

The available operations are (in this order of preference):

1) addition
2) subtraction
3) multiplication
4) division

Notes:

All input data is valid
The number of numbers in the input string >= 3
For a case like "2 2 4" - when multiple variants are possible - choose the first possible operation from the list (in this case "addition")
Integer division should be used

Example
"9 4 5 20 25"  -->  "subtraction, multiplication, addition"

Because:

9 - 4 = 5   --> subtraction
4 * 5 = 20  --> multiplication
5 + 20 = 25 --> addition

"""

def operations(s):
    r = ""
    t = s.split(' ')
    for i in range(2, len(t)):
        x = int(t[i - 1])
        y = int(t[i - 2])
        z = int(t[i])
        if x+y == z:
            r += "addition, "
        elif x-y == z or y-x == z:
            r += "subtraction, "
        elif x*y == z:
            r += "multiplication, "
        elif y > 0 and x//y == z or x > 0 and y//x == z:
            r += "division, "
        else:
            r += "unknown, "
    r = r.strip(", ")
    return r

def main():
    assert(operations("9 4 5 20 25") == "subtraction, multiplication, addition")

main()
