/*

Your task is to write a function, which takes two arguments and returns a sequence.
First argument is a sequence of values, second is multiplier.
The function should filter all non-numeric values and multiply the rest by given multiplier.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	fmt.Println(filter([]any{1, 2, 3, 4}, 1.5))
	fmt.Println(filter([]any{1, 2, 3}, 0))
	fmt.Println(filter([]any{0, 0, 0}, 2))
	fmt.Println(filter([]any{1, nil, 2.5, "string", 10, nil, []int{}}, 3))
	fmt.Println(filter([]any{1, nil, 2.5, "string", 10, nil, []int{}, true, false}, 3))
}

func filter(x []any, m float64) []any {
	r := []any{}
	for i := range x {
		rv := reflect.ValueOf(x[i])
		v := 0.0
		switch {
		case rv.CanInt():
			v = float64(rv.Int())
		case rv.CanUint():
			v = float64(rv.Uint())
		case rv.CanFloat():
			v = rv.Float()
		default:
			continue
		}
		r = append(r, v*m)
	}
	return r
}
