#!/usr/bin/env python3

"""

The program should read an array of n integers from the console and print only the elements located at odd indices, maintaining their original order. These elements should be displayed on a single line, separated by spaces. Note that the index numbering begins at 0.

Input
The first line contains the integer n (1≤n≤100), representing the number of elements in the array. The second line contains n integers, each separated by a space, with each integer having an absolute value not exceeding 100.

Output
On the first line, output the count of elements in the array that have odd indices. On the second line, print these elements separated by a space. If there are no elements with odd indices, output the message NO.

Examples

Input #1
7
-2 5 4 -3 7 -1 0

Answer #1
3
5 -3 -1

"""

def solve(a):
    print(len(a) // 2)
    for i in range(1, len(a), 2):
        print(a[i], end='')
        if i + 2 < len(a):
            print(' ', end='')
    print()
    print()

def main():
    solve([1, 2])
    solve([3, 4, 5])
    solve([3, 4, 5, 6])
    solve([-2, 5, 4, -3, 7, -1, 0])

main()
