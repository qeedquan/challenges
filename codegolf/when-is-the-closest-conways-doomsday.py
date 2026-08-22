#!/usr/bin/env python3

"""

A quote from MO.SE answer:

Although it is well known that Conway was able to quickly calculate the day of the week of any given date, it is less well known that one part of the algorithm is easy to remember and useful in practice: In any given year, the following dates all fall on the same day of the week: 4/4, 6/6, 8/8, 10/10, 12/12, 5/9, 9/5, 7/11, 11/7, and the last day of February. For example, in 2020, all these dates fall on a Saturday. Conway, in his characteristically colorful way, would say that the Doomsday of 2020 is Saturday. Knowing this fact allows you to calculate fairly quickly in your head, with no special training, the day of the week for any date in 2020.

Well, it sounds easy, but then we need to check which doomsday is the closest from the given date in order to quickly calculate the day of week. Now that sounds hard.

Practically, we'd just compare a given date with the Doomsday in the same month (or adjacent month in case of January and March).

Task
Given a date consisting of full year, month, and day, output the closest Conway's Doomsday (i.e. one of 4/4, 6/6, 8/8, 10/10, 12/12, 5/9, 9/5, 7/11, 11/7, and the last day of February) from the given date.

The closest Doomsday can be in the same month, a different month, or even a different year. If the given date has two nearest Doomsdays, output any one or both of them. Also note that the last day of February can be either 28th or 29th (depending on leap-year-ness).

You can take input and produce output in any suitable format, e.g. three integers, a formatted string, or even a built-in Date object (if your language has one). You can assume the given date is valid, and the input year is between 1901 and 2099 inclusive. Gregorian calendar is assumed in this challenge.

Test cases
YYYY-MM-DD => YYYY-MM-DD, ...
-------------------------------
2020-05-18 => 2020-05-09
2020-05-30 => 2020-06-06
2020-10-31 => 2020-11-07
2020-10-24 => 2020-10-10 or 2020-11-07
2020-01-20 => 2019-12-12
2020-01-21 => 2020-02-29
2019-01-20 => 2018-12-12 or 2019-02-28

Reference implementation in Python.

from datetime import*
from calendar import*

def f(y,m,d):
 doom = lambda y:[date(y,m,d)for m,d in[(2,28+isleap(y)),(4,4),(5,9),(6,6),(7,11),(8,8),(9,5),(10,10),(11,7),(12,12)]]
 dooms = doom(y-1)+doom(y)+doom(y+1)
 diffs = [abs(date(y,m,d) - doom) for doom in dooms]
 print([dm for dm,df in zip(dooms, diffs) if df == min(diffs)])

"""

from datetime import *
from calendar import *

def doomsday(y, m, d):
    doom = lambda y: [
        date(y, m, d)
        for m, d in [
            (2, 28 + isleap(y)),
            (4, 4),
            (5, 9),
            (6, 6),
            (7, 11),
            (8, 8),
            (9, 5),
            (10, 10),
            (11, 7),
            (12, 12),
        ]
    ]
    dooms = doom(y - 1) + doom(y) + doom(y + 1)
    diffs = [abs(date(y, m, d) - doom) for doom in dooms]
    result = [dm for dm, df in zip(dooms, diffs) if df == min(diffs)]
    return result

def main():
    assert(doomsday(2020, 5, 18) == [date(2020, 5, 9)])
    assert(doomsday(2020, 5, 30) == [date(2020, 6, 6)])
    assert(doomsday(2020, 10, 31) == [date(2020, 11, 7)])
    assert(doomsday(2020, 10, 24) == [date(2020, 10, 10), date(2020, 11, 7)])
    assert(doomsday(2020, 1, 20) == [date(2019, 12, 12)])
    assert(doomsday(2020, 1, 21) == [date(2020, 2, 29)])
    assert(doomsday(2019, 1, 20) == [date(2018, 12, 12), date(2019, 2, 28)])

main()
