#!/usr/bin/env python3

"""

Santa's elves are boxing presents, and they need your help! Write a function that takes two sequences of dimensions of the present and the box, respectively, and returns a Boolean based on whether or not the present will fit in the box provided. The box's walls are one unit thick, so be sure to take that in to account.

Examples: Present and box respectively

[10, 7, 16], [13, 32, 10] --> true, box is bigger than present
[5, 7, 9], [9, 5, 7]      --> false, present and box are same size
[17, 22, 10], [5, 5, 10]) --> false, box is too small

"""

def willfit(present, box):
    present = sorted(present)
    box = sorted(box)
    for i in range(len(present)):
        if present[i] + 1 >= box[i]:
            return False
    return True

def main():
    assert(willfit([10, 7, 16], [13, 32, 10]) == True)
    assert(willfit([5, 7, 9], [9, 5, 7]) == False)
    assert(willfit([17, 22, 10], [5, 5, 10]) == False)

main()
