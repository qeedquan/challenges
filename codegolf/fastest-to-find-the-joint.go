/*

The input is an array (or space-separated string, as you wish), zero-indexed, consisting of one strictly increasing array and one strictly decreasing array (in this order, not other vice versa), each having a length of 2 at least. Example is:

-10 -2 4 18 38 46 28 19 10
The goal is to write the fastest algorithm to find the joint of two sorted arrays.

In other words, the output is the index of the greatest element. In the provided case the output should be 5.

The input is guaranteed not to contain repeating numbers.

It's obvious that this can be solved with O(n) with ease, so please provide more interesting faster answers :)

Other test cases (first line is input, second is output):

0 1 4 3
2
1 10 9 8 7 6 5 4 3 1
1
1 3 4 6 7 8 0 -10 -20
5
1 3 5 3 1
2
You could also accept the length of the array as additional input, if needed

*/

package main

func main() {
	assert(findjoint([]int{-10, -2, 4, 18, 38, 46, 28, 19, 10}) == 5)
	assert(findjoint([]int{0, 1, 4, 3}) == 2)
	assert(findjoint([]int{1, 10, 9, 8, 7, 6, 5, 4, 3, 1}) == 1)
	assert(findjoint([]int{1, 3, 4, 6, 7, 8, 0, -10, -20}) == 5)
	assert(findjoint([]int{1, 3, 5, 3, 1}) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func findjoint(a []int) int {
	n := len(a)
	l := 0
	r := n - 1
	j := n / 2
	for j+1 < n && (a[j-1] > a[j] || a[j] < a[j+1]) {
		if a[j-1] < a[j] {
			l = j + 2
		} else {
			r = j - 2
		}
		j = l + (r-l)/2
	}
	return j
}
