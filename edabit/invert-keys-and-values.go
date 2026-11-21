/*

Write a function that inverts the keys and values of a dictionary.

Examples

invert({ "z": "q", "w": "f" })
➞ { "q": "z", "f": "w" }

invert({ "a": 1, "b": 2, "c": 3 })
➞ { 1: "a", 2: "b", 3: "c" }

invert({ "zebra": "koala", "horse": "camel" })
➞ { "koala": "zebra", "camel": "horse" }

Notes

N/A

*/

package main

import "reflect"

func main() {
	m1 := map[any]any{
		"a": 1, "b": 2, "c": 3,
	}
	p1 := map[any]any{
		1: "a", 2: "b", 3: "c",
	}

	m2 := map[any]any{
		"z": "q", "w": "f",
	}
	p2 := map[any]any{
		"q": "z", "f": "w",
	}

	m3 := map[any]any{
		"zebra": "koala", "horse": "camel",
	}
	p3 := map[any]any{
		"koala": "zebra", "camel": "horse",
	}

	test(m1, p1)
	test(m2, p2)
	test(m3, p3)
}

func test(m, r map[any]any) {
	p := invert(m)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func invert(m map[any]any) map[any]any {
	p := make(map[any]any)
	for k, v := range m {
		p[v] = k
	}
	return p
}
