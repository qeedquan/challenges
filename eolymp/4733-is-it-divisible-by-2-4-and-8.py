#!/usr/bin/env python3

"""

A nonnegative integer is given. Check if it is divisible by 2, by 4 and by 8.

Input
One nonnegative integer, that contains no more than 100 digits.

Output
Print in the first line Yes if the number is divisible by 2, otherwise print No.

Print in the second line Yes if the number is divisible by 4, otherwise print No.

Print in the third line Yes if the number is divisible by 8, otherwise print No.

Examples

Input #1
16

Answer #1
Yes
Yes
Yes

Input #2
7135618

Answer #2
Yes
No
No

"""

def solve(n):
    for i in [n%2, n%4, n%8]:
        if i == 0:
            print("Yes")
        else:
            print("No")
    print()

def main():
    solve(16)
    solve(7135618)

main()

