#!/usr/bin/env python3

"""

Alexey is trying to develop a program for a very simple microcontroller.
It makes readings from various sensors over time, and these readings must happen at specific regular times.
Unfortunately, if two of these readings occur at the same time, the microcontroller freezes and must be reset.

There are N different sensors that read data on a regular basis.
For each i from 1 to N, the reading from sensor i will occur every Ai milliseconds with the first reading occurring exactly Ai milliseconds after the microcontroller is powered up.
Each reading takes precisely one millisecond on Alexey's microcontroller.

Alexey wants to know when the microcontroller will freeze after he turns it on.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line contains single integer N denoting the number of sensors.

The second line contains N space-separated integers A1, A2, ..., AN denoting frequency of measurements. Namely, sensor i will be read every Ai milliseconds with the first reading occurring Ai milliseconds after the microcontroller is first turned on.

Output

For each test case, output a single line containing the number of milliseconds until the microcontroller freezes.

Constraints
1 ≤ T ≤ 10
2 ≤ N ≤ 500
1 ≤ Ai ≤ 10^9

"""

from math import *

def duration(a):
    r = -1
    n = len(a)
    for i in range(0, n-1):
        for j in range(i+1, n):
            v = (a[i] * a[j]) / gcd(a[i], a[j])
            if r < 0 or v < r:
                r = v
    return max(r, 0)

def main():
    assert(duration([2, 3, 5]) == 6)
    assert(duration([1, 8, 7, 11]) == 7)
    assert(duration([4, 4, 5, 6]) == 4)

main()

