/*

Given an array A consisting of n natural numbers, your task is to sort it using the bubble sort
algorithm and display the array after each iteration of the sorting process.

Input
The first line contains a single integer n (1≤n≤100), representing the size of the array.
The second line contains n natural numbers, which are the elements of array A (1≤Ai≤10^9).

Output
Provide n−1 lines of output, each containing n numbers, representing the state of the array after each iteration of the sorting process.

Examples
Input #1
6
5 4 4 2 3 1

Answer #1
4 4 2 3 1 5
4 2 3 1 4 5
2 3 1 4 4 5
2 1 3 4 4 5
1 2 3 4 4 5

*/

package main

import "fmt"

func main() {
	bubblesort([]int{5, 4, 4, 2, 3, 1})
}

func bubblesort(a []int) {
	for i := len(a) - 1; i > 0; i-- {
		for j := range i {
			if a[j] > a[j+1] {
				a[j], a[j+1] = a[j+1], a[j]
			}
		}
		fmt.Println(a)
	}
}
