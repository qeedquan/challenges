#!/usr/bin/env python3

"""

Description

John von Neumann, b. Dec. 28, 1903, d. Feb. 8, 1957, was a Hungarian-American mathematician who made important contributions to the foundations of mathematics, logic, quantum physics,meteorology, science, computers, and game theory. He was noted for a phenomenal memory and the speed with which he absorbed ideas and solved problems. In 1925 he received a B.S. diploma in chemical engineering from Zurich Institute and in 1926 a Ph.D. in mathematics from the University of Budapest. His Ph.D. dissertation on set theory was an important contribution to the subject. At the age of 20, von Neumann proposed a new definition of ordinal numbers that was universally adopted. While still in his twenties, he made many contributions in both pure and applied mathematics that established him as a mathematician of unusual depth. His Mathematical Foundations of Quantum Mechanics (1932) built a solid framework for the new scientific discipline. During this time he also proved the mini-max theorem of GAME THEORY. He gradually expanded his work in game theory, and with coauthor Oskar Morgenstern he wrote Theory of Games and Economic Behavior (1944).
There are some numbers which can be expressed by the sum of factorials. For example 9,9=1!+2!+3! Dr. von Neumann was very interested in such numbers. So, he gives you a number n, and wants you to tell him whether or not the number can be expressed by the sum of some factorials.
Well, it's just a piece of cake. For a given n, you'll check if there are some xi, and let n equal to Σ1<=i<=txi!. (t >=1 1, xi >= 0, xi = xj iff. i = j). If the answer is yes, say "YES"; otherwise, print out "NO".

Input

You will get several non-negative integer n (n <= 1,000,000) from input file. Each one is in a line by itself.
The input is terminated by a line with a negative integer.

Output

For each n, you should print exactly one word ("YES" or "NO") in a single line. No extra spaces are allowed.

Sample Input

9
-1

Sample Output

YES
Source

Asia Guangzhou 2003

"""

from math import *

# https://oeis.org/A007489
def sof(n):
    r = 0
    i = 1
    while r < n:
        r += factorial(i)
        i += 1
    return r == n

def main():
    tab = [0, 1, 3, 9, 33, 153, 873, 5913, 46233, 409113, 4037913]
    for i in range(max(tab) + 1):
        if sof(i):
            assert(i in tab)
        else:
            assert(i not in tab)

main()
