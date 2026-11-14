#!/usr/bin/env python3

"""

To "shift" over a number n places, do the following:

Remove the last n digits
Add n copies of the first digit to the beginning of the number
For example, to shift the number 31415 three places, take out the last three digits to get 31, and then add three more copies of the first digit, 3, to the end, giving 33331.

If the number is negative, digits should be taken from the left instead, and the first digit should be "filled in" from the right. For example, the string 31415 shifted over -3 places gives 15555.

If the number is 0, no change should be made.

If the shift is more than the length of the program, then digits that were filled in might start to be removed. This means that if the number given is more than the length of the string, no further changes will be made after the entire string becomes a single digit.

The challenge
Given two numbers, n and s, return n shifted over s places.

Test cases
   n,  s -> result
7243,  1 -> 7724
 452, -1 -> 522
  12,  1 -> 11
 153,  4 -> 111
This is code-golf, so the shortest valid submission (measured in bytes) wins.

"""

def shifter(n, s):
    i = 0
    if s < 0:
        i = -s
    t = str(n)

    p = t[0]*s + t + t[-1]*-s
    p = p[i:][:len(t)]

    return int(p)

def main():
    assert(shifter(7243, 1) == 7724)
    assert(shifter(452, -1) == 522)
    assert(shifter(12, 1) == 11)
    assert(shifter(153, 4) == 111)

main()
