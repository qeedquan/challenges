#!/usr/bin/env python3

"""

Description

A sequence of n > 0 integers is called a jolly jumper if the absolute values of the difference between successive elements take on all the values 1 through n-1. For instance,

1 4 2 3

is a jolly jumper, because the absolutes differences are 3, 2, and 1 respectively. The definition implies that any sequence of a single integer is a jolly jumper. You are to write a program to determine whether or not each of a number of sequences is a jolly jumper.

Input

Each line of input contains an integer n < 3000 followed by n integers representing the sequence.

Output

For each line of input, generate a line of output saying "Jolly" or "Not jolly".

Sample Input

4 1 4 2 3
5 1 4 2 -1 6

Sample Output

Jolly
Not jolly

Source

Waterloo local 2000.09.30

"""

def jolly(a):
    n = len(a)
    m = {}
    i = 1
    while i < n:
        m[abs(a[i]-a[i-1])] = True
        i += 1

    for i in range(1, n):
        if i not in m:
            return "Not jolly"
    return "Jolly"

def main():
    assert(jolly([1, 4, 2, 3]) == "Jolly")
    assert(jolly([1, 6, -1, 8, 9, 5, 2, 7]) == "Not jolly")
    assert(jolly([1, 4, 2, -1, 6]) == "Not jolly")
    assert(jolly([19, 22, 24, 21]) == "Not jolly")
    assert(jolly([19, 22, 24, 25]) == "Jolly")
    assert(jolly([2, -1, 0, 2]) == "Jolly")

main()
