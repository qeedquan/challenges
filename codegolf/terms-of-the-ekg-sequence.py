#!/usr/bin/env python3

"""

Introduction
The EKG sequence begins with 1 and 2, then the rule is that the next term is the smallest positive integer not already in the sequence and whose common factor with the last term is greater than 1 (they are not coprimes).

The first terms are:

1, 2, 4, 6, 3, 9, 12, 8, 10, 5, 15, ...

It's called EKG because the graph of its terms is quite similar to an EKG.

It's sequence A064413 in the OEIS.

Challenge
You have to write a function which takes an integer n as input and outputs how many of the n first terms of the sequence are greater than n.

As the sequence's rule begins with the third term, the input integer has to be greater or equal to 3. For example, given input 10 the output is 1 because the 7th term is 12 and none of the other first ten terms exceed 10.

Test cases
3 -> 1

10 -> 1

100 -> 9

1000 -> 70

Rules
For integers lower than 3, the function may output 0 or an error code.
No other particular rules except: it's code golf, the shorter the better!

"""


from math import *

# https://oeis.org/A064413
def gen(n):
    if n < 0:
        return []

    r = [1, 2]
    l = 2
    s = 3
    b = {}
    while len(r) < n:
        i = s
        while True:
            if not i in b and gcd(i, l) > 1:
                r.append(i)
                l, b[i] = i, True
                while s in b:
                    b.pop(s)
                    s += 1
                break
            i += 1
    
    return r[:n]

def main():
    tab = [1, 2, 4, 6, 3, 9, 12, 8, 10, 5, 15, 18, 14, 7, 21, 24, 16, 20, 22, 11, 33, 27, 30, 25, 35, 28, 26, 13, 39, 36, 32, 34, 17, 51, 42, 38, 19, 57, 45, 40, 44, 46, 23, 69, 48, 50, 52, 54, 56, 49, 63, 60, 55, 65, 70, 58, 29, 87, 66, 62, 31, 93, 72, 64, 68, 74, 37, 111, 75, 78, 76, 80, 82]

    assert(gen(len(tab)) == tab)

main()
