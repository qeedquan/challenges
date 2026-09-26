#!/usr/bin/env python3

"""

Dan likes to find the nth power of number. But he doesn't like it when the result is odd!

Return the nth power of each number, unless the result is odd, in which case round the result to the nearest 10.

Eg. if number = 7, and power = 2, result = 50.

"""

def danpower(n, p):
    r = n**p
    if r%2 != 0:
        r = (r + 5)//10 * 10
    return r

def main():
    assert(danpower(7, 2) == 50)

main()
