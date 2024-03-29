/*

You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces are distinct. Your goal is to form arr by concatenating the arrays in pieces in any order. However, you are not allowed to reorder the integers in each array pieces[i].

Return true if it is possible to form the array arr from pieces. Otherwise, return false.

Example 1:

Input: arr = [15,88], pieces = [[88],[15]]
Output: true
Explanation: Concatenate [15] then [88]

Example 2:

Input: arr = [49,18,16], pieces = [[16,18,49]]
Output: false
Explanation: Even though the numbers match, we cannot reorder pieces[0].

Example 3:

Input: arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
Output: true
Explanation: Concatenate [91] then [4,64] then [78]


Constraints:

1 <= pieces.length <= arr.length <= 100
sum(pieces[i].length) == arr.length
1 <= pieces[i].length <= arr.length
1 <= arr[i], pieces[i][j] <= 100
The integers in arr are distinct.
The integers in pieces are distinct (i.e., If we flatten pieces in a 1D array, all the integers in this array are distinct).

Hint:
Note that the distinct part means that every position in the array belongs to only one piece
Note that you can get the piece every position belongs to naively

*/

package main

func main() {
	assert(formable([]int{15, 88}, [][]int{{88}, {15}}) == true)
	assert(formable([]int{49, 18, 16}, [][]int{{16, 18, 49}}) == false)
	assert(formable([]int{91, 4, 64, 78}, [][]int{{78}, {4, 64}, {91}}) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func formable(a []int, p [][]int) bool {
	m := make(map[int][]int)
	for i := range p {
		m[p[i][0]] = p[i]
	}

	for i := 0; i < len(a); {
		if len(m[a[i]]) == 0 {
			return false
		}

		v := m[a[i]]
		for j := range v {
			if a[i] != v[j] {
				return false
			}
			i++
		}
	}
	return true
}
