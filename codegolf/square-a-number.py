#!/usr/bin/env python3

"""

People keep telling me that the square of a number is the number multiplied by itself. This is obviously false. The correct way to square a number is to make it into a square, by stacking it on top of itself a number of times equal to the number of digits it has, and then reading all the numbers from the resultant square, both horizontally (from left to right only) and vertically (from up to down only), and then adding them together. So, for the number 123, you first create the square:

123
123
123
Then you take all of the rows and columns from the square, and add them together:

123+123+123+111+222+333
Which gives us a result of 1035.

For negative numbers, you stack normally (remember that you only count the number of digits, so the negative sign is not included in the length), and then read the horizontal numbers normally (with negative signs), and then ignore the negative signs for the vertical numbers. So, for the number -144 we get the square:

-144
-144
-144
Which gives us -144-144-144+111+444+444, which equals 567

For numbers with only one digit, the square is always equal to the number doubled (read once horizontally and once vertically). So 4 gives us

4
Which gives us 4+4, which equals 8.

For numbers with decimal parts, stack normally (remember that only digits are counted in the number of times you stack the number, and therefore the decimal point is not counted), and ignore the decimal symbols when reading the vertical numbers. For example, the number 244.2 gives us

244.2
244.2
244.2
244.2
Which gives us 244.2+244.2+244.2+244.2+2222+4444+4444+2222, which equals 14308.8.

Fractional or complex numbers cannot be squared.

Your Task:
I'm tired of squaring numbers my way by hand, so I've decided to automate the process. Write me a program or function that takes a float or string, whichever you prefer, as input and returns the result of squaring it my way.

Examples:
123    -> 1035
388    -> 3273
9999   -> 79992
0      -> 0
8      -> 16
-6     -> 0
-25    -> 27
-144   -> 567
123.45 -> 167282.25
244.2  -> 14308.8
2      -> 4
-0.45  -> 997.65
0.45   -> 1000.35
Scoring:
My hands are getting cramped from writing out all those squares, and my computer doesn't support copy/paste, so the entry with the least amount of code for me to type (measured in bytes for some reason?) wins!

"""

def square(number):
    string = str(number)
    digits = []
    for value in string:
        if "/" < value:
            digits.append(value)
    length = len(digits)
    return (length*float(string) + sum(int(digit*length) for digit in digits))

def main():
    print(square(123))
    print(square(388))
    print(square(9999))
    print(square(0))
    print(square(8))
    print(square(-6))
    print(square(-25))
    print(square(-144))
    print(square(123.45))
    print(square(244.2))
    print(square(2))
    print(square(-0.45))
    print(square(0.45))

main()
