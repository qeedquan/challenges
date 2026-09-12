/*

Write a simple converter for vowels.

      Romaji:    a/A e/E i/I u/U o/O
      Hiragana:  あ  え   い  う   お
      Katakana:  ア  エ   イ  ウ   オ

Expect the above characters as input. There won't be invalid input.

Rules:

If there is no input return an empty string.
Do not change romaji. (a->a, A->A ... NOT A->a )
Change Kana to lower case romaji. (あ->a ... NOT あ->A)
Input can be mixed, but output should be consistent. (aAあア -> aAaa, for "romaji")

Example 1:

Input: "aeiou"

Output:"hiragana"

Expected output: "あえいおう"

Example 2:

Input: "AえイOう"

Output:"romaji"

Expected output: "AeiOu"

*/

package main

import (
	"bytes"
)

func main() {
	assert(vowels("aeiou", "hiragana") == "あえいおう")
	assert(vowels("ouaei", "hiragana") == "おうあえい")
	assert(vowels("AえイOう", "romaji") == "AeiOu")

	assert(vowels("aeiou", "romaji") == "aeiou")
	assert(vowels("aeiou", "hiragana") == "あえいおう")
	assert(vowels("aeiou", "katakana") == "アエイオウ")

	assert(vowels("あえいおう", "romaji") == "aeiou")
	assert(vowels("あえいおう", "hiragana") == "あえいおう")
	assert(vowels("あえいおう", "katakana") == "アエイオウ")

	assert(vowels("アエイオウ", "romaji") == "aeiou")
	assert(vowels("アエイオウ", "hiragana") == "あえいおう")
	assert(vowels("アエイオウ", "katakana") == "アエイオウ")

	assert(vowels("", "romaji") == "")
	assert(vowels("", "") == "")

	assert(vowels("aAeEoOUu", "romaji") == "aAeEoOUu")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func vowels(input, conversion string) string {
	indices := map[rune]int{
		'a': 0, 'e': 1, 'i': 2, 'u': 3, 'o': 4,
		'A': 0, 'E': 1, 'I': 2, 'U': 3, 'O': 4,
		'あ': 0, 'え': 1, 'い': 2, 'う': 3, 'お': 4,
		'ア': 0, 'エ': 1, 'イ': 2, 'ウ': 3, 'オ': 4,
	}
	romaji := []rune("aeiuoAEIUO")
	hiragana := []rune("あえいうお")
	katakana := []rune("アエイウオ")

	var mapping []rune
	switch conversion {
	case "romaji":
		mapping = romaji
		for _, symbol := range "AEIUO" {
			indices[symbol] += 5
		}
	case "hiragana":
		mapping = hiragana
	case "katakana":
		mapping = katakana
	default:
		return input
	}

	output := new(bytes.Buffer)
	for _, symbol := range input {
		index, found := indices[symbol]
		if found {
			symbol = mapping[index]
		}
		output.WriteRune(symbol)
	}
	return output.String()
}
