/*

Input a CSV table, like this:

data00,data01,data02,...,data0m
data10,data11,data12,...,data1m
...
datan0,datan1,datan2,...,datanm
The cells in the CSV table is guaranteed to contain only letters or numbers, and there's no extra whitespace.

Your task is to convert it to a Wikitext table, and output it, like this:

{|
| data00 || data01 || data02 || ... || data0m
|-
| data10 || data11 || data12 || ... || data1m
|-
...
|-
| datan0 || datan1 || datan2 || ... || datanm
|}
Your output must strictly follow this format, except for the whitespaces before or after each cell.

For example, input:

a,b,c
1,2,3
Will output:

{|
| a || b || c
|-
| 1 || 2 || 3
|}
but

{|
| a || b || c
|-
|1||2||3
|}

is also a valid output. This is code-golf, so use the fewest bytes.

*/

package main

import (
	"bytes"
	"encoding/csv"
	"fmt"
	"strings"
)

func main() {
	fmt.Println(csv2wikitext(CSV0))
	fmt.Println(csv2wikitext(CSV1))
}

func csv2wikitext(s string) string {
	r := strings.NewReader(s)
	c := csv.NewReader(r)
	p, err := c.ReadAll()
	if err != nil {
		return "invalid csv"
	}

	w := new(bytes.Buffer)
	fmt.Fprintf(w, "{|\n")
	for y := range p {
		fmt.Fprintf(w, "|")
		for x := range p[y] {
			fmt.Fprintf(w, " %s", p[y][x])
			if x+1 < len(p[y]) {
				fmt.Fprintf(w, " ||")
			}
		}
		if y+1 < len(p) {
			fmt.Fprintf(w, "\n|-")
		}
		fmt.Fprintf(w, "\n")
	}
	fmt.Fprintf(w, "|}\n")
	return w.String()
}

const CSV0 = `
a,b,c
1,2,3
`

const CSV1 = `
x, y, z, t, k, m
4, 5, 6, j, z, 1
1, 2, 3, 4, 5, 6
0, 9, 8, 7, 6, 5
`
