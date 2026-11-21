#!/usr/bin/env python3

"""

The ubiquitous Catalan numbers Cn count the number of Dyck paths, sequences of up-steps and down-steps of length 2n that start and end on a horizontal line and never go below said line.
Many other interesting sequences can be defined as the number of Dyck paths satisfying given conditions, of which the Fine sequence Fn (not the Fibonacci numbers and not related to any common definition of "fine") is one.

Let a hill be a sequence of an up-step followed by a down-step that starts – and therefore also ends – on the horizontal line. Fn is then the number of Dyck paths of length 2n with no hills.
The picture below illustrates this: there are C(5)=42 Dyck paths of length 10, of which F(5)=18 (marked in black) have no hills.

This sequence is OEIS A000957

Other things counted by the Fine numbers include the number of Dyck paths of length 2n beginning with an even number of up-steps the number of ordered trees with n+1 vertices where the root has no leaf children the number of ordered trees with n+1 vertices where the root has an even number of children and so on.
For more interpretations see Deutsch and Shapiro's "A survey of the Fine numbers".

Formulas
You may use any correct formula to generate the sequence. Here are some:

The generating function is

Sum[0, Inf] F[n]*z^n = 1/z * (1-sqrt(1-4z))/(3-sqrt(1-4z))

For n≥1, Cn=2Fn+Fn−1.

An explicit formula:

F[n] = 1/(n+1) * Sum[k=0, n] (-1)^k * (k + 1) * binomial(2n-k, n-k)

Task
Standard sequence rules apply to this challenge, where permissible behaviours are
outputting the nth term in 0- or 1-based indexing given n outputting the first n terms given n
outputting the infinite sequence with no input, either by printing or returning a lazy list/generator

This is code-golf; fewest bytes wins.

"""

from math import *

# https://oeis.org/A000957
def F(n):
    if n < 0:
        return 0

    r = 0
    for i in range(n+1):
        r += (-1)**i * (i + 1) * comb(2*n - i, n-i)
    return r//(n+1)

def main():
    tab = [0, 1, 0, 1, 2, 6, 18, 57, 186, 622, 2120, 7338, 25724, 91144, 325878, 1174281, 4260282, 15548694, 57048048, 210295326, 778483932, 2892818244, 10786724388, 40347919626, 151355847012, 569274150156, 2146336125648, 8110508473252, 30711521221376]
    for i in range(len(tab)):
        assert(F(i-1) == tab[i])

main()
