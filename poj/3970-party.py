#!/usr/bin/env python3

"""

Description

The CEO of ACM (Association of Cryptographic Mavericks) organization has invited all of his teams to the annual all-hands meeting, being a very disciplined person, the CEO decided to give a money award to the first team that shows up to the meeting.

The CEO knows the number of employees in each of his teams and wants to determine X the least amount of money he should bring so that he awards the first team to show up such that all team members receive the same amount of money. You must write a program to help the CEO achieve this task.

Input

The input consists of multiple test cases, each test case is described on a line by itself, Each line starts with an integer N (1 <= N <= 20) the number of teams in the organization followed by N space separated positive integers representing the number of employees in each of the N teams. You may assume that X will always fit in a 32 bit signed integer. The last line of input starts with 0 and shouldn't be processed.

Output

For each test case in the input print "The CEO must bring X pounds.", where X is as described above or "Too much money to pay!" if X is 1000000 or more.

Sample Input

1 3000000
2 12 4
0

Sample Output

Too much money to pay!
The CEO must bring 12 pounds.

Source

Seventh ACM Egyptian National Programming Contest

"""

from math import *

def payment(a):
    m = 1
    for v in a:
        m = m//gcd(m, v) * v
    
    if m >= 1000000:
        return "Too much money to pay!"
    return "The CEO must bring %d pounds." % (m)

def main():
    assert(payment([3000000]) == "Too much money to pay!")
    assert(payment([12, 4]) == "The CEO must bring 12 pounds.")

main()
