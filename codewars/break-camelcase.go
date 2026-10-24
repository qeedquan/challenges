/*

Complete the solution so that the function will break up camel casing, using a space between words.

### Example

solution("camelCasing")  ==  "camel Casing"

*/

package main

import (
	"regexp"
)

func main() {
	assert(camelcase("camelCasing") == "camel Casing")
	assert(camelcase("camelCasingTest") == "camel Casing Test")
	assert(camelcase("camelcasingtest") == "camelcasingtest")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func camelcase(s string) string {
	re := regexp.MustCompile("([A-Z])")
	return re.ReplaceAllString(s, " $1")
}
