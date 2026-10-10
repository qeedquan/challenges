#!/usr/bin/env python3

"""

Given a non-negative number n, output the number of ways to express n as the sum of two squares of integers n == a^2 + b^2 (OEIS A004018). Note that a and b can be positive, negative, or zero, and their order matters. Fewest bytes wins.

For example, n=25 gives 12 because 25 can be expressed as

(5)^2  + (0)^2
(4)^2  + (3)^2
(3)^2  + (4)^2
(0)^2  + (5)^2
(-3)^2 + (4)^2
(-4)^2 + (3)^2
(-5)^2 + (0)^2
(-4)^2 + (-3)^2
(-3)^2 + (-4)^2
(0)^2  + (-5)^2
(3)^2  + (-4)^2
(4)^2  + (-3)^2

Here are the values up to n=25. Be careful that your code works for n=0.

0 1
1 4
2 4
3 0
4 4
5 8
6 0
7 0
8 4
9 4
10 8
11 0
12 0
13 8
14 0
15 0
16 4
17 8
18 4
19 0
20 8
21 0
22 0
23 0
24 0
25 12
Here are the values up to n=100 as a list.

[1, 4, 4, 0, 4, 8, 0, 0, 4, 4, 8, 0, 0, 8, 0, 0, 4, 8, 4, 0, 8, 0, 0, 0, 0, 12, 8, 0, 0, 8, 0, 0, 4, 0, 8, 0, 4, 8, 0, 0, 8, 8, 0, 0, 0, 8, 0, 0, 0, 4, 12, 0, 8, 8, 0, 0, 0, 0, 8, 0, 0, 8, 0, 0, 4, 16, 0, 0, 8, 0, 0, 0, 4, 8, 8, 0, 0, 0, 0, 0, 8, 4, 8, 0, 0, 16, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 8, 4, 0, 12]
Fun facts: The sequence contains terms that are arbitrarily high, and the limit of its running average is π.

"""

from sympy import factorint

# https://oeis.org/A004018
def count(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    
    r = 4
    for p, e in factorint(n).items():
       if p%4 == 1:
           r *= (e + 1)
       elif p%4 == 3 and e%2 != 0:
           return 0
    return r

def main():
    tab = [1, 4, 4, 0, 4, 8, 0, 0, 4, 4, 8, 0, 0, 8, 0, 0, 4, 8, 4, 0, 8, 0, 0, 0, 0, 12, 8, 0, 0, 8, 0, 0, 4, 0, 8, 0, 4, 8, 0, 0, 8, 8, 0, 0, 0, 8, 0, 0, 0, 4, 12, 0, 8, 8, 0, 0, 0, 0, 8, 0, 0, 8, 0, 0, 4, 16, 0, 0, 8, 0, 0, 0, 4, 8, 8, 0, 0, 0, 0, 0, 8, 4, 8, 0, 0, 16, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 8, 4, 0, 12, 8]

    for i in range(len(tab)):
        assert(count(i) == tab[i])

main()
