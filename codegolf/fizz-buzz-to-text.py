#!/usr/bin/env python3

"""

Introduction
I don't particularly know where the fizz buzz trend came from. It might just be a meme or something, but it is somewhat popular.

Challenge
Your job today is to convert Fizz Buzz into binary (0, 1) respectively, and convert that binary to text. Pretty standard stuff.

How does that work?
FizzBuzzBuzzFizzBuzzFizzFizzFizz FizzBuzzBuzzFizzBuzzFizzFizzBuzz would translate into 01101000 01101001 then that would translate into "hi"

Constraints
Input is Fizz Buzz in a binary standpoint (see examples below.)
Output must be text.
You can assume the FizzBuzz input is right.
This is code-golf, shortest bytes win.

Input
FizzBuzzBuzzFizzBuzzFizzFizzFizz FizzBuzzBuzzFizzBuzzFizzFizzBuzz FizzFizzBuzzFizzFizzFizzFizzBuzz

"""

def text(s):
    n = len(s)
    if n == 0:
        return ""

    r = ""
    c = 0
    i = 0
    while i < n:
        if s[i] == ' ':
            i, r, c = i + 1, r + chr(c), 0
        elif s[i:].startswith("Fizz"):
            i, c = i + 4, (c << 1)
        elif s[i:].startswith("Buzz"):
            i, c = i + 4, (c << 1) | 1
        else:
            return None
    return r + chr(c)

def main():
    assert(text("FizzBuzzBuzzFizzBuzzFizzFizzFizz FizzBuzzBuzzFizzBuzzFizzFizzBuzz FizzFizzBuzzFizzFizzFizzFizzBuzz") == "hi!")

main()
