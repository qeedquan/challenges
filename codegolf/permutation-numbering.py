#!/usr/bin/env python3

"""

The Challenge
For a given set of n integers, write a program which will output its lexicographic index.

The Rules
The input must only be a set of unique non-negative integers separated by spaces.
You should output the lexicographic index (range 0 to n!-1 inclusive) of the permutation.
No permutation libraries or permutation built-ins may be used.
You may not generate the set of permutations or any subset of permutations of the input to help you find the index.
You also can't increment or decrement the given permutation to the next/previous(lexicographically) permutation.
Bonus points (-10 bytes) if you find some way to complete this without using factorials.
Runtime should be less than 1 minute for n = 100

Shortest code by byte count wins
Winner chosen Tuesday (July 22, 2014)

More About Permutations
http://www.monkeyphysics.com/articles/read/26/numbering_permutations.html
Permutation group operation
http://lin-ear-th-inking.blogspot.com/2012/11/enumerating-permutations-using.html

Examples
0 1 2 --> 0
0 2 1 --> 1
1 0 2 --> 2
1 2 0 --> 3
2 0 1 --> 4
2 1 0 --> 5
0 1 2 3 4 5 6 7 --> 0
0 1 2 3 4 5 7 6 --> 1
0 1 2 3 4 6 5 7 --> 2
1 3 5 17        --> 0
781 780 779 13  --> 23
81 62 19 12 11 8 2 0 --> 40319
195 124 719 1 51 6 3 --> 4181

"""

"""

@xnor

We use the fact that the lexicographic index of a permutation is the sum over the elements of the permutations of the number of inversions above that element (values after it but below it)
multiplied by the factorial of the number of elements after it. Rather than evaluate this polynomial-like expression term by term, we use something akin to Horner's method.

Rather then looping over array indices, we repeatedly remove the first element of the list and process the remaining elements.
The expression sorted(p).index(p.pop(0)) counts the number of inversions past the first index by taking its position in the sorted list, while at the same time doing the removal.

"""

def number(a):
    r = 0
    while True:
        n = len(a)
        if n == 0:
            break

        x = sorted(a)
        y = a.pop(0)
        i = x.index(y)
        r = r*n + i
    return r

def main():
    assert(number([0, 1, 2]) == 0)
    assert(number([0, 2, 1]) == 1)
    assert(number([1, 0, 2]) == 2)
    assert(number([1, 2, 0]) == 3)
    assert(number([2, 0, 1]) == 4)
    assert(number([2, 1, 0]) == 5)
    assert(number([0, 1, 2, 3, 4, 5, 6, 7]) == 0)
    assert(number([0, 1, 2, 3, 4, 5, 7, 6]) == 1)
    assert(number([0, 1, 2, 3, 4, 6, 5, 7]) == 2)
    assert(number([1, 3, 5, 17]) == 0)
    assert(number([781, 780, 779, 13]) == 23)
    assert(number([81, 62, 19, 12, 11, 8, 2, 0]) == 40319)
    assert(number([195, 124, 719, 1, 51, 6, 3]) == 4181)

main()
