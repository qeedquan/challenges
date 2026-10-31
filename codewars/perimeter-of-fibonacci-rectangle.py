#!/usr/bin/env python3

"""

The drawing shows 6 squares the sides of which have a length of 1, 1, 2, 3, 5, 8. The perimeter of the overall rectangle is 42.

Could you give the perimeter of a rectangle when there are n + 1 squares disposed in the same manner as in the drawing:

http://i.imgur.com/EYcuB1wm.jpg

The function perimeter has the parameter n where n + 1 is the number of squares (they are numbered from 0 to n), and returns the perimeter of the overall rectangle (not of its component squares).

JS: The result of the random tests can go up to 210 digits. So, return the result in the form of BigInt.

Credit: this kata is a twist on Perimeter of squares in a rectangle ( https://www.codewars.com/kata/perimeter-of-squares-in-a-rectangle ).

"""

from sympy import fibonacci

# https://oeis.org/A078642
def perimeter(n):
    return 2 * (fibonacci(n) + fibonacci(n + 1))

def main():
    tab = [
        4, 6, 10, 16, 26, 42, 68, 110, 178, 288, 466, 754, 1220, 1974, 3194,
        5168, 8362, 13530, 21892, 35422, 57314, 92736, 150050, 242786, 392836,
        635622, 1028458, 1664080, 2692538, 4356618, 7049156, 11405774, 18454930,
        29860704, 48315634, 78176338, 126491972
    ]

    for i in range(len(tab)):
        assert(perimeter(i + 1) == tab[i])

    assert(perimeter(6) == 42)

main()
