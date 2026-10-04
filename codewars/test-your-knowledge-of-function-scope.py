#!/usr/bin/env python3

"""

Write a function that adds from two invocations.

All inputs will be integers.

add(3)(4)  // 7
add(12)(20) // 32

"""

def add(x):
    return lambda y: x + y

def main():
    assert(add(3)(4) == 7)
    assert(add(12)(20) == 32)

main()
