#!/usr/bin/env python3

"""

In this challenge, you are required to shift characters in an inputted string n number of times and output the shifted string

Input
Input will first contain a string. In the next line, an integer, which denotes n will be present.

Output
If n is positive, shift the characters in the string to the right n times.
If n is negative, shift the characters in the string to the left n times.
If n is zero, don't shift the characters in the string.
After shifting (except when n is zero), print the shifted string.

Notes
The string will not be empty or null.
The string will not be longer than 100 characters and will only contain ASCII characters in range (space) to ~(tilde) (character codes 0x20 to 0x7E, inclusive). See ASCII table for reference.
The shift is cyclic.
The number n may be positive, negative, or zero.
n will always be greater than or equal to -1000 and lesser than or equal to 1000
You may take input via stdin or from command line arguments
The shifted string must be outputted in the stdout (or closest equivalent)
You may write a full program or a function which takes input and outputs the string in stdout or closest equivalent
Test Cases
1)

Hello world!
5             -->orld!Hello w
2)

Testing...
-3            -->ting...Tes
3)

~~~
1000          -->~~~
4)

12345
0             -->12345
5)

ABA
17            -->BAA
Scoring
This is code-golf, so the shortest submission (in bytes) wins.

"""

def rot(s, n):
    if len(s) == 0:
        return ""

    i = -n % len(s)
    return s[i:] + s[:i]

def main():
    assert(rot("Hello world!", 5) == "orld!Hello w")
    assert(rot("Testing...", -3) == "ting...Tes")
    assert(rot("~~~", 1000) == "~~~")
    assert(rot("12345", 0) == "12345")
    assert(rot("ABA", 17) == "BAA")

main()
