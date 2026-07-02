#!/usr/bin/env python3

def multiple_of_17(n):
    return n%17 == 0

def main():
    assert(multiple_of_17(34) == True)
    assert(multiple_of_17(201) == False)
    assert(multiple_of_17(2098765413) == True)
    assert(multiple_of_17(1717171717171717171717171717171717171717171717171718) == False)

main()

