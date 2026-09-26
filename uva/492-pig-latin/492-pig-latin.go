package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(solve("This is the input.") == "hisTay isay hetay inputay.")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) string {
	w := new(bytes.Buffer)
	p := []rune{}
	for _, r := range s {
		switch {
		case ('a' <= r && r <= 'z') || ('A' <= r && r <= 'Z'):
			p = append(p, r)

		default:
			if len(p) == 0 {
				fmt.Fprintf(w, "%c", r)
				continue
			}

			switch p[0] {
			case 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U':
				fmt.Fprintf(w, "%say%c", string(p), r)
			default:
				fmt.Fprintf(w, "%s%cay%c", string(p[1:]), p[0], r)
			}
			p = p[:0]
		}
	}
	return w.String()
}
