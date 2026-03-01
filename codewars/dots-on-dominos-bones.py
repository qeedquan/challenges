#!/usr/bin/env python3

"""

To earn a huge capital, you need to have an unconventional mindset. Of course, with such a complex job, there must also be special mechanisms for recreation and entertainment. For this purpose, the casino came up with a special domino set. Ordinary dominoes are a set of different combinations of two tiles, each displaying 0 to 6 points. And this set is a similar combination of tiles, but the number of points on each can be from zero to a set value that depends on the intellectual level of the players. There are all kinds of tile combinations in this dice set, but none of them must be repeated (combinations such as 2 | 5 and 5 | 2 are considered the same).there's a domino, don't worry :)When making this set of dominoes, the manufacturer faced the problem of counting the total number of points on all dominoes. This is due to the fact that the dominoes are decorated with diamonds, which are dots on the tiles and the cost of which must be estimated during manufacture.

https://avatars.steamstatic.com/1d0c4eaaa67c798d5691409ea1897931fa0fdc2f_full.jpg

Input data:

The function receives a parameter n, which indicates the maximum number of points on one domino tile.

Test values are 0 < n < 1000

Output data:

Your function should return the optional number of diamond stones to be made for a given set of dice.

Example:

For dominoes where the maximum possible number on the knuckle is 2, the possible knuckles will be as follows --> 0 | 1, 0 | 2, 1 | 1, 1 | 2, 2 | 2 therefore, the sum of all values on the knuckles will be 1 + 2 + 1 + 1 + 1 + 2 + 2 + 2 = 12

2 --> 12
3 --> 30
20 --> 4620

Help me write a program that solves this problem.

If someone is interested, you can read the rules of the domino game here ;) Domino game

"""

def dotsbf(n):
    r = 0
    for i in range(n + 1):
        for j in range(i, n + 1):
            r += i + j
    return r

# https://oeis.org/A027480
def dots(n):
    return n * (n + 1) * (n + 2) // 2

def main():
    tab = [0, 3, 12, 30, 60, 105, 168, 252, 360, 495, 660, 858, 1092, 1365, 1680, 2040, 2448, 2907, 3420, 3990, 4620, 5313, 6072, 6900, 7800, 8775, 9828, 10962, 12180, 13485, 14880, 16368, 17952, 19635, 21420, 23310, 25308, 27417, 29640, 31980, 34440]
    for i in range(len(tab)):
        assert(dots(i) == tab[i])
        assert(dotsbf(i) == tab[i])

main()
