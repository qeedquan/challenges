/*

Write a function to return the city from each of these vacation spots.

Examples
grabCity("[Last Day!] Beer Festival [Munich]") ➞ "Munich"

grabCity("Cheese Factory Tour [Portland]") ➞ "Portland"

grabCity("[50% Off!][Group Tours Included] 5-Day Trip to Onsen [Kyoto]") ➞ "Kyoto"

Notes
There may be additional brackets, but the city will always be in the last bracket pair.

*/

package main

import (
	"regexp"
	"strings"
)

func main() {
	assert(grabcity(`[Last Day!] Beer Festival [Munich]`) == `Munich`)
	assert(grabcity(`Cheese Factory Tour [Portland]`) == `Portland`)
	assert(grabcity(`[Duration: 7 hours] Tour of the Maritimes [Prince Edward Island]`) == `Prince Edward Island`)
	assert(grabcity(`[5 Stars] Traditional Gondola Experience [Venice]`) == `Venice`)
	assert(grabcity(`[Last Minute Deal][$1039] Machu Picchu 3 Day Trip [Machu Picchu]`) == `Machu Picchu`)
	assert(grabcity(`[50% Off!][Group Tours Included] 5-Day Trip to Onsen [Kyoto]`) == `Kyoto`)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func grabcity(s string) string {
	re := regexp.MustCompile(`\[(.*?)\]`)
	m := re.FindAllString(s, -1)
	r := ""
	if n := len(m); n > 0 {
		r = m[n-1]
	}
	r = strings.TrimPrefix(r, "[")
	r = strings.TrimSuffix(r, "]")
	return r
}
