#!/usr/bin/env python3

"""

Description

A number whose only prime factors are 2,3,5 or 7 is called a humble number. The sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27, ... shows the first 20 humble numbers.

Write a program to find and print the nth element in this sequence.
Input

The input consists of one or more test cases. Each test case consists of one integer n with 1 <= n <= 5842. Input is terminated by a value of zero (0) for n.
Output

For each test case, print one line saying "The nth humble number is number.". Depending on the value of n, the correct suffix "st", "nd", "rd", or "th" for the ordinal number nth has to be used like it is shown in the sample output.

Sample Input

1
2
3
4
11
12
13
21
22
23
100
1000
5842
0

Sample Output

The 1st humble number is 1.
The 2nd humble number is 2.
The 3rd humble number is 3.
The 4th humble number is 4.
The 11th humble number is 12.
The 12th humble number is 14.
The 13th humble number is 15.
The 21st humble number is 28.
The 22nd humble number is 30.
The 23rd humble number is 32.
The 100th humble number is 450.
The 1000th humble number is 385875.
The 5842nd humble number is 2000000000.

Source

Ulm Local 1996

"""

import heapq

# https://oeis.org/A002473
def gen(n):
    primes = [2, 3, 5, 7]
    r, u, v, h = [], 0, 1, [1]
    while len(r) < n:
        v = heapq.heappop(h)
        if v != u:
            r.append(v)
            u = v
            for p in primes:
                heapq.heappush(h, v*p)
    return r

def main():
    tab = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27, 28, 30, 32, 35, 36, 40, 42, 45, 48, 49, 50, 54, 56, 60, 63, 64, 70, 72, 75, 80, 81, 84, 90, 96, 98, 100, 105, 108, 112, 120, 125, 126, 128, 135, 140, 144, 147, 150, 160, 162, 168, 175, 180, 189, 192]

    x = gen(10000)
    assert(x[:len(tab)] == tab)
    assert(x[99] == 450)
    assert(x[999] == 385875)
    assert(x[5841] == 2000000000)

main()
