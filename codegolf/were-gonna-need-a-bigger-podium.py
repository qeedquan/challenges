#!/usr/bin/env python3

"""

If R runners were to run a race, in how many orders could they finish such that exactly T runners tie?

Challenge
Given a positive integer R and a non-negative integer 0≤T≤R produce the number of possible finishing orders of a race with R runners of which T tied.

Note, however, that runners that tie do not necessarily all tie with each other.

You may accept the number of runners that did not tie, R−T, in place of either R or T if you would prefer, just say so in your answer.
You may also accept just R and output a list of results for 0≤T≤R.

This is code-golf, so try to make the shortest code in bytes in your language of choice.

Examples
1. f(R=5,T=0)=120
No runners tied and the five runners could have finished in any order, thus f(R=5,T=0)=R!=5!=120

2. f(R=5,T=1)=0
There are zero ways for exactly one runner to have tied since ties involve at least two runners.

3. f(R=4,T=2)=36
The first two tied - ** * * - (42)(21)(11)=6×2×1=12 ways:
AB C D AB D C
AC B D AC D B
AD B C AD C B
BC A D BC D A
BD A C BD C A
CD A B CD B A
The middle two tied - * ** * - (41)(32)(11)=4×3×1=12 ways:
A BC D A BD C A CD B
B AC D B AD C B CD A
C AB D C AD B C BD A
D AB C D AC B D BC A
The last two tied - * * ** - (41)(31)(22)=4×3×1=12 ways:
A B CD A C BD A D BC
B A CD B C AD B D AC
C A BD C B AD C D AB
D A BC D B AC D C AB
4. f(R=5,T=5)=21
All five runners tied - ***** - (55)=1 way
The first two and the last three tied - ** *** - (52)(33)=10×1=10 ways:
AB CDE AC BDE AD BCE AE BCD BC ADE BD ACE BE ACD CD ABE CE ABD DE ABC
The first three and the last two tied - *** ** - (53)(22)=10×1=10 ways:
ABC DE ABD CE ABE CD ACD BE ACE BD ADE BC BCD AE BCE AD BDE AC CDE AB

Test cases
R,T => f(R,T)
1,0 => 1
1,1 => 0
2,0 => 2
2,1 => 0
2,2 => 1
3,0 => 6
3,1 => 0
3,2 => 6
3,3 => 1
4,0 => 24
4,1 => 0
4,2 => 36
4,3 => 8
4,4 => 7
5,0 => 120
5,1 => 0
5,2 => 240
5,3 => 60
5,4 => 100
5,5 => 21
7,5 => 5166
As a table, with x if the input does not need to be handled (all of them would be zero):

T R: 1     2     3     4     5     6     7
0    1     2     6    24   120   720  5040
1    0     0     0     0     0     0     0
2    x     1     6    36   240  1800 15120
3    x     x     1     8    60   480  4200
4    x     x     x     7   100  1170 13440
5    x     x     x     x    21   372  5166
6    x     x     x     x     x   141  3584
7    x     x     x     x     x     x   743

Isomorphic problem
This is the same as a(n=R,k=R−T) which is given in A187784 at the Online Encyclopedia of Integer Sequences as the number of ordered set partitions of {1,2,…,n} with exactly k singletons.

"""

from math import *

# https://oeis.org/A187784
def f(R, T):
    if R < 0 or T < 0:
        return 0
    if R == 0 and T == 0:
        return 1
    if R == 0 and T == 1:
        return 0

    v = R*f(R-1, T)
    for i in range(2, T+1):
        v += comb(R, i)*f(R-i, T-i)
    return v

def main():
    assert(f(1, 0) == 1)
    assert(f(1, 1) == 0)
    assert(f(2, 0) == 2)
    assert(f(2, 1) == 0)
    assert(f(2, 2) == 1)
    assert(f(3, 0) == 6)
    assert(f(3, 1) == 0)
    assert(f(3, 2) == 6)
    assert(f(3, 3) == 1)
    assert(f(4, 0) == 24)
    assert(f(4, 1) == 0)
    assert(f(4, 2) == 36)
    assert(f(4, 3) == 8)
    assert(f(4, 4) == 7)
    assert(f(5, 0) == 120)
    assert(f(5, 1) == 0)
    assert(f(5, 2) == 240)
    assert(f(5, 3) == 60)
    assert(f(5, 4) == 100)
    assert(f(5, 5) == 21)
    assert(f(7, 5) == 5166)

main()
