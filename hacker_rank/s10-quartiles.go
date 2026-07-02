/*

Task
Given an array, arr, of n integers, calculate the respective first quartile (Q1), second quartile (Q2), and third quartile (Q3). It is guaranteed that Q1, Q2, and Q3 are integers.

Example

arr = [9, 5, 7, 1, 3]

The sorted array is [1, 3, 5, 7, 9]  which has an odd number of elements.
The lower half consists of [1, 3], and its median is (1+3)/2 = 2.
The middle element is 5 and represents the second quartile.
The upper half is [7, 9] and its median is (7+9)/2 = 8. Return [2, 5, 8].

The array is already sorted. The lower half is [1, 3] with a median = (1+3)/2 = 2. The median of the entire array is (3+5)/2 = 4, and of the upper half is (5+7)/2 = 6. Return [2, 4, 6].

Function Description

Complete the quartiles function in the editor below.

quartiles has the following parameters:

int arr[n]: the values to segregate

Returns

int[3]: the medians of the left half of arr, arr in total, and the right half of arr.
Input Format

The first line contains an integer, n, the number of elements in arr.
The second line contains n space-separated integers, each an arr[i].

Constraints

5 <= n <= 50
0 < arr[i] <= 100, where arr[i] is the ith element of the array.

Sample Input

STDIN                   Function
-----                   --------
9                       arr[] size n = 9
3 7 8 5 12 14 21 13 18  arr = [3, 7, 8, 5, 12, 14, 21, 13,18]
Sample Output

6
12
16

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(medians([]int{9, 5, 7, 1, 3}))
	fmt.Println(medians([]int{1, 3, 5, 7}))
	fmt.Println(medians([]int{3, 7, 8, 5, 12, 14, 21, 13, 18}))
}

func medians(a []int) (L, X, U int) {
	n := len(a)
	sort.Ints(a)
	L = middle(a[:n/2], n/2)
	X = middle(a, n)
	U = middle(a[(n+1)/2:], n/2)
	return
}

func middle(a []int, i int) int {
	if i&1 == 0 {
		return (a[i/2] + a[i/2-1]) / 2
	}
	return a[i/2]
}
