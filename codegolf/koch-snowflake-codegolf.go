/*

The Koch snowflake (also known as the Koch star and Koch island) is a mathematical curve and one of the earliest fractal curves to have been described.
It is based on the Koch curve, which appeared in a 1904 paper titled "On a continuous curve without tangents, constructible from elementary geometry" (original French title: "Sur une courbe continue sans tangente, obtenue par une construction géométrique élémentaire") by the Swedish mathematician Helge von Koch.

https://i.sstatic.net/ct24I.gif

Here are some ascii representations of various iterations:

n=1
__
\/

n=2
__/\__
\    /
/_  _\
  \/

n=3
      __/\__
      \    /
__/\__/    \__/\__
\                /
/_              _\
  \            /
__/            \__
\                /
/_  __      __  _\
  \/  \    /  \/
      /_  _\
        \/
Since there is obviously a limit to the resolution of the ascii representation, we must enlarge the size of the snowflake by a factor of 3 for each iteration to show the extra detail.

Write the shortest code to output the snowflake in the same style for n=4

Your program should not take any input.
Your program should write the snowflake to the console.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	for i := range 6 {
		koch(i)
	}
}

// ported from @Keith Randall solution
func koch(n int) {
	fmt.Printf("n=%d\n", n)
	if n < 1 {
		fmt.Println()
		return
	}

	s := "__\n\\G\n"
	for i := 1; i < n; i++ {
		s = next(s)
	}

	z := strings.NewReplacer(
		"a", "_",
		"G", "/",
		"I", " ",
		"F", "\\",
	)
	for _, t := range strings.Split(z.Replace(s), "\n") {
		if strings.TrimSpace(t) != "" {
			fmt.Println(t)
		}
	}
	fmt.Println()
}

func next(s string) string {
	A := map[rune]string{
		'_':  "III",
		'a':  "   ",
		'/':  "__/",
		'G':  "  G",
		'\\': "\\  ",
		'F':  "F__",
		' ':  "   ",
		'I':  "III",
		'\n': "",
	}
	B := map[rune]string{
		'_':  "III",
		'a':  "   ",
		'/':  "\\  ",
		'G':  " aF",
		'\\': "/a ",
		'F':  "  G",
		' ':  "   ",
		'I':  "III",
		'\n': "",
	}
	C := map[rune]string{
		'_':  "___",
		'a':  "aaa",
		'/':  "/  ",
		'G':  "GII",
		'\\': "II\\",
		'F':  "  F",
		' ':  "   ",
		'I':  "III",
		'\n': "",
	}
	z := strings.NewReplacer(
		"____", "__/F",
		"aaaa", "aa  ",
		"/  a", "/a  ",
		"a  F", "  aF",
	)

	var a, b, c, d, r string
	for _, k := range s {
		a += A[k]
		b += B[k]
		c += C[k]
		if k == 'I' {
			a = substr(a, 0, len(a)-3)
			if substr(d, 1, 3) == "a " {
				a += "II\\"
			} else if substr(d, 0, 2) == " a" {
				a += "GII"
			} else {
				a += fmt.Sprintf("%c%c%c", k, k, k)
			}
		}
		d = substr(d, 3, len(d))
		if k == '\n' {
			c = z.Replace(c)
			d = c
			r += fmt.Sprintf("%s\n%s\n%s\n", a, b, d)
			a, b, c = "", "", ""
		}
	}
	return r
}

func substr(s string, i, j int) string {
	j = min(j, len(s))
	if i > j {
		return ""
	}
	return s[i:j]
}
