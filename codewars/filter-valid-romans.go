/*

Task
Complete the function that receives an array of strings (arr) as an argument and returns all the valid Roman numerals.

Basic Roman numerals are denoted as:

I: 1, V: 5, X: 10, L: 50, C: 100, D: 500, M: 1000
For the purposes of this kata we will consider valid only the numbers in range 0 - 5000 (both exclusive) since numbers >= 5000 were written in a different way (you had to place a heavy bar over the numeral that meant it was multiplied with 1000).

There are other ways of tackling this problem but the easiest is probably writing a Regular Expression.

Let's break the problem down:
To match a set of characters /[1-9]/(single digits) you should take into consideration the Roman numbers I, II, III, IV, V, VI, VII, VIII, IX. This could be done by testing with /IX|IV|V?I{0,3}/. This part /I{0,3}/ matches I, II or III but we have a V appearing 0 or 1 times because of the ? so /V?I{0,3}/ would match I,II,III,V,VI,VII or VIII. However there is one flaw with this. Do you see it? It is the fact that it would also match an empty string "" because of the {0,3}. In order to pass the tests you will have to filter out the empty strings as well. So the entire part matches I to IX(inclusive) but what about larger digits?

Use the same logic for the digit in the tens place and the hundreds place. Be sure to wrap each part (units, tens, hundreds, thousands) in a pair of braces (IX|IV|V?I{0,3}) and for the digit in the thousands place the logic is pretty straight forward, you just have to match M 0 to 4 times (since 5000 is not included). Wrap everything up with ^ and $ to make sure you match the entire string (^ matches from the beginning of the string, while $ denotes the end, meaning there is nothing after that sign.

Examples
["I", "IIV", "IVI", "IX", "XII", "MCD"] ==> ["I", "IX", "XII", "MCD"]

["MMMMCMXCIX", "MMDCXLIV", "MMCIX", "CLD", "LCD"}) ==> ["MMMMCMXCIX", "MMDCXLIV", "MMCIX"]
Good luck!

*/

package main

import (
	"fmt"
	"reflect"
	"regexp"
)

func main() {
	test([]string{"I", "IIV", "IVI", "IX", "XII", "MCD"}, []string{"I", "IX", "XII", "MCD"})
	test([]string{"MMMMCMXCIX", "MMDCXLIV", "MMCIX", "CLD", "LCD"}, []string{"MMMMCMXCIX", "MMDCXLIV", "MMCIX"})
	test([]string{"MMMCDLXVL", "MDLXXXVI", "DCLXII", "MMMMCLL", "MMDCCCLXXXIVCD"}, []string{"MDLXXXVI", "DCLXII"})
	test([]string{"MMMMCCCXXXII", "MMDCCCXXVCD", "MMCCCXLV", "DCCLXVIIICD", "MMMMCXII"}, []string{"MMMMCCCXXXII", "MMCCCXLV", "MMMMCXII"})
	test([]string{"DCCLIVI", "MDCCXXXVVI", "MDLXXVI", "MDVIL", "MCCLXIII"}, []string{"MDLXXVI", "MCCLXIII"})
	test([]string{"DV", "", "CLVIII", "MDCCCXXCD", "MDCLXVI", "MMMDCCCLXXXVI"}, []string{"DV", "CLVIII", "MDCLXVI", "MMMDCCCLXXXVI"})
	test([]string{"MMCDXVIII", "MMMCCXXXIV", "MMMMDCLXXXI", "MMMCMXIL", "MMMMCLXI"}, []string{"MMCDXVIII", "MMMCCXXXIV", "MMMMDCLXXXI", "MMMMCLXI"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(romans, expected []string) {
	result := filter(romans)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func filter(romans []string) []string {
	re := regexp.MustCompile(`^(M{0,4})(C?M{0,3})(C?D{0,1})(C{0,3})(X?C{0,3})(X?L{0,1})(X{0,3})(IX|IV|V?I{0,3})$`)
	result := []string{}
	for _, roman := range romans {
		if roman != "" && re.MatchString(roman) {
			result = append(result, roman)
		}
	}
	return result
}
