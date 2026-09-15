#!/usr/bin/env python3

"""

A hill number is a number that has the same digit in the first & the last, but that's not all. In a hill number the first digits are strictly increasing until the largest digit, and after the largest digit, the last digits are strictly decreasing. The largest digit can be repeated but consecutively only, meaning no gaps by smaller numbers.

Here is an example of a hill number:

12377731 | 1237...             | ...731
^ same ^ | strictly increasing | strictly decreasing
---------+---------------------+---------------------
12377731
   ^^^ okay because largest digit can be repeated
This is not:

4588774 | ...8774
        |     ^^ not the largest digit
        |        so this has to be strictly decreasing
        |        but it's not, so not a hill number
Challenge
Given a positive integer, write a full program or a function that returns truthy for hill numbers but falsy on other values.

Notes:

Input & output can be in any reasonable format.
This is code-golf so shortest answer in each language wins!

Test Cases
12321 -> Truthy
1233321 -> Truthy
99 -> Truthy
3 -> Truthy
234567992 -> Truthy
5555555 -> Truthy
1232 -> Falsy
778896 -> Falsy
23232 -> Falsy
45566554 -> Falsy
5645 -> Falsy

"""

# Ported from @etene solution
def ishill(n):
    p = (1, -2)
    r = str(n)
    l = [*r]
    for i in (-1, 0):
        while len(l) > 1 and l[i] < l[p[i]]:
            l.pop(i)
    return len({*l}) < 2 and r[0] == r[-1]

def main():
    assert(ishill(12321) == True)
    assert(ishill(1233321) == True)
    assert(ishill(99) == True)
    assert(ishill(3) == True)
    assert(ishill(234567992) == True)
    assert(ishill(5555555) == True)
    assert(ishill(1232) == False)
    assert(ishill(778896) == False)
    assert(ishill(23232) == False)
    assert(ishill(45566554) == False)
    assert(ishill(5645) == False)

main()
