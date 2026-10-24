/*

Background:
Here's a little simple challenge. You want to be able to find out whether the arrays inside an array have the same length.

Input:
Your input should consist of exactly one array (this is the value passed to the function, not a user input). Your function takes exactly 1 parameter. It could contain arrays or be empty. No error checking needed, assume only list is ever passed in. Assume a 1-D array such as [1] or [1,2,3,4,5] is never passed in.

Output:
Return true if all the list elements have the same length, false if they don't, and the parameter itself if the list is empty (or null if your language doesn't support multiple return types).

Some test cases:
List: [] - [] (or null/your language equivalent)
List: [[1], [1], [2]] - True
List: [[1]] - True
List: [[1, 2, 3, 4]] - True
List: [[1, 2, 3, 4, 5], [2], [12, 314123]] - False
List: [[1, 2, 3, 4], [1]] - False
No std(in/out) input/output needed (however, it is allowed, just not required!), the function only needs to return boolean values true or false; or the parameter itself if the function is passed an empty list (or null/your language equivalent). Only one return value is returned.

Rules:
Shortest byte count wins, only function is necessary (full programs are allowed if you desire).

*/

package main

func main() {
	assert(same([][]int{}) == false)
	assert(same([][]int{{1}, {1}, {2}}) == true)
	assert(same([][]int{{1}}) == true)
	assert(same([][]int{{1, 2, 3, 4}}) == true)
	assert(same([][]int{{1, 2, 3, 4, 5}, {2}, {12, 314123}}) == false)
	assert(same([][]int{{1, 2, 3, 4}, {1}}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func same(x [][]int) bool {
	if len(x) == 0 {
		return false
	}
	for i := 1; i < len(x); i++ {
		if len(x[i]) != len(x[i-1]) {
			return false
		}
	}
	return true
}
