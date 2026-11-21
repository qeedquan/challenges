/*

Complete the solution so that it takes the object (JavaScript/CoffeeScript) or hash (ruby) passed in and generates a human readable string from its key/value pairs.

The format should be "KEY = VALUE". Each key/value pair should be separated by a comma except for the last pair.

Example:

solution({a: 1, b: '2'}) // should return "a = 1,b = 2"

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	fmt.Println(build(map[any]any{
		"a": 1,
		"b": 2,
	}))
}

func build(pairs map[any]any) string {
	buf := new(bytes.Buffer)
	for key, value := range pairs {
		fmt.Fprintf(buf, "%v = %v,", key, value)
	}

	str := buf.String()
	if len(str) > 0 {
		str = str[:len(str)-1]
	}
	return str
}
