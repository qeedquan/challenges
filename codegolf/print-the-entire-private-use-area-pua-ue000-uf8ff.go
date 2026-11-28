/*

Print every Unicode character in the Basic Multilingual Plane’s Private Use Area, from U+E000 through U+F8FF, inclusive, in ascending code-point order.

Output the actual characters, with no separators, newlines, or placeholders.

Some characters may not display correctly in your terminal or browser, but they must still be included in the output.

The output should be exactly 6400 characters.

This is code golf—the shortest valid program in bytes wins.

*/

package main

import "fmt"

func main() {
	for i := 0xE000; i <= 0xF8FF; i++ {
		fmt.Printf("%#x %c\n", i, i)
	}
}
