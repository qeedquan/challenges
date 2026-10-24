#!/usr/bin/env python3

"""

The totient function ϕ(n), also called Euler's totient function, is defined as the number of positive integers ≤ n
that are relatively prime to (i.e., do not contain any factor in common with) n,
where 1 is counted as being relatively prime to all numbers.
(from WolframMathworld)
https://mathworld.wolfram.com/TotientFunction.html

Challenge
Given an integer N>1, output the lowest integer M>N, where ϕ(N)=ϕ(M).
If M does not exist, output a non-ambiguous non-positive-integer value to indicate that M does not exist (e.g. 0, -1, some string).

Note that  ϕ(n) >= sqrt(n) for all n>6

Examples
Where M exists
15 -> 16  (8)
61 -> 77  (60)
465 -> 482 (240)
945 -> 962 (432)

No M exists
12  (4)
42 (12)
62 (30)

Standard loopholes apply, shortest answer in bytes wins.

Related
https://codegolf.stackexchange.com/questions/83533/calculate-eulers-totient-function

"""

from sympy import totient

# https://oeis.org/A066659
def find(n):
    if n < 1:
        return 0
    
    p = totient(n)
    for m in range(n + 1, 2*n + 1):
        if p == totient(m):
            return m
    return 0

def main():
    tab = [
        2, 0, 4, 6, 8, 0, 9, 10, 14, 12, 22, 0, 21, 18, 16, 20, 32, 0, 27, 24,
        26, 0, 46, 30, 33, 28, 38, 36, 58, 0, 62, 34, 44, 40, 39, 42, 57, 54,
        45, 48, 55, 0, 49, 50, 52, 0, 94, 60, 86, 66, 64, 56, 106, 0, 75, 70,
        63, 0, 118, 0, 77, 0, 74, 68, 104, 0, 134, 80, 92, 72, 142, 78, 91
    ]

    for i in range(len(tab)):
        assert(find(i + 1) == tab[i])

    assert(find(15) == 16)
    assert(find(61) == 77)
    assert(find(465) == 482)
    assert(find(945) == 962)

main()
