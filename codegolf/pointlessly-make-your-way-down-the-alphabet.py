#!/usr/bin/env python3

"""

Disclaimer: This challenge inspired by me spending the morning debugging recursive functions, which have been frying my brain a little.

Here's an example of recursion, from a letter, we keep going to the previous letter of the alphabet, printing out each one as we go, until we hit the letter a, then we print that and stop. We do this for each letter in a string and there's a pretty pattern at the end of it.

The task
Start with a string of characters
The input string may only contain the lower-case letters a-z and the space character.
For each letter, produce a line of text (terminal output or variable or whatever)
Print out the letter
Print out the previous letter (on the same line)
Print out the previous letter (on the same line)
Print out the previous letter (on the same line)
...
If the letter is 'a', print it out and move to the next line.
If it's a space, print out an empty line (or one just containing the space character.
The rules
It's golf, try and make your code short.
Any language you like.
Please include a link to an online interpreter.
The output should be human-readable (e.g. I can't work it out from a list of bytes.
Follow the rules of the standard loopholes ¯\_(ツ)_/¯
Recursion is not mandated by the rules, but it's probably necessary.

Test Cases
Input: 'abcdefghijklmnopqrstuvwxyz' Output:

a
ba
cba
dcba
edcba
fedcba
gfedcba
hgfedcba
ihgfedcba
jihgfedcba
kjihgfedcba
lkjihgfedcba
mlkjihgfedcba
nmlkjihgfedcba
onmlkjihgfedcba
ponmlkjihgfedcba
qponmlkjihgfedcba
rqponmlkjihgfedcba
srqponmlkjihgfedcba
tsrqponmlkjihgfedcba
utsrqponmlkjihgfedcba
vutsrqponmlkjihgfedcba
wvutsrqponmlkjihgfedcba
xwvutsrqponmlkjihgfedcba
yxwvutsrqponmlkjihgfedcba
zyxwvutsrqponmlkjihgfedcba

Input: 'zyxwvutsrqponmlkjihgfedcba'

zyxwvutsrqponmlkjihgfedcba
yxwvutsrqponmlkjihgfedcba
xwvutsrqponmlkjihgfedcba
wvutsrqponmlkjihgfedcba
vutsrqponmlkjihgfedcba
utsrqponmlkjihgfedcba
tsrqponmlkjihgfedcba
srqponmlkjihgfedcba
rqponmlkjihgfedcba
qponmlkjihgfedcba
ponmlkjihgfedcba
onmlkjihgfedcba
nmlkjihgfedcba
mlkjihgfedcba
lkjihgfedcba
kjihgfedcba
jihgfedcba
ihgfedcba
hgfedcba
gfedcba
fedcba
edcba
dcba
cba
ba
a

Input: 'hello world' Output:

hgfedcba
edcba
lkjihgfedcba
lkjihgfedcba
onmlkjihgfedcba

wvutsrqponmlkjihgfedcba
onmlkjihgfedcba
rqponmlkjihgfedcba
lkjihgfedcba
dcba

"""

def makeway(s):
    a = ord('a')
    z = ord('z')
    for t in s:
        c = ord(t)
        print(chr(c), end='')
        if a <= c and c <= z:
            for i in range(c-1, a-1, -1):
                print(chr(i), end='')
        print()
    print()

def main():
    makeway("abcdefghijklmnopqrstuvwxyz")
    makeway("zyxwvutsrqponmlkjihgfedcba")
    makeway("hello world")

main()
