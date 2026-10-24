#!/usr/bin/env python3

"""

Little Vasya is very fond of equations. Once his sight caught the equation x+y+xy=n.
Vasya wants to know the number of pairs of non-negative integers x and y, that are the solutions of this equation.

Input
One integer n (0≤n≤10^9).

Output
Print the number of pairs of solutions.

Examples
Below given all the solutions of equation x+y+xy=5:

(x,y)=(0,5)

(x,y)=(1,2)

(x,y)=(2,1)

(x,y)=(5,0)

Input #1
5

Answer #1
4

Input #2
8

Answer #2
3

"""

from sympy import divisor_count

"""

https://artofproblemsolving.com/wiki/index.php/Simon%27s_Favorite_Factoring_Trick

Add 1 to both sides of the equation:
x + y + xy + 1 = n + 1

Factor the equation
(x + y)(y + 1) = n + 1

Since x and y are positive integers, they must be positive divisors of (n + 1),
Hence, the number of divisors of (n + 1) is the number of (x, y) pairs that satisfy the equation.

"""

# https://oeis.org/A000005
def solve(n):
    return divisor_count(n + 1)

def main():
    tab = [
        1, 2, 2, 3, 2, 4, 2, 4, 3, 4, 2, 6, 2, 4, 4, 5, 2, 6, 2, 6, 4, 4, 2, 8,
        3, 4, 4, 6, 2, 8, 2, 6, 4, 4, 4, 9, 2, 4, 4, 8, 2, 8, 2, 6, 6, 4, 2, 10,
        3, 6, 4, 6, 2, 8, 4, 8, 4, 4, 2, 12, 2, 4, 6, 7, 4, 8, 2, 6, 4, 8, 2,
        12, 2, 4, 6, 6, 4, 8, 2, 10, 5, 4, 2, 12, 4, 4, 4, 8, 2, 12, 4, 6, 4,
        4, 4, 12, 2, 6, 6, 9, 2, 8, 2, 8
    ]

    assert(solve(5) == 4)
    assert(solve(8) == 3)

    for i in range(len(tab)):
        assert(solve(i) == tab[i])

main()
