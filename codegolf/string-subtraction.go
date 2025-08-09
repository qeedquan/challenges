/*

Objective
Create a function to reverse string concatenation

Input
Two strings (alphanumeric + spaces), where one should be subtracted for the other.

You can assume that the string to be subtracted will never be larger than the other one.
Output
The result from the subtraction

Subtraction
You should remove one string from the start or the end of another string. If the string is present in the start and in the end, you can only remove one, which one will be removed is up to you.
If the string isn't in the start or in the end, or isn't an exact match, it is an invalid subtraction and you should output the original string.

Test Cases
Valid Subtraction
'abcde','ab' -> 'cde'
'abcde','cde' -> 'ab'
'abab','ab' -> 'ab'
'abcab','ab' -> 'abc' or 'cab'
'ababcde','ab' -> 'abcde'
'acdbcd','cd' -> 'acdb'
'abcde','abcde' -> ''
'abcde','' -> 'abcde'
'','' -> ''

Invalid Subtraction (returns original string)
'abcde','ae' -> 'abcde'
'abcde','aa' -> 'abcde'
'abcde','bcd' -> 'abcde'
'abcde','xab' -> 'abcde'
'abcde','yde' -> 'abcde'

Invalid Input (don't need to be handled)
'','a' -> ''

This is code-golf, so the shortest code in bytes wins!

*/

package main

import "strings"

func main() {
	assert(strsub("abcde", "ab") == "cde")
	assert(strsub("abcde", "cde") == "ab")
	assert(strsub("abab", "ab") == "ab")
	assert(strsub("abcab", "ab") == "cab")
	assert(strsub("ababcde", "ab") == "abcde")
	assert(strsub("acdbcd", "cd") == "acdb")
	assert(strsub("abcde", "abcde") == "")
	assert(strsub("abcde", "") == "abcde")
	assert(strsub("", "") == "")
	assert(strsub("abcde", "ae") == "abcde")
	assert(strsub("abcde", "aa") == "abcde")
	assert(strsub("abcde", "bcd") == "abcde")
	assert(strsub("abcde", "xab") == "abcde")
	assert(strsub("abcde", "yde") == "abcde")
	assert(strsub("", "a") == "")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func strsub(s, t string) string {
	if strings.HasPrefix(s, t) {
		return s[len(t):]
	}
	if strings.HasSuffix(s, t) {
		return s[:len(s)-len(t)]
	}
	return s
}
