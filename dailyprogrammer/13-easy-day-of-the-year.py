#!/usr/bin/env python3

"""

Find the number of the year for the given date. For example, january 1st would be 1, and december 31st is 365.

for extra credit, allow it to calculate leap years, as well.

"""

from datetime import date

def yearday(month, day, year=1970):
    d = date(year, month, day)
    t = d.timetuple()
    return t.tm_yday

def main():
    assert(yearday(1, 1) == 1)
    assert(yearday(12, 31) == 365)

main()
