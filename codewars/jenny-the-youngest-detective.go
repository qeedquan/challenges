/*

Jenny is 9 years old. She is the youngest detective in North America. Jenny is a 3rd grader student, so when a new mission comes up, she gets a code to decipher in a form of a sticker (with numbers) in her math notebook and a comment (a sentence) in her writing notebook. All she needs to do is to figure out one word, from there she already knows what to do. And here comes your role - you can help Jenny find out what the word is!

In order to find out what the word is, you should use the sticker (array of 3 numbers) to retrive 3 letters from the comment (string) that create the word.

Each of the numbers in the array refers to the position of a letter in the string, in increasing order.
Spaces are not places, you need the actual letters. No spaces.
The returned word should be all lowercase letters.
if you can't find one of the letters using the index numbers, return "No mission today". Jenny would be very sad, but that's life... :(

Example: input: [5, 0, 3], "I Love You" output: "ivy" (0 = "i", 3 = "v", 5 = "y")

*/

package main

import (
	"bytes"
	"sort"
	"strings"
)

func main() {
	assert(missingword([]int{5, 0, 3}, "I Love You") == "ivy")
	assert(missingword([]int{29, 31, 8}, "The quick brown fox jumps over the lazy dog") == "bay")
	assert(missingword([]int{12, 4, 6}, "Good Morning") == "No mission today")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func missingword(nums []int, str string) string {
	out := new(bytes.Buffer)
	str = strings.Replace(str, " ", "", -1)
	sort.Ints(nums)
	for _, i := range nums {
		if i < 0 || i >= len(str) {
			return "No mission today"
		}
		out.WriteByte(str[i])
	}
	return strings.ToLower(out.String())
}
