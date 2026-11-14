#!/usr/bin/env python3

"""

The system
Assume the Earth is flat and that it extends infinitely in all directions. Now assume we have one infinitely long train railway and n trains in that railway.
All trains have different speeds and all trains are going in the same direction. When a faster train reaches a slower train, the two trains connect (becoming a single train) and the new train keeps going at the speed with which the slower train was going.

E.g., if we have two trains, one going at speed 1 and another at speed 9, the lines below "simulate" what would happen on the railway:

9               1
         9       1
                 11
                  11
                   11
whereas if the trains start in a different order, we'd have

1 9
 1         9
  1                 9
   1                          9
etc...
With that being said, given a train/position/speed configuration there comes a time when no more connections will be made and the number of trains on the railway stays constant.

Task
Given the number n of trains in the railway, your task is to compute the total number of trains there will be on the railway, after all the connections have been made, summing over all n! possible arrangements of the n trains.

A possible algorithm would be:

Start counter at 0
Go over all possible permutations of the train speeds
Simulate all the connections for this permutation
Add the total number of remaining trains to the counter
Return the counter
Note that you can assume the train speeds are whatever n distinct numbers that you see fit, what really matters is the relationships between train speeds, not the magnitudes of the differences in speeds.

Input
You must take n, a positive integer, as input.

Output
An integer representing the total number of trains that there will be on the railway, summed over all possible permutations of the trains.

Test cases
1 -> 1
2 -> 3
3 -> 11
4 -> 50
5 -> 274
6 -> 1764
7 -> 13068
8 -> 109584
9 -> 1026576
10 -> 10628640
11 -> 120543840
12 -> 1486442880
13 -> 19802759040
14 -> 283465647360
15 -> 4339163001600
16 -> 70734282393600
17 -> 1223405590579200
18 -> 22376988058521600
19 -> 431565146817638400
20 -> 8752948036761600000

This is code-golf so shortest submission in bytes, wins! If you liked this challenge, consider upvoting it! If you dislike this challenge, please give me your feedback. Happy golfing!

"""

from math import *

import numpy as np

# https://people.math.sc.edu/Burkardt/py_src/polpak/stirling1.py
def stirling1(n, m):
    s = np.zeros((n, m), dtype=np.float128)
    if n <= 0 or m <= 0:
        return 0

    s[0, 0] = 1
    for j in range(1, m):
        s[0, j] = 0

    for i in range(1, n):
        s[i, 0] = -i * s[i-1, 0]
        for j in range(1, m):
            s[i, j] = s[i-1,j-1] - i*s[i-1,j]

    return s[n-1, m-1]

# https://oeis.org/A000254
def trains(n):
    return abs(int(stirling1(n+1, 2)))

def main():
    tab = [0, 1, 3, 11, 50, 274, 1764, 13068, 109584, 1026576, 10628640, 120543840, 1486442880, 19802759040, 283465647360, 4339163001600, 70734282393600, 1223405590579200, 22376988058521600, 431565146817638400, 8752948036761600000, 186244810780170240000]
    for i in range(len(tab)):
        print(i, trains(i), tab[i])
        assert(trains(i) == tab[i])

main()
