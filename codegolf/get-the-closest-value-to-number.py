#!/usr/bin/env python3

"""

In this code golf, you need to get the closest number from another one in a list.

The output may be the closest number to the input.

Example:

value: (Input) 5 --- [1,2,3] --- 3
And, the program may work with negative numbers.

Example:

value: (Input) 0 --- [-1,3,5] --- -1


value: (Input) 2 --- [1, 5, 3] --- 1 (Because it gives priority to lower numbers)
RULES:

As mentioned before, it has to work with negative numbers.

If there are two answers (Example: 0 -- [5,-5]), the program gives priority to the lowest number. (-5)

This is code golf so the shortest code wins!

"""

def closest(target, values):
    return min(values, key=lambda value: abs(target - value))

def main():
    assert(closest(5, [1, 2, 3]) == 3)
    assert(closest(0, [-1, 3, 5]) == -1)
    assert(closest(2, [1, 5, 3]) == 1)

main()

