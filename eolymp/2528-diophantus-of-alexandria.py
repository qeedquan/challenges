#!/usr/bin/env python3

"""

Diophantus of Alexandria was an Egyptian mathematician who lived in Alexandria.
He was one of the first mathematicians to study equations where variables are restricted to integer values.
In his honor, these equations are called diophantine equations. One of the most famous diophantine equations is x^n + y^n = z^n.
Fermat suggested that for n>2, there are no solutions with positive integer values for x, y, and z.
A proof of this theorem, known as Fermat's Last Theorem, was found only recently by Andrew Wiles, an English mathematician working at Princeton University (USA).

Consider the following diophantine equation:
1/x + 1/y = 1/n

where x,y,n∈N+(1)

Diophantus was interested in the following question: for a given n, how many distinct solutions (i.e., solutions satisfying x≤y) does equation (1) have?
For example, for n=4, there are exactly three distinct solutions:

1/5 + 1/20 = 1/4
1/6 + 1/12 = 1/4
1/8 + 1/8 = 1/4

Clearly, enumerating these solutions can be tedious for large values of n. Can you help Diophantus quickly compute the number of distinct solutions for large n?

Input
The first line contains the number of test cases. Each test case is given in a separate line and contains a single integer n (1≤n≤10^9).

Output
The output for each test case begins with a line containing the message Scenario #i:, where i is the number of the test case starting from 1.
The next line should display the number of distinct solutions to equation (1) for the given value of n. Output a blank line after each test case.

Examples

Input #1
2
4
1260

Answer #1
Scenario #1:
3

Scenario #2:
113

"""

from sympy import divisor_count

"""

https://math.stackexchange.com/questions/403036/natural-number-solutions-to-fracxyxy-n-equivalent-to-frac-1x-frac-1y
https://oeis.org/A018892

"""

def solve(n):
    return (divisor_count(n**2) + 1) // 2

def main():
    tab = [
        1, 2, 2, 3, 2, 5, 2, 4, 3, 5, 2, 8, 2, 5, 5, 5, 2, 8, 2, 8, 5, 5, 2,
        11, 3, 5, 4, 8, 2, 14, 2, 6, 5, 5, 5, 13, 2, 5, 5, 11, 2, 14, 2, 8, 8,
        5, 2, 14, 3, 8, 5, 8, 2, 11, 5, 11, 5, 5, 2, 23, 2, 5, 8, 7, 5, 14, 2,
        8, 5, 14, 2, 18, 2, 5, 8, 8, 5, 14, 2, 14, 5, 5, 2, 23, 5, 5, 5, 11, 2,
        23, 5, 8, 5, 5, 5, 17, 2, 8, 8
    ]

    assert(solve(4) == 3)
    assert(solve(1260) == 113)

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i])

main()

