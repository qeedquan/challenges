#!/usr/bin/env python3

"""

Sorting in computer science is an important part. Almost every problem can be solved effeciently if sorted data are found.
There are some excellent sorting algorithm which has already acheived the lower bound n · lg n.
In this problem we will also discuss about a new sorting approach.
In this approach only one operation (Flip) is available and that is you can exchange two adjacent terms.
If you think a while, you will see that it is always possible to sort a set of numbers in this way.
A set of integers will be given. Now using the above approach we want to sort the numbers in ascending order.
You have to find out the minimum number of flips required. Such as to sort ‘1 2 3’
we need no flip operation whether to sort ‘2 3 1’ we need at least 2 flip operations.

Input
The input will start with a positive integer N (N ≤ 1000). In next few lines there will be N integers.
Input will be terminated by EOF.

Output
For each data set print ‘Minimum exchange operations : M’ where M is the minimum flip operations
required to perform sorting. Use a seperate line for each case.

Sample Input
3
1 2 3
3
2 3 1

Sample Output
Minimum exchange operations : 0
Minimum exchange operations : 2

"""

def flipsort(a):
    c = 0
    for i in range(1, len(a)):
        j = i
        while j > 0 and a[j] < a[j-1]:
            a[j], a[j-1] = a[j-1], a[j]
            j -= 1
            c += 1
    return c

def main():
    assert(flipsort([1, 2, 3]) == 0)
    assert(flipsort([2, 3, 1]) == 2)

main()
