package main

import (
	"bytes"
	"fmt"
)

func main() {
	fmt.Println(solve("1T1b5T!1T2b1T1b2T!1T1b1T2b2T!1T3b1T1b1T!3T3b1T!1T3b1T1b1T!5T1*1T"))
	fmt.Println(solve("11X21b1X"))
	fmt.Println(solve("4X1b1X"))
}

func solve(s string) string {
	w := new(bytes.Buffer)
	n := 0
	for _, r := range s {
		switch r {
		case '0', '1', '2', '3', '4', '5', '6', '7', '8', '9':
			n += int(r - '0')
		case 'b':
			for range n {
				w.WriteByte(' ')
			}
			n = 0
		case '!':
			w.WriteByte('\n')
		default:
			for range n {
				w.WriteRune(r)
			}
			n = 0
		}
	}
	return w.String()
}
