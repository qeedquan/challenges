/*

Please write a function that will take a string as input and return a hash. The string will be formatted as such. The key will always be a symbol and the value will always be an integer.

"a=1, b=2, c=3, d=4"
This string should return a hash that looks like

{ 'a': 1, 'b': 2, 'c': 3, 'd': 4}

*/

package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	fmt.Println(str2hash("a=1, b=2, c=3, d=4"))
}

func str2hash(s string) map[string]int {
	m := make(map[string]int)
	t := strings.Split(s, ",")
	for i := range t {
		t[i] = strings.TrimSpace(t[i])
		p := strings.Split(t[i], "=")
		if len(p) == 2 {
			m[p[0]], _ = strconv.Atoi(p[1])
		}
	}
	return m
}
