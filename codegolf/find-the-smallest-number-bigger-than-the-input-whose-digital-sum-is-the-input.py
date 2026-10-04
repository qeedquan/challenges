#!/usr/bin/env python3

"""

"Digital sum" refers to the sum of all the digits in a number.

For example, the digital sum of 1324 is 10, because 1+3+2+4 = 10.

The challenge is to write a program/function to calculate the smallest number bigger than the input whose digital sum is the input.

Example with walkthrough
As an example, take the number 9 as the input:

9 = 1+8 -> 18
9 = 2+7 -> 27
9 = 3+6 -> 36
...
9 = 8+1 -> 81
9 = 9+0 -> 90
The valid output would be the smallest number above, which is 18.

Specs
Note that 9 is not the valid output for this example, because the reversed number must be greater than the original number.

Note that the input will be positive.

Test-Cases:
 2 => 11      (2 = 1 + 1)
 8 => 17      (8 = 1 + 7)
12 => 39     (12 = 3 + 9)
16 => 79     (16 = 7 + 9)
18 => 99     (18 = 9 + 9)
24 => 699    (24 = 6 + 9 + 9)
32 => 5999   (32 = 5 + 9 + 9 + 9)

References:
This is OEIS A161561.

"""

# https://oeis.org/A161561
def seq(n):
    if n < 0:
        return 0
    if n < 10:
        return n + 9
    return int(str(n%9) + '9'*(n//9))

def main():
    tab = [
        10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 29, 39, 49, 59, 69, 79, 89, 99,
        199, 299, 399, 499, 599, 699, 799, 899, 999, 1999, 2999, 3999, 4999,
        5999, 6999, 7999, 8999, 9999, 19999, 29999, 39999, 49999, 59999, 69999,
        79999, 89999, 99999, 199999, 299999, 399999
    ]

    assert(seq(2) == 11)
    assert(seq(8) == 17)
    assert(seq(12) == 39)
    assert(seq(16) == 79)
    assert(seq(18) == 99)
    assert(seq(24) == 699)
    assert(seq(32) == 5999)

    for i in range(len(tab)):
        assert(seq(i + 1) == tab[i])

main()
