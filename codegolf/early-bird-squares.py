#!/usr/bin/env python3

"""

Definition
If you take the sequence of positive integer squares, and concatenate them into a string of digits (i.e. 149162536496481100...), an "early bird" square is one that can be found in this string ahead of its natural position.

For example, 72 (the number 49), can be found at an offset of 2 in the string, although the natural position is at offset 10. Thus 7 is the first "early bird" square.

Note that for it to be considered an "early bird" square, all the digits in the square must occur before the start of the natural position. A match that partially overlaps the natural position does not count.

a(n) is the nth positive integer k such that k2 is an "early bird" square.

Task
Given a positive integer n, output a(n).

You can use 1-based or 0-based indexing, but if you use 0-based indexing, please say so in your answer.

You solution should be able to handle at least as high as a(53) (or if you're using 0-based indexing, a(52)).

Testcases
n     a(n)
1     7
2     8
3     21
4     25
5     46
6     97
7     129
8     161
9     196
10    221
...
13    277
...
50    30015
51    35000
52    39250
53    46111

References
OEIS A181585

"""

# https://oeis.org/A181585
def gen(n):
    r = []
    s = ""
    i = 1
    while len(r) < n:
        t = str(i * i)
        if t in s:
            r.append(i)
        s += t
        i += 1
    return r

def main():
    tab = [7, 8, 21, 25, 46, 97, 129, 161, 196, 221, 245, 258, 277, 296, 350, 436, 460, 592, 661, 694, 789, 804, 875, 877, 1250, 2025, 2221, 3500, 3959, 4020, 5461, 5920, 7925, 9607, 12500, 14772, 19821, 20010, 21825, 22011, 22221, 24012, 25225, 25375, 25388, 26013, 28014, 28064, 29631, 30015, 35000, 39250, 46111]

    assert(gen(len(tab)) == tab)

main()
