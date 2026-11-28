#!/usr/bin/env python3

"""

For the given string s, generate generate a table like below.

Input:abcd
Output:
abcd
bbcd
cccd
dddd

Input:Hello, world!
Output:
Hello, world!
eello, world!
llllo, world!
llllo, world!
ooooo, world!
,,,,,, world!
       world!
wwwwwwwworld!
ooooooooorld!
rrrrrrrrrrld!
llllllllllld!
dddddddddddd!
!!!!!!!!!!!!!
Trailing whitespace allowed.
This is a code-golf challenge so the shortest solution wins.

"""

def table(s):
    for i in range(len(s)):
        print(s[i]*i + s[i:])
    print()

def main():
    table("abcd")
    table("Hello, world!")
    table("ABCDEFGHIJKLMNOPQRSTUVWXYZ")

main()
