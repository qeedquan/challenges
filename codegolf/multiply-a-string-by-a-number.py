#!/usr/bin/env python3

"""

There was a challenge up a while ago about multiplying strings. It showed us how we can multiply not only numbers, but also strings. However, we still can't multiply a number by a string properly. There has been one attempt to do so but this is obviously wrong. We need to fix that!

Your Task:
Write a function or program that multiplies two inputs, a string and an integer. To (properly) multiply an string by an integer, you split the string into characters, repeat each character a number of times equal to the integer, and then stick the characters back together. If the integer is negative, we use its absolute value in the first step, and then reverse the string. If the input is 0, output nothing (anything multiplied by 0 equals nothing).

Input:
A string that consists solely of printable ASCII characters and newlines, and an integer (possible negative).

Output:
The string multiplied by the integer.

Examples:
Hello World!, 3            --> HHHeeellllllooo   WWWooorrrlllddd!!!
foo, 12                    --> ffffffffffffoooooooooooooooooooooooo
String, -3                 --> gggnnniiirrrtttSSS
This is a fun challenge, 0 -->
Hello
World!, 2                  --> HHeelllloo

                               WWoorrlldd!!
Scoring:
This is code-golf, lowest byte count wins!

"""

def muls(s, n):
    f = 0
    if n < 0:
        f, n = 1, abs(n)

    r = ""
    for c in s:
        r += c * n
    
    if f != 0:
        r = r[::-1]

    return r

def main():
    assert(muls("Hello World!", 3) == "HHHeeellllllooo   WWWooorrrlllddd!!!")
    assert(muls("foo", 12) == "ffffffffffffoooooooooooooooooooooooo")
    assert(muls("String", -3) == "gggnnniiirrrtttSSS")
    assert(muls("This is a fun challenge", 0) == "")
    assert(muls("Hello\nWorld!", 2) == "HHeelllloo\n\nWWoorrlldd!!")

main()
