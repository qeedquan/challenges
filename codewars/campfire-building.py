#!/usr/bin/env python3

"""

A stranger has lost himself in a forest which looks like a 2D square grid. Night is coming, so he has to protect himself from wild animals. That is why he decided to put up a campfire.

Suppose this stranger has four sticks with the same length which is equal to k. He can arrange them in square grid so that they form k x k square (each stick endpoint lies on a grid node). Using this strategy he can build campfire with areas 1, 4, 9, ... Also, if he rotates the sticks as it is shown in the image, he will get another campfire areas 2, 5, 10, ...

https://raw.githubusercontent.com/RevelcoS/Codewars/master/campfire_housing/impossible_squares.jpg

Problem
Given campfire area A (A is a natural number) is it possible to construct a campfire with four sticks so that their endpoints lie on grid nodes?

Input
1≤A≤10^9
9

Output
Return boolean (true if it is possible to construct a campfire, otherwise false):

True or False in Python
true or false in C/C++ or JavaScript

Cases
If A = 3, then it is impossible to construct a campfire because it is impossible to get the square root of 3 on the grid
If A = 8, then it is possible to construct a campfire, for example, by doubling the side length of a square with area 2 in the imageq

"""

from sympy import factorint

# https://oeis.org/A001481
def sum_of_two_squares(n):
    f = factorint(n)
    for d in f:
        if d&3 == 3 and f[d]&1 != 0:
            return False
    return True

def main():
    tab = [
        0, 1, 2, 4, 5, 8, 9, 10, 13, 16, 17, 18, 20, 25, 26, 29, 32, 34, 36, 37,
        40, 41, 45, 49, 50, 52, 53, 58, 61, 64, 65, 68, 72, 73, 74, 80, 81, 82,
        85, 89, 90, 97, 98, 100, 101, 104, 106, 109, 113, 116, 117, 121, 122,
        125, 128, 130, 136, 137, 144, 145, 146, 148, 149, 153, 157, 160
    ]

    for i in range(tab[-1] + 1):
        if i in tab:
            assert(sum_of_two_squares(i) == True)
        else:
            assert(sum_of_two_squares(i) == False)

main()
