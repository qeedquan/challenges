#!/usr/bin/env python3

"""

Task
Given an input list of integers x1…xn, compute a list of ranks r1…rn (a permutation of {1…n}) so that xr1 ≤ xr2 ≤ … ≤ xrn. Then, for each xi, replace its rank by the arithmetic mean of the ranks of all values in x that are equal to xi. (That is, whenever there is a tie between equal values in x, fairly redistribute the ranks among all of them.) Output the modified list of ranks r’1…r’n.

(For statistics geeks: such a ranking of observations is used in the Mann–Whitney U test (method two, step 1.))

Example
Given an input list [3, -6, 3, 3, 14, 3], the first list of ranks would be [2, 1, 3, 4, 6, 5], which would sort the list into [-6, 3, 3, 3, 3, 14]. Then, the ranks for all 3s in the input list are evened out into (2 + 3 + 4 + 5) ÷ 4 = 3.5. The final output is [3.5, 1, 3.5, 3.5, 6, 3.5].

Test cases
[4, 1, 4] -> [2.5, 1.0, 2.5]
[5, 14, 14, 14, 14, 5, 14] -> [1.5, 5.0, 5.0, 5.0, 5.0, 1.5, 5.0]
[9, 9, -5, -5, 13, -5, 13, 9, 9, 13] -> [5.5, 5.5, 2.0, 2.0, 9.0, 2.0, 9.0, 5.5, 5.5, 9.0]
[13, 16, 2, -5, -5, -5, 13, 16, -5, -5] -> [7.5, 9.5, 6.0, 3.0, 3.0, 3.0, 7.5, 9.5, 3.0, 3.0]

Rules
This is code-golf, so the shortest code in bytes wins.

"""

def solve(a):
    r = []
    for y in a:
        v = 0
        for x in a:
            if y > x:
                v += 2
            elif y == x:
                v += 1
        r.append((v + 1) / 2)
    return r

def main():
    print(solve([4, 1, 4]))
    print(solve([5, 14, 14, 14, 14, 5, 14]))
    print(solve([9, 9, -5, -5, 13, -5, 13, 9, 9, 13]))
    print(solve([13, 16, 2, -5, -5, -5, 13, 16, -5, -5]))

main()
