#!/usr/bin/env python3

"""

Some divisors of positive integers really hate each other and they don't like to share one or more common digits.

Those integers are called Hostile Divisor Numbers (HDN)

Examples

Number 9566 has 4 divisors: 1, 2, 4783 and 9566
(as you can see, no two of them share the same digit).
Thus, 9566 is a Hostile Divisor Number

Number 9567 is NOT HDN because its divisors (1, 3, 9, 1063, 3189, 9567) share some common digits.

Here are the first few HDN

1,2,3,4,5,6,7,8,9,23,27,29,37,43,47,49,53,59,67,73,79,83,86,87,89,97,223,227,229,233,239,257,263,267,269,277,283,293,307,337...       


Task

The above list goes on and your task is to find the nth HDN

Input

A positive integer n from 1 to 4000

Output

The nth HDN

Test Cases

here are some 1-indexed test cases.
Please state which indexing system you use in your answer to avoid confusion.

input -> output     
 1        1     
 10       23       
 101      853     
 1012     26053     
 3098     66686     
 4000     85009     

This is code-golf, so the lowest score in bytes wins.

EDIT

Good news! I submitted my sequence to OEIS and...
Hostile Divisor Numbers are now OEIS A307636

"""

from itertools import count, combinations, islice
from sympy import divisors

# https://oeis.org/A307636
def hdn(n):
    return all(len(set(s[0])&set(s[1])) == 0 for s in combinations((str(d) for d in divisors(n)), 2))

def gen(n):
    r = []
    i = 0
    while len(r) < n:
        i += 1
        if hdn(i):
            r.append(i)
    return r

def main():
    tab = [1, 2, 3, 4, 5, 6, 7, 8, 9, 23, 27, 29, 37, 43, 47, 49, 53, 59, 67, 73, 79, 83, 86, 87, 89, 97, 223, 227, 229, 233, 239, 257, 263, 267, 269, 277, 283, 293, 307, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 409, 433, 439, 443, 449, 457, 463, 467, 479, 487, 499, 503]
    
    assert(gen(len(tab)) == tab)

main()
