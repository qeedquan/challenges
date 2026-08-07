#!/usr/bin/env python3

r"""

Input
You are given 2 positive integers, n, q, followed by q queries. the queries can be of two forms:

0 a b: add the line a*x + b. a and b are integers between -10^9 and 10^9 inclusive.
1 x: output the minimum of all the lines evaluated at x, x being an integer between 0 and n inclusive
Example
Input:
100 9
0 10 5
1 50
0 9 10
1 49
1 4
0 5 408
1 99
1 100
1 0

Output:
505     (10*50+5=505)
451     (10*49+5=495, 9*49+10=451)
45      (10*4+5=45, 9*4+10=46)
901     (10*99+5=995, 9*99+10=901, 5*99+408=903)
908     (10*100+5=1005, 9*100+10=910, 5*100+408=908)
5       (10*0+5=5, 9*0+10=10, 5*0+408=408)

Restrictions
Your code must run in O(qlog^2(n) + nlog^2(n)) time or better.

Extra
First query will allways be of type 0.

The bounds on a and b are also considered a factor of time the complexity if used, 10^9 was chosen to fit within 32 bit integers.

Score
The answer with the shortest code, in bytes wins.

Non-golfed example solution in Python 3
n, q = map(int, input().split())

class line:
    def __init__(self, a, b):
        self.a = a
        self.b = b
    def evaluate(self, x):
        return self.a*x + self.b

inf = float('inf')
LCT = [line(inf, inf)]*(n + 1) #initialise Li Chao Tree

def insert_line(line, left = 0, right = n):
    mid = (left + right)//2
    if line.evaluate(mid) < LCT[mid].evaluate(mid):
        #if the line being inserted is minimal, swap
        LCT[mid], line = line, LCT[mid]
    if left != right:
        #if the bottom of the tree hasn't been reached:
        if line.a < LCT[mid].a:
            #intersection will be to the right
            insert_line(line, mid + 1, right)
        else:
            #intersection will be to the left
            insert_line(line, left, mid)

def find_minimum(x, left = 0, right = n):
    mid = (left + right)//2
    low = LCT[mid].evaluate(x) #store minimal found line
    if left != right:
        if x > mid:
            #search right
            low = min(low, find_minimum(x, mid + 1, right))
        else:
            #search left
            low = min(low, find_minimum(x, left, mid))
    return low

for _ in range(q):
    query = list(map(int, input().split()))
    if query[0] == 0:
        insert_line(line(query[1],query[2]))
    else:
        print(find_minimum(query[1]))
```

"""

n, q = map(int, input().split())

class line:
    def __init__(self, a, b):
        self.a = a
        self.b = b
    
    def evaluate(self, x):
        return self.a*x + self.b

inf = float('inf')
LCT = [line(inf, inf)]*(n + 1) # initialise Li Chao Tree

def insert_line(line, left=0, right=n):
    mid = (left + right)//2
    if line.evaluate(mid) < LCT[mid].evaluate(mid):
        # if the line being inserted is minimal, swap
        LCT[mid], line = line, LCT[mid]
    if left != right:
        # if the bottom of the tree hasn't been reached:
        if line.a < LCT[mid].a:
            # intersection will be to the right
            insert_line(line, mid + 1, right)
        else:
            # intersection will be to the left
            insert_line(line, left, mid)

def find_minimum(x, left=0, right=n):
    mid = (left + right)//2
    low = LCT[mid].evaluate(x) # store minimal found line
    if left != right:
        if x > mid:
            # search right
            low = min(low, find_minimum(x, mid + 1, right))
        else:
            # search left
            low = min(low, find_minimum(x, left, mid))
    return low

def main():
    for _ in range(q):
        query = list(map(int, input().split()))
        if query[0] == 0:
            insert_line(line(query[1],query[2]))
        else:
            print(find_minimum(query[1]))

main()
