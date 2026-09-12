#!/usr/bin/env python3

"""

[This is a partner question to Calculate a probability exactly ]
https://codegolf.stackexchange.com/questions/51406/calculate-a-probability-exactly

This task is about writing code to compute a probability exactly and quickly. The output should be a precise probability written as a fraction in its most reduced form. That is it should never output 4/8 but rather 1/2.

For some positive integer n, consider a uniformly random string of 1s and -1s of length n and call it A. Now concatenate to A its first value.
That is A[1] = A[n+1] if indexing from 1. A now has length n+1. Now also consider a second random string of length n whose first n values are -1, 0, or 1 with probability 1/4,1/2, 1/4 each and call it B.

Now consider the inner product of A[1,...,n] and B and the inner product of A[2,...,n+1] and B.

For example, consider n=3. Possible values for A and B could be A = [-1,1,1,-1] and B=[0,1,-1]. In this case the two inner products are 0 and 2.

Your code must output the probability that both inner products are zero.

Copying the table produced by Martin Büttner we have the following sample results.

n   P(n)
1   1/2
2   3/8
3   7/32
4   89/512
5   269/2048
6   903/8192
7   3035/32768
8   169801/2097152

Languages and libraries

You can use any freely available language and libraries you like. I must be able to run your code so please include a full explanation for how to run/compile your code in linux if at all possible.

The task

Your code must start with n=1 and give the correct output for each increasing n on a separate line. It should stop after 10 seconds.

"""

from math import *

r"""

@Min_25

Closed form formula
p(n) = [Sum[i=0, floor(n/2)] binomial(2*(n - 2*i), n - 2*i) * binomial(n, 2*i) * binomial(4*i, 2*i)] / 2**(3*n - 1)

Exponential generating function
P(x) = (exp(x/2) + 1) * I0(x/4)**2
I_0(x) = Bessel function of the first kind

Proof:
This problem is similar to a 2-dimensional (restricted) random walk problem.

If A[i] = A[i+1], we can move from (x, y) to (x+1, y+1) [1 way], (x, y) [2 ways] or (x-1, y-1) [1 way].

If A[i] != A[i+1], we can move from (x, y) to (x-1, y+1) [1 way], (x, y) [2 ways] or (x+1, y-1) [1 way].

Let a(n, m) = [x^m]((x+1)^n + (x-1)^n), b(n) = [x^n](1+x)^{2n} and c(n) be the number of ways to move from (0, 0) to (0, 0) with n steps.

Then, c(n) = \sum_{i=0}^n a(n, i) * b(i) * b(n-i).

Since p(n) = c(n) / 8^n, we can get the above closed-form formula.

"""

def prob(n):
    if n < 1:
        return (0, 0)

    x = 0
    y = 2**(3*n - 1)
    for i in range(n//2 + 1):
        x += comb(2*(n - 2*i), n - 2*i) * comb(n, 2*i) * comb(4*i, 2*i)
    
    l = gcd(x, y)
    return (x//l, y//l)

def main():
    assert(prob(1) == (1, 2))
    assert(prob(2) == (3, 8))
    assert(prob(3) == (7, 32))
    assert(prob(4) == (89, 512))
    assert(prob(5) == (269, 2048))
    assert(prob(6) == (903, 8192))
    assert(prob(7) == (3035, 32768))
    assert(prob(8) == (169801, 2097152))

main()
