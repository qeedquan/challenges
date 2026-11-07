#!/usr/bin/env python3

"""

Monday numbers, as defined by Gamow in this question over on Puzzling, are positive integers N with the following three properties:

The decimal representation of N does not contain the digit 0
The decimal representation of N does not contain any digit twice
N is divisible by every digit D that occurs in its decimal representation
Note that these are alternatively known, in the OEIS, as Lynch-Bell numbers.

Examples:
15 is a Monday number, as it's divisible by both 1 and 5 and satisfies the other two conditions
16 is not, because it's not divisible by 6.
The number 22 is not, because though it satisfies conditions 1 and 3, it fails condition 2.
Here's the list of the first 25 Monday numbers to get you started (there are 548 total):

1 2 3 4 5 6 7 8 9 12 15 24 36 48 124 126 128 132 135 162 168 175 184 216 248

The challenge here is to write the shortest code that generates the full sequence of Monday numbers, from 1 up to 9867312 (proven on that question to be the largest possible).

Your code should take no input, and output should be to STDOUT or equivalent, with your choice of delimiter. All the usual code-golf rules apply, and Standard Loopholes are prohibited.

"""

# https://oeis.org/A115569
def lynchbell(n):
    s = str(n)
    if "0" in s or len(set(s)) < len(s):
        return False
    return all(n%int(d) == 0 for d in s)

def gen(n):
    r = []
    i = 0
    while len(r) < n:
        if lynchbell(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [
        1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 15, 24, 36, 48, 124, 126, 128, 132, 135,
        162, 168, 175, 184, 216, 248, 264, 312, 315, 324, 384, 396, 412, 432,
        612, 624, 648, 672, 728, 735, 784, 816, 824, 864, 936, 1236, 1248, 1296,
        1326, 1362, 1368, 1395, 1632, 1692, 1764, 1824
    ]

    assert(gen(len(tab)) == tab)

main()
