#!/usr/bin/env python3

"""

Kids who are learning how to count often know runs of numbers, but can't seem to put those runs together properly.

For example, they might say:

1,2,3,4,7,8,9,10
Sometimes kids will realize that they skipped some numbers, and go back:

1,2,3,4,7,8,5,6,7,8,9,10
This is clearly the superior pattern. We need to identify them.

To identify these lists:

We identify the minimum M and the maximum N of the list

We step through the list. If the current number is greater than or equal to any member of the list to its right, then we remove the current number.

Iff the remaining list contains all numbers from M to N, then we return a truthy value.

You can assume your input list will contain at least 1 element. You can assume that all integers will be non-negative.

Test cases:
Truthy:

0
10
0 0 0
1 0 1
0 1 2 3 4 5 6 7 8 9 10
0 1 2 3 0 1 2 3
0 1 2 3 4 5 5
0 1 1 2 2 3
0 3 6 1 4 7 2 5 8 3 4 5 6 7 8
1 3 5 7 2 3 4 5 6 7
5 6 0 1 2 3 6 7 4 5 6 7
5 6 7 8
5 5 6 7 8
4 6 7 8 3 4 5 6 7 8
Falsy:

1 0
4 3 2 1
1 2 3 7 8 9
0 1 2 3 1 3
0 1 2 3 1 3 4
0 1 2 3 1 3 2 4
0 1 2 3 1 3 2 4 3
1 3 5 7 2 4 6 8
0 1 2 1 3 4 5 6
4 5 6 3 4 5
This is code-golf, so make your answers as short as possible!

"""

def takeback(a):
    x = min(a)
    y = max(a)

    i = 0
    while i < len(a):
        f = 0
        for j in range(i + 1, len(a)):
            if a[i] >= a[j]:
                f = 1
                break

        if f != 0:
            del a[i]
        else:
            i += 1

    m = {}
    for v in a:
        if x <= v and v <= y:
            m[v] = True

    return len(m) == y - x + 1

def main():
    assert(takeback([0]) == True)
    assert(takeback([10]) == True)
    assert(takeback([0, 0, 0]) == True)
    assert(takeback([1, 0, 1]) == True)
    assert(takeback([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]) == True)
    assert(takeback([0, 1, 2, 3, 0, 1, 2, 3]) == True)
    assert(takeback([0, 1, 2, 3, 4, 5, 5]) == True)
    assert(takeback([0, 1, 1, 2, 2, 3]) == True)
    assert(takeback([0, 1, 2, 3, 4, 5, 5]) == True)
    assert(takeback([0, 1, 1, 2, 2, 3]) == True)
    assert(takeback([0, 3, 6, 1, 4, 7, 2, 5, 8, 3, 4, 5, 6, 7, 8]) == True)
    assert(takeback([1, 3, 5, 7, 2, 3, 4, 5, 6, 7]) == True)
    assert(takeback([5, 6, 0, 1, 2, 3, 6, 7, 4, 5, 6, 7]) == True)
    assert(takeback([5, 6, 7, 8]) == True)
    assert(takeback([5, 5, 6, 7, 8]) == True)
    assert(takeback([4, 6, 7, 8, 3, 4, 5, 6, 7, 8]) == True)

    assert(takeback([1, 0]) == False)
    assert(takeback([4, 3, 2, 1]) == False)
    assert(takeback([1, 2, 3, 7, 8, 9]) == False)
    assert(takeback([0, 1, 2, 3, 1, 3]) == False)
    assert(takeback([0, 1, 2, 3, 1, 3, 4]) == False)
    assert(takeback([0, 1, 2, 3, 1, 3, 2, 4]) == False)
    assert(takeback([0, 1, 2, 3, 1, 3, 2, 4, 3]) == False)
    assert(takeback([1, 3, 5, 7, 2, 4, 6, 8]) == False)
    assert(takeback([0, 1, 2, 1, 3, 4, 5, 6]) == False)
    assert(takeback([4, 5, 6, 3, 4, 5]) == False)
    assert(takeback([1, 2, 3, 4, 7, 8, 9, 10]) == False)

main()
