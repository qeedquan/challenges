#!/usr/bin/env python3

"""

In this challenge, given an array of integers, the goal is to efficiently find the subarray that has the greatest value when all of its elements are summed together.
Note that because some elements of the array may be negative, the problem is not solved by simply picking the start and end elements of the array to be the subarrray, and summing the entire array.
For example, given the array

{1, 2, -5, 4, -3, 2}

The maximum sum of a subarray is 4. It is possible for the subarray to be zero elements in length (if every element of the array were negative).

Try to come up with an efficient algorithm!

taken from cprogramming.com

"""

def maxsubset(array):
    cursum = 0
    prevmax = 0
    prevmaxloc = -1
    prevmin = 0
    prevminloc = -1
    curmin = 0
    curminloc = -1

    for i in range(len(array)):
        cursum += array[i]
        if cursum < curmin:
    	    curmin = cursum
    	    curminloc = i

        if cursum-curmin > prevmax-prevmin:
            prevmax = cursum
            prevmaxloc = i
            prevmin = curmin
            prevminloc = curminloc

    return array[prevminloc+1 : prevmaxloc+1]

def main():
    print(maxsubset([1, 2, -5, 4, -3, 2]))
    print(maxsubset([-1, -2, -3]))
    print(maxsubset([1, 2, 3, -4, 5, -20]))
    print(maxsubset([31, -41, 59, 26, -53, 58, 97, -93, -23, 84]))
    print(maxsubset([1, 2, 3, -4, 5, -20]))
    print(maxsubset([-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))

main()
