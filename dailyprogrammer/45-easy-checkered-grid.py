#!/usr/bin/env python3

"""

Your challenge today is to write a program that can draw a checkered grid (like a chessboard) to any dimension. For instance, a 3 by 8 board might look like this:

*********************************
*   *###*   *###*   *###*   *###*
*   *###*   *###*   *###*   *###*
*   *###*   *###*   *###*   *###*
*********************************
*###*   *###*   *###*   *###*   *
*###*   *###*   *###*   *###*   *
*###*   *###*   *###*   *###*   *
*********************************
*   *###*   *###*   *###*   *###*
*   *###*   *###*   *###*   *###*
*   *###*   *###*   *###*   *###*
*********************************
Yours doesn't have to look like mine, you can make it look any way you want (now that I think of it, mine looks kinda bad, actually). Also try to make it scalable, so that if you want to make a 2 by 5 board, but with bigger squares, it would print out:

*******************************
*     *#####*     *#####*     *
*     *#####*     *#####*     *
*     *#####*     *#####*     *
*     *#####*     *#####*     *
*     *#####*     *#####*     *
*******************************
*#####*     *#####*     *#####*
*#####*     *#####*     *#####*
*#####*     *#####*     *#####*
*#####*     *#####*     *#####*
*#####*     *#####*     *#####*
*******************************
Have fun!

"""

def checkerboard(rows, cols):
    print("(%d, %d)" % (rows, cols))
    for row in range(rows):
        print("*" * (4*cols + 1))
        for _ in range(3):
            for col in range(cols):
                if (col + row)%2 == 0:
                    print("*   ", end='')
                else:
                    print("*###", end='')
            print("*")
    print("*" * (4*cols + 1))
    print()

def main():
    checkerboard(3, 8)
    checkerboard(2, 5)

main()
