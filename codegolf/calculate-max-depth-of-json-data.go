/*

Challenge
Given some JSON data, calculate the maximum depth reached. (Both arrays and dictionaries increase the depth)

Input/Output
The program is expected to read a JSON string from stdin and as soon as the program receives a \n start calculating the max depth, printing it to stdout and terminating the program when done.

If invalid JSON is provided, the output should be 0.

Test cases
[] -> 1

[1, 2, 3, 4, 5] -> 1

[ [ 123],   []] -> 2

[{"a": []}, ["abc"]] -> 3

{"a": 321} -> 1

{"a": []} -> 2

[[] -> 0 (invalid JSON)

hello -> 0

*/

package main

import (
	"encoding/json"
)

func main() {
	assert(maxdepth(`[]`) == 1)
	assert(maxdepth(`[1, 2, 3, 4, 5]`) == 1)
	assert(maxdepth(`[ [ 123],   []]`) == 2)
	assert(maxdepth(`[{"a": []}, ["abc"]]`) == 3)
	assert(maxdepth(`{"a": 321}`) == 1)
	assert(maxdepth(`{"a": []} `) == 2)
	assert(maxdepth(`[]]`) == 0)
	assert(maxdepth(`hello`) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxdepth(s string) int {
	var m any
	err := json.Unmarshal([]byte(s), &m)
	if err != nil {
		return 0
	}
	return walk(m)
}

func walk(e any) int {
	var r int
	switch e := e.(type) {
	case []any:
		for _, x := range e {
			r = max(r, walk(x))
		}
	case map[string]any:
		for _, x := range e {
			r = max(r, walk(x))
		}
	default:
		return 0
	}
	return r + 1
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
