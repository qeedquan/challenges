/*

Let's create some scrolling text!

Your task is to complete the function which takes a string, and returns an array with all possible rotations of the given string, in uppercase.

Example
scrollingText("codewars") should return:

[ "CODEWARS",
  "ODEWARSC",
  "DEWARSCO",
  "EWARSCOD",
  "WARSCODE",
  "ARSCODEW"
  "RSCODEWA",
  "SCODEWAR" ]

Good luck!

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(scrolltext("codewars"))
}

func scrolltext(text string) []string {
	result := []string{}
	text = strings.ToUpper(text)
	combined := text + text
	for index := range text {
		result = append(result, combined[index:index+len(text)])
	}
	return result
}
