#!/usr/bin/env python3

"""

Introduction
In this challenge you will be solving diagonal Burrows-Wheeler transforms. Here is a general overview of what a diagonal Burrows-Wheeler transform is. To encode a message, you first must guarantee that it is odd in length (i.e. 5, 7, 9, etc.). Then you make a grid, n by n, where n is the length of the message. The first row is the original message. Each row after that is the row above it, but shifted 1 character left with the first character moving to the back. For example:

Hello World
ello WorldH
llo WorldHe
lo WorldHel
o WorldHell
 WorldHello
WorldHello
orldHello W
rldHello Wo
ldHello Wor
dHello Worl
Then you take each letter on the NW to SE diagonal and put that into a new string:

Hello World  H
ello WorldH  l
llo WorldHe  o
lo WorldHel  W
o WorldHell  r
 WorldHello  d
WorldHello   e
orldHello W  l
rldHello Wo  (space)
ldHello Wor  o
dHello Worl  l
Your encoded message is HloWrdel ol. To decode, first take the length of the encoded message, add 1, and divide by 2. Lets call this number x. Now that we know x, starting at the first letter, each letter is x after the last, looping around. For example:

H   l   o   W   r   d   e   l     o   l
1

Then...

H   l   o   W   r   d   e   l     o   l
1                       2

And again...

H   l   o   W   r   d   e   l     o   l
1   3                   2

Until you get...

H   l   o   W   r   d   e   l       o   l
1   3   5   7   9  11   2   4   6   8  10
Now just rearrange the letters in the correct order to get Hello World!

Challenge
Your challenge is to write either two programs, functions, or one of each. However, both must use the same language. The first program will accept a string as input via STDIN, program arguments, or function parameters and encode it using this method. The second program will accept a string as input via STDIN, program arguments, or function parameters and decode it using this method.

Requirements
First Program/Function
A single string input using any method listed above.
Must encode the string using a diagonal Burrows-Wheeler transform style.
Second Program/Function
A single string input using any method listed above.
Must decode the string using a diagonal Burrows-Wheeler transform style.

Constraints
You cannot use any built-in or external functions that accomplish this task.
Standard loopholes are not allowed.
Both programs/functions must be in the same language.

Scoring
This is code golf, so shortest program in bytes wins.

If I need to add more information, leave a comment!

"""

def encode(s):
    return (s + s)[::2]

def decode(s):
    n = len(s)
    return (-~n//2 * s)[::n//2 + 1]

def test(s):
    x = encode(s)
    y = decode(x)
    assert(s == y)

def main():
    test("hello")
    test("abcdefghi")
    test("xyz fjx")
    test("12345")

main()
