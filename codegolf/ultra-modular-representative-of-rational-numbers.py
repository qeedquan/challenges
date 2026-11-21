#!/usr/bin/env python3

"""

Objective
Given a reduced fraction p/q where q>0, output the (unique) reduced fraction p′/q′ such that:

p′ is nonnegative and less than q′, and q′ is a positive odd integer, and

The rational number  p′/q′-p/q has denominator of a power of 2 when reduced.

Mathematical remarks
This challenge asks to, when given a number in Q, output a certain representative in
the corresponding coset in the factor group  Q/Z[1/2],
where Z[1/2] is the adjoint ring with its multiplicative structure forgotten.

I/O format
Your submission must be able to represent the I/Oed fractions exactly. So for instance, you cannot output a floating-point number.

Standard loopholes apply, especially this one.

Otherwise flexible.

Examples
Input -> Output

0/1 -> 0/1
1/1 -> 0/1
2/1 -> 0/1
1/2 -> 0/1
3/2 -> 0/1
1/3 -> 1/3
2/3 -> 2/3
1/6 -> 2/3
5/6 -> 1/3
1/8 -> 0/1
1/10 -> 3/5
3/10 -> 4/5
7/10 -> 1/5
6/5 -> 1/5
13/6 -> 2/3
-1/1 -> 0/1
-1/6 -> 1/3
-1/12 -> 2/3
-3/2 -> 0/1

"""

"""

@Tbw

This code factors q=q′*2k, then finds the integer p′ between  0 and  q′-1 such that  p≡2^k*p′(mod q′).

"""

def reduce(p, q):
    n = q & ~(q - 1)
    m = q // n
    return (p*pow(n, -1, m) % m, m)

def main():
    assert(reduce(0, 1) == (0, 1))
    assert(reduce(1, 1) == (0, 1))
    assert(reduce(2, 1) == (0, 1))
    assert(reduce(1, 2) == (0, 1))
    assert(reduce(3, 2) == (0, 1))
    assert(reduce(1, 3) == (1, 3))
    assert(reduce(2, 3) == (2, 3))
    assert(reduce(1, 6) == (2, 3))
    assert(reduce(5, 6) == (1, 3))
    assert(reduce(1, 8) == (0, 1))
    assert(reduce(3, 10) == (4, 5))
    assert(reduce(7, 10) == (1, 5))
    assert(reduce(6, 5) == (1, 5))
    assert(reduce(13, 6) == (2, 3))
    assert(reduce(-1, 1) == (0, 1))
    assert(reduce(-1, 6) == (1, 3))
    assert(reduce(-1, 12) == (2, 3))
    assert(reduce(-3, 2) == (0, 1))

main()
