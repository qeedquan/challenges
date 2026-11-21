#!/usr/bin/env python3

"""

Or Fix American Kennel Club's database
As covered by the recent video by Matt Parker, the American Kennel Club permits thirty-seven (37) dogs of each breed to be assigned the same name (source), because of a database restriction for Roman numeral length.

Given an integer, your task is to output the length of its Roman representation.

Rules
Your input will be an integer in the range 1-3899.
Conversion to Roman is performed using the standard subtractive notation (so 4=IV, 9=IX, 95=XCV, 99=XCIX).
This is code-golf, the usual rules apply.
Test-cases
input  output
1      1
2      2
3      3
4      2
5      1
6      2
9      2
10     1
37     6
38     7
95     3
99     4
288    10
2022   6
3089   9
3899   11

"""

"""

https://oeis.org/A006968

@pxeger

The magic number 5739180 encodes the list [2, 4, 3, 2, 1, 2, 3, 2, 1, 0] in base 5, which correspond to the Roman numeral lengths for the decimal digits 9 to 0.
5**(x%10)%5 extracts the x%10th base-5 digit, and the rest is a recursive function to compute the sum per decimal digit of x.

"""
def length(x):
    return x and (5739180 // 5**(x % 10)) % 5 + length(x // 10)

def main():
    tab = [1, 2, 3, 2, 1, 2, 3, 4, 2, 1, 2, 3, 4, 3, 2, 3, 4, 5, 3, 2, 3, 4, 5, 4, 3, 4, 5, 6, 4, 3, 4, 5, 6, 5, 4, 5, 6, 7, 5, 2, 3, 4, 5, 4, 3, 4, 5, 6, 4, 1, 2, 3, 4, 3, 2, 3, 4, 5, 3, 2, 3, 4, 5, 4, 3, 4, 5, 6, 4, 3, 4, 5, 6, 5, 4, 5, 6, 7, 5, 4, 5, 6, 7, 6, 5, 6, 7, 8, 6, 2, 3, 4, 5, 4, 3, 4, 5, 6, 4, 1, 2, 3, 4, 3, 2]

    for i in range(len(tab)):
        assert(length(i + 1) == tab[i])

    assert(length(288) == 10)
    assert(length(2022) == 6)
    assert(length(3089) == 9)
    assert(length(3899) == 11)

main()
