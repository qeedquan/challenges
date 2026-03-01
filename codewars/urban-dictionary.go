/*

Design a data structure that supports the following two operations:

addWord (or add_word) which adds a word,
search which searches a literal word or a regular expression string containing lowercase letters "a-z" or "." where "." can represent any letter
You may assume that all given words contain only lowercase letters.

Examples
addWord("bad")
addWord("dad")
addWord("mad")

search("pad") === false
search("bad") === true
search(".ad") === true
search("b..") === true
Note: the data structure will be initialized multiple times during the tests!

*/

package main

import (
	"unicode/utf8"
)

func main() {
	d := make(Dict)
	d.AddWord("bad")
	d.AddWord("dad")
	d.AddWord("mad")
	assert(d.SearchWord("pad") == false)
	assert(d.SearchWord("bad") == true)
	assert(d.SearchWord(".ad") == true)
	assert(d.SearchWord("b..") == true)
	assert(d.SearchWord("b.x") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Dict map[rune]Dict

func (d Dict) AddWord(w string) {
	for _, r := range w {
		if d[r] == nil {
			d[r] = make(Dict)
			d = d[r]
		}
	}
}

func (d Dict) SearchWord(w string) bool {
	for i, r := range w {
		switch r {
		case '.':
			s := utf8.RuneLen(r)
			for _, p := range d {
				if p.SearchWord(w[i+s:]) {
					return true
				}
			}
			return false

		default:
			if d[r] == nil {
				return false
			}
			d = d[r]
		}
	}
	return true
}
