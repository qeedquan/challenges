#!/usr/bin/env python3

"""

According to the Wikipedia page on the number 69, it is of note that 692=4761 and 693=328509 together use all decimal digits.
The number 69 is in fact the lowest number that satisfies this property.

For a similar reason, 32043 is remarkable: 320432=1026753849 uses all decimal digits.

If we're going to keep talking about numbers that are interesting this way, we'll need some notation.

For most integers n, the powers n2,...,nk will use all ten decimal digits (not counting leading zeroes) at least once for sufficiently large values of k.
If it exists, we'll call the lowest such k the CUDDLE (CUmulative Decimal Digits, Least Exponent) of n.

Task
Write a program or a function that accepts a single non-negative integer n as input and calculates and returns its CUDDLE.

If n does not have a CUDDLE, you may return anything but a positive integer, including an error or an empty string, as long as your code halts eventually.

Test cases
Left column is input, right column is output.

0
1
2          15
3          10
4          10
5          11
6          12
7           7
8           5
9           6
10
11          7
12          6
13          6
14          7
15          9
16          5
17          7
18          4
19          5
20         15
26          8
60         12
69          3
128         3
150         9
200        15
32043       2
1234567890  3

Additional rules
Your code must work for all inputs up to 255.

Note that this involves dealing with pretty large numbers. 2015 is already larger than 2^64.

If you print the result, it may be followed by a linefeed.

Standard code-golf rules apply.

"""

def recurse(n, i, s):
    if len(set(s)) > 10:
        return 1
    return recurse(n, i + 1, s + str(n**i)) + 1

def cuddle(n):
    if n < 2:
        return 0
    return recurse(n, 2, 'L')

def main():
    assert(cuddle(0) == 0)
    assert(cuddle(1) == 0)
    assert(cuddle(2) == 15)
    assert(cuddle(3) == 10)
    assert(cuddle(4) == 10)
    assert(cuddle(5) == 11)
    assert(cuddle(6) == 12)
    assert(cuddle(7) == 7)
    assert(cuddle(8) == 5)
    assert(cuddle(9) == 6)
    assert(cuddle(11) == 7)
    assert(cuddle(12) == 6)
    assert(cuddle(13) == 6)
    assert(cuddle(14) == 7)
    assert(cuddle(15) == 9)
    assert(cuddle(16) == 5)
    assert(cuddle(17) == 7)
    assert(cuddle(18) == 4)
    assert(cuddle(19) == 5)
    assert(cuddle(20) == 15)
    assert(cuddle(26) == 8)
    assert(cuddle(60) == 12)
    assert(cuddle(69) == 3)
    assert(cuddle(128) == 3)
    assert(cuddle(150) == 9)
    assert(cuddle(200) == 15)
    assert(cuddle(32043) == 2)
    assert(cuddle(1234567890) == 3)

main()
