#!/usr/bin/env python3

"""

Given a triangle of consecutive odd numbers:

             1
          3     5
       7     9    11
   13    15    17    19
21    23    25    27    29
...
find the triangle's row knowing its index (the rows are 1-indexed), e.g.:

odd_row(1)  ==  [1]
odd_row(2)  ==  [3, 5]
odd_row(3)  ==  [7, 9, 11]
Note: your code should be optimized to handle big inputs.

"""

def oddrow(n):
    r = [0] * n
    for i in range(n):
        r[i] = n*n - n + 1 + i*2
    return r

def main():
    assert(oddrow(1) == [1])
    assert(oddrow(2) == [3, 5])
    assert(oddrow(3) == [7, 9, 11])
    assert(oddrow(4) == [13, 15, 17, 19])
    assert(oddrow(5) == [21, 23, 25, 27, 29])

main()
