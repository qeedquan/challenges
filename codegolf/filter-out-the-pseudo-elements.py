#!/usr/bin/env python3

"""

We define the hyper-average of an array / list (of numbers) the arithmetic mean of the sums of its prefixes.

For example, the hyper-average of the list [1, 4, -3, 10] is computed in the following manner:

We get the prefixes: [1], [1, 4], [1, 4, -3], [1, 4, -3, 10].

Sum each: [1, 5, 2, 12].

And now get the arithmetic mean of the elements in this list: (1 + 5 + 2 + 12) / 4 = 5.

A pseudo-element of an array is an element whose value is strictly lower than its hyper-average. Hence, the pseudo-elements of our example list are 1, 4 and -3.

Given a list of floating-point numbers, your task is to return the list of pseudo-elements.

You don't have to worry about floating-point inaccuracies.

The input list will never be empty and it may contain both integers and floats. If mentioned, integers may be taken as floats (with <integer>.0)

You may assume that the numbers fit your language of choice, but please do not abuse that in any way.

Optionally, you may take the length of the array as input as well.

This is code-golf, so standard rules for the tag apply. The shortest code in bytes (in each language) wins!

Test Cases
Input -> Output

[10.3] -> []
[5.4, 5.9] -> [5.4, 5.9]
[1, 4, -3, 10] -> [1, 4, -3]
[-300, -20.9, 1000] -> [-300, -20.9]
[3.3, 3.3, 3.3, 3.3] -> [3.3, 3.3, 3.3, 3.3]
[-289.93, 912.3, -819.39, 1000] -> [-289.93, -819.39]

"""

import numpy as np

def filter(values):
    average = np.mean(np.cumsum(values))
    return values[values < average]

def main():
    arrays = [
        [10.3],
        [5.4, 5.9],
        [1, 4, -3, 10],
        [-300, -20.9, 1000],
        [3.3, 3.3, 3.3, 3.3],
        [-289.93, 912.3, -819.39, 1000],
    ]
    for values in arrays:
        print(filter(np.array(values)))

main()
