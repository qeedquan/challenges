/*

Write a function or a full program that applies an ASCII texture to a 2d shape.

Inputs: shape, texture, dimensions(optionally).

Both Shape and Texture can be given by any convenient method (2d matrix, array of strings or string with newlines)
Shape data have a rectangular shape and contains 2 possible values: [truthy/falsey] binary/integer values (0/1 or n1/n2) or 2 different characters, just specify which one represent the shape parts [truthy] and which one represent the blank parts [falsey] and be consistent.

The texture has a square shape only (width ≡ height) and contains printable ASCII characters.

Optionally you can also pass dimensions of the matrices if needed.
Output: the shape with each truthy value substituted with the corresponding texture value (coordinates/indices mod texture size), the blank parts must be substituted with spaces.

The ratio is always 1:1
The entire shape must be covered and only the shape.
No offset, texturing must start at top-left corner (0,0) of the shape data with the origin of the texture also at the top-left corner.
Examples (using various shape formats in JSON)
Shape

[[0,0,1,1,0,0],
 [0,1,1,1,1,0],
 [0,1,1,1,1,0],
 [0,0,1,1,0,0]]
Texture

["/\\",
 "\\/"]
Output

["  /\  ",
 " /\/\ ",
 " \/\/ ",
 "  \/  "]
Shape

["        xxxxxxxx     ",
 "  xxxxxxxxxxxxxxxx   ",
 "    xxxxxxxxxxxxxxxx ",
 "  xxxxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxxxxxx"]
Texture

["[__]",
 "_][_",
 "[__]",
 "_][_"]
Output

["        [__][__]     ",
 "  [__][__][__][__]   ",
 "    [__][__][__][__] ",
 "  [__][__][__][__][__",
 "[__][__][__][__][__][",
 "_][__][__][__][__][__",
 "[__][__][__][__][__][",
 "_][__][__][__][__][__"]
Shape

[0,0,0,1]
Texture

["ab",
 "ba"]
Output

["   b"]
Shape

["11100001011010",
 "01111010101101",
 "01011011111101"]
Texture

["   ./]| |  / /.",
 "_|_|[]|/|_/\\_|/",
 "_|_|[/|_|_\\/_|.",
 "./_./]|_|//\\/./",
 "_|_|[]|/|_/\\_|/",
 "_|_|[]/ | \\/_|.",
 " /_  /|_|//\\/3/",
 "_|_|[]|/|_/\\_|/",
 "_|_|/ |_|_\\/_|.",
 "./_$/]|_|//\\/./",
 " |_|  |/|_/\\_|/",
 "_|_|[/|_|_\\$_|/",
 "_/  /]|_/ /\\///",
 "_|_/[]|/|/ \\_|/",
 "_|/|[/|_|_ /_||",
 " /_./]|_|  \\/|/"]
Output

(a surprise for you!)

Rules
Input/output can be given by any convenient method.
You can print it to STDOUT or return it as a function result.
Either a full program or a function are acceptable.
Extraneous whitespace are forbidden.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	output(texture([]string{
		"001100",
		"011110",
		"011110",
		"001100",
	}, []string{
		"/\\",
		"\\/",
	}))

	output(texture([]string{
		"        xxxxxxxx     ",
		"  xxxxxxxxxxxxxxxx   ",
		"    xxxxxxxxxxxxxxxx ",
		"  xxxxxxxxxxxxxxxxxxx",
		"xxxxxxxxxxxxxxxxxxxxx",
		"xxxxxxxxxxxxxxxxxxxxx",
		"xxxxxxxxxxxxxxxxxxxxx",
		"xxxxxxxxxxxxxxxxxxxxx",
	}, []string{
		"[__]",
		"_][_",
		"[__]",
		"_][_",
	}))

	output(texture([]string{
		"0001",
	}, []string{
		"ab",
		"ba",
	}))

	output(texture([]string{
		"11100001011010",
		"01111010101101",
		"01011011111101",
	}, []string{
		"   ./]| |  / /.",
		"_|_|[]|/|_/\\_|/",
		"_|_|[/|_|_\\/_|.",
		"./_./]|_|//\\/./",
		"_|_|[]|/|_/\\_|/",
		"_|_|[]/ | \\/_|.",
		" /_  /|_|//\\/3/",
		"_|_|[]|/|_/\\_|/",
		"_|_|/ |_|_\\/_|.",
		"./_$/]|_|//\\/./",
		" |_|  |/|_/\\_|/",
		"_|_|[/|_|_\\$_|/",
		"_/  /]|_/ /\\///",
		"_|_/[]|/|/ \\_|/",
		"_|/|[/|_|_ /_||",
		" /_./]|_|  \\/|/",
	}))
}

func texture(s, t []string) []string {
	var (
		r          []string
		w, h, W, H int
	)

	if !dim(s, &w, &h) {
		return r
	}

	if !dim(t, &W, &H) {
		return s
	}

	b := new(bytes.Buffer)
	for y := 0; y < h; y++ {
		b.Reset()
		for x := 0; x < w; x++ {
			c := byte(' ')
			if !(s[y][x] == '0' || s[y][x] == ' ') {
				c = t[y%H][x%W]
			}
			b.WriteByte(c)
		}
		r = append(r, b.String())
	}
	return r
}

func dim(s []string, w, h *int) bool {
	if len(s) == 0 || len(s[0]) == 0 {
		return false
	}

	*w = len(s[0])
	*h = len(s)
	return true
}

func output(s []string) {
	for _, s := range s {
		fmt.Println(s)
	}
	fmt.Println()
}
