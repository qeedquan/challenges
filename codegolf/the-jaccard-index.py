#!/usr/bin/env python3

"""

The Jaccard index / similarity coefficient, also known as the Tanimoto index / coefficient, is a statistic used for gauging the similarity and diversity of finite sample sets. It was developed by Grove Karl Gilbert in 1884 for the field of weather forecasting [1] and later independently developed by Paul Jaccard [2] who was studying species of alpine plants. Finally, it was also formulated again by T. Tanimoto [3]. Overall, it is widely used in various fields where binary or binarized data are used. These include computer science, ecology, genomics, etc.

Mathematically speaking, it is defined as the size of the intersection divided by the size of the union of finite sample sets. Specifically, for two sets A
 and B
 it is defined as:

J(A,B)=|A⋂B||A⋃B|

It ranges from 0<=J(A,B)<=1
, where 0 is the case of the intersection between A
 and B
 being equal to the empty set.

Challenge
Given two finite sets, containing positive or negative integers, calculate their Jaccard coefficient. If your language of choice does not natively support sets, you can use an array / vector / list type. You may assume that at least one of the sets will be non-empty.

Test cases
{1, 2}, {}                -> 0.0
{-7, 3, -9}, {9, 2, 3, 4} -> ~0.167
{1, 2, 3}, {2, 4, 6}      -> 0.2
{0, 64}, {0, 64, 89, 93}  -> 0.5
{6, 42, 7, 1}, {42, 7, 6} -> 0.75
{3, 6, 9}, {3, 6, 9}      -> 1.0

Rules
You may use any standard I/O method
Standard loopholes are forbidden
This is code-golf, so shortest answer in bytes wins.

"""

def jaccard(a, b):
    x = set(a)
    y = set(b)
    
    u = len(x.union(y))
    v = len(x.intersection(y))
    if u == 0:
        return 0
    return v / u

def test(a, b, r):
    v = jaccard(a, b)
    print(v)
    assert(abs(v - r) < 1e-2)

def main():
    test([1, 2], [], 0)
    test([-7, 3, -9], [9, 2, 3, 4], 0.167)
    test([1, 2, 3], [2, 4, 6], 0.2)
    test([0, 64], [0, 64, 89, 93], 0.5)
    test([6, 42, 7, 1], [42, 7, 6], 0.75)
    test([3, 6, 9], [3, 6, 9], 1)

main()
