/*

Write a function that retrieves the top 3 longest words of a newspaper headline and transforms them into hashtags. If multiple words tie for the same length, retrieve the word that occurs first.

Examples
getHashTags("How the Avocado Became the Fruit of the Global Trade")
➞ ["#avocado", "#became", "#global"]

getHashTags("Why You Will Probably Pay More for Your Christmas Tree This Year")
➞ ["#christmas", "#probably", "#will"]

getHashTags("Hey Parents, Surprise, Fruit Juice Is Not Fruit")
➞ ["#surprise", "#parents", "#fruit"]

getHashTags("Visualizing Science")
➞ ["#visualizing", "#science"]

Notes
If the title is less than 3 words, just order the words in the title by length in descending order (see example #4).
Punctuation does not count towards a word's length.

*/

package main

import (
	"bytes"
	"fmt"
	"reflect"
	"sort"
	"strings"
	"unicode"
)

func main() {
	test("How the Avocado Became the Fruit of the Global Trade", []string{"#avocado", "#became", "#global"})
	test("Why You Will Probably Pay More for Your Christmas Tree This Year", []string{"#christmas", "#probably", "#will"})
	test("Hey Parents, Surprise, Fruit Juice Is Not Fruit", []string{"#surprise", "#parents", "#fruit"})
	test("Visualizing Science", []string{"#visualizing", "#science"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []string) {
	p := hashtags(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func hashtags(s string) []string {
	t := strings.Split(s, " ")
	for i := range t {
		t[i] = "#" + trim(t[i])
	}

	sort.Slice(t, func(i, j int) bool {
		return len(t[i]) > len(t[j])
	})

	if len(t) >= 3 {
		t = t[:3]
	}

	return t
}

func trim(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		if !unicode.IsPunct(r) {
			w.WriteRune(unicode.ToLower(r))
		}
	}
	return w.String()
}
