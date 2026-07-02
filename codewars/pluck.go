/*

Implement a function which takes a sequence of objects and a property name, and returns a sequence containing the named property of each object.

For example:

pluck([{a:1}, {a:2}], 'a')      // -> [1,2]
pluck([{a:1, b:3}, {a:2}], 'b') // -> [3, undefined]

If an object is missing the property, you should just leave it as undefined/None in the output array.

*/

package main

import "fmt"

type Object map[string]any

func main() {
	fmt.Println(pluck([]Object{
		{"a": 1},
		{"a": 2},
	}, "a"))

	fmt.Println(pluck([]Object{
		{"a": 1, "b": 3},
		{"a": 2},
	}, "b"))
}

func pluck(objects []Object, key string) []any {
	var result []any
	for _, object := range objects {
		if value, found := object[key]; found {
			result = append(result, value)
		} else {
			result = append(result, nil)
		}
	}
	return result
}
