/*

Supreme Sum String
Given an input string, return the word with the highest sum of each of its unicode characters.

Rules
The input should be seperated by whitespace
The value of each word is based on the sum of each character in the word's UTF-16 code
The output should be the first word with the highest value (in case of duplicate sums)
Examples
Input: "a b c d e"
Output: "e"

Input: "hello world"
Output: "world"

Input: "this is a test"
Output: "test"

Input: "àà as a test"
Output: "àà"

Input "α ää"
Output: "α"

Input: "🍬 隣隣隣"
Output: "隣隣隣"

Input: "💀 👻 🤡 🦇 🕷️ 🍬 🎃"
Output: "🕷️"
This is code golf, so the shortest answer wins! Good luck :)

*/

package main

import (
	"unicode"
)

func main() {
	assert(supreme("a b c d e") == "e")
	assert(supreme("hello world") == "world")
	assert(supreme("this is a test") == "test")
	assert(supreme("àà as a test") == "àà")
	assert(supreme("α ää") == "α")
	assert(supreme("🍬 隣隣隣") == "隣隣隣")
	assert(supreme("💀 👻 🤡 🦇 🕷️ 🍬 🎃") == "🕷️")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func supreme(s string) string {
	r, m := "", 0
	t, v := "", 0
	for _, c := range s {
		if unicode.IsSpace(c) {
			t, v = "", 0
		} else {
			t += string(c)
			v += int(c)
		}

		if v > m {
			r, m = t, v
		}
	}
	return r
}
