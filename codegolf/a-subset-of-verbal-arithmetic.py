#!/usr/bin/env python3

"""

Implement a verbal arithmetic solver of several same sequence of numbers added together:

  TWO
+ TWO
-----
 FOUR

  REPEAT
  REPEAT
  REPEAT
+ REPEAT
--------
 ANDSTOP

  SPEED
+ SPEED
-------
  KILLS
There are some restrictions: each letter should represent different digits, and no letter can be zero.

Implement the solver as a function of the operands, the sum and number of repetitions returns a list of solutions (solution: the tuple of resulting operand and sum). For example:

f(['T','W','O'], ['F','O','U','R'], 2) == [(734, 1468)]
You do not need to represent variables as letters, and you do not need to use a hash in the solution. Brute-force search allowed.

Shortest code wins.

"""

# ported from @fR0DDY solution
def solve(A, B, N):
    D = {}
    r = []
    for j in A:
        D[j] = 0
    for j in B:
        D[j] = 0
    x = len(D)
    for i in range(10**(x - 1), 10**x):
        c = str(i)
        s = {}
        for j in c:
            s[j] = 0
        if len(s)-x != 0 or "0" in c:
            continue
        k = P = Q = 0
        for j in D:
            D[j] = int(c[k])
            k += 1
        for j in A:
            P = P*10 + D[j]
        for j in B:
            Q = Q*10 + D[j]
        if P*N == Q:
            r.append((P, Q))
    return r

def main():
    print(solve(["T", "W", "O"], ["F", "O", "U", "R"], 2))
    print(solve(["S", "P", "E", "E", "D"], ["K", "I", "L", "L", "S"], 2))

main()
