#!/usr/bin/env python3

"""

https://static.e-olymp.com/content/14/148cf0420904a787941ff56b6d1357c75c3f5c5b.jpg

Given positive integer n. Print the image of size n×n, formed by the asterisk and space characters as shown in the example.

Input
One positive integer n (n≤100).

Output
Print the image n×n.

Examples

Input #1
5

Answer #1
* * *
 * *
* * *
 * *
* * *

Input #2
6

Answer #2
* * *
 * * *
* * *
 * * *
* * *
 * * *

"""

def solve(n):
    print("n=%d" % (n))
    for y in range(n):
        for x in range(n):
            if ((x^y)&1) == 0:
                print('*', end='')
            else:
                print(' ', end='')
        print()
    print()

def main():
    solve(5)
    solve(6)

main()
