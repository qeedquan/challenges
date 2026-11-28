#!/usr/bin/env python3

"""

The Riemann hypothesis is usually stated in terms of the nontrivial zeros of the Riemann zeta function. When stated like this, there's no obvious way to write a program that halts if and only if this conjecture is false. But the interesting thing about the Riemann hypothesis is that it's a bridge between complex analysis and number theory : the behavior of this function on the complex plane is deeply linked to the distribution of prime numbers, and in fact the Riemann hypothesis is equivalent to concrete statements on natural numbers, statements that have easily verifiable counterexamples if they are false. See some examples here. Your goal is to write a program that searches for such counterexamples.

Objective
Write a program that takes no input and halts if and only if the Riemann hypothesis is false.

Your answer must justify this equivalence.

This is code-golf, so the shortest program wins.

"""

from sympy import harmonic, lcm

"""

Ported from @simd solution

Hm = Sum[k=1, m] 1/k
Dn = Prod[j=1, n-1] lcm(1, ..., j)

where an empty product is 1. The Davis–Matiyasevich–Robinson criterion states that RH holds if and only if
(H_Dn - n^2/2)^2 < 36*n^3 

for every positive integer n. See Theorem 2 of Nayebi's account, including its proof.
https://anayebi.github.io/files/projects/RH_Diophantine.pdf#page=4

"""
n = d = l = 1
while (2*harmonic(d) - n**2)**2 < 144*n**3:
    l = lcm(l, n)
    d *= l
    n += 1
