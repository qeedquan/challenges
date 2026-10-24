#!/usr/bin/env python3

"""

Background
For the purposes of this challenge, an n-state cellular automaton is simply a binary function f that takes two numbers from the state set {0, 1, ..., n-1} as inputs, and returns another number from that set as output. It can be applied to a list of numbers L = [x0, x1, x2, ..., xk-1] of length at least 2 by

f(L) = [f(x0, x1), f(x1, x2), f(x2, x3), ..., f(xk-2, xk-1)]
Note that the resulting list has one fewer element than the original. A spacetime diagram of f starting from L is the list of lists obtained by repeatedly applying f to L, and collecting the results in a list. The final list has length 1. We say that the list L is an identifying sequence for f, if every two-element list over the state set is a contiguous sublist of some row of the spacetime diagram starting from L. This is equivalent to the condition that no other n-state CA has that exact spacetime diagram.

Input
Your inputs are an n-by-n integer matrix M, a list of integers L of length at least 2, and optionally the number n. The matrix M defines an n-state CA f by f(a,b) = M[a][b] (using 0-based indexing). It is guaranteed that n > 0, and that M and L only contain elements of the state set {0, 1, ..., n-1}.

Output
Your output shall be a consistent truthy value if L is an identifying sequence for the CA f, and a consistent falsy value otherwise. This means that all "yes"-instances result in the same truthy value, and all "no"-instances result in the same falsy value.

Example
Consider the inputs n = 2, M = [[0,1],[1,0]], and L = [1,0,1,1]. The matrix M defines the binary XOR automaton f(a,b) = a+b mod 2, and the spacetime diagram starting from L is

1 0 1 1
1 1 0
0 1
1
This diagram does not contain 0 0 on any row, so L is not an identifying sequence, and the correct output is False. If we input L = [0,1,0,0] instead, the spacetime diagram is

0 1 0 0
1 1 0
0 1
1
The rows of this diagram contain all pairs drawn from the state set, namely 0 0, 0 1, 1 0 and 1 1, so L is an identifying sequence and the correct output is True.

Rules
You can write a full program or a function. The lowest byte count wins, and standard loopholes are disallowed.

Test Cases
Trivial automaton
[[0]] [0,0] 1 -> True
Binary XOR
[[0,1],[1,0]] [1,0,1,1] 2 -> False
[[0,1],[1,0]] [1,0,1,0] 2 -> True
[[0,1],[1,0]] [0,1,0,0] 2 -> True
Addition mod 3
[[0,1,2],[1,2,0],[2,0,1]] [0,1,1,0,0,0,1,0,0] 3 -> False
[[0,1,2],[1,2,0],[2,0,1]] [0,1,1,0,0,0,1,0,1] 3 -> True
Multiplication mod 3
[[0,0,0],[0,1,2],[0,2,1]] [0,1,1,2,0,0,1,0,1] 3 -> False
[[0,0,0],[0,1,2],[0,2,1]] [0,1,1,2,2,2,1,0,1] 3 -> True
Some 4-state automata
[[3,2,2,1],[0,0,0,1],[2,1,3,1],[0,1,2,3]] [0,0,0,0,1,1,1,1] 4 -> False
[[3,2,2,1],[0,0,0,1],[2,1,3,1],[0,1,2,3]] [0,0,0,1,0,1,1,1] 4 -> False
[[3,2,2,1],[0,0,0,1],[2,1,3,1],[0,1,2,3]] [0,1,2,3,3,1,2,3,0] 4 -> True
[[0,1,2,1],[1,0,2,0],[2,2,1,0],[1,2,0,0]] [0,0,1,1,2,2,0,2,1] 4 -> False
[[0,1,2,1],[1,0,2,0],[2,2,1,0],[1,2,0,0]] [0,3,1,3,2,3,3,0,1] 4 -> False
[[0,1,2,1],[1,0,2,0],[2,2,1,0],[1,2,0,0]] [0,3,1,3,2,3,3,0,1,2] 4 -> True

"""

"""

Ported from @Jakube solution

Straightforward implementation: Find all pairs by zipping, memorize them for later and apply M to L. Repeat. Compare the number of unique pairs found.

Input is of the form [[0,1],[1,0]], [0,1,0,0], 2.

"""

def equivalent(matrix, path, expected_count):
    seen = []
    while path:
        edges = list(zip(path, path[1:]))
        seen.extend(edges)
        path = [matrix[i][j] for i, j in edges]
    return len(set(seen)) == expected_count**2

def main():
    assert(equivalent([[0]], [0, 0], 1) == True)

    assert(equivalent([[0, 1], [1, 0]], [1, 0, 1, 1], 2) == False)
    assert(equivalent([[0, 1], [1, 0]], [1, 0, 1, 0], 2) == True)
    assert(equivalent([[0, 1], [1, 0]], [0, 1, 0, 0], 2) == True)

    assert(equivalent([[0, 1, 2], [1, 2, 0], [2, 0, 1]], [0, 1, 1, 0, 0, 0, 1, 0, 0], 3) == False)
    assert(equivalent([[0, 1, 2], [1, 2, 0], [2, 0, 1]], [0, 1, 1, 0, 0, 0, 1, 0, 1], 3) == True)
    
    assert(equivalent([[0, 0, 0], [0, 1, 2], [0, 2, 1]], [0, 1, 1, 2, 0, 0, 1, 0, 1], 3) == False)
    assert(equivalent([[0, 0, 0], [0, 1, 2], [0, 2, 1]], [0, 1, 1, 2, 2, 2, 1, 0, 1], 3) == True)

    assert(equivalent([[3, 2, 2, 1], [0, 0, 0, 1], [2, 1, 3, 1], [0, 1, 2, 3]], [0, 0, 0, 0, 1, 1, 1, 1], 4) == False)
    assert(equivalent([[3, 2, 2, 1], [0, 0, 0, 1], [2, 1, 3, 1], [0, 1, 2, 3]], [0, 0, 0, 1, 0, 1, 1, 1], 4) == False)
    assert(equivalent([[3, 2, 2, 1], [0, 0, 0, 1], [2, 1, 3, 1], [0, 1, 2, 3]], [0, 1, 2, 3, 3, 1, 2, 3, 0], 4) == True)
    assert(equivalent([[0, 1, 2, 1], [1, 0, 2, 0], [2, 2, 1, 0], [1, 2, 0, 0]], [0, 0, 1, 1, 2, 2, 0, 2, 1], 4) == False)
    assert(equivalent([[0, 1, 2, 1], [1, 0, 2, 0], [2, 2, 1, 0], [1, 2, 0, 0]], [0, 3, 1, 3, 2, 3, 3, 0, 1], 4) == False)
    assert(equivalent([[0, 1, 2, 1], [1, 0, 2, 0], [2, 2, 1, 0], [1, 2, 0, 0]], [0, 3, 1, 3, 2, 3, 3, 0, 1, 2], 4) == True)

main()
