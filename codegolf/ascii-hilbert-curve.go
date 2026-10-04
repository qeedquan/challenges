/*

Given an integer n output the nth iteration of the Hilbert Curve in ASCII using the characters _ and |.

Here are the first 4 iterations:

n=1
 _
| |

n=2
 _   _
| |_| |
|_   _|
 _| |_

n=3
 _   _   _   _
| |_| | | |_| |
|_   _| |_   _|
 _| |_____| |_
|  ___   ___  |
|_|  _| |_  |_|
 _  |_   _|  _
| |___| |___| |

n=4
 _   _   _   _   _   _   _   _
| |_| | | |_| | | |_| | | |_| |
|_   _| |_   _| |_   _| |_   _|
 _| |_____| |_   _| |_____| |_
|  ___   ___  | |  ___   ___  |
|_|  _| |_  |_| |_|  _| |_  |_|
 _  |_   _|  _   _  |_   _|  _
| |___| |___| |_| |___| |___| |
|_   ___   ___   ___   ___   _|
 _| |_  |_|  _| |_  |_|  _| |_
|  _  |  _  |_   _|  _  |  _  |
|_| |_| | |___| |___| | |_| |_|
 _   _  |  ___   ___  |  _   _
| |_| | |_|  _| |_  |_| | |_| |
|_   _|  _  |_   _|  _  |_   _|
 _| |___| |___| |___| |___| |_

Clarifications
My question is similar to Draw the Hilbert Curve and Draw the Hilbert curve using slashes.
The conversion between underscores (_) and vertical bars (|) is u=2*v-1 where u is the number of _s and v is the number of |s.
To maintain consistency with my original post the curve must start and end at the bottom.
You can have a full program or a function.
Output to stdout (or something similar).
You can have leading or trailing white-spaces, the output just needs to line up so that it looks like the examples.
This is code-golf so shortest answer in bytes wins.

*/

package main

import "fmt"

func main() {
	h := Hilbert{}
	for i := 0; i <= 6; i++ {
		h.Draw(i)
	}
}

// ported from @Milo Yip solution
type Hilbert struct {
	l, p, q int
	dirs    [4]int
}

func (h *Hilbert) Draw(n int) {
	fmt.Printf("n=%d\n", n)
	s := 1 << n
	h.dirs = [4]int{1, -s, -1, s}
	for h.p, h.q = 0, 0; h.q < s*s; {
		h.p = s*s - s
		h.l = 1
		h.split(0, 1, n)
		h.stroke(3)
		if h.q++; h.q%s == 0 {
			fmt.Printf("\n")
		}
	}
	fmt.Println()
}

func (h *Hilbert) split(d, r, n int) {
	if n--; n >= 0 {
		h.split(d+r, -r, n)

		h.stroke(d + r)
		h.split(d, r, n)

		h.stroke(d)
		h.split(d, r, n)

		h.stroke(d - r)
		h.split(d-r, -r, n)
	}
}

func (h *Hilbert) stroke(d int) {
	const sym = "__|      _|       |___ _|_| | | "

	d &= 3
	if h.p-h.q == 0 {
		i := 8*h.l + 2*d
		fmt.Printf("%c%c", sym[i], sym[i+1])
	}
	h.l = d
	h.p += h.dirs[d]
}
