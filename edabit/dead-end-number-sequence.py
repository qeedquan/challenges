#!/usr/bin/env python3

"""

This number sequence can start with any positive integer n. s is the sum of the individual digits in n. If s divides into n evenly then the next term of the series is n//s. Otherwise the next term is n*s. Eventually the series will reach a dead end with two numbers alternating: 58, 754, 12064, 928, 17632, 928, 17632. This series has a length of 5 with 17632 as the last term.

Compose a function that takes a positive integer and returns its series length and its last term.

Examples
deadEnd(5) ➞ [2, 1]

deadEnd(11) ➞ [7, 11440]

deadEnd(123456789) ➞ [2, 5555555505]

deadEnd(35161) ➞ [39, 154838313273413215779502672965210112000]

deadEnd(101) ➞ [9, 136804096]

Notes
N/A

"""

def digsum(n):
    r = 0
    while n > 0:
        r += n % 10
        n //= 10
    return r

def deadend(n):
    m, p, c = {}, n, 0
    while True:
        s = digsum(n)
        if n in m or s == 0:
            break
        m[n], p = True, n
        
        if n%s == 0:
            n //= s
        else:
            n *= s
        c += 1

    return (c, p)

def main():
    assert(deadend(58) == (5, 17632))
    assert(deadend(5) == (2, 1))
    assert(deadend(11) == (7, 11440))
    assert(deadend(123456789) == (2, 5555555505))
    assert(deadend(35161) == (39, 154838313273413215779502672965210112000))
    assert(deadend(101) == (9, 136804096))
    assert(deadend(1) == (1, 1))
    assert(deadend(9) == (2, 1))
    assert(deadend(1000) == (1, 1000))
    assert(deadend(999) == (3, 370))
    assert(deadend(38) == (12, 174813842944))
    assert(deadend(93) == (9, 217))
    assert(deadend(11615819) == (74, 1354959139828966431926720346323206635520))
    assert(deadend(100000001) == (15, 220258825732))

main()
