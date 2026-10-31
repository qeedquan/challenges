/*

The Heap data structure can be implemented using an array.

The array must maintain the main heap property: for each i (1≤i≤n) next conditions must hold:

If 2i≤n, then ai≤a2i
If 2i+1≤n, then a[i]≤a[2i+1]

The array of integers is given. Determine whether it is a heap.

Input
First line contains number n (1≤n≤10^5). Second line contains n integers that do not exceed 2⋅10^9 by absolute value.

Output
Print "YES", if the array is a heap and "NO" otherwise.

https://static.e-olymp.com/content/df/df4744ea60c745c1fd9f6799b84250a1161add24.gif

Examples

Input #1
7
3 10 5 12 11 6 7

Answer #1
YES

*/

package main

func main() {
	assert(isheap([]int{3, 10, 5, 12, 11, 6, 7}) == "YES")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func isheap(a []int) string {
	n := len(a)
	for i := range a {
		l := 2*i + 1
		r := 2*i + 2
		if l < n && a[i] > a[l] {
			return "NO"
		}
		if r < n && a[i] > a[r] {
			return "NO"
		}
	}
	return "YES"
}
