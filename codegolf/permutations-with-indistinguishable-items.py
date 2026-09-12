#!/usr/bin/env python3

"""

Given a list of integers, output the number of permutations of the integers, with indistinguishable permutations counted once.
If there are n integers, and each group of indistinguishable numbers has length n_i, this is n! / (n_1! * n_2! * ...)

Rules
Input will be some form of list as arguments to a function or the program with 1 to 12 non-negative integers.

Output will be printing or returning the number of permutations as described above.

No standard loopholes or built-in functions (generating permutations, combinations, etc.). Factorials are allowed.

Test Cases
Inputs:

1, 3000, 2, 2, 8
1, 1, 1
2, 4, 3, 2, 3, 4, 4, 4, 4, 4, 1, 1

Outputs:

60
1
83160

"""

from math import factorial

def count(a):
    r = factorial(len(a))
    m = {}
    for x in a:
        if x not in m:
            m[x] = 0
        m[x] += 1

        r //= m[x]
    
    return r

def main():
    assert(count([1, 3000, 2, 2, 8]) == 60)
    assert(count([1, 1, 1]) == 1)
    assert(count([2, 4, 3, 2, 3, 4, 4, 4, 4, 4, 1, 1]) == 83160)

main()
