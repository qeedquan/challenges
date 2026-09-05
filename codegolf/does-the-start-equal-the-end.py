#!/usr/bin/env python3

"""

The Task
In this challenge, your task is to write a program or function which takes in a String and outputs a truthy or falsey value based on whether the first character and the last character of the input String are equal.

Input
You may take input in any way reasonable way. However, assuming that the input is present in a predefined variable is not allowed. Reading from a file, console, command line, input field etc., or taking input as a function argument is allowed.

Output
You may output in any reasonable format, except for assigning the result to a variable. Writing to a file, console, command line, modal box, function return statements etc. is allowed.

Additional Rules
The input can be empty String as well, for which you should return a falsey value.

Single-Char Input Strings should have a truthy result.

Your program should be case-sensitive. helloH should output a falsey value.

You can only have a single Truthy value and a single Falsey value. For example, outputting false for an Input String and 0 for another input String as Falsey values is not allowed.

Standard loopholes are not allowed.

Test Cases
Input    ->    Output

"10h01"        Truthy
"Nothing"      Falsey
"Acccca"       Falsey
"eraser"       Falsey
"erase"        Truthy
"wow!"         Falsey
"wow"          Truthy
"H"            Truthy
""             Falsey

This is code-golf, so the shortest code in bytes wins!

"""

def startend(s):
    if len(s) == 0:
        return False
    return s[0] == s[-1]

def main():
    assert(startend("10h01") == True)
    assert(startend("Nothing") == False)
    assert(startend("Acccca") == False)
    assert(startend("eraser") == False)
    assert(startend("erase") == True)
    assert(startend("wow!") == False)
    assert(startend("wow") == True)
    assert(startend("H") == True)
    assert(startend("") == False)

main()
