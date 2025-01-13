/*

Task
We define the middle of the array arr as follows:

if arr contains an odd number of elements, its middle is the element whose index number is the same when counting from the beginning of the array and from its end;

if arr contains an even number of elements, its middle is the sum of the two elements whose index numbers when counting from the beginning and from the end of the array differ by one.

An array is called smooth if its first and its last elements are equal to one another and to the middle. Given an array arr, determine if it is smooth or not.

Example
For arr = [7, 2, 2, 5, 10, 7], the output should be true

The first and the last elements of arr are equal to 7, and its middle also equals 2 + 5 = 7. Thus, the array is smooth and the output is true.

For arr = [-5, -5, 10], the output should be false

The first and middle elements are equal to -5, but the last element equals 10. Thus, arr is not smooth and the output is false.

Input/Output
[input] integer array arr

The given array.

Constraints: 2 ≤ arr.length ≤ 10^3, -10^3 ≤ arr[i] ≤ 10^3.

[output] a boolean value

true if arr is smooth, false otherwise.

*/

package main

func main() {
	assert(issmooth([]int{7, 2, 2, 5, 10, 7}) == true)
	assert(issmooth([]int{-12, 34, 40, -5, -12, 4, 0, 0, -12}) == true)
	assert(issmooth([]int{-5, -5, 10}) == false)
	assert(issmooth([]int{4, 2}) == false)
	assert(issmooth([]int{45, 23, 12, 33, 12, 453, -234, -45}) == false)
	assert(issmooth([]int{9, 0, 15, 9}) == false)
	assert(issmooth([]int{-6, 6, -6}) == false)
	assert(issmooth([]int{26, 26, -17}) == false)
	assert(issmooth([]int{-7, 5, 5, 10}) == false)
	assert(issmooth([]int{-5, 3, -1, 9}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func issmooth(a []int) bool {
	n := len(a)
	switch {
	case n == 0:
		return false
	case a[0] != a[n-1]:
		return false
	case n%2 != 0:
		return a[0] == a[n/2]
	default:
		return a[0] == a[n/2]+a[n/2-1]
	}
}
