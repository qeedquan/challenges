#!/usr/bin/env python3

"""

Given an integer N, output the Nth positive number K with the following property in decimal base:

For each digit I at position P of K, the number formed from K by removing the Pth digit (i.e. I) is divisible by I.

Example and remarks
324 is such a number:

3 divides 24
2 divides 34
4 divides 32
Note 1: we assume that the empty number is divisible by anything, like 0. Therefore 1, 2, 3, 4, 5, 6, 7, 8 and 9 are valid.

Note 2: K cannot contain the digit 0, since you cannot divide by 0.

Inputs and outputs
You may take the input as a function argument, through STDIN, etc.
You may return the output from a function, through STDOUT, etc.
You may index those numbers starting from 0 (in which case N >= 0) or from 1 (in which case N > 0), whichever suits you more.

Test cases
Those examples are indexed from 0, so if you indexed from 1, then add 1 to the numbers in the N column.

N    Output
0    1
4    5
8    9
15   77
16   88
23   155
42   742
47   1113
121  4244
144  6888
164  9999

Scoring
This is code-golf, so the shortest answer in bytes wins.

"""

def satisfy(n):
    s = str(n)
    if "0" in s:
        return False
    a = [int("0" + s[1:])] + [int(s[:x] + s[x + 1 :]) for x in range(1, len(s))]
    b = [int(s[x]) for x in range(len(s))]
    c = [a[x] % b[x] for x in range(len(s))]
    return not any(c)

# Ported from @LeakyNun solution
def excludivisible(n):
    c, i = -1, 1
    while True:
        if satisfy(i):
            c += 1
        if c == n:
            break
        i += 1
    return i

def main():
    assert(excludivisible(0) == 1)
    assert(excludivisible(4) == 5)
    assert(excludivisible(8) == 9)
    assert(excludivisible(15) == 77)
    assert(excludivisible(16) == 88)
    assert(excludivisible(23) == 155)
    assert(excludivisible(42) == 742)
    assert(excludivisible(47) == 1113)
    assert(excludivisible(121) == 4244)
    assert(excludivisible(144) == 6888)
    assert(excludivisible(164) == 9999)

main()
