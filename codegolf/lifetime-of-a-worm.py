#!/usr/bin/env python3

"""

Terms
A worm is any list of nonnegative integers, and its rightmost (i.e., last) element is called the head. If the head is not 0, the worm has an active segment consisting of the longest contiguous block of elements that includes the head and has all of its elements at least as large as the head. The reduced active segment is the active segment with the head decremented by 1. For example, the worm 3 1 2 3 2 has active segment 2 3 2, and the reduced active segment is 2 3 1.

Rules of evolution
A worm evolves step-by-step as follows:

In step t (= 1, 2, 3, ...),
    if the head is 0: delete the head
    else: replace the active segment by t+1 concatenated copies of the reduced active segment.

Fact: Any worm eventually evolves into the empty list, and the number of steps to do so is the worm's lifetime.

(Details can be found in The Worm Principle, a paper by L. D. Beklemishev. The usage of "list" to mean a finite sequence, and "head" to mean its last element, is taken from this paper -- it should not be confused with the common usage for lists as an abstract data type, where head usually means the first element.)

Examples (active segment in parentheses)

Worm: 0,1

step    worm
         0(1)
1        0 0 0
2        0 0
3        0
4           <- lifetime = 4

Worm: 1,0

step    worm
         1 0
1       (1)
2        0 0 0
3        0 0
4        0
5           <- lifetime = 5

Worm: 1,1

step    worm
        (1 1)
1        1 0 1 0
2        1 0(1)
3        1 0 0 0 0 0
4        1 0 0 0 0
5        1 0 0 0
...
8       (1)
9        0 0 0 0 0 0 0 0 0 0
10       0 0 0 0 0 0 0 0 0
...
18       0
19           <- lifetime = 19

Worm: 2

step    worm
        (2)
1       (1 1)
2        1 0 1 0 1 0
3        1 0 1 0(1)
4        1 0 1 0 0 0 0 0 0
5        1 0 1 0 0 0 0 0
6        1 0 1 0 0 0 0
...
10       1 0(1)
11       1 0 0 0 0 0 0 0 0 0 0 0 0 0
12       1 0 0 0 0 0 0 0 0 0 0 0 0
...
24      (1)
25       0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
...
50       0
51          <- lifetime = 51

Worm: 2,1

        (2 1)
1        2 0 2 0
2        2 0(2)
3        2 0(1 1 1 1)
4        2 0 1 1 1 0 1 1 1 0 1 1 1 0 1 1 1 0 1 1 1 0
5        2 0 1 1 1 0 1 1 1 0 1 1 1 0 1 1 1 0(1 1 1)
6        2 0 1 1 1 0 1 1 1 0 1 1 1 0 1 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0
7        2 0 1 1 1 0 1 1 1 0 1 1 1 0 1 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0(1 1)
8        2 0 1 1 1 0 1 1 1 0 1 1 1 0 1 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0{1 0}^9
...
??          <- lifetime = ??

Worm: 3

step    worm
        (3)
1       (2 2)
2       (2 1 2 1 2 1)
3        2 1 2 1 2 0 2 1 2 1 2 0 2 1 2 1 2 0 2 1 2 1 2 0
4        2 1 2 1 2 0 2 1 2 1 2 0 2 1 2 1 2 0 2 1 2 1(2)
5        2 1 2 1 2 0 2 1 2 1 2 0 2 1 2 1 2 0(2 1 2 1 1 1 1 1 1 1)
6        2 1 2 1 2 0 2 1 2 1 2 0 2 1 2 1 2 0{2 1 2 1 1 1 1 1 1 0}^7
7        2 1 2 1 2 0 2 1 2 1 2 0 2 1 2 1 2 0{2 1 2 1 1 1 1 1 1 0}^6 (2 1 2 1 1 1 1 1 1)
...      ...
??          <- lifetime = ??


Aside
Worm lifetimes are typically enormous, as shown by the following lower bounds in terms of the standard fast-growing hierarchy of functions fα:

worm                lower bound on lifetime
----------------    ------------------------------------------
11..10 (k 1s)       f_k(2)
2                   f_ω(2)
211..1 (k 1s)       f_(ω+k)(2)
2121..212 (k 2s)    f_(ωk)(2)
22..2 (k 2s)        f_(ω^k)(2)
3                   f_(ω^ω)(2)
...
n                   f_(ω^ω^..^ω)(2) (n-1 ωs)  >  f_(ε_0) (n-1)
Remarkably, worm [3] already has a lifetime that far surpasses Graham's number, G:

fωω(2) = fω2(2) = fω2(2) = fω+2(2) = fω+1(fω+1(2)) >> fω+1(64) > G.



Code Golf Challenge
Write the shortest possible function subprogram with the following behavior:

Input: Any worm.
Output: The lifetime of the worm.

Code size is measured in bytes.


Here's an example (Python, golfs to about 167 bytes):

from itertools import *
def T(w):
    w=w[::-1]
    t=0
    while w:
        t+=1
        if w[0]:a=list(takewhile(lambda e:e>=w[0],w));a[0]-=1;w=a*(t+1)+w[len(a):]
        else:w=w[1:]
    return t

NB: If t(n) is the lifetime of the worm [n], then the rate of growth of t(n) is roughly that of the Goodstein function. So if this can be golfed to below 100 bytes, it could well give a winning answer to the Largest Number Printable question. (For that answer, the growth-rate could be vastly accelerated by always starting the step-counter at n -- the same value as the worm [n] -- instead of starting it at 0.)

"""

from itertools import *

def worm(w):
    w = w[::-1]
    t = 0
    while len(w) > 0:
        t += 1
        if w[0] != 0:
            a = list(takewhile(lambda e: e >= w[0], w))
            a[0] -= 1
            w = a*(t+1) + w[len(a):]
        else:
            w = w[1:]
    return t

def main():
    assert(worm([0, 1]) == 4)
    assert(worm([1, 0]) == 5)
    assert(worm([1, 1]) == 19)
    assert(worm([2]) == 51)

main()
