#!/usr/bin/env python3

"""

Given a number N, can you fabricate the two numbers NE and NO such that NE is formed by even digits of N and NO is formed by odd digits of N? Examples:

input     NE       NO
126453  264        153
3012      2          31
4628      4628   0
0 is considered as an even number.

In C and JavaScript you should return an array of two elements such as the first is NE and the second is NO.

"""

def even_and_odd(n):
    no, ne = "", ""
    for c in str(n):
        if int(c)%2 != 0:
            no += c
        else:
            ne += c
    if ne == "":
        ne = "0"
    if no == "":
        no = "0"

    return (int(ne), int(no))

assert(even_and_odd(126453) == (264, 153))
assert(even_and_odd(3012) == (2, 31))
assert(even_and_odd(4628) == (4628, 0))

