#!/usr/bin/env python3

r"""

You want to build a standard house of cards, but you don't know how many cards you will need. Write a program which will count the minimal number of cards according to the number of floors you want to have. For example, if you want a one floor house, you will need 7 of them (two pairs of two cards on the base floor, one horizontal card and one pair to get the first floor). Here you can see which kind of house of cards I mean:

One floor:

 /\
 —
/\/\

Four floors:

    /\
    —
   /\/\
   — —
  /\/\/\
  — — —
 /\/\/\/\
 — — — —
/\/\/\/\/\

(See also http://www.wikihow.com/Build-a-Tower-of-Cards to see what it looks like in real life).
Note about floors:

This kata uses the British numbering system for building floors. If you want your house of cards to have a first floor, it needs a ground floor and then a first floor above that.
Details (Ruby & JavaScript & Python & R)

The input must be an integer greater than 0, for other input raise an error.
Details (Haskell)

The input must be an integer greater than 0, for other input return Nothing.
Details (COBOL)

The input will be an integer. If it is inferior or equal to 0, return -1.

"""

# https://oeis.org/A005449
def pentagonal(n):
    return n*(3*n + 1)//2

def house_of_cards(n):
    if n < 1:
        return -1
    return pentagonal(n + 1)

def main():
    tab = [
            0, 2, 7, 15, 26, 40, 57, 77, 100, 126, 155, 187, 222, 260, 301, 345,
            392, 442, 495, 551, 610, 672, 737, 805, 876, 950, 1027, 1107, 1190, 1276,
            1365, 1457, 1552, 1650, 1751, 1855, 1962, 2072, 2185, 2301, 2420, 2542,
            2667, 2795, 2926, 3060, 3197, 3337, 3480
    ]

    assert(house_of_cards(1) == 7)
    assert(house_of_cards(2) == 15)
    assert(house_of_cards(3) == 26)
    assert(house_of_cards(6) == 77)
    assert(house_of_cards(15) == 392)

    for i in range(2, len(tab)):
        assert(house_of_cards(i - 1) == tab[i])

main()
