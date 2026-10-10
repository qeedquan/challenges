#!/usr/bin/env python3

"""

Given an integer N, print or return integers a, b, and c that satisfy all of the following conditions, if such integers exist:

a×b + c = N
a, b, and  c are all prime a>b>c

If no valid combination of integers exist, you should return nothing, 0, None, an empty list, or raise an error.

If multiple valid combinations of integers exists, you can print or return any of them or all of them in a data type of your choosing.

A list of multiple solutions does not need to be sorted, and since we know that a>b>c, you can return them in any order.

Examples:

Input: 17
Output: 5 3 2

Input: 20
Output: None

Input: 37
Output: 7 5 2

Input: 48
Output: None

Input: 208
Output: [(41, 5, 3), (29, 7, 5)]
This is code golf, so the code with the lowest byte count wins.

Inspired by this Redditor's neat dream.
https://www.reddit.com/r/theydidthemath/comments/sgjgp5/request_i_just_took_a_nap_and_had_a_dream_where/?solution=b98005c15252d300b98005c15252d300&js_challenge=1&token=7afd7253fec22262ff1c52b1703fe9ec06b7edfc4805bb04bf954672cdef3357&jsc_orig_r=

"""

from sympy import primerange

def solve(n):
    r = []
    p = list(primerange(n))
    for i in range(len(p)):
        for j in range(i + 1, len(p)):
            for k in range(j + 1, len(p)):
                a, b, c = p[k], p[j], p[i]
                if a*b + c == n:
                    r.append((a, b, c))
    if len(r) == 0:
        return None
    return r 

def main():
    print(solve(17))
    print(solve(20))
    print(solve(37))
    print(solve(48))
    print(solve(208))

main()
