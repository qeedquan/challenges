/*

We're given some typical *nix commands and want to parse them into their arguments. We'll ignore quoted arguments and other special characters, although if any of the characters &, ;, >, | show up, those signify that a new command has started (so we can ignore any arguments after it).

##Examples

ls -R / ["ls", "-R", "/"]

   cat   /tmp/data.txt | less

  ["cat", "/tmp/data.txt"]

(note that we ignored the extra leading spaces on that last example)

*/

package main

import (
	"fmt"
	"reflect"
	"strings"
)

func main() {
	test("ls -R /", []string{"ls", "-R", "/"})
	test("cat /tmp/data.txt | less", []string{"cat", "/tmp/data.txt"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []string) {
	a := args(s)
	fmt.Println(a)
	assert(reflect.DeepEqual(a, r))
}

func args(s string) []string {
	t := strings.Split(s, " ")
	for i := range t {
		t[i] = strings.TrimSpace(t[i])
		if strings.IndexAny(t[i], "&;>|") >= 0 {
			t = t[:i]
			break
		}
	}
	return t
}
