#!/usr/bin/env python3

"""

Today's easy challenge is to write a program that draws a number in the terminal that looks like one of those old school seven segment displays you find in alarm clocks and VCRs. For instance, if you wanted to draw the number 5362, it would look somthing like:

+--+  +--+  +--+  +--+
|        |  |        |
|        |  |        |
+--+  +--+  +--+  +--+
   |     |  |  |  |
   |     |  |  |  |
+--+  +--+  +--+  +--+
I've added some +'s to the joints to make it a bit more readable, but that's optional.

Bonus: Write the program so that the numbers are scalable. In other words, that example would have a scale of 2 (since every line is two terminal characters long), but your program should also be able to draw them in a scale of 3, 4, 5, etc.

"""

def display(s):
    ZERO = ["+--+", "|  |", "|  |", "|  |", "+--+"]
    ONE = ["   +", "   |", "   |", "   |", "   +"]
    TWO = ["+--+", "   |", "+--+", "|   ", "+--+"]
    THREE = ["+--+", "   |", "+--+", "   |", "+--+"]
    FOUR = ["+  +", "|  |", "+--+", "   |", "   +"]
    FIVE = ["+--+", "|   ", "+--+", "   |", "+--+"]
    SIX = ["+--+", "|   ", "+--+", "|  |", "+--+"]
    SEVEN = ["+--+", "   |", "   |", "   |", "   +"]
    EIGHT = ["+--+", "|  |", "+--+", "|  |", "+--+"]
    NINE = ["+--+", "|  |", "+--+", "   |", "   +"]

    for y in range(5):
        for c in s:
            t = []
            if c == '0':
                t = ZERO
            elif c == '1':
                t = ONE
            elif c == '2':
                t = TWO
            elif c == '3':
                t = THREE
            elif c == '4':
                t = FOUR
            elif c == '5':
                t = FIVE
            elif c == '6':
                t = SIX
            elif c == '7':
                t = SEVEN
            elif c == '8':
                t = EIGHT
            elif c == '9':
                t = NINE
            else:
                continue
            
            print(''.join(t[y]), end=' ')
        print()

def main():
    display("0123456789")

main()

