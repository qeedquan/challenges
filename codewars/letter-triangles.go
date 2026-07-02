/*

Letter triangles

Similar to Coloured triangles ( https://www.codewars.com/kata/5a25ac6ac5e284cfbe000111 ).

But this one sums indexes of letters in alphabet.

Examples

c o d e w a r s
c is 3
o is 15
15+3=18
18. letter in the alphabet is r
then append r
next is o d
sum is 19
append s
do this until you iterate through whole string
now, string is rsibxsk
repeat whole cycle until you reach 1 character
then return the char
output is l
codewars -> l
triangle -> d

C O D E W A R S
 R S I B X S K
  K B K Z Q D
   M M K Q U
    Z X B L
     X Z N
      X N
       L

A B C D
 C E G
  H L
   T

More examples

youhavechosentotranslatethiskata -> a
cod -> k
yes -> b
hours -> y
circlecipher -> z
lettertriangles -> o
cod -> rs -> k
abcd -> ceg -> hl -> t
codewars -> rsibxsk -> kbkzqd -> mmkqu -> zxbl -> xzn -> xn -> l

Note, if the sum is bigger than 26, then start over

Input will always be lowercase letters. Random tests contains strings up to 30 letters.

*/

package main

import (
	"strings"
)

func main() {
	assert(triangle("codewars") == "l")
	assert(triangle("triangle") == "d")
	assert(triangle("youhavechosentotranslatethiskata") == "a")
	assert(triangle("cod") == "k")
	assert(triangle("yes") == "b")
	assert(triangle("hours") == "y")
	assert(triangle("circlecipher") == "z")
	assert(triangle("lettertriangles") == "o")
	assert(triangle("cod") == "k")
	assert(triangle("abcd") == "t")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func triangle(row string) string {
	const alphabet = "abcdefghijklmnopqrstuvwxyz"
	for len(row) > 1 {
		next := ""
		for index := range len(row) - 1 {
			value0 := strings.IndexByte(alphabet, row[index]) + 1
			value1 := strings.IndexByte(alphabet, row[index+1]) + 1
			next += string(alphabet[mod(value0+value1-1, 26)])
		}
		row = next
	}
	return row
}

func mod(x, m int) int {
	x %= m
	if x < 0 {
		x += m
	}
	return x
}
