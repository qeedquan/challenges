/*

Your task is to create a program will transform each letter of a text typed on a AZERTY keyboard to the equivalent on a QWERTY keyboard, using the same keystrokes.

Example: Hello; Zorld1 => Hello, World!

List of character to convert:

A <=> Q
Z <=> W
, => m
? => M
M => :
1 => !
9 => (
; => ,
§ => ?
0 => )
) => -
ù => '

QWERTY keyboard:
https://i.sstatic.net/VVfs7.png

AZERTY keyboard:
https://i.sstatic.net/2BSuV.png

Test cases:

Input: This is q text zritten zith q QWERTY keyboqrd:
Output: This is a text written with a AZERTY keyboard.

Input: Hello zorld in PythonM print9ùHello; Zorld1ù0
Output: Hello world in Python: print('Hello, World!')

Input: Zikipediq is q free online enciclopediq
Output: Wikipedia is a free online enciclopedia

Input: Progrq,,ing puwwles qnd code)golf
Output: Programming puzzles and code-golf

Input: Zhy ,y lqyout hqve szitched to QWERTY §
Output: Why my layout have switched to AZERTY ?
This is code golf, so the answer with the shortest byte count win.

*/

package main

import (
	"strings"
)

func main() {
	assert(translate("This is q text zritten zith q QWERTY keyboqrd:") == "This is a text written with a AZERTY keyboard.")
	assert(translate("Hello zorld in PythonM print9ùHello; Zorld1ù0") == "Hello world in Python: print('Hello, World!')")
	assert(translate("Zikipediq is q free online enciclopediq") == "Wikipedia is a free online enciclopedia")
	assert(translate("Progrq,,ing puwwles qnd code)golf") == "Programming puzzles and code-golf")
	assert(translate("Zhy ,y lqyout hqve szitched to QWERTY §") == "Why my layout have switched to AZERTY ?")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func translate(s string) string {
	m := map[rune]rune{
		'a':  'q',
		'z':  'w',
		'q':  'a',
		'w':  'z',
		'A':  'Q',
		'Z':  'W',
		'Q':  'A',
		'W':  'Z',
		'&':  '1',
		'é':  '2',
		'"':  '3',
		'\'': '4',
		'(':  '5',
		'-':  '6',
		'è':  '7',
		'_':  '8',
		'ç':  '9',
		'à':  '0',
		')':  '-',
		'^':  '[',
		'$':  ']',
		'M':  ':',
		'ù':  '\'',
		',':  'm',
		'?':  'M',
		';':  ',',
		':':  '.',
		'!':  '/',
		'§':  '?',
		'1':  '!',
		'2':  '@',
		'3':  '#',
		'4':  '$',
		'5':  '%',
		'6':  '^',
		'7':  '&',
		'8':  '*',
		'9':  '(',
		'0':  ')',
	}

	f := func(r rune) rune {
		if c, ok := m[r]; ok {
			r = c
		}
		return r
	}

	return strings.Map(f, s)
}
