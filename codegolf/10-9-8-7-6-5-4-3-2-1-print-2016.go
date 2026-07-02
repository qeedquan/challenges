/*

As a spin-off to my challenge over at Puzzling, your goal is to output 2016.

Rules:

You must include the numbers 10 9 8 7 6 5 4 3 2 1 in that order. They can be used as individual integers or concatenated together (like 1098), but the 10 may not be separated into 1 and 0 - no character(s) may be present between the digits. Note that, in some languages, 10 may not actually represent the integer literal 10, which is acceptable.
Your code must not contain any other numbers or pre-defined number variables or constants (so T in Pyth is not allowed, since it is a numeric constant).
You must calculate 2016 using numerics. Simply outputting 2016 without performing any operations on the required numbers (for example, by decoding an encoded string consisting of only alphabetic characters) is not allowed. Outputting 2016 in pieces (such as 20, then 16) is also not allowed; you must have a single output consisting of the numeric value 2016.
The valid answer with the fewest bytes wins.

*/

package main

import "fmt"

func main() {
	fmt.Println(x2016())
}

func x2016() int {
	return 109876/54 + 3 - 21
}
