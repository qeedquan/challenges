#!/usr/bin/env python3

"""

In chess, fork means to target two pieces with just one piece, and one of the best pieces for forking is the knight.

In this challenge, you will be given three coordinates in a to h and 1 to 8 (like a8 or e7) format. The first and second coordinates are for two other random pieces, and the third is the knight's coordinate. You must return or output the coordinate where the knight can move to create a fork, attacking both pieces. An example is this:

https://i.sstatic.net/jRBoc.png

Here, the first and second inputs will be d6 and f6 and the third (knight) will be g3. You must return e4, where the knight can attack both rooks.

Testcases
Input: d6,f6,g3 | Output:e4
Input: d4,d6,e7 | Output:f5
Input: c3,f2,b2 | Output:d1

Notes
You may assume it is possible to find a fork with the given input.
This is code-golf so the shortest code wins!

"""

"""

@tsh

For given three points (x1,y1), (x2,y2), (x3,y3), find the center of the circle determined by these three points.

https://math.stackexchange.com/questions/213658/get-the-equation-of-a-circle-when-given-3-points/

"""

def knightfork(s):
    s = s.replace(",", "", -1)
    if len(s) != 6:
        return "invalid"

    x, p, y, q, z, r = map(ord, s)
    x, y = x - z, y - z
    p, q = p - r, q - r
    u = x*x + p*p
    v = y*y + q*q
    w = x*q - (y*p)<<1
    return chr((u*q - v*p)//w + z) + chr((v*x - u*y)//w + r)

def main():
    assert(knightfork("d6,f6,g3") == "e4")
    assert(knightfork("d4,d6,e7") == "f5")
    assert(knightfork("c3,f2,b2") == "d1")

main()
