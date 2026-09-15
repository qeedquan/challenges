/*

Task
Your task is to write a function called valid_spacing() or validSpacing() which checks if a string has valid spacing. The function should return either true or false (or the corresponding value in each language).

For this kata, the definition of valid spacing is one space between words, and no leading or trailing spaces. Words can be any consecutive sequence of non space characters. Below are some examples of what the function should return:

* 'Hello world'   => true
* ' Hello world'  => false
* 'Hello world  ' => false
* 'Hello  world'  => false
* 'Hello'         => true

Even though there are no spaces, it is still valid because none are needed:
* 'Helloworld'    => true
* 'Helloworld '   => false
* ' '             => false
* ''              => true
Note - there will be no punctuation or digits in the input string, only letters.

*/

package main

import "strings"

func main() {
	assert(valid("Hello world") == true)
	assert(valid(" Hello world") == false)
	assert(valid("Hello  world ") == false)
	assert(valid("Hello") == true)
	assert(valid("Helloworld") == true)
	assert(valid("Helloworld ") == false)
	assert(valid(" ") == false)
	assert(valid("") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func valid(s string) bool {
	if s != strings.TrimSpace(s) {
		return false
	}

	for _, t := range strings.Split(s, " ") {
		if strings.IndexRune(t, ' ') >= 0 {
			return false
		}
	}
	return true
}
