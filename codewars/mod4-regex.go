/*

NOTE: This kata requires a decent knowledge of Regular Expressions. As such, it's best to learn about it before tackling this kata. Some good places to start are: the MDN pages, and Regular-Expressions.info.

You are to write a Regular Expression that matches any string with at least one number divisible by 4 (with no remainder). In most languages, you could do this easily by using number % 4 == 0. How would you do it with Regex?

A number will start with [ and end with ]. They may (or may not) include a plus or minus symbol at the start; this should be taken into account. Leading zeros may be present, and should be ignored (no octals here ;P). There may be other text in the string, outside of the number; this should also be ignored. Also, all numbers will be integers; any floats should be ignored.

If there are no valid numbers defined as above, there should be no match made by your regex.

So here are some examples:

"[+05620]" // 5620 is divisible by 4 (valid)
"[+05621]" // 5621 is not divisible by 4 (invalid)
"[-55622]" // -55622 is not divisible by 4 (invalid)
"[005623]" // 5623 invalid
"[005624]" // 5624 valid
"[-05628]" // valid
"[005632]" // valid
"[555636]" // valid
"[+05640]" // valid
"[005600]" // valid
"the beginning [0] ... [invalid] numb[3]rs ... the end" // 0 is valid
"No, [2014] isn't a multiple of 4..."  // 2014 is invalid
"...may be [+002016] will be." // 2016 is valid
NOTE: Only Mod4.test(str) will be used, so your expression will just need make a match of some kind.

*/

package main

import (
	"regexp"
)

func main() {
	assert(MOD4.MatchString("[+05620]") == true)
	assert(MOD4.MatchString("[+05621]") == false)
	assert(MOD4.MatchString("[-55622]") == false)
	assert(MOD4.MatchString("[005623]") == false)
	assert(MOD4.MatchString("[005624]") == true)
	assert(MOD4.MatchString("[-05628]") == true)
	assert(MOD4.MatchString("[005632]") == true)
	assert(MOD4.MatchString("[555636]") == true)
	assert(MOD4.MatchString("[+05640]") == true)
	assert(MOD4.MatchString("[005600]") == true)
	assert(MOD4.MatchString("the beginning [0] ... [invalid] numb[3]rs ... the end") == true)
	assert(MOD4.MatchString("No, [2014] isn't a multiple of 4...") == false)
	assert(MOD4.MatchString("...may be [+002016] will be.") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://regex101.com/library/zQ4jE9
var MOD4 = regexp.MustCompile(`\[[+-]?([048]|\d*([02468][048]|[13579][26]))\]`)
