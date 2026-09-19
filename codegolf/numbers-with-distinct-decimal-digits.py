#!/usr/bin/env python3

"""

Write a program or function that outputs all positive integers with distinct decimal digits (OEIS: A010784)

Examples:

1 2 3 4 5 6 7 8 9 10 12 13 ...
96 97 98 102 103 ...
123456789 123456798 ... 9876543120 9876543201 9876543210

Rules
You can output the list of numbers in any convenient format (string with separators, array, generator, ...)
The order of the numbers is not important as long as every number appears exactly once
You can choose if you include zero
This is code-golf the shortest solution wins

"""

# https://oeis.org/A010784
def gen(n):
    r = []
    i = 0
    while len(r) < n:
        s = str(i)
        if len(set(s)) == len(s):
            r.append(i)
        i += 1
    return r

def main():
    tab = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 102, 103, 104, 105, 106, 107, 108, 109, 120]

    assert(gen(len(tab)) == tab)

main()
