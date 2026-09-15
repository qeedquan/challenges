/*

Make a one-to-one map from the base64 character table(0-9a-zA-Z+/) to Braille(U+2800-U+283F).

These characters are fixed map for compatibility. For other characters(aka. A-Z and +) you can map any Braile as long as no two base64 characters map same Braile.

⠁ a     ⠃ b     ⠉ c     ⠙ d     ⠑ e     ⠋ f
⠛ g     ⠓ h     ⠊ i     ⠚ j     ⠅ k     ⠇ l
⠍ m     ⠝ n     ⠕ o     ⠏ p     ⠟ q     ⠗ r
⠎ s     ⠞ t     ⠥ u     ⠧ v     ⠺ w     ⠭ x
⠽ y     ⠵ z     ⠴ 0     ⠂ 1     ⠆ 2     ⠒ 3
⠲ 4     ⠢ 5     ⠖ 6     ⠶ 7     ⠦ 8     ⠔ 9     ⠌ /
For example, this is a valid (but not golfed) solution in javascript: (Generator)

c=>({"0":"⠴","1":"⠂","2":"⠆","3":"⠒","4":"⠲","5":"⠢","6":"⠖","7":"⠶","8":"⠦","9":"⠔","a":"⠁","b":"⠃","c":"⠉","d":"⠙","e":"⠑","f":"⠋","g":"⠛","h":"⠓","i":"⠊","j":"⠚","k":"⠅","l":"⠇","m":"⠍","n":"⠝","o":"⠕","p":"⠏","q":"⠟","r":"⠗","s":"⠎","t":"⠞","u":"⠥","v":"⠧","w":"⠺","x":"⠭","y":"⠽","z":"⠵","/":"⠌","Q":"⠀","W":"⠄","E":"⠈","R":"⠐","T":"⠘","Y":"⠜","U":"⠠","I":"⠡","O":"⠣","P":"⠤","A":"⠨","S":"⠩","D":"⠪","F":"⠫","G":"⠬","H":"⠮","J":"⠯","K":"⠰","L":"⠱","Z":"⠳","X":"⠷","C":"⠸","V":"⠹","B":"⠻","N":"⠼","M":"⠾","+":"⠿"})[c]
Shortest code wins.

*/

package main

import "fmt"

func main() {
	for a, b := range mappings {
		fmt.Printf("%q -> %q\n", a, b)
	}
}

var mappings = map[string]string{
	"0": "⠴",
	"1": "⠂",
	"2": "⠆",
	"3": "⠒",
	"4": "⠲",
	"5": "⠢",
	"6": "⠖",
	"7": "⠶",
	"8": "⠦",
	"9": "⠔",
	"a": "⠁",
	"b": "⠃",
	"c": "⠉",
	"d": "⠙",
	"e": "⠑",
	"f": "⠋",
	"g": "⠛",
	"h": "⠓",
	"i": "⠊",
	"j": "⠚",
	"k": "⠅",
	"l": "⠇",
	"m": "⠍",
	"n": "⠝",
	"o": "⠕",
	"p": "⠏",
	"q": "⠟",
	"r": "⠗",
	"s": "⠎",
	"t": "⠞",
	"u": "⠥",
	"v": "⠧",
	"w": "⠺",
	"x": "⠭",
	"y": "⠽",
	"z": "⠵",
	"/": "⠌",
	"Q": "⠀",
	"W": "⠄",
	"E": "⠈",
	"R": "⠐",
	"T": "⠘",
	"Y": "⠜",
	"U": "⠠",
	"I": "⠡",
	"O": "⠣",
	"P": "⠤",
	"A": "⠨",
	"S": "⠩",
	"D": "⠪",
	"F": "⠫",
	"G": "⠬",
	"H": "⠮",
	"J": "⠯",
	"K": "⠰",
	"L": "⠱",
	"Z": "⠳",
	"X": "⠷",
	"C": "⠸",
	"V": "⠹",
	"B": "⠻",
	"N": "⠼",
	"M": "⠾",
	"+": "⠿",
}
