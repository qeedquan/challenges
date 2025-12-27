#!/usr/bin/env python3

"""

Given a positive integer (n) find the nearest fibonacci number to (n).

If there are more than one fibonacci with equal distance to the given number return the smallest one.

Do it in a efficient way. 5000 tests with the input range 1 <= n <= 2^512 should not exceed 200 ms.

"""

from bisect import bisect_left

class Fibs:
    def __init__(self):
        self.fibs = [1, 2]

    def nearest(self, n):
        while self.fibs[-1] < n:
            self.fibs.append(self.fibs[-1] + self.fibs[-2])
        
        i = bisect_left(self.fibs, n)
        if self.fibs[i] == n:
            return n
        
        if i == 0:
            return self.fibs[0]

        lo, hi = self.fibs[i - 1], self.fibs[i]
        if n-lo <= hi-n:
            return lo
        return hi

def main():
    f = Fibs()
    for i in range(10000):
        print(i, f.nearest(i))
    print(f.nearest(2**512))

main()
