#!/usr/bin/env python3

"""

Suppose you have n integers labeled 1 through n.
A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.

Example 1:

Input: n = 2
Output: 2
Explanation: 
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 15

"""

# https://blog.firedrake.org/archive/2022/11/The_Weekly_Challenge_191__Large_but_Cute.html
# https://oeis.org/A320843
def arrangement(n):
    tab = [[False]]
    for x in range(1, n+1):
        tab.append([False] * (n+1))
    
    for x in range(1, n+1):
        for y in range(1, x+1):
            if x % y != 0 and y % x != 0:
                tab[x][y] = True
                tab[y][x] = True
    
    count = 0
    stackl = [[]]
    stackc = [[x for x in range(1,n+1)]]
    while len(stackl) > 0:
        l = stackl.pop()
        c = stackc.pop()
        if len(c) == 0 and len(l) == n:
            count += 1
            continue
        
        place = len(l) + 1
        for candidate in c:
            if not tab[place][candidate]:
                q = l.copy()
                q.append(candidate)
                stackl.append(q)
                stackc.append([i for i in c if i != candidate])
    return count

def main():
    tab = [1, 1, 2, 3, 8, 10, 36, 41, 132, 250, 700, 750, 4010, 4237, 10680]
    
    for i in range(len(tab)):
        assert(arrangement(i) == tab[i])

main()
