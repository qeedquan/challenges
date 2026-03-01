/*

The Rockstar programming language has "poetic number literals", allowing you to assign nonnegative, finite (at least one Rockstar interpreter supports infinity) numbers to variables without typing a single digit: just type words with length equal to each digit, modulo 10. For example,

This is a challenge
sets the variable this to 19.

So here is the challenge: given a string as input, output its value as a poetic number literal.

To calculate the value, split the string up into words (separated by one or more spaces, one or more commas, or both), then take the ones digit of the length of each word, and finally concatenate for the value. However, if there are one or more periods ., the first period is to be interpreted as a decimal point, and any other periods treated as word separators.

You can assume the input is nonempty, and will consist of nothing but letters, commas, periods and spaces. Also, you can assume there is no period before the first word.

You can ignore edge cases, like when the word is not supposed to be interpreted as a number. For example,

The news is true
will not set the variable the news to 4, because true is to be interpreted as a boolean value. However, your program should output 4 given true as an input.

Test cases:

test cases -> 45
hi -> 2
hi      bye -> 23
hi , ,, ,,, bye -> 23
hi , ,, .,,, bye -> 2.3
hi, bye -> 23
hi,bye -> 23
verylongword -> 2
a verylongword -> 12
this is azerodigit -> 420
azerodigit -> 0
azerodigit.four -> 0.4
one.azerodigit one -> 3.03
azerodigit hi -> 2
hi. bye -> 2.3
hi.bye -> 2.3
hi. -> 2
hi. bye azerodigit -> 2.3
hi. bye azerodigit ha -> 2.302
hi. azerodigit -> 2
hi.bye.ha -> 2.32
hi.,,..,bye.,.,.,.,.,ha -> 2.32
hi,,..,bye.,.,.,.,.,ha -> 2.32
hi,,,bye.,.,.,.,.,ha -> 23.2
hi,,,bye,,,,,ha -> 232
This is code-golf, so fewest bytes wins!

Edit: For clarity, there cannot be trailing 0s in the decimal part, or leading 0s in the integer part of the number for valid inputs. For example, azerodigit hi. azerodigit should output 2, not 02.0, 2.0 or anything other than 2.

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	test("test cases", "45")
	test("hi", "2")
	test("hi      bye", "23")
	test("hi , ,, ,,, bye", "23")
	test("hi , ,, .,,, bye", "2.3")
	test("hi, bye", "23")
	test("hi,bye", "23")
	test("verylongword", "2")
	test("a verylongword", "12")
	test("this is azerodigit", "420")
	test("azerodigit", "0")
	test("azerodigit.four", "0.4")
	test("one.azerodigit one", "3.03")
	test("azerodigit hi", "2")
	test("hi. bye", "2.3")
	test("hi.bye", "2.3")
	test("hi.", "2")
	test("hi. bye azerodigit", "2.3")
	test("hi. bye azerodigit ha", "2.302")
	test("hi. azerodigit", "2")
	test("hi.bye.ha", "2.32")
	test("hi.,,..,bye.,.,.,.,.,ha", "2.32")
	test("hi,,..,bye.,.,.,.,.,ha", "2.32")
	test("hi,,,bye.,.,.,.,.,ha", "23.2")
	test("hi,,,bye,,,,,ha", "232")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s, r string) {
	p := rpnl(s)
	fmt.Println(p)
	assert(p == r)
}

func rpnl(s string) string {
	d := dot(s)
	t := tokenize(s)
	v := value(t, d)
	return clean(v, d)
}

func dot(s string) int {
	for d, i := 0, 0; i < len(s); d++ {
		if s[i] == '.' {
			return d
		}

		for i < len(s) && strings.IndexByte(" ,.", s[i]) < 0 {
			i++
		}

		for i < len(s) && strings.IndexByte(" ,", s[i]) >= 0 {
			i++
		}
	}
	return -1
}

func tokenize(s string) []string {
	s = strings.Replace(s, ",", " ", -1)
	s = strings.Replace(s, ".", " ", -1)
	t := []string{}
	for _, p := range strings.Split(s, " ") {
		p = strings.TrimSpace(p)
		if p != "" {
			t = append(t, p)
		}
	}
	return t
}

func value(t []string, d int) string {
	w := new(bytes.Buffer)
	for _, p := range t {
		fmt.Fprintf(w, "%d", len(p)%10)
	}
	r := w.String()
	if d >= 0 {
		r = r[:d] + "." + r[d:]
	}
	return r
}

func clean(s string, d int) string {
	if d > 0 {
		for len(s) > 1 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 1 && s[0] == '0' && s[1] != '.' {
		s = s[1:]
	}

	s = strings.TrimSuffix(s, ".")
	if s == "" {
		s = "0"
	}

	return s
}
