#!/usr/bin/env python3

"""

Let S⊂N≥0 be a subset of the nonnegative integers, and let
S(k) = (S + S + S ...) = {a1 + a2 + a3 ... + ak : ai in S}
          k times

For example,
{1,2,3}^(2) = {1+1,1+2,1+3,2+1,2+2,2+3,3+1,3+2,3+3} = {2,3,4,5,6}

If S contains n elements, then S(k) contains at most (n+k−1k)=(n+k−1)!/((n−1)!k!) distinct elements.
If S(k) contains this number of distinct elements, we call it k-maximal. The set S={1,2,3} given in the example above is not 2-maximal because 1+3=2+2.

Challenge
Given a positive integer k, your task is to return the lexicographically earliest infinite list of nonnegative integers such that for every n the set consisting of the first n terms of S is k-maximal.

You can return a literal (infinite) list/stream, you can provide function that takes a parameter i and returns the i
th element of the list, or you can give any other reasonable answer.

This is code-golf so shortest code wins.

Test Data
 k | S^(k)
---+------------------------------------------------------------
 1 | 0, 1, 2,  3,   4,   5,    6,    7,     8,     9,    10, ...
 2 | 0, 1, 3,  7,  12,  20,   30,   44,    65,    80,    96, ...
 3 | 0, 1, 4, 13,  32,  71,  124,  218,   375,   572,   744, ...
 4 | 0, 1, 5, 21,  55, 153,  368,  856,  1424,  2603,  4967, ...
 5 | 0, 1, 6, 31, 108, 366,  926, 2286,  5733, 12905, 27316, ...
 6 | 0, 1, 7, 43, 154, 668, 2214, 6876, 16864, 41970, 94710, ...

For k=2 , this should return OEIS sequence A025582.
For k=3 , this should return OEIS sequence A051912.



"""

# ported from @ovs answer
def gen(k, n):
    r = []
    v = [1] + [0]*k
    i = 0
    while len(r) < n:
        w = []
        d = 0
        for j in v:
            d = j | (d<<i)
            w.append(d)
        
        if v[k] & (w[-2]<<i) < 1:
            r.append(i)
            v = w
        
        i += 1

    return r

def main():
    S1 = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    S2 = [0, 1, 3, 7, 12, 20, 30, 44, 65, 80, 96]
    S3 = [0, 1, 4, 13, 32, 71, 124, 218, 375, 572, 744]
    S4 = [0, 1, 5, 21, 55, 153, 368, 856, 1424, 2603, 4967]
    S5 = [0, 1, 6, 31, 108, 366, 926, 2286, 5733, 12905, 27316]
    S6 = [0, 1, 7, 43, 154, 668, 2214, 6876, 16864, 41970, 94710]

    assert(gen(1, len(S1)) == S1)
    assert(gen(2, len(S2)) == S2)
    assert(gen(3, len(S3)) == S3)
    assert(gen(4, len(S4)) == S4)
    assert(gen(5, len(S5)) == S5)
    assert(gen(6, len(S6)) == S6)

main()
