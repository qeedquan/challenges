/*

What are some clever (brief and idiomatic) approaches to taking a list of strings and returning a single properly punctuated string built from the list, with each element quoted.

This came up for me while experimenting with Groovy, for which my too-literal, but illustrative solution is

def temp = things.collect({"\'${it}\'"})
switch (things.size()) {
    case 1:
        result = temp[0]
        break
    case 2:
        result = temp.join(" and ")
        break
    default:
        result = temp.take(temp.size()-1).join(", ") + ", and " + temp[-1]
        break
}
That is, ['1'] should yield '1', ['1','2'] should yield '1 and 2', [see what I did there?] and ['1','2','3'] should yield '1, 2, and 3'.

I have some good answers for Groovy, but I'd like to see what other languages can do.

What are some compact clever approaches in various languages that take advantage of the features and idioms of those languages?

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(generate([]string{"1"}))
	fmt.Println(generate([]string{"1", "2"}))
	fmt.Println(generate([]string{"1", "2", "3"}))
	fmt.Println(generate([]string{"1", "2", "3", "4"}))
}

func generate(things []string) string {
	var result string
	switch len(things) {
	case 0:
	case 1:
		result = things[0]
	case 2:
		result = strings.Join(things, " and ")
	default:
		index := len(things) - 1
		result = strings.Join(things[:index], ", ") + ", and " + things[index]
	}
	return result
}
