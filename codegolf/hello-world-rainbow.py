#!/usr/bin/env python3

"""

Dealing with colors in non-markup languages often complicates things. I would like to see some variations of how color is used in different languages.

The object of this competition is to output 'Hello World' in the seven colors of the rainbow.

According to Wikipedia, these are the 7 colors.

Red      #FF0000 (RGB: 255, 0, 0)
Orange   #FF7F00 (RGB: 255, 127, 0)
Yellow   #FFFF00 (RGB: 255, 255, 0)
Green    #00FF00 (RGB: 0, 255, 0)
Blue     #0000FF (RGB: 0, 0, 255)
Indigo   #6600FF (RGB: 111, 0, 255)
Violet   #8B00FF (RGB: 143, 0, 255)
The rules

The program must output 'Hello World'. (Doesn't necessarily need to be text, but it must be distiguishable as 'Hello World')
Each letter must be a different color.
The colors can be in any order.
You must use each of the seven colors at least once. (You may use more than the given colors)
No use of markup languages in any case.
The winner is whoever has the lowest amount of characters AND follows the rules

Bonus -1 character if it is written in DART

I will pick the winner on Jan 11 (if I remember ;D).

Good luck

"""

def rainbow(s):
    p = 31
    for c in s:
        print("\033[%d;1m%c" % (p, c), end='')
        p += 1
        if p >= 37:
            p = 31
    print("\033[0m")

def main():
    rainbow("Hello World!")

main()
