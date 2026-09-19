#!/usr/bin/env python3

"""

Description

A cyclic number is an integer n digits in length which, when multiplied by any integer from 1 to n, yields a"cycle"of the digits of the original number. That is, if you consider the number after the last digit to "wrap around"back to the first digit, the sequence of digits in both numbers will be the same, though they may start at different positions.For example, the number 142857 is cyclic, as illustrated by the following table:
142857 *1 = 142857
142857 *2 = 285714
142857 *3 = 428571
142857 *4 = 571428
142857 *5 = 714285
142857 *6 = 857142

Input

Write a program which will determine whether or not numbers are cyclic. The input file is a list of integers from 2 to 60 digits in length. (Note that preceding zeros should not be removed, they are considered part of the number and count in determining n. Thus, "01"is a two-digit number, distinct from "1" which is a one-digit number.)
Output

For each input integer, write a line in the output indicating whether or not it is cyclic.

Sample Input

142857
142856
142858
01
0588235294117647

Sample Output

142857 is cyclic
142856 is not cyclic
142858 is not cyclic
01 is not cyclic
0588235294117647 is cyclic

Source

Greater New York 2001

"""

def cyclic(s):
    t = sorted(s)
    for i in range(2, len(s) + 1):
        u = str(int(s) * i)
        if t != sorted(u):
            return False
    return True

def main():
    assert(cyclic("142857") == True)
    assert(cyclic("142856") == False)
    assert(cyclic("142858") == False)
    assert(cyclic("01") == False)
    assert(cyclic("0588235294117647") == True)

main()
