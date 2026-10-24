#!/usr/bin/env python3

"""

I have a follow-up question here from my previous question on Math SE. I am lazy enough to explain the content again, so I have used a paraphraser to explain it below:

I was considering arbitrary series, springing up as a top priority, when I considered one potential series in my mind. It is as per the following:

https://i.stack.imgur.com/zHFsX.jpg

The essential thought is, take a line of regular numbers N which goes till boundlessness, and add them.
Something apparent here is that the most greatest biggest number Nmax would be Ni.
In essential words, on the off chance that we go till number 5, N5 the level it comes to by summation is 5.

Further, continuing, we can get:

https://i.stack.imgur.com/Nig4s.jpg

The essential ramifications here is that we knock the numbers by unambiguous N.
At start, we take the starting number, for our situation it is 1, we move once up and afterward once down.
Then we do it two times, threefold, etc. So 1 3 2 as per my outline is one knock.
At the closure N which is 2 here, we will hop it by 2 and make it low by 2. So it gets 2 5 12 7 4.
Here, expect Ni as the quantity of incrementation, before it was 1, presently it is 2.
We get various sets, with various terms, however absolute number of terms we overcome this would be 2Ni+1.
Presently, it will begin from 4, continue taking 3 leaps prior to arriving by three terms.
By this, we get series featured by circles in that three-sided exhibit as:

1, 3, 2, 5, 12, 7, 4, 9, 20, 44, 24, 13, 7, 15, 32, 68, 144, 76, 40, 21, 11, 23, 48, 100, 208, 432, 224, 116, 60, 31, 16...
The series appear to be disparate, my particular inquiry this is the way to address this series in Numerical terms.

Challenge: Implement the algorithm which can build this series.

Scoring Criteria: It is ranked by fastest-algorithm so the answer with lowest time complexity is considered (time complexity is loosely allowed to be anywhere) but the program must have been running accurate result.

"""

from math import *

"""

@Neil

s = ceil(sqrt(n))
f(n) = (n+1)*2^abs(n-s*(s-1)-1) / 2

"""
def bump(n):
    s = ceil(sqrt(n))
    p = n - s*(s - 1) - 1
    return ((n + 1) * 2**abs(p)) // 2

def main():
    tab = [1, 3, 2, 5, 12, 7, 4, 9, 20, 44, 24, 13, 7, 15, 32, 68, 144, 76, 40, 21, 11, 23, 48, 100, 208, 432, 224, 116, 60, 31, 16]
    
    for i in range(len(tab)):
        assert(bump(i + 1) == tab[i])

main()
