#!/usr/bin/env python3

"""

This time the input is a sequence of course-ids that are formatted in the following way:

name-yymm

The return of the function shall first be sorted by yymm, then by the name (which varies in length).

"""

def sort_me(courses):
    return sorted(courses, key=lambda c: (c.rsplit("-", 1)[1], c.rsplit("-", 1)[0]))

def main():
    print(sort_me(["abc-9912", "xyz-9811", "dbf-9901", "abc-9903"]))

main()
