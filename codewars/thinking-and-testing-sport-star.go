/*

No Story

No Description

Only by Thinking and Testing

Look at result of testcase, guess the code!

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	test([]string{"run", "jump", "run", "jump", "run"}, "_|_|_", "_|_|_")
	test([]string{"run", "jump", "run", "run", "run"}, "_|_|_", "_|_/_")
	test([]string{"run", "run", "run", "run", "run"}, "_|_|_", "_/_/_")
	test([]string{"jump", "jump", "jump", "jump", "jump"}, "_|_|_", "x|x|x")
	test([]string{"jump", "run", "jump", "run", "jump"}, "_|_|_", "x/x/x")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(action []string, obstacle, expected string) {
	result := testit(action, obstacle)
	fmt.Println(result)
	assert(result == expected)
}

func testit(action []string, obstacle string) string {
	output := new(bytes.Buffer)
	for i := range action {
		switch {
		case action[i] == "run" && obstacle[i] == '_':
			fallthrough
		case action[i] == "jump" && obstacle[i] == '|':
			output.WriteByte(obstacle[i])
		case obstacle[i] == '_':
			output.WriteByte('x')
		default:
			output.WriteByte('/')
		}
	}
	return output.String()
}
