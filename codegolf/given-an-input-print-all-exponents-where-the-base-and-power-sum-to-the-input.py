#!/usr/bin/env python3

"""

So this is my first challenge on this site.

The challenge is to take in an input integer n, which will be positive, and print, in ascending order (1 to n, including n), the output of i(n−i) (where i is the current integer).

Example
Given the input 5, the program will print:

1
8
9
4
1

1^4 is 1 and 1+4=5
2^3 is 8 and 2+3=5
3^2 is 9 and 3+2=5
4^1 is 4 and 4+1=5
5^0 is 1 and 5+0=5

Input and Output
Input will be in the form of a positive integer. Output will be a list of numbers, delimited by either commas or new lines.

This is code-golf, so shortest code wins.

"""

def gen(n):
    r = []
    for i in range(1, n + 1):
        r.append(i**(n - i))
    return r

def main():
    assert(gen(5) == [1, 8, 9, 4, 1])

main()
