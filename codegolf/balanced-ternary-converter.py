#!/usr/bin/env python3

"""

Credits for the challenge idea go to @AndrewPiliser. His original proposal in the sandbox was abandoned and since he has not been active here for several months, I have taken over the challenge.

Balanced ternary is a non-standard numeral system. It is like ternary in that the digits increase in value by a factor of 3 as you go further to the left - so 100 is 9 and 1001 is 28.

However, instead of having values of 0, 1 and 2, the digits have values of -1, 0, and 1. (You can still use this to express any integer.)

For this challenge, the digit meaning +1 will be written as +, -1 will be written as -, and 0 is just 0. Balanced ternary does not use the - symbol in front of numbers to negate them like other numeral systems do - see examples.

Your task is to write a complete program which takes a 32-bit decimal signed integer as input and converts it to balanced ternary. No built-in base conversion functions of any sort are allowed (Mathematica probably has one...). Input can be on standard input, command-line arguments, etc.

Leading zeroes may be present in input but not in output, unless the input is 0, in which case the output should also be 0.

Examples
These are conversions from balanced ternary to decimal; you will have to convert the other way.

+0- = 1*3^2 + 0*3^1 + -1*3^0 = 9 + 0 + -1 = 8
+-0+ = 1*3^3 + -1*3^2 + 0*3^1 + 1*3^0 = 27 + -9 + 0 + 1 = 19
-+++ = -1*3^3 + 1*3^2 + 1*3^1 + 1*3^0 = -27 + 9 + 3 + 1 = -14

"""

"""

@xnor

Generates the balanced ternary digit-by-digit from the end. The last digit is given by the residue n%3 being -1,0, or +1. We then remove the last digit and divide by 3 using Python's floor-divide n=(n+1)/3. Then, we proceed recursively with the new last digit until the number is 0.

A special case is needed for the input 0 to give 0 rather than the empty string.

"""
def bin2bte(n):
    ch = "0+-"
    s = ""
    while n != 0:
        s = ch[n % 3] + s
        n = (n + 1) // 3
    if s == "":
        s = "0"
    return s

def main():
    assert(bin2bte(8) == "+0-")
    assert(bin2bte(19) == "+-0+")
    assert(bin2bte(-14) == "-+++")
    assert(bin2bte(-49835) == "-0+++-0-+-+")
    assert(bin2bte(-1) == "-")
    assert(bin2bte(1) == "+")
    assert(bin2bte(0) == "0")

main()
