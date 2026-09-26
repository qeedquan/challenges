/*

Task
You are given a dictionary/hash/object containing some languages and your test results in the given languages. Return the list of languages where your test score is at least 60, in descending order of the results.

Note: the scores will always be unique (so no duplicate values)

Examples
{"Java" => 10, "Ruby" => 80, "Python" => 65}   -->  ["Ruby", "Python"]
{"Hindi" => 60, "Dutch" => 93, "Greek" => 71}  -->  ["Dutch", "Greek", "Hindi"]
{"C++" => 50, "ASM" => 10, "Haskell" => 20}    -->  []
My other katas
If you enjoyed this kata then please try my other katas! :-)

Translations are welcome!

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test(map[string]int{
		"Java":   10,
		"Ruby":   80,
		"Python": 65,
	}, []string{"Ruby", "Python"})

	test(map[string]int{
		"Hindi": 60,
		"Dutch": 93,
		"Greek": 71,
	}, []string{"Dutch", "Greek", "Hindi"})

	test(map[string]int{
		"C++":     50,
		"ASM":     10,
		"Haskell": 20,
	}, []string{})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m map[string]int, r []string) {
	p := languages(m)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func languages(m map[string]int) []string {
	r := []string{}
	for k, v := range m {
		if v >= 60 {
			r = append(r, k)
		}
	}
	sort.Slice(r, func(i, j int) bool {
		return m[r[i]] > m[r[j]]
	})
	return r
}
