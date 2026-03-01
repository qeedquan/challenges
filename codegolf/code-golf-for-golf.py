#!/usr/bin/env python3

"""

My first code golf question post! Hope u like it ;-)

The task is simple. Write either an stdin-stdout program or a function. Input is a 2D array which contains only either characters or the integer 0. You are allowed to replace the integers with the character '0' or null instead in any language (kudos to @SuperStormer for suggesting the "any" part) if you think it makes the problem easier or allows for decreasing code length.

Each element of the array contains 0, '>', '<', '^', 'v', or 'x'. You play golf in the grid by starting at the indices (0,0), and then moving in the direction indicated by the arrows. There is always an arrow at (0,0). 0 is the no-op. The code stops when you get to 'x', the golf hole.

Each of the arrows that you encounter represents a stroke in golf. However, obviously not all arrows will be used. Your mission is to find how many strokes you did before you get to the hole.

TL;DR: Find the number of arrows in your path from (0,0) to 'x'.

Examples:

[['>',0,0,'v','<'],[0,'>','x','<',0]]

> 0 0 v <
0 > x < 0
gives 3.

[['v',0,'>','v',0,0,0],[0,0,0,'>','v',0,0],['>',0,'^',0,'v',0,0],['>',0,0,0,'x','<','<'],[0,0,0,0,0,0,'^']]

v 0 > v 0 0 0
0 0 0 > v 0 0
> 0 ^ 0 v 0 0
> 0 0 0 x < <
0 0 0 0 0 0 ^
gives 8.

You do not need to consider handling cases which do not correspond to the input requirements.

Example code: (Python 3.8, 149 bytes, and yeah I'm so noob...)

def f(g):
    x=y=r=0
    while 1:
        if(n:=g[x][y])=='x':return r
        if n:a,b=(0,1)if n=='>'else(0,-1)if n=='<'else(-1,0)if n=='^'else(1,0);r+=1
        x+=a;y+=b
Have fun golfing!

Additional note: Changing the input values to things like "12345" is allowed if you are able to take advantage of language features by doing so. However you must mark your answer and the input code you used if you choose to do so ;-)

Additional additional note: Thanks to Unrelated String for this. "The next stroke taken is always the closest in the direction".

"""

def traverse(m):
    x = y = r = 0
    a = b = 0
    while True:
        c = m[x][y]
        if c == 'x':
            break

        if c != 0:
            if c == '>':
                a, b = 0, 1
            elif c == '<':
                a, b = 0, -1
            elif c == '^':
                a, b = -1, 0
            else:
                a, b = 1, 0
            r += 1

        if a == 0 and b == 0:
            return -1

        x += a
        y += b
    return r

def main():
    assert(traverse([['>', 0, 0, 'v', '<'], [0, '>', 'x', '<', 0]]) == 3)
    assert(traverse([['v', 0, '>', 'v', 0, 0, 0], [0, 0, 0, '>', 'v', 0, 0], ['>', 0, '^', 0, 'v', 0, 0], ['>', 0, 0, 0, 'x', '<', '<'], [0, 0, 0, 0, 0, 0, '^']]) == 8)

main()
