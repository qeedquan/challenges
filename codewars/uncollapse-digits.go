/*

Task
You will be given a string of English digits "stuck" together, like this:

"zeronineoneoneeighttwoseventhreesixfourtwofive"

Your task is to split the string into separate digits:

"zero nine one one eight two seven three six four two five"

Examples
"three"              -->  "three"
"eightsix"           -->  "eight six"
"fivefourseven"      -->  "five four seven"
"ninethreesixthree"  -->  "nine three six three"
"fivethreefivesixthreenineonesevenoneeight"  -->  "five three five six three nine one seven one eight"

*/

package main

import (
	"regexp"
	"strings"
)

func main() {
	assert(uncollapse("zeronineoneoneeighttwoseventhreesixfourtwofive") == "zero nine one one eight two seven three six four two five")
	assert(uncollapse("three") == "three")
	assert(uncollapse("eightsix") == "eight six")
	assert(uncollapse("fivefourseven") == "five four seven")
	assert(uncollapse("ninethreesixthree") == "nine three six three")
	assert(uncollapse("fivethreefivesixthreenineonesevenoneeight") == "five three five six three nine one seven one eight")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func uncollapse(s string) string {
	re := regexp.MustCompile(`(zero)|(one)|(two)|(three)|(four)|(five)|(six)|(seven)|(eight)|(nine)`)
	r := re.ReplaceAllString(s, "$0 ")
	return strings.TrimRight(r, " ")
}
