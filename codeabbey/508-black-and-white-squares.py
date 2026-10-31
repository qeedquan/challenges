#!/usr/bin/env python3

"""

Colin was looking through his store room in the hope of finding some materials from which he could create a new game. He found a stack of long thin strips of wood, all painted white. These gave him an idea. He took one of the strips and marked it out into a series of squares. The resulting strip was N squares long and one square in width. He decided that the squares should not all be the same colour. After finding some black paint he painted a number (B) of the squares black. Next Colin cut a square wooden tile which was the same size as the squares on his strip, which he now regarded as a game board. This tile was painted red and was to be used as a playing piece to move between squares on the game board.

Colin soon came up with a set of rules which would allow two players to take alternate turns in moving the red tile backwards and forwards along the squares on the board. Next he needed a goal for ending the game. He soon decided that the game would end when the number of white squares to the left of the red tile was equal to the number of black squares to the right of the red tile. The first player to move the red tile into such a position would win the game.

The strips of wood were of various different lengths so Colin set about making a number of different game boards. For his game to work he needed each board to have at least 2 white squares and at least 2 black squares. With this in mind he painted black squares at random on his new boards. Once he started playing with these boards Colin discovered that some of them had more than one position of the red tile which would end the game. He considered this to be a useful feature for those boards where it occurred. To his dismay he also discovered that, for some of the boards that he had created, there was no position of the red tile that would result in the game ending requirement.

In this problem we are interested in the boards which have at least one position of the red tile which satisfies the game ending requirement. You will be given the number of squares (N) on the board. These are all initially painted white. You are also given the number of squares (B) that are to be painted black. You are asked to find the number of different ways of painting the board (with N squares, B of which are black) so that there is at least one position of the red tile which meets the game ending requirement.

Consider the following example of a very small board where N = 6 and B = 3. There are 20 different ways of painting this board but only 14 of them have the necessary game ending requirement and can be used to play the game. These are shown in the table below. Black and white squares are indicated by B and W respectively. The left hand column shows the complete strip of 6 squares. The right hand 3 columns show one of the ways in which the strip can be split by the position of the red tile to give a game ending position. The left of these columns shows the part of the board to the left of the red tile, the middle column shows the single square which is beneath the red tile, and the right column shows the part of the board to the right of the red tile. The number gives the number of white squares to the left of the red tile, which is equal to the number of black squares to the right of the red tile. You should be able to verify that the 6 painted strips which are not shown below do not have any game ending positions.

WWBWBB  2  WWB W  BB
WWBBWB  2  WW  B BWB
WWBBBW  2  WW  B BBW
WBWWBB  2  WBW W  BB
WBBWWB  1  WBB W  WB
WBBWBW  1  WBB W  BW
WBBBWW  1  WB  B BWW
BWWWBB  2  BWW W  BB
BWBWWB  1  BWB W  WB
BWBWBW  1  BWB W  BW
BWBBWW  1  BW  B BWW
BBWWWB  1  BBW W  WB
BBWWBW  1  BBW W  BW
BBBWWW  0  BBB W  WW
Note that WWBBWB and BWBBWW are considered to be two different boards for the purpose of this problem. A simple rotation is sufficient to show that they are actually the same. However, this adds an unintentional degree of complexity to the problem so we will count these as two separate boards.

Not surprisingly, the number of valid boards increases very rapidly as N increases. For this reason you are asked to give the answer modulo 1000000007 (10^9 +7). The value of N will always be less than 1000000.

Input/Output description: The first line of the input data will contain a single integer P for the number of problems. P lines will follow. Each of these consists of two integers N and B, separated by a space. In each case, find the number of different boards which have at least one game ending position. Give your answer modulo 1000000007 and combine all answers into a single string, separated by single spaces.

Example:

input:
4
6 3
9 3
84 65
984 607

answer:
14 63 990636189 87934016

"""

from math import comb

def solve(N, B):
    return (comb(N, B) - comb(N-2, B-1)) % 1000000007

def main():
    assert(solve(6, 3) == 14)
    assert(solve(9, 3) == 63)
    assert(solve(84, 65) == 990636189)
    assert(solve(984, 607) == 87934016)

main()
