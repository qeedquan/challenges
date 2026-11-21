#!/usr/bin/env python3

"""

The drone is located on the XY coordinate plane and starts its movement from the point (0,0).
Every second, it moves one unit along either the X or Y axis.
Movement is possible in both directions along each axis.
After executing all movement commands, the drone explodes at the end of its path.
Determine the coordinates at which the drone explodes.

On the X axis, forward movement is indicated by ">", and backward movement is indicated by "<".

On the Y axis, forward movement is indicated by "^", and backward movement is indicated by "v".

Input
The first line contains one integer t (1≤t≤100) — the number of test cases.

Each of the following t lines contains a string s (1≤∣s∣≤1000) indicating the movement of the drone. Here, ∣s∣ denotes the length of the string s.

Output
For each test case, print on a separate line two integers — the X and Y coordinates of the drone explosion.

Examples

Input #1
2
>>^
>>^^v<

Answer #1
2 1
1 1

"""

def solve(s):
    x = y = 0
    for c in s:
        if c == '>':
            x += 1
        elif c == '<':
            x -= 1
        elif c == '^':
            y += 1
        elif c == 'v':
            y -= 1
    return (x, y)

def main():
    assert(solve(">>^") == (2, 1))
    assert(solve(">>^^v<") == (1, 1))

main()

