#!/usr/bin/env python3

"""

Many people know what a truth machine in programming is. But is time we kick things up a notch.
Introducing, the extended truth machine! An extended truth machine takes two things as input, a integer n and a nonempty string s.
It outputs s n times with optional trailing whitespace. However, if n is equal to 0, you must output s until the program is manually stopped i.e. it should never terminate.

Also, if n is a negative number, then the string needs to be reversed. For example with s=hello and n=-1, output would be olleh.

Standard methods of input, any kind of output as long as it can handle infinite. If you have an answer that does not handle infinite, feel free to post it if it is interesting or in a language that cannot handle infinite output.

Test Cases
n, s, output

5, "hello world", "hello worldhello worldhello worldhello worldhello world"
0, "PPCG", "PPCGPPCGPPCGPPCG..."
-2, "truThY", "YhTurtYhTurt"
2000, "o", "oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"

This is code-golf, so shortest code wins!

Here is the original Sandbox post. Edits have been made to it. Thanks go to @ComradeSparklePony for creating the idea of this challenge

"""

def extruth(n, s):
    i, j = 0, 1
    if n < 0:
        n, s = -n, s[::-1]
    elif n == 0:
        n, j = 1, 0
    
    while i < n:
        print(s, end='')
        i += j
    print()

def main():
    extruth(5, "hello world")
    extruth(-2, "truThY")
    extruth(2000, "o")
    extruth(0, "PPCG")

main()
