#!/usr/bin/env python3

"""

Given a natural number n, return the n-th Leyland number.

Leyland Number
Leyland numbers are positive integers k of the form

k=x^y+y^x

Where x and y are integers strictly greater than 1.

They are enumerated in ascending order.

EDIT: @DigitalTrauma suggested I include following "definition":

Imagine we throw xy+yx in a bag for all possible values of x and y, and avoid throwing in duplicates. Then we sort that bag. The sorted bag is our sequence.

Details
You may use 0 or 1 based indexing, whatever suits you best.

Your program must be able to output at least all Leyland numbers less than the maximum of signed 32-bit integers. (The last Leyland number below this limit is 1996813914, at index 82.)

Test cases
The first few terms are following:

8, 17, 32, 54, 57, 100, 145, 177, 320, 368, 512, 593, 945, 1124
A076980 in OEIS, except for the first entry. Note that because of that additional first entry, the indices on OEIS are shifted by one.

More can be found in the OEIS b-file

"""

# https://oeis.org/A076980
def leyland(n):
    if n < 3:
        return []

    l = [3]
    for y in range(2, n+1):
        for x in range(2, n+1):
            l.append(x**y + y**x)
    return sorted(set(l))

def main():
    tab = [3, 8, 17, 32, 54, 57, 100, 145, 177, 320, 368, 512, 593, 945, 1124, 1649, 2169, 2530, 4240, 5392, 6250, 7073, 8361, 16580, 18785, 20412, 23401, 32993, 60049, 65792, 69632, 93312, 94932, 131361, 178478, 262468, 268705, 397585, 423393, 524649, 533169]
    val = leyland(20)
    assert(val[:len(tab)] == tab)

main()
