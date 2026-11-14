#!/usr/bin/env python3

"""

On the Mathematica Stack Exchange, 100xln2 asks:

I need a list of integers […] The list contains integers and is characterized by [three] parameters, lets call them k and j [and listmax], which should be variable.

If k=1 and j=1 then the list would look like this: {1,3,5,7,9,11,....until listmax}

If k=2 and j=3 then the list would look like this: {1,2,6,7,11,12,16,17,.....until listmax}

Generally speaking, the List contains the first k integers, then doesn't contain the next j integers, then contains the next k integers, then doesn't contain the next j integers and so on and so on.

Let's help them out! (I hope they're okay with Jelly, Vyxal, or Befunge code instead of Mathematica…)

Given three positive integers (k,j,listmax), make a list of integers as described above, sorted in increasing order.

For (3,2,6) you should return [1,2,3,6] rather than [1,2,3] or [1,2,3,6,7,8]. You can imagine you're generating an infinite “include 3, skip 2” list, and taking elements from it as long as they're ≤ 6.

Rules
This is code-golf. Write the shortest possible answer, measured in bytes.

Standard I/O methods apply, which means valid submissions include:

a three-parameter function that returns a list of numbers,
a three-parameter function that prints each number in the list,
a full program that reads inputs and prints each number in the list,
and so on.

Tests
In the format k j listmax --> output:

1 1 11 --> [1, 3, 5, 7, 9, 11]
2 13 19 --> [1, 2, 16, 17]
2 13 16 --> [1, 2, 16]
1 4 49 --> [1, 6, 11, 16, 21, 26, 31, 36, 41, 46]
2 4 22 --> [1, 2, 7, 8, 13, 14, 19, 20]
2 10 13 --> [1, 2, 13]
5 15 10 --> [1, 2, 3, 4, 5]
1 13 27 --> [1, 15]
7 4 31 --> [1, 2, 3, 4, 5, 6, 7, 12, 13, 14, 15, 16, 17, 18, 23, 24, 25, 26, 27, 28, 29]
99 99 1 --> [1]

"""

def kjr(k, j, n):
    r = []
    for i in range(1, n + 1, k + j):
        for l in range(k):
            if i + l > n:
                break
            r.append(i + l)
    return r

def main():
    assert(kjr(1, 1, 11) == [1, 3, 5, 7, 9, 11])
    assert(kjr(2, 13, 19) == [1, 2, 16, 17])
    assert(kjr(2, 13, 16) == [1, 2, 16])
    assert(kjr(1, 4, 49) == [1, 6, 11, 16, 21, 26, 31, 36, 41, 46])
    assert(kjr(2, 4, 22) == [1, 2, 7, 8, 13, 14, 19, 20])
    assert(kjr(2, 10, 13) == [1, 2, 13])
    assert(kjr(5, 15, 10) == [1, 2, 3, 4, 5])
    assert(kjr(1, 13, 27) == [1, 15])
    assert(kjr(7, 4, 31) == [1, 2, 3, 4, 5, 6, 7, 12, 13, 14, 15, 16, 17, 18, 23, 24, 25, 26, 27, 28, 29])
    assert(kjr(99, 99, 1) == [1])

main()
