#!/usr/bin/env python3

r"""

"The Shell Game" involves cups upturned on a playing surface, with a ball placed underneath one of them. The index of the cups are swapped around multiple times. After that the players will try to find which cup contains the ball.

Your task is as follows. Given the cup that the ball starts under, and list of swaps, return the location of the ball at the end. Cups are given like array/list indices.

For example, given the starting position 0 and the swaps [(0, 1), (1, 2), (1, 0)]:

The first swap moves the ball from 0 to 1
The second swap moves the ball from 1 to 2
The final swap doesn't affect the position of the ball.
So

(start = 0 ; swaps = [(0, 1), (2, 1), (0, 1)] ) --> 2
There will always be at least two cups. You can assume all swaps are valid, and involve two distinct indices.

"""

def findball(ball, swaps):
    cups = 1 << ball
    for i, j in swaps:
        bit0 = 1 << i
        bit1 = 1 << j

        val0 = 0
        val1 = 0
        if cups & bit0:
            val1 = bit1
            ball = j
        if cups & bit1:
            val0 = bit0
            ball = i
        
        cups &= ~(bit0 | bit1)
        cups |= val0 | val1

    return ball

def main():
    assert(findball(0, [[0, 1], [1, 2], [1, 0]]) == 2)
    assert(findball(5, []) == 5)
    assert(findball(0, [[0, 1]]) == 1)
    assert(findball(1, [[0, 1]]) == 0)
    assert(findball(0, [[0, 1], [2, 1], [0, 1]]) == 2)
    assert(findball(0, [[0, 1], [1, 2], [2, 0], [0, 1], [1, 2], [2, 1], [2, 0], [0, 2]]) == 1)
    assert(findball(0, [[0, 2], [1, 0]]) == 2)
    assert(findball(1, [[0, 2], [1, 0]]) == 0)
    assert(findball(0, [[0, 9], [9, 3], [3, 7], [7, 8], [8, 2], [4, 5]]) == 2)
    assert(findball(1, [[0, 9], [9, 3], [3, 7], [7, 8], [8, 2], [4, 5]]) == 1)
    assert(findball(2, [[0, 9], [9, 3], [3, 7], [7, 8], [8, 2], [4, 5]]) == 8)
    assert(findball(3, [[0, 9], [9, 3], [3, 7], [7, 8], [8, 2], [4, 5]]) == 9)
    assert(findball(4, [[0, 9], [9, 3], [3, 7], [7, 8], [8, 2], [4, 5]]) == 5)
    assert(findball(5, [[0, 9], [9, 3], [3, 7], [7, 8], [8, 2], [4, 5]]) == 4)
    assert(findball(6, [[0, 9], [9, 3], [3, 7], [7, 8], [8, 2], [4, 5]]) == 6)

main()

