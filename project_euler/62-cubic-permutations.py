#!/usr/bin/env python3

"""

The cube, 41063625 (345^3), can be permuted to produce two other cubes: 56623104 (384^3) and 66430125 (405^3).
In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.

Find the smallest cube for which exactly five permutations of its digits are cube.

"""

class Value:
    def __init__(self, smallest):
        self.smallest = smallest
        self.count = 0
        self.bound = 0

def digitsort(n):
    d = 10*[0]
    while n > 0:
        d[n % 10] += 1
        n //= 10

    r = 0
    for v in range(9, -1, -1):
        r = (10 ** d[v] * (v + 9 * r) - v) // 9;
    return r

# https://www.xarg.org/puzzle/project-euler/problem-62/
def solve(l):
    m = {}
    c = []
    i = 1
    while True:
        k = digitsort(i**3)
        if k not in m:
            m[k] = Value(i)
        
        v = m[k]
        v.count += 1
        if v.count == l:
            v.bound = int(k**(1/3))
            c.append(v)

        for v in c:
            if v.bound >= i and v.count == l:
                return v.smallest**3
        
        i += 1

def main():
    print(solve(5))

main()
