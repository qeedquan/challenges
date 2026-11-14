#!/usr/bin/env python3

"""

The challenge
The program must return all numbers included into a group (comma and hyphen separated sequence) of numbers.

Rules
s is the sequence string;
all numbers included in s are positive;
numbers will always increase;
numbers will never repeat
when you answer, show the output for s="1,3-5,9,16,18-23"
Examples
input(s)    outputs
-----------------
1           1
1,2         1,2
1-4         1,2,3,4
1-4,6       1,2,3,4,6
1-4,8-11    1,2,3,4,8,9,10,11
Good luck. =)

"""

def ranges(string):
    output = []
    for field in string.split(','):
        if '-' in field:
            start, end = map(int, field.split('-'))
            output += range(start, end + 1)
        else:
            output += [int(field)]
    return output

def main():
    assert(ranges("1") == [1])
    assert(ranges("1,2") == [1, 2])
    assert(ranges("1-4") == [1, 2, 3, 4])
    assert(ranges("1-4,6") == [1, 2, 3, 4, 6])
    assert(ranges("1-4,8-11") == [1, 2, 3, 4, 8, 9, 10, 11])

main()
