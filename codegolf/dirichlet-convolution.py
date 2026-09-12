#!/usr/bin/env python3

"""

The Dirichlet convolution is a special kind of convolution that appears as a very useful tool in number theory. It operates on the set of arithmetic functions.

Challenge
Given two arithmetic functions f,g (i.e. functions f,g:N→R) compute the Dirichlet convolution (f∗g):N→R as defined below.

Details
We use the convention 0∉N={1,2,3,…}.
The Dirichlet convolution f∗g of two arithmetic functions f,g is again an arithmetic function, and it is defined as (f∗g)(n)=∑d|nf(nd)⋅g(d)=∑i⋅j=nf(i)⋅g(j).
(Both sums are equivalent. The expression d|n means d∈N divides n, therefore the summation is over the natural divisors of n.
Similarly we can subsitute i=nd∈N,j=d∈N and we get the second equivalent formulation.
If you're not used to this notation there is a step by step example at below.) Just to elaborate (this is not directly relevant for this challenge):
The definition comes from computing the product of Dirichlet series: (∑n∈Nf(n)ns)⋅(∑n∈Ng(n)ns)=∑n∈N(f∗g)(n)ns
The input is given as two black box functions. Alternatively, you could also use an infinite list, a generator, a stream or something similar that could produce an unlimited number of values.
There are two output methods: Either a function f∗g is returned, or alternatively you can take take an additional input n∈N and return (f∗g)(n) directly.
For simplicity you can assume that every element of N can be represented with e.g. a positive 32-bit int.
For simplicity you can also assume that every entry R can be represented by e.g. a single real floating point number.

Examples
Let us first define a few functions. Note that the list of numbers below each definition represents the first few values of that function.

the multiplicative identity (A000007)
ϵ(n)={10n=1n>1
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ...

the constant unit function (A000012)
1(n)=1∀n
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, ...

the identity function (A000027)
id(n)=n∀n
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, ...

the Möbius function (A008683)
μ(n)={(−1)k0 if n is squarefree and k is the number of Primefactors of n otherwise 
1, -1, -1, 0, -1, 1, -1, 0, 0, 1, -1, 0, -1, 1, 1, 0, -1, 0, -1, ...

the Euler totient function (A000010)
φ(n)=n∏p|n(1−1p)
1, 1, 2, 2, 4, 2, 6, 4, 6, 4, 10, 4, 12, 6, 8, 8, 16, 6, 18, 8, ...

the Liouville function (A008836) λ(n)=(−1)k
where k is the number of prime factors of n counted with multiplicity 1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, 1, 1, -1, -1, -1, ...

the divisor sum function (A000203)
σ(n)=∑d|nd
1, 3, 4, 7, 6, 12, 8, 15, 13, 18, 12, 28, 14, 24, 24, 31, 18, 39, 20, ...

the divisor counting function (A000005)
τ(n)=∑d|n1
1, 2, 2, 3, 2, 4, 2, 4, 3, 4, 2, 6, 2, 4, 4, 5, 2, 6, 2, 6, 4, 4, 2, 8, ...

the characteristic function of square numbers (A010052)
sq(n)={10 if n is a square numberotherwise
1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, ...

Then we have following examples:

ϵ=1∗μ
f=ϵ∗f∀f
ϵ=λ∗|μ|
σ=φ∗τ
id=σ∗μ and σ=id∗1
sq=λ∗1 and λ=μ∗sq
τ=1∗1 and 1=τ∗μ
id=φ∗1 and φ=id∗μ
The last for are a consequence of the Möbius inversion: For any f,g the equation g=f∗1 is equivalent to f=g∗μ.

Step by Step Example
This is an example that is computed step by step for those not familiar with the notation used in the definition. Consider the functions f=μ and g=σ.
We will now evaluate their convolution μ∗σ at n=12.
Their first few terms are listed in the table below.

f f(1) f(2) f(3) f(4) f(5) f(6) f(7) f(8) f(9) f(10) f(11) f(12)
μ 1    -1   -1   0    -1   1    -1   0    0    1     -1    0
σ 1    3    4    7    6    12   8   15    13   18    12    28

The sum iterates over all natural numbers d∈N that divide n=12, thus d assumes all the natural divisors of n=12=22⋅3.
These are d=1,2,3,4,6,12.
In each summand, we evaluate g=σ at d and multiply it with f=μ evaluated at nd. Now we can conclude

(μ∗σ)(12)= 12 = id(12)

"""

from sympy.ntheory import *

# Based on @Leaky Nun solution
def dirichlet(f, g, n):
    r = 0
    for d in range(1, n + 1):
        if n%d == 0:
            r += f(d) * g(n // d)
    return r

def con(n):
    return lambda x: n

def main():
    assert(dirichlet(con(1), con(1), 15) == 4)
    assert(dirichlet(mobius, divisor_sigma, 12) == 12)

main()
