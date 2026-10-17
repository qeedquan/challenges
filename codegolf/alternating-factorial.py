#!/usr/bin/env python3

"""

The alternating factorial is defined as

af(n) = Sum[i=1, n] (-1)^(n-i) * i!

where i! is the regular factorial of i:

For example,
af(4) = (-1)^3*1! + (-1)^2*2! + (-1)^1*3! + (-1)^0*4! = 19

The alternating factorial can also be calculated by the recurrence relation
af(n) = {0,            if n=0
         n! - af(n−1), otherwise
The sequence of alternating factorials is OEIS A005165.

Task
Given a non-negative integer as input, output its alternating factorial. You don't need to worry about values exceeding your language's integer limit. This is code-golf, so the code with the fewest bytes (in each language) wins.

Test cases
n   af(n)
0   0
1   1
2   1
3   5
4   19
5   101
6   619
7   4421
8   35899
9   326981

"""

# https://oeis.org/A005165
def altfact(n):
    a = 0
    f = 1
    for i in range(1, n + 1):
        f *= i
        a = f - a
    return a

def main():
    tab = [0, 1, 1, 5, 19, 101, 619, 4421, 35899, 326981, 3301819, 36614981, 442386619, 5784634181, 81393657019, 1226280710981, 19696509177019, 335990918918981, 6066382786809019, 115578717622022981, 2317323290554617019, 48773618881154822981]

    for i in range(len(tab)):
        assert(altfact(i) == tab[i])

main()
