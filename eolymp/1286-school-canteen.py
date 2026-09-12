#!/usr/bin/env python3

"""

https://static.e-olymp.com/content/50/50e525c90048ff6129043670dcdf670a33d6fe2d.jpg

In the school cafeteria, by the end of the lessons, several cakes remained: a vanilla, b chocolate, and c fruit.
Dima wants to buy some cakes before the cafeteria closes. What is the maximum number of cakes Dima can take?

Input
Three non-negative integers are given, representing the number of vanilla, chocolate, and fruit cakes, respectively. Each number does not exceed 20000.

Output
Print the maximum number of cakes that Dima can take.

Examples
Input #1
4 2 3

Answer #1
9

"""

def solve(a, b, c):
    return a + b + c

def main():
    assert(solve(4, 2, 3) == 9)

main()
