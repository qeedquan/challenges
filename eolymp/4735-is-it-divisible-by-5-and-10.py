#!/usr/bin/env python3

"""

One number is given. Find, is it divisible by 5 and by 10.

Input
One number that contains no more than 1000 digits.

Output
In the first line print Yes if it is divisible by 5, otherwise print No. In the second line print Yes if it is divisible by 10, otherwise print No.

Examples

Input #1
17

Answer #1
No
No

Input #2
915

Answer #2
Yes
No

"""

def check(n, m):
    if n%m == 0:
        print("Yes")
    else:
        print("No")

def solve(n):
    check(n, 5)
    check(n, 10)

def main():
    solve(17)
    solve(915)

main()
