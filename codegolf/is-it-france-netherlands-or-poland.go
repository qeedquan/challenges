/*

Below are simplified versions of the flags of France, Netherlands and Poland respectively, as 9x6 pixels:

https://i.sstatic.net/lQrcYVv9.png

See here for a plain text version.
0=red, 1=white, 2=blue

France
2,2,2,1,1,1,0,0,0
2,2,2,1,1,1,0,0,0
2,2,2,1,1,1,0,0,0
2,2,2,1,1,1,0,0,0
2,2,2,1,1,1,0,0,0
2,2,2,1,1,1,0,0,0

Netherlands
0,0,0,0,0,0,0,0,0
0,0,0,0,0,0,0,0,0
1,1,1,1,1,1,1,1,1
1,1,1,1,1,1,1,1,1
2,2,2,2,2,2,2,2,2
2,2,2,2,2,2,2,2,2

Poland
1,1,1,1,1,1,1,1,1
1,1,1,1,1,1,1,1,1
1,1,1,1,1,1,1,1,1
0,0,0,0,0,0,0,0,0
0,0,0,0,0,0,0,0,0
0,0,0,0,0,0,0,0,0

(Many other flags use this color scheme, but I think a smaller number of flags allows for more creative solutions.)

Task
Given a pair (x,y) of coordinates within the flag matrix and a color c, return the list of countries whose flags have that color at that position.

This is a code-golf challenge.

I/O formats
The I/O formats are quite flexible:

The coordinates may be 0-indexed or 1-indexed, with the smallest y corresponding to either the top row or the bottom row.
You can take either 3 distinct characters or 3 distinct decimal digits for the colors. (But not large numbers that would allow to encode hidden information.)
You can use any 3 distinct values for the countries, in any reasonable format.
You may also return 3 Boolean values or a single bit-mask (e.g. 1=France, 2=Netherlands, 4=Poland).

Test cases
Here we use 0-indexed coordinates with (0,0) at the top-left corner, RWB for the colors and FNP for the countries.

x, y, c    output
0, 0, B    [ F ]
7, 1, R    [ F, N ]
4, 2, W    [ F, N, P ]
4, 2, B    []
7, 4, R    [ F, P ]
8, 2, W    [ N, P ]
6, 3, W    [ N ]
2, 3, R    [ P ]
2, 4, B    [ F, N ]
8, 5, B    [ N ]

*/

package main

import (
	"bytes"
)

func main() {
	assert(id(0, 0, 'B') == "F")
	assert(id(7, 1, 'R') == "FN")
	assert(id(4, 2, 'W') == "FNP")
	assert(id(4, 2, 'B') == "")
	assert(id(7, 4, 'R') == "FP")
	assert(id(8, 2, 'W') == "NP")
	assert(id(6, 3, 'W') == "N")
	assert(id(2, 3, 'R') == "P")
	assert(id(2, 4, 'B') == "FN")
	assert(id(8, 5, 'B') == "N")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@Mukundan314

This function takes input as 0-indexed coordinates with (0,0) at the bottom-left corner and 0, 1, and 2 representing Blue, White, and Red, respectively.
It returns an array of three boolean values, each indicating the presence of a country in the order of France, Netherlands, and Poland.

Explanation
The process for all three countries works in a similar way: divide the x or y coordinate, depending on the direction of the stripes, by the width of the stripes.
This gives us an index of the stripe. After this, we compare the index with the color.

*/

func id(x, y, c int) string {
	switch c {
	case 'B':
		c = 0
	case 'W':
		c = 1
	case 'R':
		c = 2
	}
	y = 5 - y

	w := new(bytes.Buffer)
	if x/3 == c {
		w.WriteByte('F')
	}
	if y/2 == c {
		w.WriteByte('N')
	}
	if y/3 == 2-c {
		w.WriteByte('P')
	}
	return w.String()
}
