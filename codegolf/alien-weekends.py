#!/usr/bin/env python3

"""

Alien Weekends!
I've crash-landed on another planet! Luckily, the alien society I landed in is almost identical to that of Earth's, except for their timekeeping. Their calendar doesn't use months, so each day is represented by a single nonnegative integer. Each alien week consists of m weekdays followed by an n-day weekend, with the first day of the first week being 0. I'd like to know exactly how many weekdays and weekends are in a week, but I'm too embarrassed to ask.

Fortunately, one of the local aliens started talking about xyr job and mentioned a few days that are part of the week, and a few that are part of the weekend. I'd like some code that could use what xe said in order to tell me how long the week is.

Challenge
Given two disjoint, non-empty lists of distinct nonnegative integers (d and e), output two positive integers m and n such that:

For each weekday di in d, di%(m+n)<m
For each weekend day ei in e, ei%(m+n)>=m
Alternatively, you may output m+n and either m or n. If you wish, you can take input as 1-indexed: that is, the first week starts on 1, (di-1)%(m+n)<m and (ei-1)%(m+n)>=m. If you use an alternative input or output method, mention it in your answer.

You are guaranteed that there exists at least one pair of valid m and n values. If multiple outputs are possible, you may output any of them.

Examples
[0, 3, 4, 8, 11], [5, 6, 12] -> 5, 2
The alien (yet familiar) calendar looks like this:

A  B  C  D  E  F  G
-------------- ~~~~~
0  1  2  3  4  5  6
7  8  9  10 11 12 13
Days A (0), B (8), C, D (3), and E (4, 11) are weekdays, while F (5, 12) and G (6) are weekends. Note that the calendar will always begin on a weekday, and end on a weekend.

[0, 2, 6], [7, 9] -> 1, 1 OR 7, 3/4/5/...
The calendar might look like this:

A B
- ~
0 1
2 3
4 5
6 7
8 9
OR like this:

A B C D E F G H I J
------------- ~~~~~
0 1 2 3 4 5 6 7 8 9
As such, both 1, 1 and 7, 3 are valid outputs. Notably, 7, 4 or 7, [integer greater than 2] are also valid, with none of the mentioned days occurring on the second week.

Samples
These each take 0-indexed input and output m, n.

[0, 3, 4, 8, 11], [5, 6, 12] -> 5, 2
[0, 2, 6], [7, 9] -> 1, 1 OR 7, 3/4/5/...
[3, 14, 1], [5, 9, 26] -> 5, 5 OR 4, 7 OR 5, 9 OR 4, 10
[8, 16, 24], [3, 4, 7, 9] -> 1, 7

"""

# Ported from @Ajax1234 solution
def find(d, e):
    candidates = [(1, 1)]
    for m, n in candidates:
        period = m + n
        if all(i%period < m for i in d) and all(i%period >= m for i in e):
            return m, n
        candidates.extend([(m + 1, n), (m, n + 1)])

def main():
    assert(find([0, 3, 4, 8, 11], [5, 6, 12]) == (5, 2))
    assert(find([0, 2, 6], [7, 9]) == (1, 1))
    assert(find([3, 14, 1], [5, 9, 26]) == (5, 5))
    assert(find([8, 16, 24], [3, 4, 7, 9]) == (1, 7))

main()
