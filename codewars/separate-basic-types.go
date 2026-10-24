/*

Given: a sequence of different type of values (number, string, boolean). You should return an object with a separate properties for each of types presented in input. Each property should contain an array of corresponding values.

keep order of values like in input array
if type is not presented in input, no corresponding property are expected

So, for this input:

['a', 1, 2, false, 'b']
expected output is:

{
  number: [1, 2],
  string: ['a', 'b'],
  boolean: [false]
}

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	fmt.Println(separate([]any{"a", 1, 2, false, "b"}))
}

func separate(values []any) map[string][]any {
	table := make(map[string][]any)
	for _, value := range values {
		typeof := reflect.TypeOf(value)
		key := ""
		switch typeof.Kind() {
		case reflect.Int,
			reflect.Int8,
			reflect.Int16,
			reflect.Int32,
			reflect.Int64,
			reflect.Uint,
			reflect.Uint8,
			reflect.Uint16,
			reflect.Uint32,
			reflect.Uint64,
			reflect.Uintptr,
			reflect.Float32,
			reflect.Float64,
			reflect.Complex64,
			reflect.Complex128:
			key = "number"
		case reflect.String:
			key = "string"
		case reflect.Bool:
			key = "boolean"
		}
		if key != "" {
			table[key] = append(table[key], value)
		}
	}
	return table
}
