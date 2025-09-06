/*

Given an input of an ASCII art picture, output the ASCII art italicized.

To italicize the ASCII art:

Insert zero spaces before the last line, one space before the second-last line, two spaces before the third-last line, etc.

Remove any extra leading whitespace that may have been created. That is, if each line has at least n spaces preceding it, remove n spaces from the beginning of each line.

Replace all \s with |, all |s with /, and all /s with _. Keep existing _s the same.

The input is guaranteed to contain only the characters \|/_ and space.

For example, the input

/\/\/\    /\/\/\      /\/\/\    /\/\/\
 /\    /\  /\    /\  /\        /\
  /\/\/\    /\/\/\    /\        /\  /\/\
   /\        /\        /\        /\    /\
    /\        /\          /\/\/\    /\/\/\
must output

_|_|_|    _|_|_|      _|_|_|    _|_|_|
_|    _|  _|    _|  _|        _|
_|_|_|    _|_|_|    _|        _|  _|_|
_|        _|        _|        _|    _|
_|        _|          _|_|_|    _|_|_|
which in turn, provided as input, outputs

    _/_/_/    _/_/_/      _/_/_/    _/_/_/
   _/    _/  _/    _/  _/        _/
  _/_/_/    _/_/_/    _/        _/  _/_/
 _/        _/        _/        _/    _/
_/        _/          _/_/_/    _/_/_/
which would output

        ______    ______      ______    ______
      __    __  __    __  __        __
    ______    ______    __        __  ____
  __        __        __        __    __
__        __          ______    ______
Input and output may be either a single string (with optional trailing newline) or an array of lines.

Since this is code-golf, the shortest code in bytes will win.

Extra test cases:

|||||
  /////
 \\\\\
   _____
 /////
  _____
|||||
 _____

________
________

(that is, input of empty string results in output of empty string)

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
	"unicode"
)

func main() {
	fmt.Println(italicize(ART1))
	fmt.Println(italicize(ART2))
	fmt.Println(italicize(ART3))
	fmt.Println(italicize(ART4))
	fmt.Println(italicize(ART5))
	fmt.Println(italicize(ART6))
}

func italicize(s string) string {
	r := []string{}
	t := strings.Split(s, "\n")
	m := 0
	for i, p := range t {
		n := leadingspaces(p) + len(t) - i - 1
		p = strings.TrimSpace(p)
		p = strings.Repeat(" ", n) + p
		p = sub(p)
		m = minz(m, leadingspaces(p))
		r = append(r, p)
	}
	for i := range r {
		r[i] = r[i][m:]
	}

	return strings.Join(r, "\n")
}

func minz(a, b int) int {
	if a == 0 || a > b {
		return b
	}
	return a
}

func leadingspaces(s string) int {
	for i, r := range s {
		if !unicode.IsSpace(r) {
			return i
		}
	}
	return len(s)
}

func sub(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		switch r {
		case '\\':
			r = '|'
		case '|':
			r = '/'
		case '/':
			r = '_'
		}
		w.WriteRune(r)
	}
	return w.String()
}

func mkart(s string) string {
	r := []string{}
	t := strings.Split(s, "\n")
	for _, t := range t {
		if strings.TrimSpace(t) != "" {
			r = append(r, t)
		}
	}
	return strings.Join(r, "\n")
}

var ART1 = mkart(`
/\/\/\    /\/\/\      /\/\/\    /\/\/\
 /\    /\  /\    /\  /\        /\
  /\/\/\    /\/\/\    /\        /\  /\/\
   /\        /\        /\        /\    /\
    /\        /\          /\/\/\    /\/\/\
`)

var ART2 = mkart(`
_|_|_|    _|_|_|      _|_|_|    _|_|_|
_|    _|  _|    _|  _|        _|
_|_|_|    _|_|_|    _|        _|  _|_|
_|        _|        _|        _|    _|
_|        _|          _|_|_|    _|_|_|
`)

var ART3 = mkart(`
    _/_/_/    _/_/_/      _/_/_/    _/_/_/
   _/    _/  _/    _/  _/        _/
  _/_/_/    _/_/_/    _/        _/  _/_/
 _/        _/        _/        _/    _/
_/        _/          _/_/_/    _/_/_/
`)

var ART4 = mkart(`
|||||
  /////
 \\\\\
   _____
`)

var ART5 = mkart(`________`)

var ART6 = mkart(``)
