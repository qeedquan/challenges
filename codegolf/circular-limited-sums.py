#!/usr/bin/env python3

"""

Challenge
Let's imagine an N-tuple of integers between 0 and M inclusive, and let's call it F.

There are (M + 1) ** N possible Fs in total.

How many such Fs satisfy all of the following inequalities (index is one-based)?

F[n] + F[n+1] <= M for 1 <= n < N
F[N] + F[1] <= M

Write a program or function that takes two positive integers N and M and outputs the answer in any convenient form.

Test Cases
(N,M) => Answer

(1,1) => 1
(2,1) => 3
(3,1) => 4
(4,1) => 7

(1,2) => 2
(2,2) => 6
(3,2) => 11
(4,2) => 26

(10,3) => 39175
(10,4) => 286555
(10,5) => 1508401

(25,3) => 303734663372
(25,4) => 43953707972058
(25,5) => 2794276977562073

(100,3) => 8510938110502117856062697655362747468175263710
(100,4) => 3732347514675901732382391725971022481763004479674972370
(100,5) => 60964611448369808046336702581873778457326750953325742021695001
Explanation
M (max value of element) = 1

F[1] + F[1] <= 1; F = [0]
(1,1) => 1

F[1] + F[2] <= 1; F = [0,0], [0,1], [1,0]
(2,1) => 3

F = [0,0,0], [0,0,1], [0,1,0], [1,0,0]
(3,1) => 4

F = [0,0,0,0], [0,0,0,1], [0,0,1,0], [0,1,0,0], [0,1,0,1], [1,0,0,0], [1,0,1,0]
(4,1) => 7

---

M = 2

F[1] + F[1] <= 2; F = [0], [1]
(1,2) => 2

F = [0,0], [0,1], [0,2], [1,0], [1,1], [2,0]
(2,2) => 6

F = [0,0,0], [0,0,1], [0,0,2], [0,1,0], [0,1,1], [0,2,0], [1,0,0], [1,0,1],
[1,1,0], [1,1,1], [2,0,0]
(3,2) => 11

(4,2) => 26 (left as exercise for you)

Rules
This is a restricted-complexity challenge. The time complexity of your code should be polynomial in M and N (e.g. you can't generate all (M + 1) ** N tuples and then check for the condition). Please explain your approach in your submission.
Standard code-golf rules apply. The shortest answer in bytes wins.

"""

from sympy import Matrix, trace
import numpy as np

# ported from @xnor solution
def cls(n, m):
    T = np.tri(m + 1, dtype=int)
    M = Matrix(T[::-1])
    return trace(M**n)

def main():
    assert(cls(1, 1) == 1)
    assert(cls(2, 1) == 3)
    assert(cls(3, 1) == 4)
    assert(cls(4, 1) == 7)

    assert(cls(1, 2) == 2)
    assert(cls(2, 2) == 6)
    assert(cls(3, 2) == 11)
    assert(cls(4, 2) == 26)

    assert(cls(10, 3) == 39175)
    assert(cls(10, 4) == 286555)
    assert(cls(10, 5) == 1508401)

    assert(cls(25, 3) == 303734663372)
    assert(cls(25, 4) == 43953707972058)
    assert(cls(25, 5) == 2794276977562073)

    assert(cls(100, 3) == 8510938110502117856062697655362747468175263710)
    assert(cls(100, 4) == 3732347514675901732382391725971022481763004479674972370)
    assert(cls(100, 5) == 60964611448369808046336702581873778457326750953325742021695001)

main()
