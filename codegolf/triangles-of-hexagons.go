/*

Suppose an infinite tiling of hexagons composed of |/\ characters.

 / \ / \ / \ / \
|   |   |   |   |
 \ / \ / \ / \ /  etc.
  |   |   |   |
   \ / \ / \ /
Given input n > 0, output a triangular portion of that tiling as depicted in the below examples, anchored with a _ in the middle of a hexagon:

n=1
\_/

n=2
\/ \/
 \_/

n=3
\  |  /
 \/ \/
  \_/

n=4
\/ \ / \/
 \  |  /
  \/ \/
   \_/

n=5
\  |   |  /
 \/ \ / \/
  \  |  /
   \/ \/
    \_/

n=6
\/ \ / \ / \/
 \  |   |  /
  \/ \ / \/
   \  |  /
    \/ \/
     \_/

n=7
\  |   |   |  /
 \/ \ / \ / \/
  \  |   |  /
   \/ \ / \/
    \  |  /
     \/ \/
      \_/

n=8
\/ \ / \ / \ / \/
 \  |   |   |  /
  \/ \ / \ / \/
   \  |   |  /
    \/ \ / \/
     \  |  /
      \/ \/
       \_/

and so on

Rules
Leading/trailing newlines or other whitespace are optional, provided that the characters line up appropriately.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
Output can be to the console, saved as an image, returned as a list of strings, etc.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	for i := 1; i <= 8; i++ {
		trihex(i)
	}
}

// Ported from @Mr. Xcoder solution
func trihex(n int) {
	const sym0 = `/ \ `
	const sym1 = `  | `

	fmt.Printf("n=%d\n", n)
	for i, k := n, n; i > 0; i-- {
		s := repeat(" ", k-i) + `\`
		if i&1 != 0 {
			s += repeat(sym1, i-1)
		} else {
			s += repeat(sym0, i-1)
		}

		j := min(k+i, len(s))
		s = s[:j]
		if i <= 1 {
			s += "_"
		}
		s += "/"

		fmt.Println(s)
	}
	fmt.Println()
}

func repeat(s string, n int) string {
	if n < 1 {
		return ""
	}
	return strings.Repeat(s, n)
}
