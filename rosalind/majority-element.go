/*

Problem
An array A[1..n] is said to have a majority element if more than half of its entries are the same.

Given: A positive integer k≤20, a positive integer n≤10^4, and k arrays of size n containing positive integers not exceeding 10^5.

Return: For each array, output an element of this array occurring strictly more than n/2 times if such element exists, and "-1" otherwise.

Source: Algorithms by Dasgupta, Papadimitriou, Vazirani. McGraw-Hill. 2006.

Sample Dataset
4 8
5 5 5 5 5 5 5 5
8 7 7 7 1 7 3 7
7 1 6 5 10 100 1000 1
5 1 6 7 1 1 10 1

Sample Output
5 7 -1 -1

Discussion
It is not difficult to develop a divide-and-conquer algorithm checking whether a given array of size n contains a majority element in O(nlogn) time.
It is interesting to note that there is also a linear time algorithm and it is also based on divide-and-conquer.

*/

package main

func main() {
	assert(majority([]int{5, 5, 5, 5, 5, 5, 5, 5}) == 5)
	assert(majority([]int{8, 7, 7, 7, 1, 7, 3, 7}) == 7)
	assert(majority([]int{7, 1, 6, 5, 10, 100, 1000, 1}) == -1)
	assert(majority([]int{5, 1, 6, 7, 1, 1, 10, 1}) == -1)
	assert(majority([]int{}) == -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
func majority(a []int) int {
	n, m, c := len(a), 0, 1
	for i := 1; i < n; i++ {
		if a[m] == a[i] {
			c++
		} else {
			c--
		}
		if c == 0 {
			m, c = i, 1
		}
	}

	c = 0
	for i := range a {
		if a[m] != a[i] {
			continue
		}
		if c++; c > n/2 {
			return a[m]
		}
	}
	return -1
}
