#!/usr/bin/env python3

"""

Write a function loopArr that loops array in a specified direction by some number of steps.

By "looping array" it means removing elements from start and adding them to end of array one-by-one (if direction is "left") or removing from end and adding them to start one by-one (if direction is "right").

Function should accept three arguments:

array - non-empty array of elements of any type;
direction - 'left' or 'right' - tells how to loop array;
steps - number of steps to loop array (less or equal to array size);

Examples:

loopArr([1, 5, 87, 45, 8, 8], 'left', 2);

should produce result: [87, 45, 8, 8, 1, 5]

loopArr([1, 5, 87, 45, 8, 8], 'right', 2);

should produce result: [8, 8, 1, 5, 87, 45]

"""

def loop_array(array, direction, steps):
    result = []
    if direction == "left":
        result = array[steps:] + array[:steps]
    elif direction == "right":
        result = array[-steps:] + array[:-steps]
    return result

def main():
    assert(loop_array([1, 5, 87, 45, 8, 8], "left", 2) == [87, 45, 8, 8, 1, 5])
    assert(loop_array([1, 5, 87, 45, 8, 8], "right", 2) == [8, 8, 1, 5, 87, 45])

main()
