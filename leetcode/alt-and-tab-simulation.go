/*

There are n windows open numbered from 1 to n, we want to simulate using alt + tab to navigate between the windows.

You are given an array windows which contains the initial order of the windows (the first element is at the top and the last one is at the bottom).

You are also given an array queries where for each query, the window queries[i] is brought to the top.

Return the final state of the array windows.

Example 1:

Input: windows = [1,2,3], queries = [3,3,2]

Output: [2,3,1]

Explanation:

Here is the window array after each query:

    Initial order: [1,2,3]
    After the first query: [3,1,2]
    After the second query: [3,1,2]
    After the last query: [2,3,1]

Example 2:

Input: windows = [1,4,2,3], queries = [4,1,3]

Output: [3,1,4,2]

Explanation:

Here is the window array after each query:

    Initial order: [1,4,2,3]
    After the first query: [4,1,2,3]
    After the second query: [1,4,2,3]
    After the last query: [3,1,4,2]



Constraints:

    1 <= n == windows.length <= 10^5
    windows is a permutation of [1, n].
    1 <= queries.length <= 10^5
    1 <= queries[i] <= n

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(
		[]int{1, 2, 3}, []int{3, 3, 2},
		[]int{2, 3, 1},
	)

	test(
		[]int{1, 4, 2, 3}, []int{4, 1, 3},
		[]int{3, 1, 4, 2},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(windows, queries, expected []int) {
	result := simulate(windows, queries)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func simulate(windows, queries []int) []int {
	lookup := make(map[int]bool)
	result := []int{}
	for i := len(queries) - 1; i >= 0; i-- {
		if !lookup[queries[i]] {
			lookup[queries[i]] = true
			result = append(result, queries[i])
		}
	}

	for _, window := range windows {
		if !lookup[window] {
			result = append(result, window)
		}
	}
	return result
}
