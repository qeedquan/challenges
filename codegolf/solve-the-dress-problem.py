#!/usr/bin/env python3

"""

Background
Peter's Father, the Teacher of a dance-club, asks Peter a question:
Given are two natural numbers (N x and y).

x is the number of the garment types (e.g. shorts, shirts…) we have y is number of colors (e.g. green, blue, …) of each garment we have.

In the dance class, every one should be in a unique dress.

Example:

https://i.stack.imgur.com/p0CEq.png

But:

https://i.stack.imgur.com/0ZLAB.png

Now tell me: For every given x and y, what is the maximum number of people who an visit our class?
Can you help Peter?

Challenge
The input should be two natural numbers (∀x,y∈N) separated by a comma,. The input can also be your languages equivalent for a list which has two elements.

The Output should be an Integer, the maximum number of people who can visit the dance-class.

Test cases
In:1,0
Out:0

In:0,0
Out:0

In:[2,2]
Out:4

In:3,2
Out:9

Rules
This is code-golf so the shortest code wins

"""

def people(x, y):
    if x < 1 or y < 1:
        return 0
    return x**y

def main():
    assert(people(1, 0) == 0)
    assert(people(0, 0) == 0)
    assert(people(2, 2) == 4)
    assert(people(3, 2) == 9)
    assert(people(2, 3) == 8)

main()
