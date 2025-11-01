#!/usr/bin/env python3

"""

Permutations
The "permutations of 3" for the sake of this text are the possible arrangements of the list of first 3 numbers (0 based but optional) in sorted order

0 1 2
0 2 1
1 0 2
1 2 0
2 0 1
2 1 0
The permutation number is the index in this list. The "3rd permutation of 3" is 1 0 2. "1 2 0 has permutation number 3 (0 based)"

input:

what is 240th permutation of 6
what is 3240th permutation of 7

output:
1 5 4 3 2 0
4 2 6 5 3 1 0

combinations
The "combinations of 3 out of 6" is the sorted list of the possible ways to take 3 items out of the first 6 numbers (as a set where order does not matter)

0 1 2
0 1 3
0 1 4
0 1 5
0 2 3
0 2 4
0 2 5
0 3 4
0 3 5
0 4 5
1 2 3
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5
The "3rd combination number of 3 out of 6 is 0 1 4". "0 2 4 is combination index/number 5 or the 6th combination of 3 out of 6"

input:
24th combination of 3 out of 8
112th combination of 4 out of 9

output
1 2 5
3 4 5 6

Brute force solutions (generate full list, then take the number/index) to all of today's challenges are encouraged.

"""

from math import factorial, comb

"""

@wizao

The permutations follow the factoradic numbers. You can use this to calculate the nth number directly.
https://en.wikipedia.org/wiki/Factorial_number_system#Permutations

Similarly, I think the combinatorial numbers will be helpful for the other part. A solution from these will work for very large numbers where brute force will fail.
https://en.m.wikipedia.org/wiki/Combinatorial_number_system

"""

# ported from @gabyjunior solution
def permpos(n, p):
    if n < 1 or p < 1 or factorial(n) < p:
        return [1]
    return permposrec(n-1, factorial(n-1), p-1, [0]*n)

def permposrec(n, f, p, u):
    if n < 1:
        return [0]

    v = p // f
    i = -1
    j = 0
    while i < v:
        if not u[j]:
            i += 1
        if i < v:
            j += 1
    u[j] = 1
    return [j] + permposrec(n-1, f//n, p - v*f, u)

def combpos(n, k, p):
    if n < 1 or k < 1 or k > n or p < 1 or comb(n, k) < p:
        return [1]
    return combposrec(n, k, p, -1)

def combposrec(n, k, p, u):
    if k < 0:
        return []
    if k == 1:
        if u < 0:
            return [p-1]
        if u >= 0:
            return [u+p]

    v = 0
    if u >= 0:
        v = u + 1
    
    s = comb(n-v-1, k-1)
    t = 0
    while s < p:
        v += 1
        t = s
        s += comb(n-v-1, k-1)
    return [v] + combposrec(n, k-1, p-t, v)

def main():
    assert(permpos(6, 240) == [1, 5, 4, 3, 2, 0])
    assert(permpos(7, 3240) == [4, 2, 6, 5, 3, 1, 0])
    assert(permpos(100, 93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000) == list(range(100))[::-1])

    assert(combpos(8, 3, 24) == [1, 2, 5])
    assert(combpos(9, 4, 112) == [3, 4, 5, 6])
    assert(combpos(1000, 20, 1000000000000000000000000001) == [0, 1, 2, 3, 4, 5, 6, 7, 73, 261, 270, 275, 402, 406, 409, 541, 843, 868, 895, 970])

main()
