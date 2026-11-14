#!/usr/bin/env python3

"""

The goal of this Kata is to return the greatest distance of index positions between matching number values in an array or 0 if there are no matching values.

Example: In an array with the values [0, 2, 1, 2, 4, 1] the greatest index distance is between the matching '1' values at index 2 and 5. Executing greatestDistance against this array would return 3. (i.e. 5 - 2)

Here's the previous example in test form:

Test.assertEquals(greatestDistance([0, 2, 1, 2, 4, 1]), 3);
This is based on a Kata I had completed only to realize I has misread the instructions. I enjoyed solving the problem I thought it was asking me to complete so I thought I'd add a new Kata for others to enjoy. There are no tricks in this one, good luck!

"""

def gd(a):
    m = 0
    p = {}
    for i, x in enumerate(a):
        if x not in p:
            p[x] = i
        m = max(m, i - p[x])
    return m

def main():
    assert(gd([0, 2, 1, 2, 4, 1]) == 3)
    assert(gd([8, 2, 4, 8, 3, 4, 6, 5, 2, 5]) == 7)

main()
