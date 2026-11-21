#!/usr/bin/env python3

"""

Intro:
You accidentally corrupted the flow of time with a device you made for fun, that turned out to be a time machine. As a result, you got pushed to the far future. You realized that computing, processing power, and computers in general have been evolved by a huge amount, an infinite amount to be precise. So you grab yourself a computer with infinite memory and processing power. You have no idea how it can have infinite memory and infinite processing power, but you just accept it and return to the present.

Challenge:
You heard that the person who discovered the currently largest prime 2^74,207,281 − 1 got paid $100.000. You decide to make a program that finds the next prime, since you want to get back the money you spent for the computer. You make one that takes input of a number, and finds the next prime number, either by bruteforcing or any other method.

Clarifications: You have a hypothetical machine with infinite memory and processing power. Your program MUST NOT be limited (e.g.: C#'s int's can store from -2,147,483,648 to 2,147,483,647), well your program must be able to store, and work with any number of any size. You have infinite resources, so you shouldnt care if you would run out of memory if you allowed that.

Example I/O:
Input: The currently largest discovered prime with 22,338,618 digits.
Output: Exactly the next prime

Obviously, you dont have to prove that it works, as it would take a ton of time to compute in a physical machine. But if you moved your program to a hypothetical machine with infinite processing power / memory, it should compute instantly.

Finding the next prime and checking if a number is a prime, are two completely different things

"""

from sympy import nextprime

def main():
    print(nextprime(30))
    print(nextprime(10000))

main()
