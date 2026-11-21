#!/usr/bin/env python3

"""

Union of closed disjoint intervals
Write a function interval_insert which takes as input

a list myl of disjoint closed intervals with integer endpoints, sorted by increasing order of left endpoints
an interval interval
and returns the union of interval with the intervals in myl, as an array of disjoint closed intervals.

Terminology
A closed interval includes its endpoints. For example [0,5] means greater than or equal to 0 and less than or equal to 5. For more, refer to Wikipedia.

Two intervals are said to be disjoint if they have no element in common. Equivalently, disjoint intervals are intervals whose intersection is the empty interval. For example,
[1,3] and [4,6] are disjoint
[1,3] and [3,5] are not.

Examples:
                         [(1, 2)], (3, 4) -> [(1, 2), (3, 4)]
                         [(3, 4)], (1, 2) -> [(1, 2), (3, 4)]
                 [(1, 2), (4, 6)], (1, 4) -> [(1, 6)]
[(0, 2), (3, 6), (7, 7), (9, 12)], (1, 8) -> [(0, 8), (9, 12)]

"""

def interval_insert(intervals, interval):
    intervals.append(interval)
    intervals = sorted(intervals)

    length = 0
    for i in range(1, len(intervals)):
        if intervals[length][1] >= intervals[i][0]:
            if intervals[length][1] <= intervals[i][1]:
                intervals[length] = (intervals[length][0], intervals[i][1])
        else:
            length += 1
            intervals[length] = intervals[i]
    return intervals[:length + 1]

def main():
    assert(interval_insert([(1, 2)], (3, 4)) == [(1, 2), (3, 4)])
    assert(interval_insert([(3, 4)], (1, 2)) == [(1, 2), (3, 4)])
    assert(interval_insert([(1, 2), (4, 6)], (1, 4)) == [(1, 6)])
    assert(interval_insert([(0, 2), (3, 6), (7, 7), (9, 12)], (1, 8)) == [(0, 8), (9, 12)])

main()
