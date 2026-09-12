/*

The static method Favourites.isFavourite tests if a given flower is a favourite or not. Only roses are a favourite, but the current implementation is still too strict! Fix the method so that the test-cases pass.

*/

package main

import (
	"regexp"
)

func main() {
	assert(favorite("rose") == true)
	assert(favorite("rOsE") == true)
	assert(favorite("ROSEs") == true)
	assert(favorite("posy") == false)
	assert(favorite("sunflower") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func favorite(flower string) bool {
	matched, _ := regexp.MatchString(`(?i)rose\s*`, flower)
	return matched
}
