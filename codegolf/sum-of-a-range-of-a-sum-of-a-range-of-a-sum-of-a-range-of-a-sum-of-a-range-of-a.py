#!/usr/bin/env python3

"""

Inspired by the fact that a few related challenges to this could be answered by Vyxal in 0 Bytes using a special flag combination.
Given only one input integer n, calculate f(n,n) where
f(x,y)={xf((∑xk=1k), y−1)if y=0 otherwise
If you want an explanation in plain English, here it is, quoted from OEIS:

Let T(n) be the n-th triangular number n∗(n+1)/2; then a(n) = n-th iteration [of] T(T(T(...(n)))).

Note that a(n) is the function.

This is also A099129(n), but with the case for n=0.
This is code-golf, so as long as you make your answer short, it doesn't matter whether it times out on TIO (my computer can't calculate n=6 within five minutes!).
Yes, standard loopholes apply.

Test cases:
0 -> 0
1 -> 1
2 -> 6
3 -> 231
4 -> 1186570
5 -> 347357071281165
6 -> 2076895351339769460477611370186681
7 -> 143892868802856286225154411591351342616163027795335641150249224655238508171

"""

def triangular(n):
    return n*(n+1) // 2

# https://oeis.org/A099129
def iterated_triangular(n):
    r = n
    for i in range(n):
        r = triangular(r)
    return r

def main():
    tab = [0, 1, 6, 231, 1186570, 347357071281165, 2076895351339769460477611370186681, 143892868802856286225154411591351342616163027795335641150249224655238508171]

    for i in range(len(tab)):
        assert(iterated_triangular(i) == tab[i])

main()
