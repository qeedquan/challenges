package main

import "fmt"

func main() {
	for i := 2; i <= 8; i += 2 {
		quirksome(i)
	}
}

func quirksome(n int) {
	switch n {
	case 2:
		calc(2, 10)
	case 4:
		calc(4, 100)
	case 6:
		calc(6, 1000)
	case 8:
		calc(8, 10000)
	}
}

func calc(n, b int) {
	for i := range b {
		a := i * i
		if i-(a/b) == a%b {
			fmt.Printf("%0*d\n", n, a)
		}
	}
}
