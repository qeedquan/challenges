#!/usr/bin/env python3

"""

Square numbers are those that take the form of n^2 where n is an integer. These are also called perfect squares, because when you take their square root you get an integer.

The first 10 square numbers are: (OEIS)

0, 1, 4, 9, 16, 25, 36, 49, 64, 81

Triangular numbers are numbers that can form an equilateral triangle. The n-th triangle number is equal to the sum of all natural numbers from 1 to n.

The first 10 triangular numbers are: (OEIS)

0, 1, 3, 6, 10, 15, 21, 28, 36, 45

Square triangular numbers are numbers that are both square and triangular.

The first 10 square triangular numbers are: (OEIS)

0, 1, 36, 1225, 41616, 1413721, 48024900, 1631432881, 55420693056, 1882672131025, 63955431761796

There is an infinite number of square numbers, triangle numbers, and square triangular numbers.

Write a program or named function that given an input (parameter or stdin) number n,
calculates the nth square triangular number and outputs/returns it, where n is a positive nonzero number. (For  n=1 return 0)

For the program/function to be a valid submission it should be able to return at least all square triangle numbers smaller than  2^31-1.

Bonus
-4 bytes for being able to output all square triangular numbers less than 2^63-1

-4 bytes for being able to theoretically output square triangular numbers of any size.

+8 byte penalty for solutions that take nonpolynomial time.

Bonuses stack.

This is code-golf challenge, so the answer with the fewest bytes wins.

"""

# https://oeis.org/A001110
def tsn(n):
    if n < 1:
        return 0

    a = 1
    b = 0
    for i in range(n):
        a, b = b, 34*b - a + 2
    return a

def main():
    tab = [
        0, 1, 36, 1225, 41616, 1413721, 48024900, 1631432881, 55420693056,
        1882672131025, 63955431761796, 2172602007770041, 73804512832419600,
        2507180834294496361, 85170343853180456676, 2893284510173841030625,
        98286503002057414584576, 3338847817559778254844961,
        113422539294030403250144100
    ]

    for i in range(len(tab)):
        assert(tsn(i + 1) == tab[i])

main()
