/*

Your function must accept one string and return the opposite

The opposite string is a string where all characters go in reverse order, all letters are replaced with the opposite mirror letter from the English alphabet and are changed in case, and all digits are replaced with opposite mirror digits

opposite mirror for letters means that a must be replaced with z, b must be replaced with y and so on. In general let's say we have some letter which index in alphabet is Index then it must be replaced with letter which index is 25 - Index (25 if zero based)

opposite mirror for digits means that 0 must be replaced with 9, 1 must be replaced with 8 and so on. In general let's say we have some digit which index in 0123456789 is Index then it must be replaced with digit which index is 9 - Index (9 if zero based)

If there is a symbol from non English alphabet or digits in string then you don't change it just move to the correct position in reversed string

Input string can contain any printable character. I mean that there also can be Chinese symbols, Arabic symbols, Russian symbols and so on. But all symbols will be printable

Test cases:

Hello world! --> !WOILD LOOVs

Z 02468 a 13579 A --> z 02468 Z 13579 a

~!@#$%^&*() --> )(*&^%$#@!~

(I) [LOVE] {PROGRAMMING} ,,more,, ..than.. ??10000000000!! --> !!99999999998?? ..MZSG.. ,,VILN,, }tmrnnzitlik{ ]velo[ )r(

By the way мне нравится программировать! --> !ьтавориммаргорп ястиварн енм BZD VSG By
The shortest code in each programming language wins!

*/

package main

func main() {
	assert(opposite("Hello world!") == "!WOILD LOOVs")
	assert(opposite("Z 02468 a 13579 A") == "z 02468 Z 13579 a")
	assert(opposite("~!@#$%^&*()") == ")(*&^%$#@!~")
	assert(opposite("(I) [LOVE] {PROGRAMMING} ,,more,, ..than.. ??10000000000!!") == "!!99999999998?? ..MZSG.. ,,VILN,, }tmrnnzitlik{ ]velo[ )r(")
	assert(opposite("By the way мне нравится программировать!") == "!ьтавориммаргорп ястиварн енм BZD VSG By")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func opposite(s string) string {
	r := []rune(s)
	n := len(r)
	for i := 0; i < n; i++ {
		if i < n/2 {
			r[i], r[n-i-1] = r[n-i-1], r[i]
		}

		switch {
		case 'a' <= r[i] && r[i] <= 'z':
			r[i] = 'Z' - r[i] + 'a'
		case 'A' <= r[i] && r[i] <= 'Z':
			r[i] = 'z' - r[i] + 'A'
		case '0' <= r[i] && r[i] <= '9':
			r[i] = '9' - r[i] + '0'
		}
	}
	return string(r)
}
