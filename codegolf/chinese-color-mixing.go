/*

Objective
Given two Chinese ideographs meaning basic colors, output the ideograph that means the color resulting from mixing them.

Basic colors
The basic colors are:

靑(U+9751; blue)
赤(U+8D64; red)
黃(U+9EC3; yellow)
白(U+767D; white)
黑(U+9ED1; black)
Mixed colors
Mixing 靑(blue) and 赤(red) yields 靘(U+9758; purple).
Mixing 赤(red) and 黃(yellow) yields 熏(U+718F; orange).
Mixing 黃(yellow) and 白(white) yields 硅(U+7845; beige).
Mixing 白(white) and 黑(black) yields 黻(U+9EFB; grey).
Mixing 黑(black) and 靑(blue) yields 黯(U+9EEF; deep blue).
Mixing 靑(blue) and 黃(yellow) yields 綠(U+7DA0; green).
Mixing 黃(yellow) and 黑(black) yields 騮(U+9A2E; brown).
Mixing 黑(black) and 赤(red) yields 紫(U+7D2B; wine red).
Mixing 赤(red) and 白(white) yields 紅(U+7D05; pink).
Mixing 白(white) and 靑(blue) yields 碧(U+78A7; sky blue).
(This scheme of color terms is historical, and it doesn't reflect the modern usage of Chinese.)

To summarize in Unicode points:

9751, 8D64, 9758
8D64, 9EC3, 718F
9EC3, 767D, 7845
767D, 9ED1, 9EFB
9ED1, 9751, 9EEF
9751, 9EC3, 7DA0
9EC3, 9ED1, 9A2E
9ED1, 8D64, 7D2B
8D64, 767D, 7D05
767D, 9751, 78A7

Rules
I/O format is flexible. In particular, I/O in Unicode points is okay, and outputting trailing whitespace is permitted.

Mixing colors is commutative. It is assumed that the two inputted basic colors are different.

In any case, an input not fitting into your format falls in don't care situation.

Examples
Given 靑 and 白, output 碧.
Given 赤 and 白, output 紅.

*/

package main

import "fmt"

func main() {
	assert(mix('靑', '白') == '碧')
	assert(mix('赤', '白') == '紅')
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mix(a, b rune) rune {
	m := map[string]rune{
		"靑赤": '靘',
		"赤黃": '熏',
		"黃白": '硅',
		"白黑": '黻',
		"黑靑": '黯',
		"靑黃": '綠',
		"黃黑": '騮',
		"黑赤": '紫',
		"赤白": '紅',
		"白靑": '碧',
	}

	k := fmt.Sprintf("%c%c", a, b)
	if m[k] == 0 {
		k = fmt.Sprintf("%c%c", b, a)
	}
	return m[k]
}
