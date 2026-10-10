#!/usr/bin/env python3

"""

WARNING: This challenge may need 128 bit floats.1

The task is to perform numerical integration. Consider the following three functions.

f(x) = c * x^(c-1) * e^(-x^c)

g1(x) = 0.5*e^(-x)

g2(x) = 5*e^(-10x)

We will have that c >= 0.2. Your code should be correct for any value between 0.2 and 1.0.

The task is to perform the integral:

Integral[0, oo] = f(x) * ln(f(x) / (g1(x) + g2(x))) dx

Your output should be correct to within plus or minus 10^-10 percent of the correct answer.

Input

A single real number c.

Output shown to 15 significant places

c = 0.2. Output: 119.2233798550179
c = 0.3. Outout: 8.077346771987397
c = 0.4. Output: 2.07833944013377
c = 0.5. Output: 0.8034827042913205
c = 0.6. Output: 0.3961739639940003
c = 0.7. Output: 0.2585689391629249
c = 0.8. Output: 0.2287758419066705
c = 0.9. Output: 0.2480070283065089
c = 1.0. Output: 0.2908566108890576

Timing

Your code must complete on TIO before it times out.

As is usual, this is a competition per language. In other words, Java coders should not be put off by the single character solution in a language they can't believe exists. You may use any language/library you choose.

Questions and notes

Does this integral actually exist/converge?
Yes. It is the Kullback Leibler divergence between two probability distributions.

Show me any code that can compute these integrals.
See this Wolfram Alpha example.

Why such high precision that we need 128 bit floats?
It is quite easy to solve the integral to low precision using simple ideas. However, to get high precision seems to need careful thought both about the integral itself but also the quadrature method that will be used. I felt this made the question more challenging and interesting.

1. For lots of languages this is easy. E.g Fortran has real128, gcc/clang have _Float128 for C/C++, Python has Decimal (and many other options), Dyalog APL has 128 bit (decimal) floats, C# has the Decimal type, Haskell has rounded, PHP has decimal, MATLAB has the Multiprecision Computing Toolbox, Julia has BigFloat, Java has BigDecimal, JavaScript has big.js, Ruby has BigDecimal, R has Rmpfr, Perl has Math::BigFloat, SOGL has 200 digit decimal precision, etc. If your favourite golfing language doesn't, maybe consider adding it?

Update
Alexey Burdin has shown that

Integral[0, oo] = f(x) * ln(f(x) / (g1(x) + g2(x))) dx

Integral[0, 1] (ln(c) + (ln(-ln(t))))*((c - 1)/c) + ln(t) - ln(0.5 + 5*e^(-9*x(t))) + (-ln(t))^(1/c) dt

This potentially greatly simplifies the problem.

"""

from mpmath import *

def integral(c):
    f = lambda t: log(.5 + 5*exp(-9*((-log(t))**(1/c))))
    return gamma(1/c + 1) + log(c) - euler*(1 - 1/c) - 1 - quad(f, [0, 1])

def test(c, r):
    x = integral(c)
    print(x)
    assert(abs(x - r) < 1e-9)

def main():
    test(0.2, 119.2233798550179)
    test(0.3, 8.077346771987397)
    test(0.4, 2.07833944013377)
    test(0.5, 0.8034827042913205)
    test(0.6, 0.3961739639940003)
    test(0.7, 0.2585689391629249)
    test(0.8, 0.2287758419066705)
    test(0.9, 0.2480070283065089)
    test(1.0, 0.2908566108890576)

main()
