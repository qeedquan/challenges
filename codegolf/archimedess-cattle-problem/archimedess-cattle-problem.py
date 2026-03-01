#!/usr/bin/env python3

"""

Compute, O friend, the number of the cattle of the sun which once grazed upon the plains of Sicily, divided according to color into four herds, one milk-white, one black, one dappled and one yellow.
The number of bulls is greater than the number of cows, and the relations between them are as follows:

White bulls =(12+13) black bulls + yellow bulls,
Black bulls =(14+15) dappled bulls + yellow bulls,
Dappled bulls =(16+17) white bulls + yellow bulls,
White cows =(13+14) black herd,
Black cows =(14+15) dappled herd,
Dappled cows =(15+16) yellow herd,
Yellow cows =(16+17) white herd.

If thou canst give, O friend, the number of each kind of bulls and cows, thou art no novice in numbers, yet can not be regarded as of high skill.
Consider, however, the following additional relations between the bulls of the sun:

White bulls + black bulls = a square number,
Dappled bulls + yellow bulls = a triangular number.

If thou hast computed these also, O friend, and found the total number of cattle, then exult as a conqueror, for thou hast proved thyself most skilled in numbers.

- Archimedes

Some clarifications:

black herd = black bulls + black cows, white herd = white bulls + white cows, etc.
(12+13) black bulls + yellow bulls, means only the black bulls get the coefficient
A square number is a number which can be represented as n * n where n is an integer
A triangular number is a number which can be represented as 1 + 2 + ... + (n - 1) + n

Task
Write a program/function to output the size of the smallest herd that could satisfy both the first and second parts of the above problem.

Output
You must output this number. Standard Output rules for integers apply.

Scoring
This is code-golf so shortest bytes wins.

Hash of decimal representation of answer for easy checking:

sha256 (with newline): 4fce7274734a18e9d27592e59480b50876da243de4caef4323f783339c456a7c
sha256 (without newline): 8500b362f3d6b5e96c775ca16d1475b519ff18669b0f6f3d35e4fb23d2c18d01
Inspired by The Archimedes Number - Numberphile

"""

from sympy import Matrix
import sys

"""

http://jultika.oulu.fi/Record/isbn951-42-5932-7
https://mathworld.wolfram.com/ArchimedesCattleProblem.html
https://oeis.org/A096151

@Arnauld

Formula
This is an implementation of the method described in A simple solution to Archimedes' cattle problem by Antti Nygrén, whose final formula is:

(u)  = (a1 a2)^1164 * (r1)
(v)    (a3 a1)        (r2)

T = 6299*957*u^2*v^2 + 21054639*957*u^2*v^2/4657

with:

a1=109931986732829734979866232821433543901088049
a2=392567302329690546856394748066206816187916440
a3=30784636507697855142356992218944109072681060
r1=300426607914281713365
r2=84129507677858393258

"""

def solve():
    a1 = 109931986732829734979866232821433543901088049
    a2 = 392567302329690546856394748066206816187916440
    a3 = 30784636507697855142356992218944109072681060
    r1 = 300426607914281713365
    r2 = 84129507677858393258
    
    A = Matrix([[a1, a2], [a3, a1]])
    B = Matrix([[r1], [r2]])
    C = A**1164 * B
    
    u = C[0]
    v = C[1]
    T = 6299*957*u**2*v**2 + 21054639*957*u**2*v**2/4657 
    return T

def solution():
    f = open("solution.txt")
    s = f.read()
    s = s.rstrip()
    return int(s)

def main():
    sys.set_int_max_str_digits(1000000)
    assert(solve() == solution())

main()
