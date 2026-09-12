#!/usr/bin/env python3

"""

I'm sure you're familiar with factorials – that is, the product of an integer and all the integers below it.

For example, 5! = 120, as 5 * 4 * 3 * 2 * 1 = 120

Your challenge is to create a function that takes any number and returns the number that it is a factorial of. So, if your function receives 120, it should return "5!" (as a string).

Of course, not every number is a factorial of another. In this case, your function would return "None" (as a string).

Examples
120 will return "5!"
24 will return "4!"
150 will return "None"

"""

def invfact(n):
    if n < 1:
        return "None"

    r = 1
    i = 1
    while r <= n:
        if r == n:
            return f"{i}!"
        i += 1
        r *= i
    return "None"

def main():
    assert(invfact(6) == "3!")
    assert(invfact(1) == "1!")
    assert(invfact(120) == "5!")
    assert(invfact(24) == "4!")
    assert(invfact(150) == "None")

main()
