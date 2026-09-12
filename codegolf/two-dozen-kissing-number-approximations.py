#!/usr/bin/env python3

"""

Given a number from 1 to 24, output the kissing number to the best of current knowledge (some numbers will have more than one acceptable output).
Knowledge of geometry is not essential as the outputs are all listed below.

From the Wikipedia page on the Kissing Number Problem:

a kissing number is defined as the number of non-overlapping unit spheres that can be arranged such that they each touch another given unit sphere

That is, given one unit sphere, how many more unit spheres can touch it without any of them overlapping? The question will be asked in N dimensional space, where a sphere is understood to be an N-1 dimensional sphere.

For example:

in 2 dimensional space, a unit circle can touch 6 other unit circles.
in 3 dimensional space, a unit sphere can touch 12 other unit spheres.
The Wikipedia page lists values for 1 to 24 dimensional space. However, some of these are not yet known accurately, so only a lower and upper bound are given.
The table is reproduced here so that it will remain fixed, regardless of any future narrowing of the ranges due to new proofs. Solutions are judged against this fixed table, even if the Wikipedia page is modified in future.

Table of bounds
Dimension   Lower bound     Upper bound
1           2               2
2           6               6
3           12              12
4           24              24
5           40              44
6           72              78
7           126             134
8           240             240
9           306             364
10          500             554
11          582             870
12          840             1357
13          1154            2069
14          1606            3183
15          2564            4866
16          4320            7355
17          5346            11072
18          7398            16572
19          10668           24812
20          17400           36764
21          27720           54584
22          49896           82340
23          93150           124416
24          196560          196560

Input
The dimension: An integer from 1 to 24 (inclusive).

Here "integer" indicates that the input will have no fractional part - it may be 2 or 3 but never 2.5. A solution may still take input as a float, or a string, for example.

Output
A number in the relevant range, from the lower limit to the upper limit for that input (inclusive).

The output must be deterministic (always the same for the same input).

The output must be integer. For example, for input 5 the possible valid outputs are 40, 41, 42, 43, 44.
Note this is a restriction on the value, not the type. It is acceptable to return a float, provided it has zero fractional part.
For example, 41.5 would not be valid, but 41.0 would be valid.

Scoring
This is code-golf. Your score is the number of bytes in your code. For each language, the winner is the solution with the lowest score.

"""

KISSINGS = [
    [1, 2, 2],
    [2, 6, 6],
    [3, 12, 12],
    [4, 24, 24],
    [5, 40, 44],
    [6, 72, 78],
    [7, 126, 134],
    [8, 240, 240],
    [9, 306, 364],
    [10, 500, 554],
    [11, 582, 870],
    [12, 840, 1357],
    [13, 1154, 2069],
    [14, 1606, 3183],
    [15, 2564, 4866],
    [16, 4320, 7355],
    [17, 5346, 11072],
    [18, 7398, 16572],
    [19, 10668, 24812],
    [20, 17400, 36764],
    [21, 27720, 54584],
    [22, 49896, 82340],
    [23, 93150, 124416],
    [24, 196560, 196560]
]

def f(x):
    if x < 1 or x >= len(KISSINGS)+1:
        return 0
    
    k = KISSINGS[x-1]
    return round((k[1] + k[2]) * 0.5)

def main():
    for i in range(1, 25):
        print(i, f(i))

main()
