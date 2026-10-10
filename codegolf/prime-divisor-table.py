#!/usr/bin/env python3

"""

Intro
Something I've played around with in recreational mathematics has been construction of a divisor table to visually compare/contrast the prime divisors of a set of numbers. The set of input numbers are across the top as column labels, the prime divisors are on the left as row labels, and a mark indicates where the two line up.

For example, for input 6, 9, 14, 22 a table similar to the following would be constructed:

    6  9 14 22
 2  *     *  *
 3  *  *
 7        *
11           *
This is because 6 has prime divisors of 2 and 3, 9 has prime divisors of 3, and so on.

Construction
The table is constructed such that the input numbers form column labels that are separated by spaces and in ascending order (you can assume they are pre-sorted), and the prime divisors are listed on the left in ascending order one per line forming the row labels.
Note that leading spaces on the prime divisors and input numbers may be required if the numbers are different lengths, so that all columns are the same width and line up appropriately.
Each divisor is represented by a single * (or other suitable ASCII character of your choosing, so long as the same character is used for all occurrences).
Multiple divisors are ignored (e.g., 3 x 3 = 9 but there's only one * for that intersection).
The * can be placed anywhere horizontally in the column, so long as it's unambiguous (I have all my examples with the * right-aligned).

Input
A list of positive integers in any convenient format, each >1.
You can assume that the input is pre-sorted.
The input is guaranteed to have only unique values.

Output
The resulting ASCII art representation of the prime divisor table.

Rules
Leading or trailing newlines or whitespace are all optional, so long as the characters themselves line up correctly.
If it's shorter to have a divider line separating the column/row headings from the tabular data, that's allowed, too.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
If possible, please include a link to an online testing environment so people can try out your code!
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

Examples
6,9,14,22

    6  9 14 22
 2  *     *  *
 3  *  *
 7        *
11           *


2,3,5,7

  2 3 5 7
2 *
3   *
5     *
7       *

2,4,8,16,32

   2  4  8 16 32
2  *  *  *  *  *

75,99,151,153

     75  99 151 153
  3   *   *       *
  5   *
 11       *
 17               *
151           *

"""

from sympy import *
from math import *

def table(p):
    r = 0
    c = 0
    m = {}
    q = []
    for v in p:
        for u in primefactors(v):
            m[(u, v)] = True
            q.append(u)
            r = max(c, ceil(log10(u)) + 1)
        c = max(r, ceil(log10(v)) + 1)
    
    p = sorted(p)
    q = sorted(list(dict.fromkeys(q)))

    print(' ' * r, end='')
    for v in p:
        print("%*d" % (c, v), end='')
    print()

    for u in q:
        print("%*d" % (r, u), end='')
        for v in p:
            print(' ' * (c - 1), end='')
            if (u, v) in m:
                print("*", end='')
            else:
                print(" ", end='')
        print()
    
    print()

def main():
    table([6, 9, 14, 22])
    table([2, 3, 5, 7])
    table([2, 4, 8, 16, 32])
    table([75, 99, 151, 153])

main()
