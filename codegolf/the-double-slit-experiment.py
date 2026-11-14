#!/usr/bin/env python3

"""

A lazy physicist has the job to perform the double slit experiment. However, they are lazy and can't be bothered to set up all the equipment themselves and so are going to simulate the effects. They can't program though so are going to need some help. As they are lazy your program should be as short as possible.

Given an odd positive integer n (n >= 1 and n % 2 == 1), perform the simulation.

How it works

You will start off with an empty canvas and each frame a single particle of light will go through the slits and land on the canvas. The particle will land at a maxima with a chance of:

n = 1:

+-----+
|     |
| 1/2 |
|     |
+-----+
n = 3:

+-----+ +-----+ +-----+
|     | |     | |     |
| 1/4 | | 1/2 | | 1/4 |
|     | |     | |     |
+-----+ +-----+ +-----+
n = 5:

+-----+ +-----+ +-----+ +-----+ +-----+
|     | |     | |     | |     | |     |
| 1/8 | | 1/4 | | 1/2 | | 1/4 | | 1/8 |
|     | |     | |     | |     | |     |
+-----+ +-----+ +-----+ +-----+ +-----+
etc.

For example for n=5 we check the middle box, there's a 50% chance of falling in it. If it falls end of frame, if not move to the next two, there's a 25% chance of falling in those. If it falls end of frame, if not move to the next two, there's a 12.5% chance of falling in those. If it doesn't fall it doesn't matter, it's still the end of the frame.

There has been some confusion over how to calculate the chances, most of this is due to people thinking of them as probabilities that should add up to 1. Remove that idea from your mind and it should clear it up a bit for you.

At most one particle will lad per frame, this means a particle may not land at all on that frame.
A particle can be represented by any printable character.
The particle will land anywhere in the box with a random chance.
The width of the boxes should be 2n-1 the size of the canvas. So for n=5 they should be 1/9th of the canvas's width.
The height of the boxes should be the height of the canvas.
The particle should not land outside of the boxes at all.
If a particle has already landed at a spot that is chosen that doesn't matter it can land there again.
The above ascii boxes are for clarity, they should not be drawn.
You may choose your own canvas size as long as it is reasonable. For example, it mustn't just be a few pixels high. It also should be able to fit all of the boxes on it.
If your code sleeps between frames you do not need to add that into your byte count.
There should be gaps between each of the maxima, a minima. This should be the same width as a box but no particles will land there. See the following diagram:

+---+---+---+---+---+
|   |   |   |   |   |
|max|min|max|min|max|
|   |   |   |   |   |
+---+---+---+---+---+
The program should run until it is stopped manually.

Rules

A pseudo random number generator (pRNG) is fine.
Standard loopholes are forbidden.
Input may be taken by any reasonable format.
You should output to STDOUT.
This is code-golf so the shortest answer wins.
Example

The following GIF is an example run for n = 5. I only knocked it up quickly so the chances may be off slightly.
https://i.sstatic.net/MlQCN.gif

"""

import curses
import random
import time
import sys

def main():
    if len(sys.argv) != 2:
        print("usage: <slits>")
        exit(1)

    count = int(sys.argv[1])
    screen = curses.initscr()
    height, width = screen.getmaxyx()
    spacing = width // (2*count - 1)
    while True:
        for index in range(count//2 + 1):
            if random.randint(0, 1):
                direction = 2 - 4*random.randint(0, 1)
                x = (index*direction + count)*spacing - random.randint(1, spacing)
                y = random.randint(0, height - 1)
                screen.addch(y, int(x), "*")

        screen.refresh()
        time.sleep(0.1)

main()
