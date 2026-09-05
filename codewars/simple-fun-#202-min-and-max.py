#!/usr/bin/env python3

"""

Task
You are given three integers l, d and x. Your task is:

• determine the minimal integer n
    such that l ≤ n ≤ d, and the sum of its digits equals x.
• determine the maximal integer m
    such that l ≤ m ≤ d, and the sum of its digits equals x.

It is guaranteed that such numbers always exist.

Input/Output
[input] integer l

[input] integer d

1 ≤ l ≤ d ≤ 10000.

[input] integer x

1 ≤ x ≤ 36

[output] an integer array

Array of two elements, where the first element is n, and the second one is m.

Example
For l = 500, d = 505, x = 10, the output should be [505, 505].

For l = 100, d = 200, x = 10, the output should be [109, 190].

"""

def digsum(n):
    r = 0
    while n > 0:
        r += n % 10
        n //= 10
    return r

def min_and_max(l, d, x):
    r0, r1 = -1, -1
    for i in range(l, d + 1):
        s = digsum(i)
        if s == x:
            if r0 < 0:
                r0, r1 = i, i
            r0 = min(r0, i)
            r1 = max(r1, i)
    return [r0, r1]

def main():
    assert(min_and_max(500, 505, 10) == [505, 505])
    assert(min_and_max(100, 200, 10) == [109, 190])
    assert(min_and_max(123, 456, 5) == [131, 410])
    assert(min_and_max(99, 501, 5) == [104, 500])
    assert(min_and_max(99, 234, 1) == [100, 100])
    assert(min_and_max(99, 234, 19) == [199, 199])
    assert(min_and_max(99, 5001, 27) == [999, 4995])
    assert(min_and_max(99, 5001, 28) == [1999, 4996])
    assert(min_and_max(2000, 7000, 3) == [2001, 3000])

main()
