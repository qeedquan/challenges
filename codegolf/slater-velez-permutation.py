#!/usr/bin/env python3

"""

Let's build a sequence of positive integers. The rule will be that the next number will be the smallest number which:

It hasn't already appeared in the sequence
Its absolute difference from the number preceding it wouldn't be equal to any previous absolute difference between consecutive elements.
Task
Your task is to implement this sequence. You may use sequence defaults, found in the tag wiki.

This is code-golf so answers will be scored in bytes with fewer bytes being better.

Example
As an example let's construct the first couple of terms. The first term is 1 since it's the smallest positive integer. After that comes 2.

Sequence: 1, 2
Diffs:     1
3 is the next smallest number, but it's difference from 2 is the same as the difference between 1 and 2, so 4 is the next term.

Sequence: 1, 2, 4
Diffs:     1, 2
Now 3 still can't be added because it's difference from 4 is 1, 5 and 6 also can't be added because their diffs are 1 and 2. So the smallest number is 7.

Sequence: 1, 2, 4, 7
Diffs:     1, 2, 3
Now 3 can be added, since it's difference from 7 is 4 which we haven't seen before.

Sequence: 1, 2, 4, 7, 3
Diffs:     1, 2, 3, 4
Since the diffs count up to 4 we know the next one is at least 5, so the next number is at least 8. 8 hasn't appeared so we can add it.

Sequence: 1, 2, 4, 7, 3, 8
Diffs:     1, 2, 3, 4, 5

Test cases
This sequence is OEIS A081145. Here are the first few terms taken from OEIS:

1, 2, 4, 7, 3, 8, 14, 5, 12, 20, 6, 16, 27, 9, 21, 34, 10, 25, 41, 11, 28, 47, 13, 33, 54, 15, 37, 60, 17, 42, 68, 18, 45, 73, 19, 48, 79, 22, 55, 23, 58, 94, 24, 61, 99, 26, 66, 107, 29, 71, 115, 30, 75, 121, 31, 78, 126, 32, 81, 132, 35, 87, 140, 36, 91, 147, 38, 96, 155, 39


"""

# https://oeis.org/A081145
# ported from @pxeger solution
def gen(n):
    r = []
    p = 1
    m = {0, p}
    while len(r) < n:
        r.append(p)
        d = p
        while True:
            s = {p - d, -d * d}
            if not s&m:
                m |= s
                break
            d -= 1
        p -= d
    return r

def main():
    tab = [1, 2, 4, 7, 3, 8, 14, 5, 12, 20, 6, 16, 27, 9, 21, 34, 10, 25, 41, 11, 28, 47, 13, 33, 54, 15, 37, 60, 17, 42, 68, 18, 45, 73, 19, 48, 79, 22, 55, 23, 58, 94, 24, 61, 99, 26, 66, 107, 29, 71, 115, 30, 75, 121, 31, 78, 126, 32, 81, 132, 35, 87, 140, 36, 91, 147, 38, 96, 155, 39]

    assert(gen(len(tab)) == tab)

main()
