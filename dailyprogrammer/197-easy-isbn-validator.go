/*

Description
ISBN's (International Standard Book Numbers) are identifiers for books. Given the correct sequence of digits, one book can be identified out of millions of others thanks to this ISBN. But when is an ISBN not just a random slurry of digits? That's for you to find out.

Rules
Given the following constraints of the ISBN number, you should write a function that can return True if a number is a valid ISBN and False otherwise.

An ISBN is a ten digit code which identifies a book. The first nine digits represent the book and the last digit is used to make sure the ISBN is correct.

To verify an ISBN you :-

obtain the sum of 10 times the first digit, 9 times the second digit, 8 times the third digit... all the way till you add 1 times the last digit. If the sum leaves no remainder when divided by 11 the code is a valid ISBN.

For example :

0-7475-3269-9 is Valid because

(10 * 0) + (9 * 7) + (8 * 4) + (7 * 7) + (6 * 5) + (5 * 3) + (4 * 2) + (3 * 6) + (2 * 9) + (1 * 9) = 242 which can be divided by 11 and have no remainder.

For the cases where the last digit has to equal to ten, the last digit is written as X. For example 156881111X.

Bonus
Write an ISBN generator. That is, a programme that will output a valid ISBN number (bonus if you output an ISBN that is already in use :P )

Finally
Thanks to u/TopLOL for the submission!

*/

package main

import "strings"

func main() {
	assert(isbn("0-7475-3269-9") == true)
	assert(isbn("156881111X") == true)
	assert(isbn("156881112X") == false)
	assert(isbn("1290830") == false)
	assert(isbn("3813401383") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func isbn(s string) bool {
	s = strings.Replace(s, "-", "", -1)
	if len(s) != 10 {
		return false
	}

	r := 0
	for i, j := len(s), 0; i > 0; i, j = i-1, j+1 {
		if s[j] == 'X' {
			r += 10 * i
		} else if '0' <= s[j] && s[j] <= '9' {
			r += int(s[j]-'0') * i
		}
	}
	return r%11 == 0
}
