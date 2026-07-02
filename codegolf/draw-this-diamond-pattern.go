/*

The below pattern will form the basis of this challenge.

     /\
     \/
     /\
    /  \
   /    \
/\/      \/\
\/\      /\/
   \    /
    \  /
     \/
     /\
     \/
Given an input width and height, each >=1, output the above ASCII art pattern repeated that many times, joining (and overlapping) at the small diamonds.

For example, here is an input with width = 2 and height = 1:

     /\        /\
     \/        \/
     /\        /\
    /  \      /  \
   /    \    /    \
/\/      \/\/      \/\
\/\      /\/\      /\/
   \    /    \    /
    \  /      \  /
     \/        \/
     /\        /\
     \/        \/
Here is an input width = 3 and height = 2:

     /\        /\        /\
     \/        \/        \/
     /\        /\        /\
    /  \      /  \      /  \
   /    \    /    \    /    \
/\/      \/\/      \/\/      \/\
\/\      /\/\      /\/\      /\/
   \    /    \    /    \    /
    \  /      \  /      \  /
     \/        \/        \/
     /\        /\        /\
     \/        \/        \/
     /\        /\        /\
    /  \      /  \      /  \
   /    \    /    \    /    \
/\/      \/\/      \/\/      \/\
\/\      /\/\      /\/\      /\/
   \    /    \    /    \    /
    \  /      \  /      \  /
     \/        \/        \/
     /\        /\        /\
     \/        \/        \/

Rules and I/O
Input and output can be given by any convenient method.
You can print it to STDOUT or return it as a function result.
Either a full program or a function are acceptable.
Any amount of extraneous whitespace is acceptable, so long as the characters line up appropriately.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	diamond(1, 1)
	diamond(2, 1)
	diamond(3, 2)
}

func diamond(w, h int) {
	art := [4][]string{
		ART,
		trim(ART, 2, 0),
		ART[2:],
		trim(ART[2:], 2, 0),
	}

	f := 0
	for y := 0; y < h; y++ {
		l := len(art[f])
		for i := 0; i < l; i++ {
			f &^= 1
			for x := 0; x < w; x++ {
				fmt.Print(art[f][i])
				f |= 1
			}
			if i+1 < l {
				fmt.Println()
			}
		}
		fmt.Println()
		f |= 2
	}
	fmt.Println()
}

func trim(s []string, i, j int) []string {
	r := []string{}
	for _, t := range s {
		r = append(r, t[i:len(t)-j])
	}
	return r
}

func mkart(s string) []string {
	r := []string{}
	t := strings.Split(s, "\n")
	m := 0
	for _, t := range t {
		m = max(m, len(t))
	}
	for _, t := range t {
		if strings.TrimSpace(t) != "" {
			t += strings.Repeat(" ", max(m-len(t), 0))
			r = append(r, t)
		}
	}
	return r
}

var ART = mkart(`
     /\
     \/
     /\
    /  \
   /    \
/\/      \/\
\/\      /\/
   \    /
    \  /
     \/
     /\
     \/
`)
