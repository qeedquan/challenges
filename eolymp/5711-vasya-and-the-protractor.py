#!/usr/bin/env python3

"""

In his father's desk, Vasya discovered an intriguing tool known as a protractor.
His father explained to the curious schoolboy how to use this device to measure angles, and Vasya eagerly began experimenting.
Coincidentally, they had just started studying triangles at school the day before, so his notebook was filled with drawings.

After measuring each angle, Vasya would promptly jot down its value in his notebook before moving on to the next one.

However, his learning session was abruptly interrupted by his mother, who loudly announced: "Duty is duty, but lunch is on schedule!".
After lunch, Vasya found that his father had locked the protractor in the desk, leaving one angle unmeasured.

Help Vasya complete his unfinished experiment.

Input
First, the value of the first measured angle is provided, followed by the second. All input values are positive integers that do not exceed 200.

Output
Output a single number representing the magnitude of the angle in the triangle that Vasya did not measure, in degrees, or −1 if Vasya made an error in measuring the previous angles due to his mother's interruption.

Examples

Input #1
52
48

Answer #1
80

Input #2
92
103

Answer #2
-1

"""

def solve(a, b):
    if a < 1 or b < 1 or a + b >= 180:
        return -1
    return 180 - (a + b)

def main():
    assert(solve(52, 48) == 80)
    assert(solve(92, 103) == -1)

main()
