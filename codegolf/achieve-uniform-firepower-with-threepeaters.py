#!/usr/bin/env python3

"""

The Threepeater from Plants vs. Zombies fires three peas at a time: one in its own lane and one in each of the two adjacent lanes. On the top and bottom lanes, it only fires two peas at a time, since those lanes only have one adjacent lane.

It's a cool plant, but there's one not-so-nice thing about it: using it often gets you uneven firepower between lanes. For example, if you just planted one on each lane of a five-lane lawn, you'd get less firepower on the top and bottom lanes:

Count - Threepeaters | Firepower - Amount
1       A              AB          2
1       B              ABC         3
1       C               BCD        3
1       D                CDE       3
1       E                 DE       2
And if you planted on the same lawn in a pattern of [0, 2, 0, 2, 0], you'd get significantly more firepower in the middle lane:

Count - Threepeaters | Firepower - Amount
0                      AB          2
2       AB             AB          2
0                      ABCD        4
2       CD               CD        2
0                        CD        2
However, there are ways to plant Threepeaters without this unevenness in firepower. For a five-lane lawn, we can plant in a pattern of [1, 1, 0, 1, 1] to get a uniform firepower of 2 "units" in each lane:

Count - Threepeaters | Firepower - Amount
1       A              AB          2
1       B              AB          2
0                       BC         2
1       C                CD        2
1       D                CD        2
This is actually less cost-effective than the previous pattern, but in the name of symmetry over efficiency, this is the kind of planting configuration that we will pursue. This challenge is about finding this kind of uniform-firepower solution for  n
  lanes.

Task
Given a number of lanes n (you may assume  5≤n≤28), output an n-lane planting pattern (a list of n numbers, indicating how many Threepeaters there are in each lane) such that every lane gets the same amount of firepower. There are infinitely many possible solutions for any given  n
 ; you may output any one of them. At least one Threepeater must be planted, so [0, 0, ..., 0] is never a valid solution. I/O can be in any reasonable format.

This is code-golf -- shortest code in each language wins.

Example solutions
5: [1, 1, 0, 1, 1], [0, 1, 0, 0, 1]
6: [0, 2, 0, 0, 2, 0]
7: [1, 0, 0, 1, 0, 0, 1]
8: [1, 0, 0, 1, 0, 0, 1, 0], [3, 5, 0, 3, 5, 0, 3, 5]
9: [0, 3, 0, 0, 3, 0, 0, 3, 0]
10: [99, 0, 0, 99, 0, 0, 99, 0, 0, 99]
Python function to validate a solution for a given n:

def check(n: int, solution: list[int]) -> bool:
    if len(solution) != n: return False
    if sum(solution) == 0: return False
    firepower = [0] * n
    for i, p in enumerate(solution):
        for j in {i - 1, i, i + 1}:
            if 0 <= j < n:
                firepower[j] += p
    return len(set(firepower)) == 1

"""

def check(n, solution):
    if len(solution) != n:
        return False
    if sum(solution) == 0:
        return False
    firepower = [0] * n
    for i, p in enumerate(solution):
        for j in {i - 1, i, i + 1}:
            if 0 <= j < n:
                firepower[j] += p
    return len(set(firepower)) == 1

"""

@Dominic van Essen

1..n multiplied by n..1, modulo 3.
If n divides by 3, plant a threepeater in the second lane, otherwise in the first lane. Then plant a threepeater every 3rd lane after that.

"""

def gen(n):
    r = []
    for i in range(1, n + 1):
        x = i * (n - i + 1)
        r.append(x % 3)
    return r

def main():
    for i in range(5, 1000):
        assert(check(i, gen(i)) == True)

main()
