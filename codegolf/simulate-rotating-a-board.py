#!/usr/bin/env python3

r"""

Introduction
You're playing a matching game, in which coins are inserted at the top and fall to the bottom (onto the top coin) due to gravity.

So this

O <- inserting this coin

OO O
OOOOO
will become this

O
OO O
OOOOO
Now imagine someone rotates the board clockwise. The following will happen:

1. The board is rotated
OOO
OO
O
OO
O
2. Coins fall down due to gravity
O
O
OO
OO
OOO
Your task
Your task is to simulate the rotation of the board by writing a program or a function. For the sake of simplicity we're only dealing with one kind of coin (it's not a too exciting matching game, is it…). You can assume that gravity is applied only after the rotation is complete. The board is rotated clockwise.

Input
The input is going to be a string, which contains 3 types of characters:

O (capital o) OR 0 (zero) - a coin (you decide which one your solution supports)
(space) - an empty field
\n (new line) - end of row
The input represents the state of the board. You can assume, the input is well formed and contains a valid state of the board (no coins are floating). The input can be a function parameter, or can be read from the standard input or from a file.

Output
The output is the new state of the board after rotation. The output contains the same 3 types of characters as the input. The output can be returned from your function or can be written to the standard output or to a file.

Sample
Input1:

O
OO O
OOOOO

Output1:

O
O
OO
OO
OOO

Input2:

O O
O O
Output2:

OO
OO
You can use any language and the standard library of the chosen language. Shortest program in bytes wins.

"""

# Ported from @xnor solution
def rotate(board):
    lines = board.split("\n")
    for symbols in sorted(zip(*lines)):
        print(''.join(symbols[::-1]))

def main():
    rotate("O    \nOO O \nOOOOO")
    rotate("O O\nO O")

main()
