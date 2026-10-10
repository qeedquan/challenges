#!/usr/bin/env python3

"""

Given 2 integers n and start. Your task is return any permutation p of (0,1,2.....,2^n -1) such that :

p[0] = start
p[i] and p[i+1] differ by only one bit in their binary representation.
p[0] and p[2^n -1] must also differ by only one bit in their binary representation.


Example 1:

Input: n = 2, start = 3
Output: [3,2,0,1]
Explanation: The binary representation of the permutation is (11,10,00,01).
All the adjacent element differ by one bit. Another valid permutation is [3,1,0,2]
Example 2:

Input: n = 3, start = 2
Output: [2,6,7,5,4,0,1,3]
Explanation: The binary representation of the permutation is (010,110,111,101,100,000,001,011).


Constraints:

1 <= n <= 16
0 <= start < 2^n

Hint:
Use gray code to generate a n-bit sequence.
Rotate the sequence such that its first element is start.

"""

def popcnt(x):
    return bin(x).count('1')

def bin2gray(n):
    return n ^ (n >> 1)

def circular_permutation(n, s):
    r = []
    for i in range(1<<n):
        r.append(s ^ bin2gray(i))
    return r

def test(n, s, r):
    p = circular_permutation(n, s)
    print(p)
    assert(set(p) == set(r))
    for i in range(1, len(p)):
        assert(popcnt(p[i] ^ p[i-1]) == 1)

def main():
    test(2, 3, [3, 2, 0, 1])
    test(3, 2, [2, 6, 7, 5, 4, 0, 1, 3])

main()
