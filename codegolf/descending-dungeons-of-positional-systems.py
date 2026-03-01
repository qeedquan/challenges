#!/usr/bin/env python3

"""

The sequence discussed in this challenge is a variant of the Descending Dungeons sequence family. Specifically, the sequence generation rules:

(A_b = A's base 10 representation read as a base b number, A = A_10)
A(0) = 10
A(n) = 10_(11_(12_(...(n+9)_(n+10))))
Your goal is to make a program which accepts a nonnegative integer n and returns A(n) of the descending dungeons sequence, using 0-indexing.

Base conversion built-ins are allowed.

Return the result itself in base 10.

Test cases: (A = B means input A returns B)

0 = 10
1 = 11
2 = 13
3 = 16
4 = 20
5 = 25
6 = 31
7 = 38
8 = 46
9 = 55
10 = 65
11 = 87
12 = 135
13 = 239
14 = 463
15 = 943
16 = 1967
17 = 4143
18 = 8751
19 = 18479
20 = 38959
Use OEIS A121263 for further test cases.

This is code golf, so the shortest program wins. Have fun.

Final sidenote: This sequence came to my attention through a recent Numberphile video discussing descending dungeon sequences.

"""

# https://oeis.org/A121263
def dds(n):
    if n < 1:
        return 0

    x = [(10 + int(i)) for i in range(n)]
    while len(x) != 1:
        e = 0
        x[-2] = list(str(x[-2]))
        for i in range(len(x[-2])):
            x[-2][-i - 1] = int(x[-2][-i - 1])
            x[-2][-i - 1] *= x[-1]**e
            e += 1
        x[-2] = sum(x[-2])
        x = x[:len(x) - 1]
    return x[0]

def main():
    tab = [10, 11, 13, 16, 20, 25, 31, 38, 46, 55, 65, 87, 135, 239, 463, 943, 1967, 4143, 8751, 18479, 38959, 103471, 306223, 942127, 2932783, 9153583, 28562479, 89028655, 277145647, 861652015, 2675637295, 10173443119, 41132125231, 168836688943, 695134284847]

    for i in range(len(tab)):
        assert(dds(i + 1) == tab[i])

main()
