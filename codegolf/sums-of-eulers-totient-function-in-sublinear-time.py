#!/usr/bin/env python3

"""

Given a number n, Euler's totient function, φ(n) is the number of integers up to n which are coprime to n.
That is, no number bigger than 1 divides both of them.
For example, φ(6)=2, because the only relevant numbers are 1,5. This is OEIS A000010.

We can now define the sum of euler's totient function as S(n)=∑ni=1φ(i), the sum of φ(i) for all numbers from 1 to n. This is OEIS A002088.

Your task is to calculate S(n), in time sublinear in n, o(n).

Test cases
10 -> 32
100 -> 3044
123 -> 4636
625 -> 118984
1000 -> 304192
1000000 (10^6) -> 303963552392
1000000000 (10^9) -> 303963551173008414

Rules
Your complexity must be o(n). That is, if your algorithm takes time T(n) for input n, you must have limn→∞T(n)n=0. Examples of valid time complexities are O(n/log(n)) , O(sqrt(n)), O(n^(5/7)*log^4(n)), etc.
You can use any reasonable I/O format.
Note that due to the limited complexity you can't take the input in unary nor output in it (because then the I/O takes Ω(n) time), and the challenge might be impossible in some languages.
Your algorithm should in theory be correct for all inputs, but it's fine if it fails for some of the big test cases (due to overflow or floating-point inaccuracies, for example).
Standard loopholes are disallowed.
This is code golf, so the shortest answer in each language wins.

"""

from functools import *

# https://oeis.org/A002088
@lru_cache(maxsize=None)
def totientsum(n):
    if n == 0:
        return 0
    c, j = 0, 2
    k1 = n//j
    while k1 > 1:
        j2 = n//k1 + 1
        c += (j2 - j) * (2*totientsum(k1) - 1)
        j, k1 = j2, n // j2
    return (n*(n - 1) - c + j) // 2

def main():
    tab = [0, 1, 2, 4, 6, 10, 12, 18, 22, 28, 32, 42, 46, 58, 64, 72, 80, 96, 102, 120, 128, 140, 150, 172, 180, 200, 212, 230, 242, 270, 278, 308, 324, 344, 360, 384, 396, 432, 450, 474, 490, 530, 542, 584, 604, 628, 650, 696, 712, 754, 774, 806, 830, 882, 900, 940, 964]

    for i in range(len(tab)):
        assert(totientsum(i) == tab[i])

    assert(totientsum(10) == 32)
    assert(totientsum(100) == 3044)
    assert(totientsum(123) == 4636)
    assert(totientsum(625) == 118984)
    assert(totientsum(1000) == 304192)
    assert(totientsum(1000000) == 303963552392)
    assert(totientsum(1000000000) == 303963551173008414)

main()
