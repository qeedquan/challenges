/*

Description:
Give you a character matrix. Find out the character which has the smallest amount.

Arguments:
matrix: A string that contains some letters. Each row is separated by "\n".

Results & Note:
Returns the characters which has smallest amount, using string format.
If more than one characters are found, sort them according to the order A-Za-z0-9.
You can assume that there are at least two characters in the matrix.
Please ignore the "\n" ;-)

Some Examples
matrix=
00000000
0000O000
00000000
00000000
00000000

result -> "O"

matrix=
mmmmmmmmmmmmm
mmmmmmmmmmmmm
mmmmmmmmmmmmm
mmmmmmmmmnmmm

result -> "n"

matrix=
AAAAAAAAAAA
AABBBBBBBBB
BCCCCCCCCDD
DDDDEEEEFFF

result -> "F"

matrix=
AAAAA
ABBBB
BCCCC
DDDDE
EEEEF
FFFFF

result -> "CD"

*/

package main

import (
	"math"
	"sort"
	"strings"
)

func main() {
	assert(findchars([]string{
		"00000000",
		"0000O000",
		"00000000",
		"00000000",
		"00000000",
	}) == "O")

	assert(findchars([]string{
		"mmmmmmmmmmmmm",
		"mmmmmmmmmmmmm",
		"mmmmmmmmmmmmm",
		"mmmmmmmmmnmmm",
	}) == "n")

	assert(findchars([]string{
		"AAAAAAAAAAA",
		"AABBBBBBBBB",
		"BCCCCCCCCDD",
		"DDDDEEEEFFF",
	}) == "F")

	assert(findchars([]string{
		"AAAAA",
		"ABBBB",
		"BCCCC",
		"DDDDE",
		"EEEEF",
		"FFFFF",
	}) == "CD")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func findchars(matrix []string) string {
	count := make(map[rune]int)
	for index := range matrix {
		for _, symbol := range matrix[index] {
			count[symbol] += 1
		}
	}

	minimum := math.MaxInt
	for _, value := range count {
		minimum = min(minimum, value)
	}

	result := []rune{}
	for key, value := range count {
		if value == minimum {
			result = append(result, key)
		}
	}

	sort.Slice(result, func(i, j int) bool {
		const alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
		x := strings.IndexRune(alphabet, result[i])
		y := strings.IndexRune(alphabet, result[j])
		return x < y
	})
	return string(result)
}
