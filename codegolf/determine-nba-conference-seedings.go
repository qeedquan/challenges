/*

Heading into the final day of regular season games for the 2023 NBA season, the fifth to ninth seeds in the Western Conference were still very undecided. Four games would determine the seeding:

New Orleans (N) at Minnesota (M)
Utah at LA Lakers (L)
Golden State (G) at Portland
LA Clippers (C) at Phoenix
Let the Boolean variables M L G C denote the event of the respective team winning. Then the seeding depends on these variables as follows (taken from this Twitter post):

M L G C | 5 6 7 8 9
0 0 0 0 | N G C L M
0 0 0 1 | C N G L M
0 0 1 0 | G N C L M
0 0 1 1 | C G N L M
0 1 0 0 | N C L G M
0 1 0 1 | C L N G M
0 1 1 0 | G N C L M
0 1 1 1 | C G L N M
1 0 0 0 | C G M L N
1 0 0 1 | C G M L N
1 0 1 0 | G C M L N
1 0 1 1 | C G M L N
1 1 0 0 | C L G M N
1 1 0 1 | C L G M N
1 1 1 0 | G C L M N
1 1 1 1 | C G L M N

Task
Given the bits M L G C, output the corresponding permutation of C G L M N, with the fifth seed first. For example, the input M L G C = 1 0 1 0 should give G C M L N. You may use any five distinct symbols for the teams and may format the permutation in any reasonable manner.

Instead of taking M you may take its inverse N, with results altered accordingly (so the input N L G C = 1 0 1 0 gives the same result as M L G C = 0 0 1 0, i.e. G N C L M). You may also combine the Boolean inputs into a single four-bit integer, but in any case you must clearly indicate which bit or bit position corresponds to which game.

This is code-golf; fewest bytes wins.

*/

package main

import "fmt"

func main() {
	for i := 0; i < 16; i++ {
		fmt.Println(seedings(i))
	}
}

func seedings(n int) string {
	tab := []string{
		"NGCLM",
		"CNGLM",
		"GNCLM",
		"CGNLM",
		"NCLGM",
		"CLNGM",
		"GNCLM",
		"CGLNM",
		"CGMLN",
		"CGMLN",
		"GCMLN",
		"CGMLN",
		"CLGMN",
		"CLGMN",
		"GCLMN",
		"CGLMN",
	}
	if n < 0 || n >= len(tab) {
		return ""
	}
	return tab[n]
}
