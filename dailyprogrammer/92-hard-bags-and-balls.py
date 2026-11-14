#!/usr/bin/env python3

"""

Compute all the permutations of placing 9 balls into 4 bags such that each bag contains an odd number of balls.

Ball count is transient when placing bags within one another. For example, a bag containing 3 balls is placed inside a bag containing 2 balls. The inner bag contains 3 balls and the outer bag contains 5 balls.

Some example permutations:

((((9))))
(8(((1))))
(1)(1)((7))
Thanks to skeeto for suggesting this problem at r/dailyprogrammer_ideas!

"""

from functools import lru_cache

# ported from @Cosmologicon solution
# a bag is a tuple containing a number of free balls, plus zero or more other bags.
# returns a list of tuples. Each tuple is a sequence of bags.
@lru_cache(maxsize=None)
def solve(k, n):
    if n < 0 or k < 0:
        return []
    if n == 0:
        return [()] if k == 0 else []
    if n == 1:
        return [((k,),)] if k % 2 else []

    r = []
    for j in range(1, k + 1, 2): # how many balls in the first bag?
        for m in range(n):  # how many bags in the first bag?
            outs = solve(k - j, n - 1 - m)  # arrange everything outside the first bag
            if not outs:
                continue
            
            for p in range(j + 1): # free balls in the first bag
                bag0s = [(p,) + con for con in solve(j - p, m)]   # arrange everything inside the first bag
                if not bag0s:
                    continue
                
                for bag0 in bag0s:
                    for out in outs:
                        if out and bag0 > out[0]:
                            continue # bags are out of order
                        r.append((bag0,) + out)
    return r

def rep(bags):
    return "".join("(%s%s)" % (bag[0] or "", rep(bag[1:])) for bag in bags) if bags else ""

def main():
    print("\n".join(map(rep, solve(9, 4))))

main()
