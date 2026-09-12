#!/usr/bin/env python3

"""

Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.

Example 1:

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.

Example 2:

Input: date = "2019-02-10"
Output: 41

Constraints:

    date.length == 10
    date[4] == date[7] == '-', and all other date[i]'s are digits
    date represents a calendar date between Jan 1st, 1900 and Dec 31th, 2019.

"""

from datetime import *

def day_of_year(date):
    tm = datetime.strptime(date, "%Y-%m-%d")
    return int(tm.strftime('%j'))

def main():
    assert(day_of_year("2019-01-09") == 9)
    assert(day_of_year("2019-02-10") == 41)

main()
