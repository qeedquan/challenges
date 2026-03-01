#!/usr/bin/env python3

"""

So you are given a POSITIVE base 10 (decimal) number. Your job is to reverse the binary digits and return that base 10 number.

Examples:
1 => 1 (1 => 1)
2 => 1 (10 => 01)
3 => 3 (11 => 11)
4 => 1 (100 => 001)
5 => 5 (101 => 101)
6 => 3 (110 => 011)
7 => 7 (111 => 111)
8 => 1 (1000 => 0001)
9 => 9 (1001 => 1001)
10 => 5 (1010 => 0101)
This is a code-golf challenge, so the solution that uses the least bytes wins.

This is A030101 in the OEIS.

"""

# https://oeis.org/A030101
def binrev(n):
    return int(bin(n)[2:][::-1], 2)

def main():
    tab = [0, 1, 1, 3, 1, 5, 3, 7, 1, 9, 5, 13, 3, 11, 7, 15, 1, 17, 9, 25, 5, 21, 13, 29, 3, 19, 11, 27, 7, 23, 15, 31, 1, 33, 17, 49, 9, 41, 25, 57, 5, 37, 21, 53, 13, 45, 29, 61, 3, 35, 19, 51, 11, 43, 27, 59, 7, 39, 23, 55, 15, 47, 31, 63, 1, 65, 33, 97, 17, 81, 49, 113, 9, 73, 41, 105, 25, 89, 57]

    for i in range(len(tab)):
        assert(binrev(i) == tab[i])

main()
