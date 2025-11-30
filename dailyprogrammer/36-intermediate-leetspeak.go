/*

Because I want to watch the world burn, write a program that accepts a sentence as input and outputs the sentence in leetspeak.
Here is a link for a leetspeak translation table.
https://en.wikipedia.org/wiki/Leet

Since leetspeak has multiple character selections per letter, randomly pick the character selection.
The challenging part will be to be a resourceful developer and write a utility or use an existing application to save the table into a format that you will load in your program to do the translation.
Oh yeah, if the input sentence contains one !, for the love of God translate that into !!!!11!!!1! ;)

*/

package main

import (
	"bytes"
	"fmt"
	"math/rand"
	"strings"
	"unicode"
)

func main() {
	fmt.Println(leetspeak("what is this?!"))
}

func leetspeak(input string) string {
	buffer := new(bytes.Buffer)
	for _, symbol := range input {
		mapping := MAP[unicode.ToLower(symbol)]
		if mapping == nil {
			buffer.WriteRune(symbol)
		} else {
			index := rand.Intn(len(mapping))
			buffer.WriteString(mapping[index])
		}
	}
	result := buffer.String()
	result = strings.Replace(result, "!", "!!!!11!one", -1)
	return result
}

var MAP = map[rune][]string{
	'a': []string{"4", "@", "/-\\", "/\\", "^", "aye", "∂", "ci", "λ", "Z]"},
	'b': []string{"8", "|3", "6", "13", "|3", "ß", "]3"},
	'c': []string{"(", "<", "¢", "{", "©", "sea", "see"},
	'd': []string{"|)", "[)", "∂", "])", "I>", "|>", "0", "ð", "cl"},
	'e': []string{"3", "£", "&", "€", "[-", "ə"},
	'f': []string{"|=", "]=", "}", "ph", "(=", "ʃ"},
	'g': []string{"6", "9", "&", "(_+", "C-", "gee", "jee", "(γ,", "cj"},
	'h': []string{"|-|", "#", "]-[", "[-]", ")-(", "(-)", ":-:", "}{", "}-{", "aych"},
	'i': []string{"!", "1", "|", "eye", "3y3", "ai", "¡"},
	'j': []string{"_|", "_/", "]", "¿", "</", "_)", "ʝ"},
	'k': []string{"X", "|<", "|X", "|{", "ɮ"},
	'l': []string{"1", "7", "|_", "£", "|", "|_", "lJ", "¬"},
	'm': []string{"44", "/\\/\\", "|\\/|", "em", "|v|", "IYI", "IVI", "[V]", "^^", "nn", "//\\\\//\\\\", "(V)", "(\\/)", "/|\\", "/|/|", ".\\", "/^^\\", "/V\\", "|^^|", "AA"},
	'n': []string{"|\\|", "/\\/", "//\\\\//", "И", "[\\]", "<\\>", "{\\}", "//", "₪", "[]\\[]", "]\\[", "~"},
	'o': []string{"0", "()", "oh", "[]", "¤", "Ω"},
	'p': []string{"|*", "|o", "|º", "|>", "|\"", "?", "9", "[]D", "|7", "q", "þ", "¶", "℗", "|D"},
	'q': []string{"0_", "0,", "(,)", "<|", "cue", "9", "¶"},
	'r': []string{"|2", "2", "/2", "I2", "|^", "|~", "lz", "®", "|2", "[z", "|`", "l2", "Я", ".-", "ʁ"},
	's': []string{"5", "$", "z", "§", "es"},
	't': []string{"7", "+", "-|-", "1", "']['", "†"},
	'u': []string{"|_|", "(_)", "Y3W", "M", "µ", "[_]", "\\_/", "\\_\\", "/_/"},
	'v': []string{"\\/", "√", "\\\\//"},
	'w': []string{"\\/\\/", "vv", "'//", "\\\\'", "\\^/", "(n)", "\\X/", "\\|/", "\\_|_/", "\\\\//\\\\//", "\\_:_/", "]I[", "UU", "Ш", "ɰ", "￦", "JL"},
	'x': []string{"%", "><", "Ж", "}{", "ecks", "×", "*", ")(", "ex"},
	'y': []string{"j", "`/", "`(", "-/", "'/", "Ψ", "φ", "λ", "Ч", "¥"},
	'z': []string{"2", "≥", "~/_", "%", "ʒ", "7_"},
}
