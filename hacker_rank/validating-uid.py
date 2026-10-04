#!/usr/bin/env python3

"""

ABCXYZ company has up to 100 employees.
The company decides to create a unique identification number (UID) for each of its employees.
The company has assigned you the task of validating all the randomly generated UIDs.

A valid UID must follow the rules below:

It must contain at least 2 uppercase English alphabet characters.
It must contain at least 3 digits (0 - 9).
It should only contain alphanumeric characters (a - z, A - Z & 0 - 9).
No character should repeat.
There must be exactly  characters in a valid UID.
Input Format

The first line contains an integer T, the number of test cases.
The next T lines contains an employee's UID.

Output Format

For each test case, print 'Valid' if the UID is valid. Otherwise, print 'Invalid', on separate lines. Do not print the quotation marks.

Sample Input

2
B1CD102354
B1CDEF2354

Sample Output

Invalid
Valid
Explanation

B1CD102354: 1 is repeating → Invalid
B1CDEF2354: Valid

"""

def between(c, a, b):
    return ord(a) <= ord(c) and ord(c) <= ord(b)

def valid(s):
    if len(s) != 10:
        return False

    m = {}
    for c in s:
        if not (between(c, 'a', 'z') or between(c, 'A', 'Z') or between(c, '0', '9')) or c in m:
            return False
        m[c] = True
    return True

def main():
    assert(valid("B1CD102354") == False)
    assert(valid("B1CDEF2354") == True)

main()
