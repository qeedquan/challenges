/*

The goal of this kata is to implement trie (or prefix tree) using dictionaries (aka hash maps or hash tables), where:

the dictionary keys are the prefixes
the value of a leaf node is None in Python, nil in Ruby and null in Groovy, JavaScript and Java.
the value for empty input is {} in Python, Ruby, Javascript and Java (empty map) and [:] in Groovy.
Examples:

buildTrie() => {}
buildTrie("") => {}
buildTrie("trie") => {'t': {'tr': {'tri': {'trie': null}}}}
buildTrie("tree") => {'t': {'tr': {'tre': {'tree': null}}}}
buildTrie("A","to", "tea", "ted", "ten", "i", "in", "inn") => {'A': null, 't': {'to': null, 'te': {'tea': null, 'ted': null, 'ten': null}}, 'i': {'in': {'inn': null}}}
buildTrie("true", "trust") => {'t': {'tr': {'tru': {'true': null, 'trus': {'trust': null}}}}}
Happy coding! :)

*/

package main

import "fmt"

type Trie map[string]Trie

func main() {
	fmt.Println(build())
	fmt.Println(build(""))
	fmt.Println(build("trie"))
	fmt.Println(build("tree"))
	fmt.Println(build("A", "to", "tea", "ted", "ten", "i", "in", "inn"))
	fmt.Println(build("true", "trust"))
}

func build(words ...string) Trie {
	root := Trie{}
	for _, word := range words {
		node := root
		for i := 0; i < len(word)-1; i++ {
			key := word[:i+1]
			if node[key] == nil {
				node[key] = Trie{}
			}
			node = node[key]
		}
		if len(word) > 0 {
			node[word] = nil
		}
	}
	return root
}
