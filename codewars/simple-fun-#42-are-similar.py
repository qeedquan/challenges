#!/usr/bin/env python3

"""

Task
Two arrays are called similar if one can be obtained from another by swapping at most one pair of elements.

Given two arrays, check whether they are similar.

Example
For A = [1, 2, 3] and B = [1, 2, 3], the output should be true;

For A = [1, 2, 3] and B = [2, 1, 3], the output should be true;

For A = [1, 2, 2] and B = [2, 1, 1], the output should be false.

Input/Output
[input] integer array A

Array of integers.

Constraints: 3 ≤ A.length ≤ 10000, 1 ≤ A[i] ≤ 1000.

[input] integer array B

Array of integers of the same length as A.

Constraints: B.length = A.length, 1 ≤ B[i] ≤ 1000.

[output] a boolean value

true if A and B are similar, false otherwise.

"""

def similar(a, b):
    if len(a) != len(b):
        return False

    a = sorted(a)
    b = sorted(b)
    c = 0
    for i in range(len(a)):
        if a[i] != b[i]:
            c += 1
    return c <= 2 and a == b

def main():
    assert(similar([1, 2, 3], [1, 2, 3]) == True)
    assert(similar([1, 2, 3], [2, 1, 3]) == True)
    assert(similar([1, 2, 2], [2, 1, 1]) == False)
    assert(similar([1, 2, 3], [1, 10, 2]) == False)
    assert(similar([2, 3, 1], [1, 3, 2]) == True)
    assert(similar([1, 1, 2], [1, 2, 2]) == False)

main()
