#!/usr/bin/env python3

"""

There may be an actual name to this base system (let us/me know in comments), and there is a math insight that makes this problem even easier, but it is still pretty easy with no math insight.

for "permutation base 2", the indexes and values start with:

index	value
0	0
1	1
2	00
3	01
4	10
5	11
6	000
7	001
8	010
9	011
sample challenge:

what is the base-value for index 54?

what is the index-value for base 111000111

solutions:

 permbase2 54
1 1 0 0 0

 permbase2 inv 1 1 1 0 0 0 1 1 1
965

challenge index inputs (some are 64 bit+ inputs)

234234234
234234234234234
234234234234234234234234

challenge value inputs

000111000111111000111111000111111000111
11111111000111000111111000111111000111111000111

bonus:

extend the function to work with any base. Base 10 index value 10 is 00. index value 109 is 99

"""

def permbase2_inv(s):
    return int(s, base=2) + 2**len(s) - 2

def permbase2(n):
    x = 1
    while 2**x <= n:
        n -= 2**x
        x += 1
    return '{0:0{count}b}'.format(n, count=x)

def main():
    assert(permbase2(54) == "11000")
    assert(permbase2(234234234) == "101111101100010000101111100")
    assert(permbase2(234234234234234) == "10101010000100011101000010100110110010101111100")
    assert(permbase2(234234234234234234234234) == "10001100110011101110100000000000000011110000000000101011011000110010101111100")

    assert(permbase2_inv("111000111") == 965)
    assert(permbase2_inv("000111000111111000111111000111111000111") == 610944389061)
    assert(permbase2_inv("11111111000111000111111000111111000111111000111") == 280986409471941)

main()
