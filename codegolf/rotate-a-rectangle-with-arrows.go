/*

Challenge:
You get an input that's composed of six characters: <, ^, >, v, space and newline.
The task is to rotate this rectangle 90 degrees clockwise, even rotating the arrow characters, shifting the four characters.

For example:

> v
< ^
^< v
Gets transformed to:

>^v
^
 ><
<
Specifications:
The input and output is always padded accordingly with spaces. You may assume that the input, output or both always end with a trailing newline. The rectangle size has a minimum width and height of 1, and a maximum width and height of 20.

The shortest code in bytes wins!

*/

package main

import "fmt"

func main() {
	dump(rotate([]string{
		"> v ",
		"< ^ ",
		"^< v",
	}))

	dump(rotate([]string{
		">>>",
		"^^^",
		"<<<",
		"vvv",
	}))
}

/*

@Arnauld

Conversion table for arrow rotation
We handle the 90° clockwise rotation of the characters by reducing their ASCII codes modulo 13 and modulo 6.
This is a simple but minimal perfect hash function. The corresponding lookup string is " <^>v".

Input	ASCII code	mod 13	mod 6	Output
" "	32	6	0	" "
"<"	60	8	2	"^"
">"	62	10	4	"v"
"^"	94	3	3	">"
"v"	118	1	1	"<"

*/

func rotate(s []string) []string {
	const sym = " <^>v"

	if len(s) == 0 {
		return s
	}

	r := []string{}
	for x := 0; x < len(s[0]); x++ {
		t := ""
		for y := len(s) - 1; y >= 0; y-- {
			t += fmt.Sprintf("%c", sym[s[y][x]%13%6])
		}
		r = append(r, t)
	}
	return r
}

func dump(s []string) {
	for i := range s {
		fmt.Printf("%s\n", s[i])
	}
	fmt.Println()
}
