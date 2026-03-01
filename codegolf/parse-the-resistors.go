/*

The aim is simple: given the string of resistance values, draw the part of "electrical circuit" of those resistors. Examples follow.

Input: 3. Output:

--3--
Input: 1,2,3. Output:

--1----2----3--
Next, the resistors can be joined parallel (by 2 or 3 resistors per join), but the required depth of parallel joins is only 1.

Input: 1|2. Output:

 |--1--|
-|     |-
 |--2--|
Input: 1|2|3. Output:

 |--1--|
-|--2--|-
 |--3--|
Note, that --2-- resistor is now centered.

Input: 1|2,3|4|5. Output:

 |--1--|  |--3--|
-|     |--|--4--|-
 |--2--|  |--5--|
Combined joins:

Input: 1,2,3|4,5,6|7|8,9. Output:

           |--3--|       |--6--|
--1----2---|     |---5---|--7--|---9--
           |--4--|       |--8--|
If it would be more convenient, the input can be a two-dimensional array. I.e. the input for the last example would look like this: [1,2,[3,4],5,[6,7,8],9].

Some notes:

No other forms of (in|out)puts are allowed.
The resistance of each resistor can vary in the range from 1 to 9. Other values, like -, 42 or 0 are disallowed.
The joins like 1|2|3|4 are invalid. As already mentioned, max 3 per parallel join. Empty joins, i.e. ...,|,... or ...,,... are invalid.
Oh, and this is code golf :)

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	circuit([][]int{
		{1},
		{2},
		{3, 4},
		{5},
		{6, 7, 8},
		{9},
	})
}

func circuit(r [][]int) {
	p := [][]byte{}
	for i := range r {
		if len(r[i]) == 1 {
			p = combine(p, serial(r[i][0]))
		} else {
			p = combine(p, parallel(r[i]))
		}
	}

	for i := range p {
		for j := range p[i] {
			fmt.Printf("%c", p[i][j])
		}
		fmt.Println()
	}
	fmt.Println()
}

func combine(p1, p2 [][]byte) [][]byte {
	if len(p1) == 0 {
		return p2
	}
	if len(p2) == 0 {
		return p1
	}

	w1, h1 := len(p1[0]), len(p1)
	w2, h2 := len(p2[0]), len(p2)

	w := w1 + w2
	h := max(h1, h2)
	p := make([][]byte, h)
	for y := range p {
		p[y] = make([]byte, w)
		for x := range p[y] {
			p[y][x] = ' '
		}
	}

	x1, y1 := 0, 0
	x2, y2 := w1, 0
	if h1 < h {
		y1 = (h - h1) / 2
	} else if h2 < h {
		y2 = (h - h2) / 2
	}
	xcopy(p, p1, x1, y1)
	xcopy(p, p2, x2, y2)

	return p
}

func xcopy(p, q [][]byte, xo, yo int) {
	for y := range q {
		for x := range q[y] {
			p[y+yo][x+xo] = q[y][x]
		}
	}
}

func serial(r int) [][]byte {
	return [][]byte{
		[]byte(fmt.Sprintf("--%v--", r)),
	}
}

func parallel(r []int) [][]byte {
	w := 0
	for i := range r {
		w = max(w, len(fmt.Sprint(r[i])))
	}

	p := [][]byte{}
	n := len(r)
	m := n + ((n & 1) ^ 1)
	j := 0
	for i := range m {
		b := new(bytes.Buffer)
		c0 := ' '
		c1 := '-'
		s := ""
		if i == m/2 {
			c0 = '-'
		}
		if i != m/2 || n == m {
			s, j = fmt.Sprint(r[j]), j+1
		} else {
			c1 = ' '
		}
		t := strings.Repeat(" ", w-len(s))
		fmt.Fprintf(b, "%c|%c%c%s%s%c%c|%c", c0, c1, c1, t, s, c1, c1, c0)
		p = append(p, b.Bytes())
	}

	return p
}
