#!/usr/bin/env python3

"""

Task:
There are a lot of answers on this site that are arranged into ascii art, like this one. Usually the arrangement is done manually, but wouldn't a program help with that? :)

Your program will take 3 inputs:

The code, as one single line
The number of lines in the pattern (can be omitted if not necessary)
The pattern itself, as *s or another char
Rules:
You have to write a program (not a function) that reads from stdin
The text is placed left-to-right per line
If there is not enough text to fill the pattern, put .s in the remaining spaces
If there is too much text to fill the pattern, print it out after the output
code-golf, so the shortest code, in bytes wins
Sample Runs:
Input (Exact Fit test):

qwertyuiopasdfghjklzxcvbnm
4
***** * ***
*   * * *
*   * * *
***** * ***
Output:

qwert y uio
p   a s d
f   g h j
klzxc v bnm
Input (Extra characters test):

qwertyuiopasdfghjklzxcvbnm12345
4
***** * ***
*   * * *
*   * * *
***** * ***
Output:

qwert y uio
p   a s d
f   g h j
klzxc v bnm
12345
Input (Insufficient Characters test):

qwertyuiopasdfg
4
***** * ***
*   * * *
*   * * *
***** * ***
Output:

qwert y uio
p   a s d
f   g . .
..... . ...

"""

def output(letters, lines):
    for line in lines:
        for char in line:
            if char == "*" and letters:
                print(letters[0], end='')
                letters = letters[1:]
            else:
                print(char, end='')
        print()
    print("".join(letters))

def main():
    output("qwertyuiopasdfghjklzxcvbnm", ["***** * ***", "*   * * *", "*   * * *", "***** * ***"])
    output("qwertyuiopasdfghjklzxcvbnm12345", ["***** * ***", "*   * * *", "*   * * *", "***** * ***"])
    output("qwertyuiopasdfg", ["***** * ***", "*   * * *", "*   * * *", "***** * ***"])

main()
