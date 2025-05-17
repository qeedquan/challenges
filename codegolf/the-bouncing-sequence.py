#!/usr/bin/env python3

"""

Let us define a sequence. We will say that a(n) is the smallest number, x, that has the following properties:

x and n are co-prime (they share no factor)
x does not appear earlier in the sequence
|n - x| > 1

Unlike most sequences the domain and range of our sequence are the integers greater than 1.

Let us calculate the first couple of terms.

a(2), must be at least 4, but 4 and 2 share a factor of 2 so a(2) must be 5.

a(3), must be at least 5 but 5 is taken by a(2), so it is at least 6, but 6 shares a factor with 3 so it must be at least 7, 7 fulfills all three requirements thus a(3)=7.

a(4)

2 Shares a factor
3 Too close
4 Too close
5 Too close
6 Shares a factor
7 Taken by a(3)
8 Shares a factor
9 is good
a(5)

2 is good

Task
In this challenge you are to write a program that takes a number greater than 1 and returns a(n).

This is a code-golf question so answers will be scored in bytes, with fewer bytes being better.

Test Cases
Here are the first couple terms of the sequence (They are of course 2 indexed):

5,7,9,2,11,3,13,4,17,6,19,8,23,22,21,10,25,12,27,16,15,14

Bonus Fun fact
As proven by Robert Israel on Math.se (link) this sequence is its own inverse, that means that a(a(n))=n for all n.

OEIS
After asking this question I submitted this sequence to the OEIS and after a few days it was added.

OEIS A290151

"""

from math import gcd

# https://oeis.org/A290151
def bounce(n):
    r = []
    for i in range(2, n):
        j = 2
        while abs(i - j) < 2 or gcd(j, i) > 1 or j in r:
            j += 1
        r.append(j)

    if len(r) == 0:
        return 0
    
    return r[-1]

def main():
    tab = [5, 7, 9, 2, 11, 3, 13, 4, 17, 6, 19, 8, 23, 22, 21, 10, 25, 12, 27, 16, 15, 14, 29, 18, 31, 20, 33, 24, 37, 26, 35, 28, 39, 32, 41, 30, 43, 34, 47, 36, 53, 38, 49, 52, 51, 40, 55, 44, 57, 46, 45, 42, 59, 48, 61, 50, 63, 54, 67, 56, 65, 58, 69, 62, 71, 60, 73, 64, 79, 66, 77, 68, 81, 82, 83, 72, 85, 70, 87, 74, 75, 76, 89, 78, 91, 80, 93, 84, 97, 86, 95, 88, 99, 92, 101]

    for i in range(len(tab)):
        assert(bounce(i + 3) == tab[i])

main()
