/*

Do you know the optical effect of a tridimensional hand painted whit horizontal lines? Examples

This challenge consists of making something like that effect with ascii, and transforming one 2d input into a "3d" output.

The algorithm
To perform this transformation, you first replace all 1 with a ¯ and all 0 with a _. In order to make things more realistic, you should replace a ¯ that does not have another ¯ before it with /, and a ¯ that does not have another ¯ after it with \.

Some examples:

Input:
001111100

Output:
__/¯¯¯\__
Input:
0110
1111

Output:
_/\_
/¯¯\
^ In this case, there are multiple lines, so apply this to all lines.

Input:
000000000000000000000000000000000
000000111100000000000001111100000
000000111110000000000111111000000
000000111111000000011111100000000
000000111111000001111110000000000
000000011111100011111100000000000
000000111111111111111100000000000
000000111101111111011110000000000
000000111100111110011110000000000
000000111111111111111110000000000
000000111111111111111110000000000
000000001111111111110000000000000
000000000001111100000000000000000
000000000000000000000000000000000

Output:
_________________________________
______/¯¯\_____________/¯¯¯\_____
______/¯¯¯\__________/¯¯¯¯\______
______/¯¯¯¯\_______/¯¯¯¯\________
______/¯¯¯¯\_____/¯¯¯¯\__________
_______/¯¯¯¯\___/¯¯¯¯\___________
______/¯¯¯¯¯¯¯¯¯¯¯¯¯¯\___________
______/¯¯\_/¯¯¯¯¯\_/¯¯\__________
______/¯¯\__/¯¯¯\__/¯¯\__________
______/¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\__________
______/¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\__________
________/¯¯¯¯¯¯¯¯¯¯\_____________
___________/¯¯¯\_________________
_________________________________
Exceptions / rules:

The input will never have a single positive cell in a row (e.g. 00100)

You can consider other characters for the input. However, it should only be two characters and not the same characters that the output uses. For instance:

Valid input:    0001111000 # two characters, different from the output
Valid input:    aaiiaiiaaa # two characters, different from the output
Valid input:    ,€€€€,,,,, # two characters, different from the output
Invalid input:  0001223000 # four different characters are used.
Invalid input:  ___1111___ # invalid, because the output uses underscores.
Invalid input:  ///\\\\/// # both slash and backslash are used by the output.
The output must use the four characters described above and only those four. Alternatively, you may use - instead of the macron (¯)

The macron (upper character) has a codepoint of 175, but you may count it as one byte.

This is code-golf, so the shortest code in bytes wins.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	draw(pseudo3d([]string{
		`001111100`,
	}))

	draw(pseudo3d([]string{
		`0110`,
		`1111`,
	}))

	draw(pseudo3d([]string{
		`000000000000000000000000000000000`,
		`000000111100000000000001111100000`,
		`000000111110000000000111111000000`,
		`000000111111000000011111100000000`,
		`000000111111000001111110000000000`,
		`000000011111100011111100000000000`,
		`000000111111111111111100000000000`,
		`000000111101111111011110000000000`,
		`000000111100111110011110000000000`,
		`000000111111111111111110000000000`,
		`000000111111111111111110000000000`,
		`000000001111111111110000000000000`,
		`000000000001111100000000000000000`,
		`000000000000000000000000000000000`,
	}))
}

func draw(lines []string) {
	for _, line := range lines {
		fmt.Println(line)
	}
	fmt.Println()
}

func pseudo3d(lines []string) []string {
	result := []string{}
	for _, line := range lines {
		line = strings.Replace(line, `0`, `_`, -1)
		line = strings.Replace(line, `1`, `/\`, -1)
		line = strings.Replace(line, `\/`, `¯`, -1)
		line = strings.Replace(line, `/¯`, `/`, -1)
		result = append(result, line)
	}
	return result
}
