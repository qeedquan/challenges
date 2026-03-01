#!/usr/bin/env python3

"""

Calculate the p-adic norm of a rational number
Write a function or a program, that takes 3 integers m,n,p (where p is a positive prime) as input, that outputs the p-adic norm (denoted by |m/n|_p) as a (completely reduced) fraction. Fermat is known to have only very small margins, but what is rather unknown is that he only had a very small computer screen. So try to make the code as short as possible for it to fit on Fermat's screen!

Definition
Given a prime p, every fraction m/n can uniquely be written (ignoring the signs) as (a/b)* p^e such that e is a integer and p divides neither a nor b. The p-adic norm of m/n is p^-e. There is a special case, if the fraction is 0: |0|_p = 0.

The output format must be x/y (e.g. 1/3; for integers both 10 or equivalently 10/1 is allowed, for negative numbers there must be a leading minus e.g. -1/3)

Details
The program must use stdin/stdout, or just consist of a function that returns the rational number or string. You have to assume that the input m/n is not fully reduced. You can assume that p is a prime. The program has to be able to process integers between -2^28 up to 2^28, and should not take more than 10 seconds.

Built in factorization and prime checking functionalities are not allowed, as well as built in base conversatio, and built in function that calculate the p-adic valuation or norm.

Examples (stolen from wikipedia):
x = m/n = 63/550 = 2^-1 * 3^2 * 5^-2 * 7 * 11^-1
|x|_2 = 2
|x|_3 = 1/9
|x|_5 = 25
|x|_7 = 1/7
|x|_11 = 11
|x|_13 = 1
Interesting trivia
(Not necessary to know/read for this challenge, but perhaps nice to read as a motivation.)

(Please correct me if I use the wrong words, or something else is wrong, I am not used to talking about this in english.)

If you consider the rational numbers as a field, then the p-adic norm induces the p-adic metric d_p(a,b) = |a-b|_p. Then you can complete this field with regard to this metric, that means you can construct a new field where all cauchy sequences converge, which is a nice topological property to have. (Which e.g. the rational numbers do not have, but the reals do.) These p-adic numbers are as you might have guessed, used a lot in number theory.

Another interesting result is Ostrowski's theorem which basically says, any absolut value (as defined below) on the rational numbers is one of the following three:

The trivial: |x|=0 iff x=0, |x|=1 otherwise
The standard (real): |x| = x if x>=0, |x| = -x if x<0
The p-adic (as we defined it).
An absolute value / a metric is just the generalization of what we consider a distance. A absolute value |.| satisfies following conditions:

|x| >= 0  and |x|=0 if x=0
|xy| = |x| |y|
|x+y| <= |x|+|y|
Note that you can easily construct metrics from absolute values and vice versa: |x| := d(0,x) or d(x,y) := |x-y|, so they are almost the same if you can add/substract/multiply (that is in integral domains). You can of course define a metric on more general sets, without this structure.

"""

from sympy import *

"""

https://mathworld.wolfram.com/p-adicNorm.html

The idea is to take prime factorization of a rational number m/n.
The prime factorization of m/n is all the list of primes and their exponents (possibly negative) which multiplies out to the rational number.
Then we can just read off the exponent at that prime and calculate p^(-e) to get the solution.

"""
def padicnorm(m, n, p):
    if m == 0:
        return 0

    f = factorrat(S(m)/S(n))
    if p not in f:
        return 1
    return S(p)**S(-f[p])

def main():
    assert(padicnorm(63, 550, 2) == S(2))
    assert(padicnorm(63, 550, 3) == S(1)/S(9))
    assert(padicnorm(63, 550, 5) == S(25))
    assert(padicnorm(63, 550, 7) == S(1)/S(7))
    assert(padicnorm(63, 550, 11) == S(11))
    assert(padicnorm(63, 550, 13) == S(1))

    assert(padicnorm(140, 297, 2) == S(1)/S(4))
    assert(padicnorm(140, 297, 3) == S(27))
    assert(padicnorm(140, 297, 5) == S(1)/S(5))
    assert(padicnorm(140, 297, 7) == S(1)/S(7))
    assert(padicnorm(140, 297, 11) == S(11))

main()
