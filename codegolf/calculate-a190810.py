#!/usr/bin/env python3

"""

Your task is pretty simple, calculate the n-th element of A190810.

Elements of A190810 are calculated according to these rules:

The first element is 1
The sequence is increasing
If x occurs in the sequence, then 2x+1 and 3x-1 also do
You can use 1-based or 0-based indexing, but if you use 0-based indexing, please say it in the answer.

Test cases

a(1) = 1
a(2) = 2
a(3) = 3
a(4) = 5
a(5) = 7
a(10) = 17
a(20) = 50
a(30) = 95
a(55) = 255

Since this is code-golf, the shortest answer in bytes wins!

"""

# https://oeis.org/A190810
def gen(n):
    r = [1]
    i = 0
    while len(r) < 3*n:
        r += [2*r[i] + 1, 3*r[i] - 1]
        i += 1
    return sorted(set(r))[:n]

def main():
    tab = [
        1, 2, 3, 5, 7, 8, 11, 14, 15, 17, 20, 23, 29, 31, 32, 35, 41, 44, 47,
        50, 59, 63, 65, 68, 71, 83, 86, 89, 92, 95, 101, 104, 119, 122, 127,
        131, 137, 140, 143, 149, 167, 173, 176, 179, 185, 188, 191, 194, 203,
        209, 212, 239, 245, 248, 255, 257, 263, 266, 275, 281
    ]

    assert(gen(len(tab)) == tab)

main()
