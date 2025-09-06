/*

Inspired by "You had me at hello"

Introduction
For those who don't know, hexadecimal is a base system like decimal. Contrary to decimal however, it uses 16 (hence the name) digits instead of 10.

Here are the first few numbers while counting up in hexadecimal to maybe give you a feel of things, although you should probably google it for more info.

0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 1A, 1B, 1C, 1D, 1E, 1F, 20...

From now on I'll refer to hexadecimal as hex.

Challenge
Take a possibly infinite stream of bytes, and convert it to hex. This should be done as you read since you might get an infinite stream and keep on reading forever.

The twist, is that if a sequence of converted numbers equals the exact hex number DEADBEEF (3735928559 in decimal), you must output FEEDBEEF (4276993775 in decimal) instead.

If no DEADBEEF is found, print the string as it was

Inter-character matches work too, so 2D EA DB EE F0 works and should be converted to 2F EE DB EE F

Example
This might seem a bit vague, so here are 2 step-by-step examples.

Example 1
Input: Hello, World (bytes represented as string)

Step 1: Convert the input to ASCII: 072 101 108 108 111 044 032 087 111 114 108 100

Step 2: Convert the ASCII to hex: 48 65 6C 6C 6F 2C 20 57 6F 72 6C 64

Step 3: Print out everything until DEADBEEF is found. It wasn't found, so just print Hello, World again.

Example 2
Input: Hello,Þ­¾ï,,

Step 1: Convert to ASCII: 72 101 108 108 111 44 222 173 190 239 44 44

Step 2: Convert to hex: 48 65 6C 6C 6F 2C DE AD BE EF 2C 2C

Step 3: Is there DEADBEEF? Yep. so take everything up to it. 48 65 6C 6C 6F 2C

Step 4: Append FEEDBEEF to it. 48 65 6C 6C 6F 2C FE ED BE EF

Step 5: Convert back to a string and print it. Output is Hello,þí¾ï

Scoring
Try to make a program that does the above in the fewest bytes of source code as possible.

Remember!
Make sure your program works for finite and infinite streams. The stream can be STDIN, file, function argument (if you can pass streams as arguments), or your language's closest alternative. Output is to STDOUT or function returning (if you can return streams).

More test cases (contain invisible characters)
eeþí¾Þ­¾ïe (6565feedbedeadbeef65) -> eeþí¾þí¾ïe
Þ­¾ï (deadbeef)-> þí¾ï
Þ=êÛîôV -> Þ?îÛîôV

*/

package main

import (
	"encoding/hex"
	"fmt"
	"strings"
)

func main() {
	fmt.Printf("%q\n", taste("Hello, World"))
	fmt.Printf("%q\n", taste(strhex("48 65 6C 6C 6F 2C DE AD BE EF 2C 2C")))
	fmt.Printf("%q\n", taste(strhex("6565feedbedeadbeef65")))
	fmt.Printf("%q\n", taste(strhex("deadbeef")))
	fmt.Printf("%q\n", taste("Þ=êÛîôV"))
}

func strhex(s string) string {
	s = strings.Replace(s, " ", "", -1)
	b, err := hex.DecodeString(s)
	if err != nil {
		panic(err)
	}
	return string(b)
}

func taste(s string) string {
	i := strings.Index(s, "\xde\xad\xbe\xef")
	if i >= 0 {
		s = s[:i] + "\xfe\xed\xbe\xef"
	}
	return s
}
