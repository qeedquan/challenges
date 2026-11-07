#!/usr/bin/env python3

"""

There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.



Example 1:

Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
Example 2:


Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."


Constraints:

n == dominoes.length
1 <= n <= 10^5
dominoes[i] is either 'L', 'R', or '.'.m

"""

# https://walkccc.me/LeetCode/problems/0838/
def push_dominoes(s):
    p = list(s)
    L = -1
    R = -1
    for i in range(len(s) + 1):
        if i == len(s) or s[i] == 'R':
            if L < R:
                while R < i:
                    p[R], R = 'R', R+1
            R = i
        elif s[i] == 'L':
            if R < L or (L, R) == (-1, -1):
                if (L, R) == (-1, -1):
                    L += 1
                while L < i:
                    p[L], L = 'L', L+1
            else:
                l, r = R+1, i-1
                while l < r:
                    p[l], p[r] = 'R', 'L'
                    l, r = l+1, r-1
            L = i

    return ''.join(p)

def main():
    assert(push_dominoes("RR.L") == "RR.L")
    assert(push_dominoes(".L.R...LR..L..") == "LL.RR.LLRRLL..")

main()
